#include <iostream>
using namespace std;
int main() {
    short number;
    cout << "Enter a number: ";
    cin >> number;
    if (number >= 0 && number < 20){
    cout << "The factorial of " << number << " is ";
    int accumulator = 1;
    for (; number > 0; accumulator *= number--);
    cout << accumulator << ".\n";
    }
    else if (number < 0)
        cout << "Enter a positive Number.\n";
    else if (number >= 20)
        cout << "Too expensive to compute.\n";
    return 0;
}
