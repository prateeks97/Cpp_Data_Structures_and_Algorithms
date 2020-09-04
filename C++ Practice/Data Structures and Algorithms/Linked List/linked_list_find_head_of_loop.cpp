#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *FindBeginLoop(Node *head)
{
    Node* slowptr = head;
    Node *fastptr = head;
    int flag = 0;
    while (slowptr && fastptr && fastptr->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (slowptr == fastptr){
            flag = 1;
            break;
        }
    }
    slowptr = head;
    if (flag){
        while (slowptr != fastptr){
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }
        return slowptr;
    }
    return NULL;
}

int FindLengthLoop(Node *head)
{
    Node *slowptr = head;
    Node *fastptr = head;
    int flag = 0;
    int count = 0;
    while (slowptr && fastptr && fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (slowptr == fastptr){
            flag = 1;
            break;
        }
    }
    if (flag){
        fastptr = fastptr->next;
        while(slowptr != fastptr)
        {
            fastptr = fastptr->next;
            count++;
        }
        return count;
    }
    return 0;
}

Node *createNewNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node *InsertInSortedList(Node *head, int data)
{
    Node *current = head;
    Node *temp = head;
    Node *newNode = createNewNode(data);
    if (head == NULL){
        return newNode;
    }
    if (data < head->data){
        newNode->next = head;
        return newNode;
    }
    while (current != NULL && data > current->data){
        temp = current;
        current = current->next;
    }
    newNode->next = current;
    temp->next = newNode;
    return head;
}
void Print(Node *head){
    while (head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *reverseList(Node *head){
    Node *prev = NULL;
    Node *current = head;
    Node* next;
    while (current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* head;

void reverseListRecurvise(Node *p)
{
    if (p->next == NULL){
        head = p;
        return;
    }
    reverseListRecurvise(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}
/*
Node *FindIntersectingPoints(Node *list1, Node *list2)
{
    int L1 = 0, L2 = 0, diff = 0;
    Node *head1 = list1;
    Node *head2 = list2;
    while (head1 != NULL){
        L1++;
        head1 = head1->next;
    }
    while (head2 != NULL){
        L2++;
        head2 = head2->next;
    }
    if (L1<L2)
    {
        head1 = list2;
        head2 = list1;
        diff = L2-L1;
    }
    else{
        head1 = list1;
        head2 = list2;
        diff = L1-L2;
    }
    for (int i =0; i<diff; i++){
        head1 = head->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
        {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}
*/
void Print_recursive(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Print_recursive(head->next);
    cout << head->data << " ";
}

Node *MergeSortedList(Node *a, Node *b)
{
    Node *result = NULL;
    if (a == NULL){
        return b;
    }
    if (b == NULL){
        return a;
    }
    if (a->data < b->data){
        result = a;
        result->next = MergeSortedList(a->next, b);
    }
    else{
        result = b;
        result->next = MergeSortedList(a, b->next);
    }
    return result;
}

Node *reversePairList(Node *head)
{
    Node *temp1 = NULL, *temp2 = NULL, *current = head;
    while (current != NULL && current->next != NULL){
        if (temp1 != NULL){
            temp1->next->next = current->next;
        }
        temp1 = current->next;
        current->next = current->next->next;
        temp1->next = current;
        if (temp2 == NULL){
            temp2 = temp1;
        }
        current = current->next;
    }
    return temp2;
}

Node *reversePairList_recursive(Node *head)
{
    Node *temp;
    if (head == NULL || head->next == NULL){
        return head;
    }
    else{
        temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head = temp;
        head->next->next = reversePairList_recursive(head->next->next);
        return head;
    }
}

void spiltCircularList(Node *head, Node **head1, Node **head2)
{
    Node *fastptr = *slowptr = head;
    while (fastptr->next != head && fastptr->next->next != head){
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }
    *head1 = head;
    Node *temp = slowptr->next;
    *head2 = temp;
    slowptr->next = *head1;
    if (fastptr->next == head){
        fastptr->next = temp;
    }
    else if (fastptr->next->next == head){
        fastptr = fastptr->next;
        fastptr->next = temp;
    }
}

int main(){
    head = NULL;
    head = InsertInSortedList(head, 5);
    head = InsertInSortedList(head, 10);
    head = InsertInSortedList(head, 8);
    head = InsertInSortedList(head, 4);
    head = InsertInSortedList(head, 61);
    head = InsertInSortedList(head, 18);
    head = InsertInSortedList(head, 21);
    Print(head);
    //head = reverseList(head);
    //Print(head);
    reverseListRecurvise(head);
    Print(head);
    //cout << "Recursive reverse List: ";
    //Print_recursive(head);
    //cout << endl;
    cout << "Pair Reverse: ";
    //head = reversePairList(head);
    head = reversePairList_recursive(head);
    Print(head);
    cout << endl;
    return 0;
}
