#include <iostream>
#include <cmath>
using namespace std;
void Test_1(int n){
    if (n>0){
        Test_1(n-1);
        cout << n << " ";
    }
    cout << endl;
}
void Test_2(int n){
    if (n>0){
        for (int i=0; i<n ;i++){
            cout << n << " ";
        }
        Test_2(n-1);
    }
    cout << endl;
}

void Test_3(int n){
    if (n>1){
        cout << n << " ";
        Test_3(n/2);
    }
    cout << endl;
}
void Test_4(int n){
    if (n>2){
        cout << n << " ";
        Test_4(sqrt(n));
    }
    cout << endl;
}
int main(){
    int num;
    cin>>num;
    //Test_1(num);
    //Test_2(num);
    //Test_3(num);
    Test_4(num);
    return 0;
}
