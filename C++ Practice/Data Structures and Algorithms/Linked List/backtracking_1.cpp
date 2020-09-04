#include <iostream>
using namespace std;
/*
void Binary(int n){
    if (n<1){
        printf("%s", A);
    }
    else{
        A[n-1] = 0;
        Binary(n-1);
        A[n-1] = 1;
        Binary(n-1);
    }
}
*/
struct Node{
    int data;
    Node *next;
};

int length(Node *head){
    Node* current = head;
    int count = 0;
    while(current!= NULL){
        count++;
        current = current->next;
    }
    return count;
}

Node* Insert(Node *head, int value){
    Node* temp = newNode(value);
    head = temp;
    temp->next = head->next;
    return head;
}

Node *newNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void Print(Node *head){
    if (head == NULL){
        cout << "NULL";
    }

    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    head = Insert(head, 7);
    Print(head);
    return 0;
}
