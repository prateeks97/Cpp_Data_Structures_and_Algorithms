#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int *p;
    p = &a;
    cout << "Initioal pointer p: %d \n",p << endl;
    *p = 12;
    cout << *(p+1)<< endl;
    return 0;
}
