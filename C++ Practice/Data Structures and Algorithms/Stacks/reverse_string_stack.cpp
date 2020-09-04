#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

Reverse(char c[], int n){
    stack<char> S;
    for (int i=0; i<n;i++){
        S.push(c[i]);
    }
    for (int j=0;j<n;j++){
        c[j] = S.top();
        S.pop();
    }
}

int main(){
    char c[51];
    cout<< "Enter a String: ";
    cin >> c;
    Reverse(c,strlen(c));
    cout << c;
    return 0;
}
