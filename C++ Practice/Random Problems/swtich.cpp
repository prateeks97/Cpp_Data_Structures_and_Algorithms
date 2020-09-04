#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number- "; cin >> n;
    switch (n) {
        case 0:
            cout << "You typed zero .\n";
            break;
        case 2:
            cout << "n is an even number .\n";
            break;
        default :
            cout << " Only single - digit positive numbers are allowed .\n";
            break;
    }
    return 0;
}
