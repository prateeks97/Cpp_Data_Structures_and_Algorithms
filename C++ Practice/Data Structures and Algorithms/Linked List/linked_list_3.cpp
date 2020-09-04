#include <iostream>

using namespace std;

class Node{
    int data;
    Node* next;
public:
    void Insert_begin(Node** PointerToHead , const int x)
    {
    Node* temp = new Node();
    temp-> data = x;
    temp-> next = *PointerToHead;
    *PointerToHead = temp;
    }

    void Print(Node* head)
    {
    cout << "List is: ";
    while(head != NULL){
        cout << head-> data<< " ";
        head = head->next;
    }
    cout << endl;
    }
};

int main(){
    Node linked_list;
    Node* head = NULL;
    cout << "How many numbers? ";
    int n,x;
    cin >> n;
    cout << '\n';
    for (int i=0; i<n;i++){
        cout << "Enter a number: "<<endl;
        cin >> x;
        linked_list.Insert_begin(&head, x);
        linked_list.Print(head);
    }
    return 0;
}
