#include<iostream>
using namespace std;

int main(){

    int num;
    cin>>num;
    int sum1=0, sum2=0;
    while(num%10!=0){
        if (num%2==0){
                sum1=sum1+(num%10);
        }
        else if (num%2==1){
            sum2=sum2+(num%10);
        }
        num=num/10;
    }
    cout<<sum1<<" "<<sum2;
    return 0;
}
