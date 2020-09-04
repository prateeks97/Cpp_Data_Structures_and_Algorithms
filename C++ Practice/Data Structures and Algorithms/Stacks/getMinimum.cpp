#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct MyStack{
    stack<int> s;
    stack<int> minStack;
    //int minElement;

    void getMin(){
        if (s.empty() || minStack.empty()){
            cout << "Stack is empty\n";
            return;
        }
        else{
            cout << "Min value is: " << minStack.top() << endl;
        }
    }
    void peek(){
        if (s.empty()){
            cout << "Stack is empty\n";
            return;
        }
        else{
            cout << s.top() << endl;
        }
    }
    void pop(){
        if (s.empty()){
            cout << "Stack is Empty\n";
        }
        else{
            s.pop();
            minStack.pop();
        }
    }
    void push(int data){
        s.push(data);
        if (minStack.empty()){
            minStack.push(data);
        }
        else{
            if (data <= minStack.top()){
                minStack.push(data);
            }
            else
                minStack.push(minStack.top());
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
   // s.peek();
    return 0;
}
