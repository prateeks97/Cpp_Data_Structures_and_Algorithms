#include <iostream>
using namespace std;

int rotated_array(int A[], int n)
{
    int low = 0, high = n-1;
    while (low <= high){
        int mid  = (low+high)/2;
        if (A[low] <= A[high])
        {
            return low;
        }
        else if (A[mid] <= A[(mid +1)%n] && A[mid] <= A[(mid + n - 1)%n])
        {
            return mid;
        }
        else if (A[mid] <= A[high])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
}

int CircularArraySearch(int A[], int n, int x)
{
    int low = 0, high = n-1;
    while (low<= high)
    {
        int mid = (low+high)/2;
        if (A[mid] == x)
        {
            return mid;
        }
        else if (A[mid] <= A[high])
        {
            if (x >= A[mid] && x <= A[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        else if (A[mid] >= A[low])
        {
            if (x >= A[low] && x<= A[mid])
            {
                high = mid-1;
            }
            else
            {
                low = mid +1;
            }
        }
    }
    return -1;
}

int main()
{
    int A[] = {9,10,11,12,6,7,8};
    int n = sizeof(A)/sizeof(A[0]);
    //int result = rotated_array(A,n);
    int result = CircularArraySearch(A,n,9);
    if (result == -1){
        cout << "Element not found.\n";
    }
    else{
        cout << "Found at: " << result+1;
    }
    //cout << result;
    return 0;
}
