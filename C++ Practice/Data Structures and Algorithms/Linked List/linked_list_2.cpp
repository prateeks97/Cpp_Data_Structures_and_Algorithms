#include <iostream>
#include <cstddef>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;
void Insert_begin(const int x){
    Node* temp = new Node();
    temp-> data = x;
    temp-> next = head;
    head = temp;
}

void Print()
{
    Node* temp = head;
    cout << "List is: ";
    while(temp != NULL){
        cout << temp-> data<< " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    head = NULL;
    cout << "How many numbers? ";
    int n,x;
    cin >> n;
    cout << '\n';
    for (int i=0; i<n;i++){
        cout << "Enter a number: "<<endl;
        cin >> x;
        Insert_begin(x);
        Print();
    }
    return 0;
}
