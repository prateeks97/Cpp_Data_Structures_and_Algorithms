#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char fromeg, char topeg, char, auxeg)
{
    if (n==1){
        cout << "Move disk from fromeg to topeg\n";
        return;
    }
    TowerOfHanoi(n-1, fromeg, auxeg, topeg);
    cout << "\nMove disk n from fromeg to peg topeg";

    TowerOfHanoi(n-1, auxeg, topeg, fromeg);

}

/*
int isArraySorted(int A[], int n){
    if (n == 1){
        return 1;
    }
    return (A[n-1] < A[n-2] ? 0 : isArraySorted(A, n-1));
}
*/

int main(){
  //  int A[] = {1,2,3,5,4};
    //cout << (isArraySorted(A, 5)== 1);
    return 0;
}

