#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *CreateNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct QueueList{
    Node *front, *rear;
    QueueList(){
        front = rear = NULL;
    }
    void EnQueue(int item){
        Node *temp = CreateNode(item);
        if (rear == NULL){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    int DeQueue(){
        if (front == NULL){
            cout << "Queue is Empty.\n";
            return 0;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL){
            rear = NULL;
        }
        int data = temp->data;
        delete temp;
        return data;
    }
    void printQueue(){
        if (front == NULL){
            cout << "Queue is Empty.\n";
        }
        Node *current = front;
        while (current != NULL){
            cout << current->data << " " ;
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    QueueList myQueue;
    //
    myQueue.EnQueue(14);
    myQueue.EnQueue(22);
    myQueue.EnQueue(13);
    myQueue.EnQueue(18);
    myQueue.EnQueue(83);
    myQueue.printQueue();
    myQueue.DeQueue();
    myQueue.DeQueue();
    myQueue.DeQueue();
    myQueue.printQueue();
    return 0;
}
