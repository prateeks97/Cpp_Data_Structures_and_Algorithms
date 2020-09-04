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

int main(){
    BstNode* root = NULL;
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

}
