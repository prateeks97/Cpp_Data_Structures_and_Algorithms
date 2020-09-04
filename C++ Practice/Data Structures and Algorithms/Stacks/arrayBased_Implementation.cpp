#include <iostream>
#define MAXSIZE 10
using namespace std;

struct ArrayStack{
    int top;
    int capacity;
    int *array;
};

ArrayStack *CreateStack(){
    ArrayStack *S = new ArrayStack;
    if (!S){
        return NULL;
    }
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array = new int[S->capacity];
    if (!S->array){
        return NULL;
    }
    return S;
}
int IsEmptyStack(ArrayStack *S){
    return S->top == -1;
}

int IsFullStack(ArrayStack *S){
    return S->top == S->capacity-1;
}

void Push(ArrayStack *S, int data){
    if (IsFullStack(S)){
        cout << "Stack Overflow\n";
    }
    else{
        S->array[++S->top] = data;
    }
}
int Pop(ArrayStack *S){
    if (IsEmptyStack(S)){
        cout << "Stack Empty\n";
        return INT_MIN;
    }
    else{
        return S->array[S->top--];
    }
}
void DeleteStack(ArrayStack *S){
    if (S){
        if (S->array){
            delete S->array;
        }
        delete S;
    }
}

int main(){

}
