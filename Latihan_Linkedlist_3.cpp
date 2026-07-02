#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void buatList(Node **head, Node **tail) {
    Node *pertama = new Node;
    Node *kedua = new Node;
    Node *ketiga = new Node;

    pertama->data = 10;
    pertama->prev = NULL;
    pertama->next = kedua;

    kedua->data = 20;
    kedua->prev = pertama;
    kedua->next = ketiga;

    ketiga->data = 30;
    ketiga->prev = kedua;
    ketiga->next = NULL;

    *head = pertama;
    *tail = ketiga;
}

void tampilDariHead(Node *head) {
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}

void tampilDariTail(Node *tail) {
    while (tail != NULL) {
        cout << tail->data << endl;
        tail = tail->prev;
    }
    cout << endl;
}

void hitungTotal(Node *head) {
    int jumlah = 0;
    int no = 1;

    while (head != NULL) {
        cout << "Data ke-" << no << " : " << head->data << endl;
        jumlah += head->data;
        head = head->next;
        no++;
    }

    cout << "Total nilai = " << jumlah << endl;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    buatList(&head, &tail);

    cout << "Data dari Head:" << endl;
    tampilDariHead(head);

    cout << "Data dari Tail:" << endl;
    tampilDariTail(tail);

    hitungTotal(head);

    return 0;
}