#include<iostream>
using namespace std;


int main(){

    int p,r,t,SI;
    cout<<"Enter principle amount= ";
    cin>>p;
    cout<<"Enter rate of interest= ";
    cin>>r;
    cout<<"Enter time(in years)= ";
    cin>>t;
    SI=(p*r*t)/100;
    cout<<"The calculated simple interest is = "<<SI;

    return 0;
}
