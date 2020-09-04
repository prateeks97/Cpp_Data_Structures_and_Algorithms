#include<iostream>
using namespace std;

int main(){
    double allow, hra, da, pf, totalSalary, basic;
    char grade;

    cin>>basic;
    cin>>grade;

    switch(grade){
        case 'A' : allow=1700;
            break;
        case 'B' : allow=1500;
            break;
        default : allow=1300;
    }
    hra=0.20*basic;
    da=0.50*basic;
    pf=0.11*basic;

    totalSalary= basic+hra+da+allow-pf;

    return 0;
}
