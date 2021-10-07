#pragma once

namespace strukdat {

namespace circular_list {

/**
 * @brief Node linked list berisi nilai bertipe `T` yang disimpan pada `data`
 */
template <typename T>
struct Node {
  T data;
  Node *prev;
  Node *next;
};

/**
 * @brief Tipe pointer dari node
 */
template <typename T>
using NodePtr = Node<T> *;

/**
 * @brief Membuat dan menginisialisasi head/sentinel node linked list
 * @note Sentinel node adalah node yang tidak digunakan untuk menyimpan data,
 *       akan tetapi digunakan sebagai node pembantu untuk mempermudah
 *       operasi-operasi pada linked list.
 *
 * @see https://en.wikipedia.org/wiki/Sentinel_node
 *
 * @return        pointer ke head/sentinel node
 */
template <typename T>
NodePtr<T> new_list() {
  NodePtr<T> head = new Node<T>;
  head->next = head;
  head->prev = head;
  return head;
}

/**
 * @brief Melakukan delete pada semua elemen dari linked list
 *
 * @param head    pointer ke sentinel node
 */
template <typename T>
void destroy_list(NodePtr<T> head) {
  if (head->next == head) {
    delete head;
  } else {
    NodePtr<T> temp = head, target;
    while (temp->next != head) {
      target = temp->next;
      head->next = target->prev;
      delete target;
    }
    delete head;
  }
}

/**
 * @brief Menambahkan elemen pada awal list
 *
 * @param head    pointer ke sentinel node
 * @param data    data baru yang akan disimpan pada linked list
 * @return        pointer ke node yang menyimpan data baru
 */
template <typename T>
NodePtr<T> push_front(NodePtr<T> head, const T &data) {
  NodePtr<T> newNode = new Node<T>;
  newNode->data = data;
  newNode->prev = head;

  if (head->next == head) {
    head->next = newNode;
    newNode->next = head;
    head->prev = newNode;
  } else {
    newNode->next = head->next;
    head->next = newNode;
  }
  return newNode;
}

/**
 * @brief Menambahkan elemen pada ujung list
 *
 * @param head    pointer ke sentinel node
 * @param data    data baru yang akan disimpan pada linked list
 * @return        pointer ke node yang menyimpan data baru
 */
template <typename T>
NodePtr<T> push_back(NodePtr<T> head, const T &data) {
  NodePtr<T> newNode = new Node<T>;
  newNode->data = data;
  head->prev = newNode;
  
  if (head->next == head) {
    head->next = newNode;
    newNode->prev = head;
    newNode->next = head;
  } else {
    NodePtr<T> temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next = head;
  }
  return newNode;
}

/**
 * @brief Menambahkan elemen setelah posisi tertentu pada linked list
 *
 * @param position  pointer ke posisi target
 * @param data      data baru yang akan disisipkan setelah posisi target
 * @return          pointer ke node yang menyimpan data baru
 */
template <typename T>
NodePtr<T> insert_after(NodePtr<T> position, const T &data) {
 NodePtr<T> newNode = new Node<T>;
  newNode->data = data;

  position->next->prev = newNode;
  newNode->next = position->next;
  position->next = newNode;
  newNode->prev = position;
  return newNode;
}

/**
 * @brief Menghapus sebuah sebuah node pada linked list.
 *
 * @note Penghapusan tidak dilakukan jika target merupakan sentinel node
 *
 * @param head      pointer ke sentinel node
 * @param position  pointer ke node yang akan dihapus
 */
template <typename T>
void erase(NodePtr<T> const head, NodePtr<T> position) {
  if (position == head) {
    return;
  } else {
    position->next->prev = position->prev;
    position->prev->next = position->next;
    delete position;
  }
}

/**
 * @brief Mengiterasi dan mengeksekusi fungsi pada setiap elemen linked list
 *
 * @param head      pointer ke sentinel node
 * @param func      fungsi yang akan dieksekusi pada setiap elemen
 */
template <typename T, typename F>
void for_each(NodePtr<T> head, F func) {
  NodePtr<T> temp = head;
  while (temp->next != head) {
    temp = temp->next;
    func(temp->data);
  }
}
/**
 * @brief Mencari node yang memiliki data tertentu
 *
 * @param head      pointer ke sentinel node
 * @param data      data yang akan dicari
 * @return          pointer ke node yang pertama kali ditemukan memiliki data.
 *                  `nullptr` jika tidak ditemukan
 */
template <typename T>
NodePtr<T> find(NodePtr<T> head, const T &data) {
  NodePtr<T> temp = head;
  while (temp->next != head) {
    temp = temp->next;
    if (temp->data == data) {
      return temp;
    }
  }
  return nullptr;
}

}  // namespace circular_list

}  // namespace strukdat