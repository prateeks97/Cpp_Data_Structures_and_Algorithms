#include<iostream>
using namespace std;

void SelectionSort(int A[], int n)
{
    for (int i=0; i<n-1;i++)
    {
        int iMin = i;
        for (int j=i+1; j<n; j++)
        {
            if (A[j] < A[iMin])
            {
                iMin = j;
            }
        }
        int temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;
    }
}
void BubbleSort(int A[], int n)
{
    for (int j=0; j<n;j++)
    {
        int flag = 0;
        for (int i = 0; i<n-1;i++)
        {
            if (A[i] > A[i+1])
            {
                int temp = A[i+1];
                A[i+1] = A[i];
                A[i] = temp;
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

void InsertionSort(int A[], int n)
{
    for (int i = 1; i< n;i++)
    {
        int value = A[i];
        int hole = i;
        while(hole >0 && A[hole-1] > value)
        {
            A[hole] = A[hole-1];
            hole = hole-1;
        }
        A[hole] = value;
    }
}
int main(){
    int A[] = {2,7,4,1,5,3};
    //SelectionSort(A,6);
    //BubbleSort(A,6);
    InsertionSort(A,6);
    for (int i=0;i<6;i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
