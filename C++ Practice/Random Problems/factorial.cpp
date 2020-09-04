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
        cout << "BC positive number daal, ye defined nhi h";
    else if (number >= 20)
        cout << "Aukat se bahar h ye";
    return 0;
}
