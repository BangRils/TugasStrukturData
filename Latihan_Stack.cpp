#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *atas = NULL;

void tambahData(int angka){
    Node *baru = new Node;

    baru->data = angka;
    baru->next = atas;
    atas = baru;

    cout << "Data " << angka << " berhasil ditambahkan." << endl;
}

void hapusData(){
    if(atas == NULL){
        cout << "Stack masih kosong!" << endl;
        return;
    }

    Node *hapus = atas;
    int nilai = hapus->data;

    atas = atas->next;
    delete hapus;

    cout << "Data yang dihapus : " << nilai << endl;
}

void lihatAtas(){
    if(atas == NULL){
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Data teratas : " << atas->data << endl;
}

void tampilStack(){
    if(atas == NULL){
        cout << "Tidak ada data." << endl;
        return;
    }

    Node *bantu = atas;

    cout << "Isi Stack : ";
    while(bantu != NULL){
        cout << bantu->data;
        if(bantu->next != NULL)
            cout << " -> ";
        bantu = bantu->next;
    }

    cout << " -> NULL" << endl;
}

int main(){

    tambahData(10);
    tambahData(20);
    tambahData(30);

    cout << endl;

    tampilStack();

    cout << endl;

    lihatAtas();

    cout << endl;

    hapusData();
    hapusData();

    cout << endl;

    tampilStack();

    return 0;
}