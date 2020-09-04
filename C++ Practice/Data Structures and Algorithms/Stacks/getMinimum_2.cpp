#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct MyStack{
    stack<int> S;
    stack<int> minStack;

    void getMin(){
        if (S.empty()){
            cout << "Stack is Empty.\n";
        }
        else{
            cout << minStack.top() << endl;
        }
    }

    void push(int data){
        S.push(data);
        if (minStack.empty()){
            minStack.push(data);
        }
        else{
            if (minStack.top() >= data){
                minStack.push(data);
            }
        }
    }

    void pop(){
        if (S.empty()){
            cout << "Stack is Empty.\n";
        }
        else {
            int value = S.top();
            S.pop();
            if (value == minStack.top()){
                minStack.pop();
            }
        }
    }
};


int main(){
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    return 0;
}
