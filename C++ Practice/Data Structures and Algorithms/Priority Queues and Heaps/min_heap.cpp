#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class minHeap{
    int size;
    int capacity;
    vector<int> heap;
    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return (2*i +1);
    }
    int right(int i)
    {
        return (2*i+2);
    }
public:
    //Consturctor
    minHeap(int capacityIn)
    {
        size = 0;
        capacity = capacityIn;
        heap.resize(capacity);
    }
    void Insert(int k)
    {
        if (size == capacity)
        {
            cout << "Min heap already full.\n";
            return;
        }

        size++;
        int i = size-1;
        heap[i] = k;

        while (i != 0 && hap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    int extractMin(int i){
        if (size <= 0){
            cout << "Heap is empty.\n";
            return -1;
        }
        else if (size == 1){
            size--;
            return heap[0];
        }
        else
        {
            int root  = heap[0];
            heap[0] = heap[size-1];
            size--;
            Heapify(0);
        }
        return root;
    }
    void Heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest  = i;
        if (l < size && heap[l] < heap[smallest]){
            smallest = l;
        }
        if (r < size && heap[r] < heap[smallest]){
            smallest = r;
        }
        if (smallest != i){
            swap(heap[i], heap[smallest]);
            Heapify(smallest);
        }
    }
};

using namespace std;
int main(){
}
