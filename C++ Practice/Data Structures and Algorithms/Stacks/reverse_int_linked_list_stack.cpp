#include <iostream>
#include <stack>
using namespace std;

class Node{
    int data;
    Node* link;
public:
    void Insert(Node** head, int data, int n){
        Node* temp1 = new Node();
        temp1-> data = data;
        temp1-> link = NULL;
        if (n==1){
            temp1->link = *head;
            *head = temp1;
            return;
        }
        Node* temp2 = *head;
        for (int i=0; i<n-2; i++){
            temp2 = temp2->link;
        }
        temp1->link = temp2->link;
        temp2->link = temp1;
    }
    void Print(Node* head){
        cout << "List is: ";
        while(head != NULL){
            cout << head-> data<< " ";
            head = head->link;
        }
        cout << endl;
    }
    void Delete(Node** head, int n){
        Node* temp_d = *head;
        if (n == 1){
            *head = temp_d->link;
            delete temp_d;
            return;
        }
        for (int i=0; i<n-2; i++){
            temp_d = temp_d->link;  // points to (n-1)th node
        }
        Node* temp2_d = temp_d->link;   // points to nth node
        temp_d->link = temp2_d->link;   //points to (n+1)th node
        delete temp2_d;
    }
    void Reverse_itr(Node** head){
        Node* current = *head;
        Node* prev = NULL;
        Node* next;
        while (current != NULL){
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }
        *head = prev;
    }
    void Print_recursion(Node* p){
        if (p == NULL){
            cout << '\n';
            return;
        }
        cout << p->data<< " ";
        Print_recursion(p->link);
    }
    void Print_reverse_recursion(Node* p){
        if (p == NULL){
            cout << '\n';
            return;
        }
        Print_reverse_recursion(p->link);
        cout << p->data<< " ";

    }
    void Reverse_recursion(Node** head, Node* p){
        if (p->link == NULL){
            *head = p;
            return;
        }

        Reverse_recursion(head, p->link);
        Node* temp = p->link;
        temp->link = p;
        p->link = NULL;
    }
    void Revese_stack(Node** head){
        if (*head == NULL)
            return;
        stack<Node*> S;
        Node* temp = *head;
        while (temp!= NULL){
            S.push(temp);
            temp=temp->link;
        }
        temp = S.top();
        *head = temp;
        S.pop();
        while (!S.empty()){
            temp->link = S.top();
            S.pop();
            temp = temp->link;
        }
        temp->link = NULL;
    }
};

Node* head;

int main(){
    head = NULL; //empty list
    Node linked_list;
    int num, pos;
    linked_list.Insert(&head,2,1);
    linked_list.Insert(&head,3,2);
    linked_list.Insert(&head,4,1);
    linked_list.Insert(&head,5,2);
    linked_list.Print(head);
    //linked_list.Delete(&head, 4);
    //linked_list.Print(head);
    //linked_list.Reverse_itr(&head);       // Much more efficient for printing than forward printing recursion
    //linked_list.Print(head);
   // linked_list.Print_recursion(head);
    //linked_list.Print_reverse_recursion(head);  // Its about equally efficient to use normal printing in reverse order and using recursion to do so.
    //linked_list.Reverse_recursion(&head, head);
    linked_list.Revese_stack(&head);
    linked_list.Print(head);
    return 0;
}
