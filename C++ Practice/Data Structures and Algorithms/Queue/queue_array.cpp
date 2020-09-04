#include <iostream>
#include <cmath>
#include <cstring>
#define MAX_SIZE 101
using namespace std;

class Queue{
    int A[MAX_SIZE];
    int front;
    int rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    bool IsEmpty(){
        return (front == -1 && rear == -1);
    }

    void Enqueue(int x){
        if ((rear+1)%MAX_SIZE == front){
            cout << "Queue already full.\n";
            return;
        }
        else if (IsEmpty()){
            front = 0;
            rear = 0;
            A[rear] = x;
        }
        else{
            rear = (rear+1)%MAX_SIZE;
        }
        A[rear] = x;
    }
    void Print(){
        cout << "Queue is: ";
        for (int i = front; i<=rear; i++){
            cout << A[i] << " ";
        }
        cout << endl;
    }
    void Dequeue(){
        if (IsEmpty()){
            cout << "Queue empty.\n";
            return;
        }
        else if (front == rear){
            front = -1;
            rear = -1;
        }
        else
            front = (front+1)%MAX_SIZE;
    }
};

int main(){
    Queue q;
    //cout<< q.IsEmpty();
    q.Enqueue(2);
    //cout<< q.IsEmpty();
    q.Enqueue(5);
    q.Print();
    q.Dequeue();
    q.Print();
    return 0;
}
