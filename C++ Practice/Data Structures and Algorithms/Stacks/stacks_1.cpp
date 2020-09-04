#include <iostream>
#define MAX_SIZE 101
using namespace std;

int A[MAX_SIZE];
int top = -1;
void Push(int x){
    if (top == MAX_SIZE -1){
        cout << "Error: Stack overflow\n";
        return;
    }
    top++;
    A[top] = x;
}
void Pop(){
    if (top == -1){
        cout << "Stack already empty\n.";
        return;
    }
    top--;
}
int Top(){
    return A[top];
}
void Print(){
    for (int i=0; i<=top; i++){
        cout << A[i] << " ";
    }
    cout << '\n';
}

int main(){
    Push(2);
    Print();
    Push(4);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    Push(25);
    Print();
}
