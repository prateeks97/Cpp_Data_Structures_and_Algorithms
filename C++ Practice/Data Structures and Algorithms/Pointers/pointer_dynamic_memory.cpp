#include <iostream>
using namespace std;
int compare(int a, int b){
    return a > b ? -1:1;
}
void BubbleSort(int *arr, int n,int (*compare)(int,int)){
    int temp;
    for (int i = 0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (compare(arr[j],arr[j+1]) > 0){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int A[] = {5,6,9,2,4,7};
    BubbleSort(A,6,compare);
    for(int i=0;i<6;i++){cout << A[i] << " ";}
    return 0;
}
