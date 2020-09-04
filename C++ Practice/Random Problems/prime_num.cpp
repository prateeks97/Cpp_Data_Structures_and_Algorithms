#include <iostream>
using namespace std;

bool isPrime(int n){
    if (n <= 1){
        return false;
    }
    for (int i = 2; i < n; i++){
        if (n%i == 0)
            return false;
    }
    return true;
}

int main() {
    int N;
    cout << "Enter a number- ";
    cin >> N;
    isPrime(N) ? cout << " true\n" : cout << " false\n";;

    return 0;
}

