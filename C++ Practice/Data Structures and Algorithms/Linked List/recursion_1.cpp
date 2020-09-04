#include <iostream>
using namespace std;

void Print(int n){
    if (n==0){
        return;
    }
    cout << n << " ";
    Print(n-1);
}

int Factorial(int n)
{
    if (n == 0){
        return 1;
    }
    else{
        return n*Factorial(n-1);
    }
}
int main(){
   // Print (4);
    int num;
    cin >> num;
    cout << Factorial(num);
    return 0;
}
