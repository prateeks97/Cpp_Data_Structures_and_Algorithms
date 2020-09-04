#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

Node* Insert(Node* root, int data){
    if (root == NULL){
        root = GetNewNode(data);
    }
    else if (root->data >= data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;

}
bool Search(Node* root, int data){
    if (root == NULL)
        return false;
    if(root->data == data){
        return true;
    }
    else if (data <= root->data){
        return Search(root->left, data);
    }
    else{
        return Search(root->right, data);
    }
}

Node* FindMin_rec(Node* root){
    if (root == NULL){
        cout<< "Empty Tree\n";
        return NULL;
    }
    else if (root->left == NULL){
            return root;
        }
    return FindMin_rec(root->left);
}

Node* Delete(Node* root, int data){
    if (root==NULL) return root;
    else if (data < root->data){
        root->left = Delete(root->left,data);
    }
    else if (data > root->data){
        root->right = Delete(root->right,data);
    }
    else{
        // Case 1: No Child
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        // Case 2: One Child
        else if (root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two Child
        else{
            Node* temp = FindMin_rec(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    int num;
    cout << "Enter a number to be searched\n";
    cin >> num;
    if (Search(root,num) == true){
        cout << "Found\n";
    }
    else{
        cout << "Not Found\n";
    }

    root = Delete(root, num);

    //int num;
    cout << "Enter a number to be searched\n";
    cin >> num;
    if (Search(root,num) == true){
        cout << "Found\n";
    }
    else{
        cout << "Not Found\n";
    }
}

