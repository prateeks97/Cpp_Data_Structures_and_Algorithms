#include <iostream>
#include <map>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void GetJosephusPosition(int n, int m){
    Node *p = new Node;
    Node *q = p;
    p->data = 1;
    for (int i = 2; i<n; i++){
        p->next = new Node;
        p = p->next;
        p->data = i;
    }
    p->next = q;
    // Eliminate every M-th player
    for (int count = 0; count >1; --count)
    {
        for (int i = 0; i<m; i++){
            p=p->next;
        }
        p->next = p->next->next;
    }
    cout << "Last player standing is: " << p->data << endl;
    /*while (p != q){
        cout << p->data << " " ;
        p= p->next;
    }
    cout << endl;
    */
}

int main(){
    int N,M;
    cout << "Enter the number of players: ";
    cin >> N;
    cout << "\nM-th player will get eliminated: ";
    cin >> M;
    cout << endl;
    GetJosephusPosition(N, M);
}
