#include <iostream>
#include <cmath>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int blockSize;

struct ListNode{
    int value;
    ListNode* next;
};
struct LinkedBlock{
    LinkedBlock *next;
    ListNode *head;
    int nodeCount;
};

LinkedBlock * blockHead;

LinkedBlock* newLinkedBlock(){
    LinkedBlock *block = new LinkedBlock;
    block->next = NULL;
    block->head = NULL;
    block->nodeCount = 0;
    return block;
}

ListNode* newListNode(int value){
    ListNode *node = new ListNode;
    node->next = NULL;
    node->value = value;
    return node;
}
void searchElement(int k, LinkedBlock **fLinkedBlock, ListNode ** fListNode)
{
    // Find the block
    int j = (k + blockSize - 1)/blockSize;  // k-th node is in the j-th block
    LinkedBlock *p = blockHead;
    while (--j){
        p = p->next;
    }

    *fLinkedBlock = p;
    // Find the node
    ListNode *q = p->head;
    k = k%blockSize;
    if (k == 0){
        k = blockSize;
    }
    k = p->nodeCount + 1 -k;
    while (--k){
        q = q->next;
    }
    *fListNode = q;
}

void shift(LinkedBlock *A){
    LinkedBlock *B;
    ListNode *temp;
    while (A->nodeCount > blockSize){
        if (A->next = NULL){
            A->next = newLinkedBlock();
            B = A->next;
            temp = A->head->next;
            A->head->next = A->head->next->next;
            B->head = temp;
            temp->next = temp;
            A->nodeCount--;
            B->nodeCount++;
        }
        else{
            B = A->next;
            temp = A->head->next;
            A->head->next = A->head->next->next;
            temp->next = B->head->next;
            B->head->next = temp;
            B->head = temp;
            A->nodeCount--;
            B->nodeCount++;
        }
        A = B;
    }
}

void addElement(int k, int x){
    ListNode *p,*q;
    LinkedBlock *r;

    if (!blockHead){    // Initial first node and block
        blockHead = newLinkedBlock();
        blockHead->head = newListNode(x);
        blockHead->head->next = blockHead->head;
        blockHead->nodeCount++;
    }
    else{   // Special case for k=0
        if (k==0){
            p = blockHead->head;
            q = p->next;
            p->next = newListNode(x);
            p->next->next = q;
            blockHead->head = p->next;
            blockHead->nodeCount++;
            shift(blockHead);
        }
        else{
            searchElement(k,&r,&p);
            q = p;
            while(q->next!=p){
                q= q->next;
            }
            q->next = newListNode(x);
            q->next->next = p;
            r->nodeCount++;
            shift(r);
        }
    }
}

int searchElement(int k){
    ListNode *p;
    LinkedBlock *q;
    searchElement(k,&q,&p);
    return p->value;
}

int testUnrolledLinkedList()
{
    int tt = clock();
    int m,i,k,x;
    char cmd[10];
    cin >> m;
    blockSize = (int)(sqrt(m-0.001))+1;

    for (i = 0; i<m; i++){
        cin >> cmd;
        if (strcmp(cmd,"add") == 0){
            cin>>k >> x;
            addElement(k,x);
        }
        else if (strcmp(cmd,"search") == 0){
            cin >> k;
            cout << searchElement(k);
        }
        else{
            fprintf(stderr, "Wrong Input\n");
        }
    }
    return 0;
}

int main(){
    int num = testUnrolledLinkedList();
    return num;
}
