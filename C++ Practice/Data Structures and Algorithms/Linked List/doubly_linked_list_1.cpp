#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    Node* prev;
public:
    Node* GetNewNode(int x){
        Node* newNode = new Node();
        newNode->prev = NULL;
        newNode-> next = NULL;
        newNode->data = x;
        return newNode;
    }
    void InsertAtHead(Node** head, int x){
        Node* newNode = GetNewNode(x);
        Node* temp = *head;
        if (*head == NULL){
            *head = newNode;
            return;
        }
        else{
            temp->prev = newNode;
            newNode->next = temp;
            *head = newNode;
        }
    }

    void InsertAtTail(Node** head, int x){
        Node* newNode = GetNewNode(x);
        Node* temp = *head;
        if (*head == NULL){
            *head = newNode;
            return;
        }
        else{
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next  = newNode;
            newNode->prev = temp;
        }
    }

    void Print(Node* head){
        cout << "Doubly list: ";
        while (head != NULL){
            cout << head->data<<" ";
            head= head->next;
        }
        cout << '\n';
    }
    void Print_reverse(Node* head){
        if (head == NULL){
            return;
        }
        while (head->next != NULL){
            head = head->next;
        }
        cout << "Reverse: ";
        while (head != NULL){
            cout << head->data<< " ";
            head = head->prev;
        }
        cout << '\n';
    }
};

int main(){
    Node* head = NULL;
    Node dl_list;
    dl_list.InsertAtHead(&head, 5);
    dl_list.InsertAtHead(&head, 8);
    dl_list.InsertAtTail(&head, 10);
    dl_list.InsertAtTail(&head, 9);
    dl_list.InsertAtTail(&head, 19);
    dl_list.Print(head);
    dl_list.Print_reverse(head);
    return 0;
}
