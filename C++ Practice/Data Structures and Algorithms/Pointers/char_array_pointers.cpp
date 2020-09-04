#include <iostream>
#include <string.h>
using namespace std;
void print(char* c){
    while (*c != '\0'){
        cout << *c;
        c++;
    }
}
int main(){
    char crr[5] = "John";

    print(crr);
    return 0;
}

