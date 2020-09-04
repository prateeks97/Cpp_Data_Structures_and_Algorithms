#include <bits/stdc++.h>

using namespace std;

void InversePush(stack<int> &S, int data){
    int temp;
    if (S.empty()){
        S.push(data);
        return;
    }
    temp = S.top();
    S.pop();
    InversePush(S,data);
    S.push(temp);

}

void reverseStack(stack<int> &S){
    int data;
    if (S.empty()){
        return;
    }
    data = S.top();
    S.pop();
    reverseStack(S);
    InversePush(S,data);
}
void Print(stack<int> S){
    while (!S.empty()){
        cout << S.top() << endl;
        S.pop();
    }
    cout << endl;
}

int main(){
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.push(6);
    Print(S);
    cout << endl;
    reverseStack(S);
    Print(S);
    return 0;
}
