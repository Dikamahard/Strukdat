#pragma once

/**
 * @brief       Struct yang memeiliki sebuah pointer struct selanjutnya.
 * 
 * @note  Tambahkan atribut dengan nama variabel "data" dan "nextNode". 
 *        Jika terdapat error, tipe data dari atribut dapat berpengaruh.
 * 
 */
struct SingleNode{
  int data;
  SingleNode* nextNode; //SingleNode *nextNode
};

/**
 * @brief       Struct yang memiliki pointer ke struct sebelum dan setelahnya.
 * 
 * @note  Tambahkan atribut dengan nama variabel "data", "nextNode", "prevNode". 
 *        Jika terdapat error, tipe data dari atribut dapat berpengaruh.
 */
struct DoubleNode{
  int data;
  DoubleNode* nextNode; // DoubleNode *nextNode
  DoubleNode* prevNode; // DOubleNode *prevNode
};

typedef SingleNode* SinglePointer;
typedef DoubleNode* DoublePointer;