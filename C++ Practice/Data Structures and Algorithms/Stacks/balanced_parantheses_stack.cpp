#include <iostream>
#include <stack>
#include <cstring>
#define MAX_SIZE 101
using namespace std;

void balance_check(char *c){
    stack<char> S;
    for (int i=0;i<strlen(c);i++){
        if (c[i] == '(' || c[i] == '{' || c[i] == '['){
                S.push(c[i]);
            }
        if (!S.empty()){
        if (c[i] == ')'){
            if (S.top() == '('){
                    S.pop();
                }
            else{
                cout << "False";
                return;
            }
        }
        else if (c[i] == '}'){
            if (S.top() == '{'){
                    S.pop();
                }
            else{
                cout << "False";
                return;
            }
        }
        else if (c[i] == ']'){
            if (S.top() == '['){
                    S.pop();
                }
            else{
                cout << "False";
                return;
            }
        }
        }
        else{
            cout << "Unbalanced Expression\n";
            return;
        }
    }
    if (S.empty()){
        cout << "Balanced Expression\n";
    }
}

int main(){
    char c[MAX_SIZE];
    cout<< "Enter expression: ";
    cin >> c;
    //cout<< strlen(c);
    balance_check(c);
    //return 0;
}
