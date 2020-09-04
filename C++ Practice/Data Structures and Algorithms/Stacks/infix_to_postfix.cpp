#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char x){
    if (x == '^'){
        return 3;
    }
    else if (x == '*' || x == '/'){
        return 2;
    }
    else if (x == '+' || x == '-'){
        return 1;
    }
    else {
        return -1;
    }
}

void infixToPostfix(string s){
    stack<char> St;
    string result;
    for(int i =0; i<s.size(); i++){
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
            result +=s[i];
        }
        else if (s[i] == '('){
            St.push(s[i]);
        }
        else if (s[i] == ')'){
            while(!St.empty() && St.top() != '('){
                char c = St.top();
                St.pop();
                result += c;
            }
            if (St.top() == '('){
                St.pop();
            }
        }
        else{
            while (!St.empty() && prec(s[i]) <= prec(St.top())){
                char c = St.top();
                St.pop();
                result += c;
            }
            St.push(s[i]);
        }
    }
    while (!St.empty()){
        char c = St.top();
        St.pop();
        result += c;
    }
    cout << result << endl;
}

void infixToPostfix2(string s){
    string result;
    stack<char> st;
    for (int i=0; i<s.size(); i++){
            // For operand
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            result += s[i];
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            while (!st.empty() && st.top() != '('){
                char c = st.top();
                st.pop();
                result += c;
            }
            if (st.top() == '('){
                st.pop();
            }
        }
        //For Operator
        else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())){
                char c = st.top();
                st.pop();
                result += c;
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()){
        char c = st.top();
        st.pop();
        result += c;
    }
    cout << result << endl;
}

int main(){
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(s);
    infixToPostfix2(s);
    return 0;
}
