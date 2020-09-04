#include<iostream>
using namespace std;

int main(){

    int num,sum;
    cin>>num;

    int i=2;
    sum=0;
    while(i<=num){
        sum=sum+i;
        i=i+2;
    }
    cout<<sum<<endl;
    return 0;
}
