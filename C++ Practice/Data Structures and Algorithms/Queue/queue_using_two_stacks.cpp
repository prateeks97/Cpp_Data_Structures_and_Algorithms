#include <bits/stdc++.h>
using namespace std;

void reverseStacks(stack<int> &from, stack<int> &to){
    while (!from.empty()){
        to.push(from.top());
        from.pop();
    }
}

struct myQueue{
    stack<int> S1;
    stack<int> S2;

    void EnQueue(int data){
        S1.push(data);
    }
    int DeQueue(){
        if (S1.empty()){
            cout << "Queue is Empty.Cannot DeQueue.\n";
            return 0;
        }
        reverseStacks(S1, S2);
        int data = S2.top();
        S2.pop();
        reverseStacks(S2, S1);
        return data;
    }
    void print(){
        if (S1.empty()){
            cout << "Queue is Empty.\n";
            return;
        }
        stack<int> safe = S1;
        reverseStacks(S1, S2);
        while (!S2.empty()){
            cout << S2.top() << " ";
            S2.pop();
        }
        cout << endl;
        S1 = safe;
    }
};

int main(){
    myQueue Q;
    Q.EnQueue(10);
    Q.EnQueue(9);
    Q.EnQueue(18);
    Q.print();
    Q.EnQueue(20);
    Q.print();
    Q.DeQueue();
    Q.print();
    return 0;
}
