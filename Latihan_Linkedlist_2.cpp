#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};


Node* createNode(int nilai){
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}


void buatList(Node **head, Node **tail){
    Node *n1 = createNode(10);
    Node *n2 = createNode(20);
    Node *n3 = createNode(30);

    n1->next = n2;

    n2->prev = n1;
    n2->next = n3;

    n3->prev = n2;

    *head = n1;
    *tail = n3;
}


void tampilMaju(Node *head){
    cout << "Isi List (Head ke Tail)" << endl;

    while(head != NULL){
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}

void tampilMundur(Node *tail){
    cout << "Isi List (Tail ke Head)" << endl;

    while(tail != NULL){
        cout << tail->data << endl;
        tail = tail->prev;
    }
    cout << endl;
}


void nilaiMaksimum(Node *head){
    if(head == NULL){
        cout << "List kosong!" << endl;
        return;
    }

    int maksimum = head->data;
    int nomor = 1;
    Node *bantu = head;

    while(bantu != NULL){
        cout << "Node ke-" << nomor << " : " << bantu->data << endl;

        if(bantu->data > maksimum){
            maksimum = bantu->data;
        }

        bantu = bantu->next;
        nomor++;
    }

    cout << "Nilai terbesar = " << maksimum << endl;
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    buatList(&head, &tail);

    tampilMaju(head);
    tampilMundur(tail);

    nilaiMaksimum(head);

    return 0;
}