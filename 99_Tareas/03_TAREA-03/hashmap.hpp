#ifndef __HASHMAP_HPP
#define __HASHMAP_HPP

#include <iostream>
#include <stdexcept>
#include <string>

const int INITIAL_SIZE = 5;

template <typename VT>
struct KeyValueNode {
    std::string key;
    VT value;
    KeyValueNode<VT> *next;
};

template <typename VT>
class HashMap {
private:
    /*Class properties*/
    KeyValueNode<VT> **table;
    int table_size;
    int count;

    /*Private Methods*/
    KeyValueNode<VT>* search_bucket(int i, std::string key);
    int hash_fun(std::string key);
    void rehash();

public:

    /*Constructor & Destructor*/
    HashMap();
    ~HashMap();

    /*Modifier Methods*/
    void insert(std::string key, VT value);
    void remove(std::string key); /* Métodos a implementar */
    void clear();


    /*Accessor Methods*/
    bool contains(std::string key); /* Métodos a implementar */
    VT get(std::string key); /* Métodos a implementar */
    void display();
    bool empty();
    int size();


};



/*=============================| IMPLEMENTACIÓN |=============================*/
/*============================================================================*/

/*==========================| CONTRUCTOR&DESTRUCTOR |=========================*/
template <typename VT>
HashMap<VT>::HashMap() {
    table_size = INITIAL_SIZE;
    table = new KeyValueNode<VT>*[table_size];
    for(int i = 0; i < table_size; ++i) table[i] = nullptr;
    count = 0;
}

template <typename VT>
HashMap<VT>::~HashMap() {
    clear();
    delete[] table;
}

/*============================| PRIVATE_METHODS |=============================*/
template <typename VT>
KeyValueNode<VT>* HashMap<VT>::search_bucket(int i, std::string key) {
    KeyValueNode<VT> *cursor = table[i];
    while(cursor != nullptr){
        if(cursor->key == key) return cursor;
            cursor = cursor->next;
    }
    return nullptr;
}

template <typename VT>
int HashMap<VT>::hash_fun(std::string key) {
    int index = 0;
    for(char c : key)
        index += c;
    return index % table_size;
}

template <typename VT>
void HashMap<VT>::rehash() {
    int old_table_size = table_size;
    KeyValueNode<VT> **old_table = table;
    table_size *= 2;
    table = new KeyValueNode<VT>*[table_size];
    for(int i = 0; i < table_size; ++i) table[i] = nullptr;
    count = 0;

    KeyValueNode<VT> *cursor;
    for(int i = 0; i < old_table_size; ++i){
        cursor = old_table[i];
        while(old_table[i] != nullptr){
            insert(cursor->key, cursor->value);
            cursor = cursor->next;
            delete old_table[i];
            old_table[i] = cursor;
        }
    }
    delete[] old_table;
}

/*===========================| MODIFIER_METHODS |=============================*/
template <typename VT>
void HashMap<VT>::insert(std::string key, VT value) {
    if(count == 2*table_size) rehash();
    int index = hash_fun(key);
    KeyValueNode<VT> *cursor = search_bucket(index, key);
    if(cursor != nullptr){
        cursor->value = value;
    } else {
        KeyValueNode<VT> *new_node = new KeyValueNode<VT>;
        new_node->key = key;
        new_node->value = value;
        new_node->next = table[index];
        table[index] = new_node;
        count++;
    }
}

/* Métodos a implementar */
template <typename VT>
void remove(std::string key) {

}

template <typename VT>
void HashMap<VT>::clear() {
    KeyValueNode<VT> *cursor;
    for(int i = 0; i < table_size; ++i){
        cursor = table[i];
        while(table[i] != nullptr){
            cursor = cursor->next;
            delete table[i];
            table[i] = cursor;
    }
  }
  count = 0;
}

/*===========================| ACCESSOR_METHODS |=============================*/
/* Métodos a implementar */
template <typename VT>
bool contains(std::string key) {
    int index = hash_fun(key);
    

}

/* Métodos a implementar */
template <typename VT>
VT get(std::string key) {

}


template <typename VT>
void HashMap<VT>::display() {
  std::cout << count << " elements:\n";
  KeyValueNode<VT> *cursor;
  for(int i = 0; i < table_size; ++i){
    cursor = table[i];
    while(cursor != nullptr){
      std::cout << "(" << cursor->key
                << "," << cursor->value
                << ") ";
      cursor = cursor->next;
    }
    std::cout << std::endl;
  }
}

template <typename VT>
bool HashMap<VT>::empty() {
    return count == 0;
}

template <typename VT>
int HashMap<VT>::size() {
    return count;
}

#endif
