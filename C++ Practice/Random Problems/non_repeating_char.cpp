#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char non_repeating_char(string str){
    vector<char> v;
    vector<char>::iterator it;
    for (int i=0; i<str.size();i++){
        it = find(v.begin(), v.end(), str[i]);
        if (it!= v.end()){
            v.erase(it);
        }
        else{
            v.push_back(str[i]);
        }
    }
    if (v.size() > 0){
        return v[0];
    }
    else {
        return '_';
    }
}


int main()
{
    char s = non_repeating_char("abcabcabc");
    cout << s;
	return 0;
}
