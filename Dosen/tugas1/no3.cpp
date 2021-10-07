
#include <iostream>

struct node{
    int data;
    node *next;
};

typedef node* ptrnode;


void print(ptrnode &head){
    ptrnode temp = head;
    while(temp != NULL){
        std::cout << temp->data << ' ';
        temp = temp -> next;
    }
    std::cout << std::endl;
}

void new_Node(ptrnode &pBaru){
    pBaru = new node;
    std::cin>>pBaru->data;
    pBaru->next = NULL;
}

void insert_Depan(ptrnode &head){
    ptrnode pBaru;
    new_Node(pBaru);
    if(head ==NULL){
        head = pBaru;
    }else{
        pBaru ->next = head;
        head = pBaru;
    }
}

void insert_Belakang(ptrnode &head){
    ptrnode pBaru;
    new_Node(pBaru);
    ptrnode temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = pBaru;
}

void insert_Tengah(ptrnode &head, int target){
    bool search_item = false;
    ptrnode prev;
    ptrnode temp = head;
    while (!search_item && temp != NULL){
        if(prev->data == target){
            ptrnode pBaru;
            new_Node(pBaru);
            pBaru->next = temp;
            prev->next = pBaru;
            search_item = true;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    if(!search_item)
        std::cout << "Input Salah" << std::endl;
}

void hapus_Awal(ptrnode &head){
    ptrnode previous;
    ptrnode temp = head;
    while(temp->next != NULL){
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    delete temp;
    previous = head;
    temp = head->next;
    head = temp;
    delete previous;
    std::cout << std::endl;
}

void hapus_Akhir(ptrnode &head){
    ptrnode prev;
    ptrnode temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    std::cout << std::endl;
}

void hapus_Tengah(ptrnode &head, int n){
    ptrnode prev, after;
    ptrnode temp = head;
    while (temp->data != n && temp != NULL){
        prev = temp;
        temp = temp->next;
        after = temp->next;
    }
    prev->next = after;
    delete temp;
}

void replace_Data(ptrnode &head, int index){
    if (head == nullptr){
        return;
    }else if(head->next == nullptr){
        ptrnode pBaru;
        ptrnode temp = head;
        new_Node(pBaru);
        head = pBaru;
        delete temp;
    }else{
        ptrnode pBaru;
        new_Node(pBaru);
        ptrnode temp = head;
        if(index == 1){
            pBaru->next = temp->next;
            head = pBaru;
            delete temp;
        }else{
            ptrnode previous;
            for(int i=0; i<index-1; i++){
                previous = temp;
                temp = temp->next;
            }
            pBaru->next = temp->next;
            previous->next = pBaru;
            delete temp;
        }
    }
}

int main(){
    ptrnode pertama;
    ptrnode ptr1;
    int a;
  
    std::cout << "Masukkan interval data : "; std::cin >> a;
    ptr1 = new node;
    std::cout << "Masukkan datanya : " << std::endl; std:: cin >> ptr1->data;
    ptr1->next = NULL;
    pertama = ptr1;

    for(int i=0; i<a-1; i++){
        insert_Belakang(pertama);
    }
    std::cout << "ptrnode : "; 
    print(pertama);
    std::cout << std::endl;


    std::cout << "Masukkan data dari belakang : ";
    insert_Belakang(pertama);
    print(pertama);
    std::cout << std::endl;

    std::cout << "Masukkan data dari depan : ";
    insert_Depan(pertama);
    print(pertama);
    std::cout << std::endl;

    int data;
    std::cout << "Masukkan data disamping kanan angka : "; std::cin >> data;
    std::cout << "Masukkan data baru : ";
    insert_Tengah(pertama, data);
    print(pertama);
    std::cout << std::endl;

    std::cout << "Hapus data dari depan : ";
    hapus_Awal(pertama);
    print(pertama);
    std::cout << std::endl;

    std::cout << "Hapus data dari belakang : ";
    hapus_Akhir(pertama);
    print(pertama);
    std::cout << std::endl;

    int del;
    std::cout << "Hapus data bebas : "; std::cin >> del;
    hapus_Tengah(pertama, del);
    print(pertama);
    std::cout << std::endl;

    int index;
    std::cout << "Index data yang mau diubah : "; std::cin >> index;
    std::cout << "Masukkan data baru : "; 
    replace_Data(pertama, index);
    print(pertama);
    std::cout << std::endl;
}