#include <bits/stdc++.h>
using namespace std;

void check_palindrome(string s){
    stack<char> st;
    int i;
    for (i = 0; i < s.size(); i++){
        if (s[i] == 'X'){
            break;
        }
        st.push(s[i]);
    }
    ++i;
   // cout << "s[i]" << s[i] << endl;
    while (i < s.size()){
            //cout << st.top() << "  <- st.top    s[i]-> " << s[i] << endl;
        if (s[i] == st.top()){
            st.pop();
            i++;
        }
        else{
            cout << "Not Palindrome.\n";
            return;
        }
    }
    cout << "Palindrome.\n";
}

int main(){
    string s = "abbXbab";
    check_palindrome(s);
    return 0;
}
