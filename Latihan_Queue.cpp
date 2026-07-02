#include <iostream>
using namespace std;

const int MAKS = 3;

struct Queue{
    int data[MAKS];
    int front;
    int rear;
    int banyak;
};

void buatQueue(Queue &q){
    q.front = 0;
    q.rear = -1;
    q.banyak = 0;
}

bool kosong(Queue &q){
    return q.banyak == 0;
}

bool penuh(Queue &q){
    return q.banyak == MAKS;
}

void tambahAntrian(Queue &q, int nilai){
    if(penuh(q)){
        cout << "Antrian penuh!" << endl;
        return;
    }

    q.rear = (q.rear + 1) % MAKS;
    q.data[q.rear] = nilai;
    q.banyak++;

    cout << nilai << " masuk ke antrian." << endl;
}

void keluarAntrian(Queue &q){
    if(kosong(q)){
        cout << "Antrian kosong!" << endl;
        return;
    }

    int ambil = q.data[q.front];

    q.front = (q.front + 1) % MAKS;
    q.banyak--;

    cout << ambil << " keluar dari antrian." << endl;
}

void lihatDepan(Queue &q){
    if(kosong(q)){
        cout << "Antrian kosong." << endl;
        return;
    }

    cout << "Antrian terdepan : " << q.data[q.front] << endl;
}

void tampilQueue(Queue &q){
    if(kosong(q)){
        cout << "Antrian kosong." << endl;
        return;
    }

    cout << "Isi Antrian : ";

    for(int i = 0; i < q.banyak; i++){
        int index = (q.front + i) % MAKS;
        cout << q.data[index];

        if(i != q.banyak - 1)
            cout << " -> ";
    }

    cout << endl;
}

int main(){

    Queue q;
    buatQueue(q);

    tambahAntrian(q,10);
    tambahAntrian(q,20);
    tambahAntrian(q,30);
    tambahAntrian(q,40);

    cout << endl;

    tampilQueue(q);

    cout << endl;

    lihatDepan(q);

    cout << endl;

    keluarAntrian(q);
    keluarAntrian(q);

    cout << endl;

    tampilQueue(q);

    cout << endl;

    tambahAntrian(q,40);
    tambahAntrian(q,50);
    tambahAntrian(q,60);

    tampilQueue(q);

    cout << endl;

    while(!kosong(q)){
        keluarAntrian(q);
    }

    keluarAntrian(q);

    return 0;
}