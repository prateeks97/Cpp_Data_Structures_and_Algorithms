#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
struct Stack{
    Node *top;
};

struct Stack *createStack(){
    return NULL;
};

void Push(Stack **top, int data){
    Stack *temp;
    temp = new Stack;
    if (!temp){
        return NULL;
    }
    temp->data = data;
    temp->next = *top;
    *top = temp;
}
int IsEmptyStack(Stack *top){
    return top == NULL;
}

int Pop(Stack **top){
    int data;
    Stack *temp;
    if (IsEmptyStack(top)){
        return INT_MIN;
    }
    temp = *top;
    *top = *top->next;
    data = temp->data;
    delete temp;
    return data;
}

int Top(Stack *top){
    if (IsEmptyStack(top)){
        return INT_MIN;
    }
    return top->next->data;
}

void deleteStack(Stack **top){
    Stack *temp, *p;
    p = *top;
    while (p->next){
        temp = p->next;
        p->next = temp->next;
        delete temp;
    }
    delete p;
}

int main(){
    Node *head = NULL;
}
