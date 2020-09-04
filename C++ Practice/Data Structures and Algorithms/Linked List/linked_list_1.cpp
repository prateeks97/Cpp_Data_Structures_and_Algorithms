#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};
Node* A;        //Created pointer for head of the node
A = Null;      //empty list

Node* temp = new Node();    //create new Node() and set the addresse to A to signify that this is the starting point of the linked list
temp -> data = 2;
temp -> link = Null;
A = temp;

temp = new Node();  // create another element in the list
temp -> data = 4;
temp -> link = Null;

Node* temp1 = A;        // Done to traverse through the list to the end point to establish the link of the second last node
while(temp1->link != Null){
    temp1 = temp1->link;
}
temp1->link = temp;     // Setting link to the second last node
