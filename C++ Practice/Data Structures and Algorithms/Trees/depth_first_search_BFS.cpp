
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

void PostOrder(Node* root){
    if (root == NULL){
        return;
    }
    InOrder(root->left);
    InOrder(root->right);
    cout << root->data<< " ";
}

int main(){
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    LevelOrder(root);
    return 0;
}
