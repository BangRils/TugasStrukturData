#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void tambahAkhir(Node **head, int angka) {
    Node *baru = new Node;
    baru->data = angka;
    baru->next = NULL;

    if (*head == NULL) {
        *head = baru;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = baru;
}

void tampilkanData(Node *head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *head = NULL;
    int jumlahData, inputData, dataBaru;

    cout << "Masukkan jumlah data : ";
    cin >> jumlahData;

    for (int i = 0; i < jumlahData; i++) {
        cout << "Masukkan data ke-" << i + 1 << " : ";
        cin >> inputData;
        tambahAkhir(&head, inputData);
    }

    cout << "\nMasukkan data yang akan ditambahkan di akhir : ";
    cin >> dataBaru;

    tambahAkhir(&head, dataBaru);

    cout << "\nLinked List setelah penambahan data di akhir:\n";
    tampilkanData(head);

    return 0;
}