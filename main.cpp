#include <iostream>
using namespace std;
#define MAX 8

struct antrian{
    int data[MAX];
    int head;
    int tail;
}antre;

void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void tampil();
void Clear();
void menu(int);


int main(){
    int pilih;
    do{
        cout << "[1] Create" << "\n";
        cout << "[2] Enqueue" << "\n";
        cout << "[3] Dequeue" << "\n";
        cout << "[4] Clear data" << "\n";
        cout << "[5] Tampil data" << "\n";
        cout << "[0] Exit" << "\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilih;
        menu(pilih);
    }
    while(pilih != 0);
    return 0;
}

void menu(int pil){
    int data;
    switch(pil){
        case 1: create(); break;
        case 2: cin >> data; enqueue(data); break;
        case 3: dequeue(); break;
        case 4: Clear(); break;
        case 5: tampil(); break;
        case 0: break;
        default: cout << "pilihan tidak ditemukan." << endl; break;
    }
}

void create(){
    antre.head = antre.tail = -1;
    cout << "Create berhasil!" << "\n";
}

bool isEmpty(){
    if(antre.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(){
    if(antre.tail == MAX-1){
        return true;
    } else {
        return false;
    }
}

void enqueue(int data){
    if(isEmpty()==true){
        antre.head = antre.tail = 0;
        antre.data[antre.tail] = data;
        cout << antre.data[antre.tail] << " Dimasukkan ke antrian \n";
    } else {
        antre.tail++;
        antre.data[antre.tail] = data;
        cout << antre.data[antre.tail] << " Dimasukkan ke antrian \n";
    }
}

int dequeue(){
    int i;
    int e = antre.data[antre.head];
    for(i=antre.head; i<=antre.tail-1; i++){
        antre.data[i] = antre.data[i+1];
    }
    antre.tail--;
    return e;
}

void Clear(){
    antre.head=antre.tail=-1;
    cout << "data clear" << "\n";
}

void tampil(){
    if(isEmpty()==0){
        for (int i=antre.head; i<=antre.tail; i++){
            cout << antre.data[i] << "\n";
        }
    } else {
        cout << "data kosong" << "\n";
    }
}
