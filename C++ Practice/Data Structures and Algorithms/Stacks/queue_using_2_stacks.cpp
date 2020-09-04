#include <bits/stdc++.h>
using namespace std;

void fill_stack(stack<int> &Q, stack<int> &aux){
    while (!Q.empty()){
        aux.push(Q.top());
        Q.pop();
    }
}

void Print(stack<int> S){
    if (S.empty()){
        cout << "Stack is empty.\n";
        return;
    }
    while (!S.empty()){
        cout << S.top() << endl;
        S.pop();
    }
    cout << endl;
}

struct myQueue{
    stack<int> Q;
    stack<int> aux;
    int count = 0;

    void enqueue(int data){
        fill_stack(Q, aux);
        Q.push(data);
        fill_stack(aux, Q);
    }

    void dequeue(){
        if (Q.empty()){
            cout << "Queue is Empty.\n";
            return;
        }
        int x = Q.top();
        Q.pop();
        cout << x << endl;
    }
};

int main(){
    myQueue Q;
    Q.enqueue(5);
    Q.enqueue(7);
    Q.enqueue(9);
    Q.enqueue(2);
    Q.dequeue();
    Q.dequeue();
    Q.enqueue(10);
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    return 0;
}
