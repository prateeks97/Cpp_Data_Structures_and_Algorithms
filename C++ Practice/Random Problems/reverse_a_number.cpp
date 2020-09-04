#include<iostream>
using namespace std;

int main(){

    int num;
    cin>>num;

    int r=0;
    while (num>0){
        r=r*10+num%10;
        num=num/10;
    }
    cout<<r;


    return 0;
}
