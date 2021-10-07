#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    node *next;
};

typedef node *ptrnode;


void insertDataRandom(ptrnode& head){
    ptrnode temp;
    temp = head; 
    int num;
    for (int i=1; i<=11; i++){
        num = rand() % 11;
        cout << num << " ";
        temp->data = num;
        temp = temp->next;
    }
}

// void printList(ptrnode head){
//     ptrnode temp;
//     temp = head; 

//     for(int i=1; i<=11; i++){
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }

int  largestData(ptrnode head ){
    int result = 0;
  ptrnode temp = head;
  while (temp->next != nullptr) {
    if (temp->data > result) {
      result = temp->data;
    }
    temp = temp->next;
  }
    
  return result;
}

// void sortAscending(ptrnode& head)
// {
//   ptrnode temp = head;
//   while (temp) {
//     ptrnode min = temp;
//     ptrnode r = temp->next;
//     while (r) {
//       if (min->data > r->data)
//         min = r;
//       r = r->next;
//     }
//     int x = temp->data;
//     temp->data = min->data;
//     min->data = x;
//     temp = temp->next;
//   }
//   for(int i=1; i<=11; i++){
//       temp = temp->next;
//       cout << temp;
//   }
// }

int main(){
    ptrnode linkedlist;
    linkedlist = nullptr;
    //int hasil ;

    
    cout << "==========================================" << endl;
    cout << "List Data : " << endl;
    //printList(linkedlist);
    insertDataRandom(linkedlist);
    cout << '\n' << "Data Terbesar : "  << endl;
    cout << largestData(linkedlist);
    //sortAscending(linkedlist);
   
}