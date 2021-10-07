#include <iostream>
using namespace std;

struct anak{
    string dataAnak;

    anak *nextAnak;
};

struct pegawai{
    string dataPeg;
    //string namaPeg;
    anak *firstAnak;

    pegawai *next;
};

typedef pegawai *ptrpeg;
typedef anak *ptranak;

typedef ptrpeg listpeg;

void createlistpeg(ptrpeg& head) {
    head = nullptr;
}

void createpegawai(ptrpeg& newnode) {
    newnode = new pegawai;

    cin >> newnode->dataPeg;

    newnode->next = nullptr;
    newnode->firstAnak = nullptr;
}

void createanak(ptranak& newnode) {
    newnode = new anak;

    cin >> newnode->dataAnak;

    newnode->nextAnak = nullptr;
}

void transversalpeg(ptrpeg head) {
    ptrpeg temp;
    temp = head;

    if(head == nullptr) {
        cout << "List kosong \n";
    }else {
        while(temp != nullptr) {
            cout << temp->dataPeg << "\n";
            temp = temp->next;
        }
    }
}

void search(listpeg head, string key, ptrpeg& psearch, int& status) {
    psearch = head;
    status = 0;

    while(psearch != nullptr && status == 0) {
        if(psearch->dataPeg == key){
            status = 1;
        }else {
            psearch = psearch->next;
        }
    }
}

void insertfirstpeg(listpeg& head, ptrpeg nodebaru) {

    if(head == nullptr) {
        head = nodebaru;
    }else {
        nodebaru->next = head;
        head = nodebaru;
    }
}

// void dellistanak(ptranak& headanak) {
//     ptranak del, temp = headanak;

//     if(headanak->nextAnak == nullptr){
//         delete(headanak);
//     }else {
//         while(del != nullptr) {
//             del = temp;
//             temp = temp->nextAnak;
//             del->nextAnak = nullptr;
//             delete(del);
//         }
//     }
// }

void delfirstpeg(listpeg& head) {
    ptrpeg del;

    if(head == nullptr) {
        del = nullptr;
    }else if(head->next == nullptr) {
        del = head;
    }else {
        del = head;
        head = head->next;
        del->next = nullptr;
    }
}

void insertfirstanak(listpeg& head, string key, ptranak nodebaru) {
    ptrpeg ortu;
    int ketemu;

    search(head, key, ortu, ketemu);

    if(ketemu == 1){
        cout << "ditemukan \n";
        if(ortu->firstAnak == nullptr){
            ortu->firstAnak = nodebaru;
        }else {
            nodebaru->nextAnak = ortu->firstAnak;
            ortu->firstAnak = nodebaru;
        }
    }else {
        cout << "Error 101 \n";
    }
}

void delfirstanak(listpeg& head, string key) {
    ptrpeg ortu;
    ptranak del;
    int ketemu;

    ortu = head;
    ketemu = 0;

    search(head, key, ortu, ketemu);

    if(ketemu == 1){
        if(ortu->firstAnak == nullptr) {
            del = nullptr;
        }else if(ortu->firstAnak->nextAnak == nullptr){
            del = ortu->firstAnak;
            ortu->firstAnak = nullptr;
        }else {
            del = ortu->firstAnak;
            ortu->firstAnak = ortu->firstAnak->nextAnak;
            del->nextAnak = nullptr;
        }
        delete(del);
    }else {
        cout << "ERROR 101 \n";
    }

}

void transversalortuanak(listpeg head) {
    ptrpeg temppeg;
    ptranak tempanak;

    temppeg = head;
    while(temppeg != nullptr) {
        cout << temppeg->dataPeg << "\n";
        tempanak = temppeg->firstAnak;

        while(tempanak != nullptr) {
            cout << tempanak->dataAnak << "\n";
            tempanak = tempanak->nextAnak;
        }

        temppeg = temppeg->next;
    }
}



int main() {
ptrpeg peg1, peg2, peg3;
ptranak anak2;
listpeg kepala;


createlistpeg(kepala);

cout << "Masukkan data 3 pegawai \n";
createpegawai(peg1);
createpegawai(peg2);
createpegawai(peg3);

insertfirstpeg(kepala, peg1);
insertfirstpeg(kepala, peg2);
insertfirstpeg(kepala, peg3);
cout << "\n";

transversalpeg(kepala);
cout << "\n";

createanak(anak2);
cout << "\n";

insertfirstanak(kepala, "b", anak2);

transversalortuanak(kepala);

}