#include<iostream>
using namespace std;

int main(){

    char ch;
    cin>>ch;

    switch(ch){
        case 'M' : cout<<"Monday"<<endl;
            break;
        case 'T' : cout<<"Tuesday"<<endl;
            break;
        case 'S' : cout<<"Sunday"<<endl;
            break;
        default : cout<<"Invalid Alphabet";
    }

    return 0;
}
