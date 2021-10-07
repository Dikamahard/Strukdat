#include <iostream>

struct node{
    int data;
    node *next;
};
typedef node *ptrnode;


void print(ptrnode &head){
    ptrnode temp = head;
    std::cout << "List : ";
    while(temp != NULL){
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << std::endl;
}

void new_Node(ptrnode &pBaru){
    pBaru = new node;
    std::cin>>pBaru->data;
    pBaru->next = NULL;
}

void print_Head_Last(ptrnode &head){
    ptrnode temp = head;
    if (head == nullptr){
        std::cout << "head : null" << std::endl;
        std::cout << "tail : null" << std::endl;
    } else if(head->next == nullptr){
        std::cout << "head : " << &head << std::endl;
        std::cout << "tail : " << &head << std::endl;
    } else {
        while(temp != NULL){
            temp = temp->next;
        }
        std::cout << "head : " << &head << std::endl;
        std::cout << "tail : " << &temp << std::endl;
    }
}

void insert_Depan(ptrnode &head){
    ptrnode pBaru;
    new_Node(pBaru);
    if(head == NULL){
        head = pBaru;
    } else {
        pBaru->next = head;
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

int main(){
    ptrnode pertama = nullptr;
    ptrnode pBaru;

    print_Head_Last(pertama);
    std::cout << std::endl;
    
    std::cout << "Elemen baru di depan : ";
    insert_Depan(pertama);
    print_Head_Last(pertama);
    print(pertama);
    std::cout << std::endl;

    std::cout << "Elemen baru di depan : ";
    insert_Depan(pertama);
    print_Head_Last(pertama);
    print(pertama);
    std::cout << std::endl;

    std::cout << "Elemen baru di belakang: ";
    insert_Belakang(pertama);
    print_Head_Last(pertama);
    print(pertama);
}