#include <bits/stdc++.h>
using namespace std;

void reverseElements(queue<int> &Q){
    stack<int> S;
    while(!Q.empty()){
        S.push(Q.front());
        Q.pop();
    }
    while (!S.empty()){
        Q.push(S.top());
        S.pop();
    }
}
void Print(queue<int> Q){
    while (!Q.empty()){
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;
}

int main(){
    queue<int> Q;
    Q.push(10);
    Q.push(21);
    Q.push(91);
    Print(Q);
    reverseElements(Q);
    Print(Q);
}
