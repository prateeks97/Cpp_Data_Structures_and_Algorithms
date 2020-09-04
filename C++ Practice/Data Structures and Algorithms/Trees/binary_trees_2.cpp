#include <iostream>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){
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
bool Search(BstNode* root, int data){
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

int FindMin_itr(BstNode* root){
    if (root == NULL){
        cout<< "Empty Tree\n";
        return -1;
    }
    while (root->left != NULL){
            root = root->left;
        }
    return root->data;
}
int FindMax_itr(BstNode* root){
    if (root == NULL){
        cout<< "Empty Tree\n";
        return -1;
    }
    while (root->right != NULL){
            root = root->right;
        }
    return root->data;
}
int FindMin_rec(BstNode* root){
    if (root == NULL){
        cout<< "Empty Tree\n";
        return -1;
    }
    else if (root->left == NULL){
            return root->data;
        }
    return FindMin_rec(root->left);
}

int FindMax_rec(BstNode* root){
    if (root == NULL){
        cout<< "Empty Tree\n";
        return -1;
    }
    else if (root->right == NULL){
            return root->data;
        }
    return FindMax_rec(root->right);
}

int FindHeight(BstNode* root){
    if (root == NULL){
        return -1;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) +1 ;
}

int main(){
    BstNode* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,3);
    /*int num;
    cout << "Enter a number to be searched\n";
    cin >> num;
    if (Search(root,num) == true){
        cout << "Found\n";
    }
    else{
        cout << "Not Found\n";
    }
    */
    cout << "Minimum data value (iterative): " << FindMin_itr(root)<< endl;
    cout << "Maximum data value (iterative): " << FindMax_itr(root)<< endl;
    cout << "Minimum data value (recursive): " << FindMin_rec(root)<< endl;
    cout << "Maximum data value (recursive): " << FindMax_rec(root)<< endl;
    cout << "Maximum height of the tree: " << FindHeight(root)<< endl;
}
