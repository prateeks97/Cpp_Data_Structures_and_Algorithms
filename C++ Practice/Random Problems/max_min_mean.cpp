#include <iostream>
#include <limits>
 using namespace std;


 int main(){
    int n;
    cout << "Enter number of points to be entered- ";
    cin >> n;
    int sum = 0;
    int num = 0;
    int max_val = 0;
    int min_val = numeric_limits<int>::max();
    for (int i = 0; i < n; i++){
        cout << "Enter number- ";
        cin >> num;
        if (num > max_val)
            max_val = num;
        if (num < min_val)
            min_val = num;
        sum = num + sum;
    }
    double mean = (double)sum/n;
    cout << "Mean- " << mean << "\n Maximum number is: " << max_val << "\n Minimum number is: " << min_val;

    return 0;
 }
