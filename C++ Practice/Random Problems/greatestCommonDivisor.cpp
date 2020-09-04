#include<iostream>
using namespace std;

long long FibList_fast(int n)
{
    long long arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i<=n;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n-1];
}

int gcd(int a, int b)
{
    if (b == 0){
        return a;
    }
    else
    {
        int a_prime = a%b;
        return gcd(b,a_prime);
    }
}
int main()
{
    int result  = gcd(357,234);
    cout << result<<endl;
    long long fib_result = FibList_fast(2);
    cout << fib_result<<endl;
    return 0;
}
