#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string s){
    map<char, int> m;
    string result;
    int idx = 0;
    for (int i = 0; i<s.size(); i++){
        if (m.find(s[i]) == m.end()){
            m[s[i]] = i;
            cout << s[i];
            result[idx] = s[i];
            idx++;
        }
        else{
            continue;
        }
    }
    return result;
}

string removeAdjacentDuplicates(string &s){
    int idx = -1;
    int i = 0;
    int len = s.size();
    while (i<len)
    {
        if (idx == -1 || s[idx] != s[i]){
            idx++;
            s[idx] = s[i];
            i++;
        }
        else{
            while (i < len && s[idx] == s[i]){
                i++;
            }
            idx--;
        }
    }
    while (idx + 1  < len){
        s[idx+1] = '\0';
        idx++;
    }

    return s;
}

int main(){
    string S = "careermonk";
    string D = "mississippi";
    //cout << removeDuplicates(S) << endl;
    cout << removeAdjacentDuplicates(S) << endl;
    cout << removeAdjacentDuplicates(D) << endl;
}
