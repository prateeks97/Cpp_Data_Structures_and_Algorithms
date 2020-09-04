#include<iostream>
using namespace std;

int main(){
    int num,sum1=0,sum2=0;
    cin>>num;
    while(num!=0){
        int rem=num%10;
        if (rem%2==0){
            sum1=sum1+rem;
        }
        else{
            sum2+=rem;
        }
        num=num/10;
    }
    if (sum1%3==0 || sum2%4==0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
