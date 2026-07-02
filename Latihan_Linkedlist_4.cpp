#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void tambahBelakang(Node **head, int dataBaru) {
    Node *baru = new Node;
    baru->data = dataBaru;
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

void tambahDepan(Node **head, int dataBaru) {
    Node *baru = new Node;
    baru->data = dataBaru;
    baru->next = *head;
    *head = baru;
}

void tampilkan(Node *head) {
    while (head != NULL) {
        cout << head->data;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Node *head = NULL;
    int jumlahData, dataInput, dataAwal;

    cout << "Masukkan jumlah data : ";
    cin >> jumlahData;

    for (int i = 0; i < jumlahData; i++) {
        cout << "Masukkan data ke-" << i + 1 << " : ";
        cin >> dataInput;
        tambahBelakang(&head, dataInput);
    }

    cout << "\nMasukkan data yang akan ditambahkan di awal : ";
    cin >> dataAwal;

    tambahDepan(&head, dataAwal);

    cout << "\nLinked List setelah penambahan data di awal:\n";
    tampilkan(head);

    return 0;
}