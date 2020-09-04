#include <iostream>
using namespace std;

int BinarySearch_itr(int A[], int n, int x)
{
    int low = 0, high = n-1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (x == A[mid])
            return mid;
        else if (x < A[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}

int BinarySearch_occurance(int A[], int n, int x, int first)
{
    int low = 0, high = n-1, result = -1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (x == A[mid]){
            result  = mid;
            if (first == 1)
                high = mid-1;
            else
                low = mid+1;
        }
        else if (x < A[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return result;
}


void Print(int x, int index)
{
    if (index!=-1)
    {
        cout << "Number " << x << " is at index " << index << endl;
    }
    else
    {
        cout << "Number " << x << " not found in the array.\n";
    }
}

int BinarySearch_rec(int A[], int low, int high, int x)
{
    if (low > high){
        return -1;
    }
    int mid = low+(high-low)/2;
    if (x == A[mid])
    {
        return mid;
    }
    else if (x < A[mid])
    {
        return BinarySearch_rec(A, low, mid-1, x);
    }
    else
    {
        return BinarySearch_rec(A, mid+1, high, x);
    }
}
int main()
{
    int A[] = {2,4,5,7,13,13,13,14,15,23};
    int arr_size = sizeof(A)/sizeof(A[0]);
    cout << "Enter a number: ";
    int x; cin>>x;
    //int index = BinarySearch_itr(A,8,x);
    int first  = 0;
    int index = BinarySearch_occurance(A,arr_size,x, first);
    cout << "First occurance is on index: " <<index<< endl;
    //int index = BinarySearch_rec(A,0, 7, x);
    //Print(x,index);
    return 0;
}
