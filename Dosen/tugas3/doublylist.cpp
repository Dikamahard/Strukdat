// 18-4-2021
// Rizky Mahardika Hariyanato - 140810200010
//

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

typedef node *ptr;
typedef ptr list;

void search(ptr head, ptr& psearch, int key){
    psearch = head;
    
    while(psearch != nullptr){
        if (psearch->data == key ){
            break;
        }else {
            psearch = psearch->next;
        }
    }
}

void insertAfter(ptr& head, ptr newnode, int key) {
    ptr psearch;
    search(head, psearch, key);

    if(psearch->next == nullptr){
        psearch->next = newnode;
        newnode->prev = psearch;
    }else {
        newnode->next = psearch->next;
        newnode->prev = psearch;
        psearch->next->prev = newnode;
        psearch->next = newnode;
    }

}

void insertBefore(ptr& head, ptr newnode, int key) {
    ptr psearch;
    search(head, psearch, key);

    if(psearch->prev = nullptr) {
        psearch->prev = newnode;
        newnode->next = psearch;
    }else {
        newnode->next = psearch;
        newnode->prev = psearch->prev;
        psearch->prev->next = newnode;
        psearch->prev = newnode;
    }
}

void delfisrt(ptr& head) {
    ptr del;
    del = head;

    if(head == nullptr) {
        del = nullptr;
    }else if(head->next == nullptr) {
        del = head;
    }else {
        head = head->next;
        head->prev = nullptr;
        del->next = nullptr;
    }
    
    delete(del);
}

void dellast(ptr& head) {
    ptr del;
    ptr temp = head;
    ptr pre = nullptr;

    if(head == nullptr) {
        del = nullptr;
    }else if(head->next == nullptr) {
        del = head;
    }else {
        while(temp->next != nullptr){
            pre = temp;
            temp = temp->next;
        }
        del = temp;
        pre->next = nullptr;
        del->prev = nullptr;
    }

    delete(del);
}

void delafter(ptr& head, int key) {
    ptr psearch;
    ptr del = nullptr;
    search(head, psearch, key);

    if(psearch->next == nullptr) {
        del;
    }else if(psearch->next->next == nullptr) {
        dellast(head);
    }else {
        del = psearch->next;
        psearch->next = del->next;
        del->next->prev = psearch;
        del->prev = nullptr;
        del->next = nullptr;
    }
    delete(del);
}

void delbefore(ptr& head, int key) {
    ptr psearch;
    ptr del = nullptr;

    search(head, psearch, key);

    if(psearch->prev == nullptr){
        del;
    }else if(psearch->next->prev->prev == nullptr) {
        delfisrt(head);
    }else {
        del = psearch->prev;
        del->prev->next = psearch;
        psearch->prev = del->prev;
        del->next = nullptr;
        del->prev = nullptr;
    }
    delete(del);
}

void delkey(ptr& head, int key){
    ptr psearch;
    ptr del;

    search(head, psearch, key);

    if(psearch == head) {
        delfisrt(head);
    }else if(psearch->next == nullptr) {
        dellast(head);
    }else {
        del = psearch;
        del->prev->next = del->next;
        del->next->prev = del->prev;
        del->next = nullptr;
        del->prev = nullptr;
    }
    delete(del);

}


int main() {
    int angka[] = {100, 200, 300, 400, 500};
    list kepala;

    kepala = new node;
    kepala->next = nullptr;
    kepala->prev = nullptr;



}

