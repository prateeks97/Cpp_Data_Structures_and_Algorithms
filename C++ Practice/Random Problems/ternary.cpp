#include <iostream>
using namespace std;
bool divisible5 (int n){
    if (n % 5 == 0 && n >0)
        return true;
    else
        return false;
}
int main(){
    int num;
    while (true){
        cout << "\n Enter a number- "; cin >> num; cout;
        divisible5(num) ? cout << "Divided by 5: " << num/5: cout << -1;
    }
    return 0;
}
