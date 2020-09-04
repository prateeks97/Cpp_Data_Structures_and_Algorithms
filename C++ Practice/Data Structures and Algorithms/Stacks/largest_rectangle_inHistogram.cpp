#include <bits/stdc++.h>
using namespace std;

void largestRectangle(vector<int> heights){
    stack<int> S;
    int max_area = 0;
    int area = 0 , idx, i;
    for (i = 0; i < heights.size(); i++){
        if (S.empty() || heights[S.top()] < heights[i]){
            S.push(i);
        }
        else{
            while(!S.empty() && heights[S.top()] > heights[i]){
                idx = S.top();
                S.pop();
                area = heights[idx] * (S.empty() ? i : i - S.top() - 1);
                if (max_area < area){
                    max_area = area;
                }
            }
            S.push(i);
        }
    }
    while(!S.empty()){
        idx = S.top();
        S.pop();
        area = heights[idx] * (S.empty() ? i : i - S.top() - 1);
        if (max_area < area){
            max_area = area;
        }
    }
    cout << "Maximum area of rectangle is: " << max_area << endl;
}

int main(){
    vector<int> heights = {3,2,5,6,1,4,4};
    largestRectangle(heights);
    return 0;
}
