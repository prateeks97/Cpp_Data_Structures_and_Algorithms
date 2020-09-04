#include <iostream>
#include <vector>
using namespace std;

void leftRotation(vector<int> v, int d){
    int size_vec = v.size();
    vector<int> l_vec;
    int i = d%size_vec;
    //cout << i << "end "<< (size_vec+d)%size_vec << endl;
    int count =0;
    while ( count < size_vec)
    {
        count++;
        cout << v[i] << " ";
        i++;
        i = i%size_vec;
        //cout << v[i] << " " << endl;
    }

}

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> v;
    int num;
    for (int i = 0; i<n; i++){
        cin >> num;
        v.push_back(num);
    }
    leftRotation(v, d%n);
    return 0;
}
