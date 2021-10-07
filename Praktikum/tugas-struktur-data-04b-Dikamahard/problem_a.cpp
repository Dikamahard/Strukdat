#include "problem_a.hpp"
#include <iostream>

void createSingleNode(SinglePointer& newNode, int data)
{
  newNode = new SingleNode;
  newNode->data = data;
  newNode->nextNode = nullptr;

}

void insertSingleFirst(SinglePointer& head, SinglePointer newNode)
{
  if(head == nullptr){
    head = newNode;
  }else{
    newNode->nextNode = head;
    head = newNode;
  }
}

void insertSingleLast(SinglePointer& head, SinglePointer newNode)
{
 SinglePointer temp;
 if (head == nullptr){
   head = newNode;
 }else {
   temp = head;
   while (temp->nextNode != nullptr){
     temp = temp->nextNode;
   }
   temp->nextNode = newNode;
 }
}

void createDoubleNode(DoublePointer& newNode, int data)
{
  newNode = new DoubleNode;
  newNode->data = data;
  newNode->nextNode = nullptr;
  newNode->prevNode = nullptr;
}

void insertDoubleFirst(DoublePointer& head, DoublePointer newNode)
{
  if (head == nullptr){
    head = newNode;
  }else {
  head->prevNode = newNode;
  newNode->nextNode = head;
  head = newNode;
  }
}

void insertDoubleLast(DoublePointer& head, DoublePointer newNode)
{
  DoublePointer temp;
  //DoubleNode *temp = new DoubleNode;
  if (head == nullptr){
    head = newNode;
  }else{
    temp = head;
    while(temp->nextNode != nullptr){
      temp = temp->nextNode;
    }
    temp->nextNode = newNode;
    newNode->prevNode = temp;
  }
}

void deleteDoubleLast(DoublePointer& head)
{
  DoublePointer delNode, last, pre;
  if (head == nullptr){
    delNode = nullptr;
  }else if(head->nextNode == nullptr){
    delNode = head;
    head = nullptr;
  }else {
    last = head;
    pre = nullptr;
    while(last->nextNode != nullptr){
      pre = last;
      last = last->nextNode;
    }
    delNode = last;
    delNode->prevNode = nullptr;
    pre->nextNode = nullptr;
  }
}

void deleteDoubleFirst(DoublePointer& head)
{
  DoublePointer delNode;
  if(head == nullptr){
    delNode = nullptr;
  }else {
    delNode = head;
    head = delNode->nextNode;
    if(head != nullptr){
      head->prevNode = nullptr;
    }
    delNode->nextNode = nullptr;
  }
}

int dataAt(SinglePointer head, int index)
{
  SinglePointer temp;
  if (head == nullptr){
    std :: cout << "list kosong";
  }else if(head->nextNode == nullptr){
    temp = head;
  }else {
    temp = head;
    for(int i=1; i<index; i++){
      temp = temp->nextNode;
    }
  }
  return temp->data;
}

int nodeCount(DoublePointer head)
{
  DoublePointer temp;
  temp = head;
  int count=1;
  while(temp->nextNode != nullptr){
  count++;
  }
  return count;
}

int nodeCount(SinglePointer head)
{
  SinglePointer temp;
  temp = head;
  int count=1;
  while(temp->nextNode != nullptr){
  count++;
  }
  return count;
}

void sortAscending(SinglePointer& head)
{
  SinglePointer temp = head;
  while (temp) {
    SinglePointer min = temp;
    SinglePointer r = temp->nextNode;
    while (r) {
      if (min->data > r->data)
        min = r;
      r = r->nextNode;
    }
    int x = temp->data;
    temp->data = min->data;
    min->data = x;
    temp = temp->nextNode;
  }
}

 void reverseList(SinglePointer& head, SinglePointer& reverseHead)
 {
   if (head == nullptr)
    return;
  SinglePointer curr = head;
  while (curr != nullptr) {
    SinglePointer newNode;
    createSingleNode(newNode, curr->data);
    newNode->nextNode = reverseHead;
    reverseHead = newNode;
    curr = curr->nextNode;
  }
 }
