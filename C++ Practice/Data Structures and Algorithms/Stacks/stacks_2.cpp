#include <iostream>
using namespace std;

class Node{
    int data;
    Node* link;
    Node* top;
public:
    Node(){
        top = NULL;
    }
    void Push(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->link = top;
        top = temp;
    }
    void Pop(){
        Node* temp;
        if (top==NULL)
            return;
        temp = top;
        top = top->link;
        delete temp;
    }
    Print(){
        Node* temp = top;
        while (temp!=NULL){
                cout << temp->data << " ";
            temp = temp->link;
        }
        cout << '\n';
    }
};

int main(){
    Node s;
    s.Push(7);
    s.Push(9);
    s.Push(1);
    s.Print();
    s.Pop();
    s.Print();
}
