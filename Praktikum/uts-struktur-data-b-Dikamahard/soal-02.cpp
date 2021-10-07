#include <iostream>
using namespace std;


struct futsal{
    string nama;
    int angkatan;
    int gol;
    futsal* next;
    futsal* prev;
};
typedef futsal* ptr;
typedef ptr list;


void createnode(ptr& nodebaru) {
    nodebaru = new futsal;
    nodebaru->next = nullptr;
    nodebaru->prev = nullptr;
    cout << "Masukkan nama pemain " << endl ;
    cin >> nodebaru->nama;
    cout << "Masukkan tahun angkatan " << endl;
    cin >> nodebaru->angkatan;
    cout << "Masukkan jumlah gol " << endl;
    cin >> nodebaru->gol;
}

void createlist(ptr& head){
    head = nullptr;
}

void insertlast(ptr& head, ptr nodebaru){
    ptr temp;
    temp = head;
    
    if (head == nullptr){
        head = nodebaru;
    } else{
        while(temp->next != nullptr ){
            temp = temp->next;
        } 
        temp->next = nodebaru;
        nodebaru->prev = temp;
    }
}

void print(ptr head){
    ptr temp = head;
    if (head == nullptr){
        cout << "data kososng";
    }else {
        while (temp != nullptr){
            cout << temp->nama << " ";
            cout << temp->angkatan << " ";
            cout << temp->gol << " " << endl; 
            temp = temp->next;
        }
    }
}

void search(ptr& head, ptr& psearch, int key){
    psearch = head;
    
    while(psearch != nullptr){
        if (psearch->gol == key ){
            break;
        }else {
            psearch = psearch->next;
        }
    }
}

void insertbefore(ptr& head, ptr nodebaru, ptr psearch){
    ptr temp;
    temp = head;

    while(temp != psearch){
        temp = temp->next;
    }
    nodebaru->next = temp;
    nodebaru->prev = temp->prev;
    temp->prev->next = nodebaru;
    temp->prev = nodebaru;
}

void dellast(ptr& head){
    ptr temp, del, pre;
    temp = head;

    while(temp->next != nullptr){
        pre = temp;
        temp = temp->next;
    }
    del = temp;
    pre->next = nullptr;
    del->prev = nullptr;
    delete(del);
}


int main(){
    list kepala;
    ptr data1, data2, data3, data4, data5, data6;
    ptr psearch;
    int key;

    createlist(kepala);

    createnode(data1);  // Michael
    createnode(data2);  // Fernandes
    createnode(data3);  // Steven
    createnode(data4);  // James
    createnode(data5);  // Diego

    cout << "Masukkan list awal" << endl;
    insertlast(kepala, data1);
    insertlast(kepala, data2);
    insertlast(kepala, data3);
    insertlast(kepala, data4);
    insertlast(kepala, data5);

    print (kepala);
    
    cout << "Masukkan node tambahan" << endl;
    createnode(data6);  // Jajang

    key = 4;                       // jumlah gol steven sebagai key
    search(kepala, psearch, key);  // Mencari elemen tempat steven 

    insertbefore(kepala, data6, psearch);

    dellast(kepala);

    cout << "Hasil list yang sudah di update" << endl;
    print(kepala);

}
