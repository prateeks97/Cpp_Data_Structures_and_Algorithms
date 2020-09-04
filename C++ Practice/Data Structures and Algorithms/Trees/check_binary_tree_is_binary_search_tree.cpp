
#include <iostream>
#include <queue>
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

void LevelOrder(Node* root){
    if (root == NULL){
        return;
    }
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* current = Q.front();
        cout << current->data<<" ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}

void PreOrder(Node* root){
    if (root == NULL){
        return;
    }
    cout << root->data<< " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node* root){
    if (root == NULL){
        return;
    }
    InOrder(root->left);
    cout << root->data<< " ";
    InOrder(root->right);
}

bool IsBstUtil(Node* root, int minValue, int maxValue){
    if(root == NULL)
        return true;
    if (root->data > minValue
        && root->data < maxValue
        && IsBstUtil(root->left, minValue, root->data)
        && IsBstUtil(root->right, root->data, maxValue)){
            return true;
        }
    else
        return false;
}

bool IsBinaySearchTree(Node* root){
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

int main(){
    Node* root = NULL;
    root = Insert(root,10);
    root = Insert(root,5);
    root = Insert(root,16);
    root = Insert(root,4);
    root = Insert(root,2);
    root = Insert(root,7);
    root = Insert(root,11);
    //LevelOrder(root);
    InOrder(root);
    if (IsBinaySearchTree(root) == true){
        cout << "Binary Search Tree\n";
    }
    else
        cout << "Not a Binary Search Tree\n";
    return 0;
}

