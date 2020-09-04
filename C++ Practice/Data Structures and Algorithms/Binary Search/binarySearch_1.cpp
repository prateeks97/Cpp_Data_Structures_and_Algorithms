#include<iostream>
using namespace std;

int BinarySearch(int A[], int n, int value){
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high){
        //cout << low << " -------- " << high<< endl;
        mid = (high+low)/2;
        if (A[mid] == value){
            return mid;
        }
        else if (A[mid] > value){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int rec_BinarySearch(int A[], int low, int high, int value){
    if (low == high){
        if (A[low] == value){
            return low;
        }
        else{
            return -1;
        }
    }
    else{
        int mid = (low+high)/2;
        if (A[mid] == value){
            return mid;
        }
        else if (A[mid] > value){
            return rec_BinarySearch(A, low, mid-1, value);
        }
        else {
            return rec_BinarySearch(A, mid+1, high, value);
        }
    }
}
int R_BSA(int A[], int n, int value){
    int low = 0;
    int high = n-1;
    return rec_BinarySearch(A, low, high, value);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,10,13,15,17};
    int size = sizeof(arr)/sizeof(arr[0]);
    int value;
    cin >> value;
    //int result = BinarySearch(arr,size,value);
    int result = R_BSA(arr,size,value);
    if (result == -1){
        cout << "Element not found.\n";
    }
    else{
        cout << "Element found at index: " << result+1 << endl;
    }
    return 0;
}
