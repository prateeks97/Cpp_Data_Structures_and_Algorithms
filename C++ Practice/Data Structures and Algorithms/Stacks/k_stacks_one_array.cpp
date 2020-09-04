#include <bits/stdc++.h>

using namespace std;

class kStacks{
    int *arr;   // Array of size n to store actual values
    int *top;   // Array of size k to store indexes of top elements of the stack
    int *next;  // Array of size n to store the next entry in all stacks and free lists

    int n, k;
    int free;   // To store the beginning index of free list
public:
    kStacks(int k, int n);  // Constructor to create k stacks in array of size n.

    bool isFull()   //Check if there is a space available the array.
    {
        return (free == -1);
    }

    void push (int item, int sn);   // To push an item in stack number 'sn' where sn is from 0 to k-1.

    int pop(int sn);

    bool isEmpty(int sn)    // To check whether stack 'sn' is empty or not
    {
        return (top[sn] == -1);
    }
};

kStacks::kStacks(int k1, int n1)
{
    //Initialize arrays and allocate memory for all arrays
    k = k1;
    n = n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];
    //Initialize all stacks as empty stacks
    for (int i = 0; i < k; i++){
        top[i] = -1;
    }
    //Initialize all space as free
    free = 0;
    for (int i = 0; i < n-1; i++){
        next[i] = i+1;
    }
    next[n-1] = -1; // -1 inidicate the end of the free list
}

void kStacks::push(int item, int sn)
{
    if (isFull()){
        cout << "Stack overflow\n.";
        return;
    }
    int i = free; // store the index of the first free slot
    free = next[i]; // Update the free slot to index of the next slot in free list

    next[i] = top[sn];
    top[sn] = i;

    arr[i] = item;
}

int kStacks::pop(int sn){
    if (isEmpty(sn)){
        cout << "Stack underslow.\n";
        return INT_MAX;
    }
    int i = top[sn];
    top[sn] = next[i];

    next[i] = free;
    free = i;
    return arr[i];
}

int main()
{
    return 0;
}
