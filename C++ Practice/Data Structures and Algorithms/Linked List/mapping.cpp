#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;
void mapSTL()
{
    map<string, int, greater<string>> M;
    M.insert(make_pair("Prateek", 100));
    M.insert(make_pair("Rohan", 99));
    M["Shubham"] = 98;
    M["Piggy"] = 97;

    for (auto &it: M){
        cout << it.first << " " << it.second << endl;
    }
}
void pwrOfSTL(){
    set<pair<int, int>> S;
    S.insert({2,3});
    S.insert({10,20});
    S.insert({30,400});
    S.insert({401,450});
    int point = 401;
    /*auto it = upper_bound(S.begin(), S.end(), {point,INT_MAX});
    it--;
    pair<int, int> current = *it;
    if (current.first <= point && current.second >= point){
        cout << current<<endl;
    }*/
    for (auto it: S){
        if (it.first <= point && it.second >= point){
            cout << "Found in interval: " << it.first << " " << it.second << endl;
            return;
        }
    }
    cout << "Not Found!\n";
    return;
}

int main(){

    //mapSTL();
    pwrOfSTL();
    return 0;
}
