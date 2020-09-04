#include <iostream>
using namespace std;

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

int Count(int A[], int n, int x)
{
    int first = 1;
    int first_index = BinarySearch_occurance(A,n,x, first);
    first = 0;
    int last_index = BinarySearch_occurance(A,n,x, first);
    if (first_index == -1)
        return  0;
    else
        return last_index - first_index +1;
}
int main()
{
    int A[] = {2,4,5,7,13,13,13,14,15,23};
    int arr_size = sizeof(A)/sizeof(A[0]);
    cout << "Enter a number: ";
    int x; cin>>x;
    cout << "Number " << x << " occurs " << Count(A,arr_size,x) << " times\n";

    return 0;
}
