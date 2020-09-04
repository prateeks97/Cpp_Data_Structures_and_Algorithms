#include<iostream>
using namespace std;

void Print(int A[]){
    for (int i=0;i<6;i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Merge(int L[],int R[],int A[], int nL, int nR)
{
    //int nL = ArraySize(L);
    //cout << nL;
   // int nR = ArraySize(R);
    int i=0, j=0, k=0;
    cout << "\nA[k]: ";
    while (i<nL && i< nR)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            cout << A[k] << " ";
            i++;
        }
        else
        {
            A[k] = R[i];
            cout << A[k] << " ";
            j++;
        }
        k++;
        cout << "\n ******** End of while loop\n";
    }
    while(i<nL)
    {
        A[k] = L[i];
        cout << "Last element: " << A[k] << endl;
        i++;
    }
    while(j<nR)
    {
        A[k] = R[i];
        cout << "Last element: " << A[k] << endl;
        j++;
    }
    k++;
}

void MergeSort(int A[], int n)
{
    //int n = ArraySize(A);
    cout << "Function ke start wala: ";
    Print(A);
    if (n<2)
    {
        return;
    }
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    cout << "Left array: ";
    for (int i=0; i< mid; i++)
    {
        left[i] = A[i];
        cout << left[i];
    }
    cout << "\n Right Array: ";
    for (int i = mid; i<n; i++)
    {
        right[i-mid] = A[i];
        cout << right[i-mid];
    }
    cout << endl;
    int nL = sizeof(left)/sizeof(left[0]);
    int nR = sizeof(right)/sizeof(right[0]);
    MergeSort(left, nL);
    MergeSort(right, nR);
    Merge(left,right,A, nL, nR);
    cout << "Function ke end wala: ";
    Print(A);
}



int main(){
    int A[] = {2,7,4,1,5,3};
    int arr_size = sizeof(A)/sizeof(A[0]);
    MergeSort(A,arr_size);

   // cout << ArraySize(A);
    return 0;
}
