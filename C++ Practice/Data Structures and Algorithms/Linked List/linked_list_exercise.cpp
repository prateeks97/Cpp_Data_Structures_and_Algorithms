#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void nthNode_find(Node *head, int n){
    Node *p_nth = NULL;
    Node *pTemp = head;
    for (int count = 1; count < n; count++){
        if (pTemp){
            pTemp = pTemp->next;
        }
    }
    while (pTemp){
        if (p_nth == NULL){
            p_nth = head;
        }
        else{
            p_nth = p_nth->next;
        }
        pTemp = pTemp->next;
    }
    if (p_nth){
        return p_nth;
    }
    return NULL;
}

int main(){
    Node * head = NULL;
    return 0;
}
