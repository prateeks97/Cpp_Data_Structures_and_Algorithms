#include <bits/stdc++.h>
using namespace std;

struct QueueArray{
    int front, rear, nosElements;
    int capacity;
    int *array;
    QueueArray(int s){
        capacity = s;
        array = new int[s];
        front = rear = -1;
        nosElements = 0;
    }
    int IsEmptyQueue(){
        return nosElements == 0;
    }
    int IsFullQueue(){
        return nosElements == capacity;
    }
    int sizeQueue(){
        return nosElements;
    }
    void Enqueue(int item);
    int Dequeue();
    void DisplayQueue();
};

void QueueArray::Enqueue(int item){
    if (IsFullQueue()){
        cout << "Queue is already full.\n";
        return;
    }
    //cout << "front: " << front << endl;
    //cout << "rear: " << rear << endl;
    rear = (rear+1)% capacity;
    if (front == -1){
        //cout << "front is changing\n";
        front = rear;
    }
    array[rear] = item;
    //cout << "front: " << front << endl;
    //cout << "rear: " << rear << endl;
    nosElements++;
}
int QueueArray::Dequeue(){
    if (IsEmptyQueue()){
        cout << "Queue already Empty.\n";
        return 0;
    }
    int value = array[front];
    if (front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%capacity;
    }
    nosElements--;
    return value;
}

void QueueArray::DisplayQueue(){
    if (IsEmptyQueue()){
        cout << "Queue is Empty\n";
        return;
    }
    if (rear >= front){
        for (int i = front; i <= rear; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else{
        for (int i = front; i < capacity; i++){
            cout << array[i] << " ";
        }
        for (int i = 0; i <= rear; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    QueueArray myQueue(5);
    myQueue.Enqueue(14);
    myQueue.Enqueue(22);
    myQueue.Enqueue(13);
    myQueue.Enqueue(-6);
    myQueue.Enqueue(-29);
    myQueue.DisplayQueue();
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Enqueue(36);
    myQueue.Enqueue(86);
    myQueue.Dequeue();
    myQueue.DisplayQueue();
    return 0;
}
