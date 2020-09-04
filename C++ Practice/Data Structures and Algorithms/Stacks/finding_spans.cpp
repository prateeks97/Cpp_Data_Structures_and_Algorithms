#include <bits/stdc++.h>

using namespace std;

void find_span(vector<int> data){
    stack<int> S;
    int max_span = 0;
    for (int i = 0; i<data.size(); ++i){
        int span = 0;
        if (S.empty() || data[i] > S.top()){
            S.push(data[i]);
        }
        else if (data[i] < S.top()){
            while(!S.empty()){
                span++;
                S.pop();
            }
            S.push(data[i]);
        }
        if (max_span < span){
            max_span = span;
        }
    }
    int span = 0;
    while(!S.empty()){
        span++;
        S.pop();
    }
    if (max_span < span){
        max_span = span;
    }
    cout << "Maximum span is: " << max_span << endl;
}

int main(){
    vector<int> V = {1,9,4,5,8,9};
    find_span(V);
    return 0;
}
