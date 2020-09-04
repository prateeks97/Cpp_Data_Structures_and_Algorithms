#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
class minHeap{
    int size;
    int capacity;
    vector<int> heap;
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
public:
    minHeap(int cap){
        size = 0;
        capacity = cap;
        heap.resize(capacity);
    }
    void Insert(int k)
    {
        if (size == capacity)
        {
            cout << "Heap Full!\n";
            return;
        }
        size++;
        int i = size - 1;
        heap[i] = k;

        while (i != 0 && heap[parent(i)] > heap[i]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && heap[l] < heap[smallest]){
            smallest = l;
        }
        if (r < size && heap[r] < heap[smallest]){
            smallest = r;
        }

        while (smallest != i){
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    int extractMin(){
        if (size == 0){
            cout << "Cant extract\n";
            return -1;
        }
        if (size == 1){
            size--;
            return heap[0];
        }
        int root = heap[0];
        heap[0] = heap[size-1];
        size--;
        heapify(0);
        return root;
    }
    void Print(){
        cout << heap[0];
    }
    int find(int k){
        for (int i = 0; i<size; i++){
            if (heap[i] == k){
                return i;
            }
        }
        return -1;
    }
    void deleteHeap(int k){
        int i = find(k);
        heap[i] = heap;
        if (i != 0 && heap[parent(i)] > heap[i]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
        extractMin();
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    minHeap H(100);
    cin >> q;
    for (int i = 0; i<q; i++){
        int choice, num;
        cin >> choice;
        if (choice == 1){
            cin >> num;
            H.Insert(num);
        }
        else if (choice == 2){
            cin >> num;
            H.deleteHeap(num);
        }
        else if (choice == 3){
            H.Print();
        }
    }
    return 0;
}
