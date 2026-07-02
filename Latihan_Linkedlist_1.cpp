#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};


Node* buatNode(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}


void buatList(Node **head, Node **tail) {
    Node *n1 = buatNode(10);
    Node *n2 = buatNode(20);
    Node *n3 = buatNode(30);

    n1->next = n2;

    n2->prev = n1;
    n2->next = n3;

    n3->prev = n2;

    *head = n1;
    *tail = n3;
}

void tampilDepan(Node *head) {
    cout << "Data dari Head ke Tail" << endl;
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}


void tampilBelakang(Node *tail) {
    cout << "Data dari Tail ke Head" << endl;
    while (tail != NULL) {
        cout << tail->data << endl;
        tail = tail->prev;
    }
    cout << endl;
}

void tampilSemua(Node *head) {
    int nomor = 1, total = 0;

    while (head != NULL) {
        cout << "Node ke-" << nomor << " : " << head->data << endl;
        head = head->next;
        nomor++;
        total++;
    }

    cout << "Total Node = " << total << endl;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    buatList(&head, &tail);

    tampilDepan(head);
    tampilBelakang(tail);
    tampilSemua(head);

    return 0;
}