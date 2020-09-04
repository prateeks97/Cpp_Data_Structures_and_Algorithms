#include<iostream>
using namespace std;

void Print(int A[]){
    for (int i=0;i<8;i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int A[], int start, int end)
{
    int pivot = A[end];
    int partitionIndex = start;
    for (int i=start; i<end; i++)
    {
        if (A[i] <= pivot)
        {
            swap(A[i], A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(A[partitionIndex], A[end]);
    return partitionIndex;
}

void QuickSort(int A[], int start, int end)
{
    if (start < end)
    {
        int partitionIndex = Partition(A,start,end);
        QuickSort(A, start, partitionIndex-1);
        QuickSort(A, partitionIndex+1, end);
    }
}

int main(){
    int A[] = {7,6,5,4,3,2,1,0};
   // int arr_size = sizeof(A)/sizeof(A[0]);
    QuickSort(A,0,7);
    Print(A);
   // cout << ArraySize(A);
    return 0;
}
