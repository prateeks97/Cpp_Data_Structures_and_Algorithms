#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

long long max_pairwise(vector<double> arr){
    double max_1 = 0;
    double max_2 = 0;
    for (int i=0; i<arr.size(); i++){
        if (arr[i] >= max_1){
            max_1 = arr[i];
        }
    }
    vector<double>:: iterator it;
    it = find(arr.begin(), arr.end(), max_1);
    arr.erase(it);
     for (int i=0; i<arr.size(); i++){
        if (arr[i] >= max_2){
            max_2 = arr[i];
        }
    }
    return max_1*max_2;
}

int main(){
    int N;
    cin >> N;
    double num;
    vector<double> v;
    for (int i=0;i<N;i++){
        cin >> num;
        v.push_back(num);
    }
    long long result = max_pairwise(v);
    cout << result << endl;
}
