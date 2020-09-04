#include <iostream>
using namespace std;
void double_arr(int* A,int s){
    for (int i=0; i<s; i++){
        A[i] *= 2;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    double_arr(arr,size);
    for (int j = 0; j<size; j++){
    cout << arr[j] << " ";
    }
    return 0;
}
