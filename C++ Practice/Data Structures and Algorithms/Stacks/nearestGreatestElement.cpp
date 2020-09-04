#include <bits/stdc++.h>

using namespace std;

void removeNearestGreatestElement(vector<int> v)
{
    stack<int> S;
    S.push(v[0]);
    int nextnumber, element;
    int i;
    for (i = 1; i<v.size(); i++)
    {
        while (!S.empty() && S.top() < v[i]){
            cout << S.top() << " -> " << v[i] << endl;
            S.pop();
        }
        S.push(v[i]);
    }
    while (!S.empty()){
        cout << S.top() << " -> " << -1 << endl;
        S.pop();
    }
    cout << endl;
}

int main(){
    vector<int> V = {4, 5, 2, 25};
    vector<int> V1 = {13, 7, 6, 12};
    vector<int> V2 = {11, 13, 21, 3};
    removeNearestGreatestElement(V);
    removeNearestGreatestElement(V1);
    removeNearestGreatestElement(V2);
    return 0;
}
