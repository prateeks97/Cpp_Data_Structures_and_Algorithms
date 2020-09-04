#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checked_balanced(string c){
    stack<char> S;
    char temp;
    for (char x : c){
        if (x == '(' || x == '{' || x == '['){
                S.push(x);
            }
        temp = S.top();
        if (x == ')'){
            if (S.empty()){
                return false;
            }
            if (temp != '('){
                return false;
            }
            else if (temp == '('){
                S.pop();
            }
        }
        else if (x == '}'){
            if (S.empty()){
                return false;
            }
            if (temp != '{'){
                return false;
            }
            else if (temp == '{'){
                S.pop();
            }
        }
        else if (x == ']'){
            if (S.empty()){
                return false;
            }
            if (temp != '['){
                return false;
            }
            else if (temp == '['){
                S.pop();
            }
        }
    }
    if (!S.empty()){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    string c;
    cout << "Enter string: ";
    cin >> c;
    cout << endl;
    if (checked_balanced(c)){
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;
}
