#include <iostream>
#include <climits>
using namespace std;
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
class MinHeap{
    int *harr;
    int capacity;
    int heap_size;
public:
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap_size && harr[l] < harr[i])
        {
            smallest = l;
        }
        if(r < heap_size && harr[r] < harr[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(&harr[i] , &harr[smallest]);
            MinHeapify(smallest);
        }

    }

    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {
        return (2*i+2);
    }
    int extractMin()
    {
        if (heap_size <= 0)
        {
            return INT_MAX;
        }
        if (heap_size == 1){
            heap_size--;
            return harr[0];
        }
        // Store min value and remove it from the heap.
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MinHeapify(0);

        return root;
    }
    void decreaseKey(int i, int new_value)
    {
        harr[i] = new_value;
        while(i != 0 && harr[parent(i)] > harr[i]){
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }
    int getMin()
    {
        return harr[0];
    }
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void insertKey(int k)
    {
        if (heap_size == capacity)
        {
            cout << "Heap already full.\n";
            return;
        }
        //First insert the new key at the end.
        heap_size++;
        int i = heap_size-1;
        harr[i] = k;
        //Fix minHeap property.
        while(i != 0 && harr[parent(i)] > harr[i]){
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }
};

int main()
{

    return 0;
}
