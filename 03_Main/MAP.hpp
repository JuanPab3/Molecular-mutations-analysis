/*CLASS MAP AS BST FOR BLAST ALGORITHM*/

#ifndef __MAP_HPP__
#define __MAP_HPP__

#include<iostream>
#include<stdexcept>
using namespace std;

//Linked list to save the posit. of the 3-mer
template<typename dataType>
struct Node{
    dataType data;
    Node *next;
};

template<typename dataType>
class LL{
private:

    int count;
    Node<dataType> *head;

public:
    LL();
    ~LL();

    void clear();
    void push_back(dataType data);
    void display_ll();
    void copy(LL<dataType> &cop);
    void reverse();

    bool empty() const;

    int size() const;

    Node<dataType>* find(dataType d);
    Node<dataType>* pop_back();
    
    dataType peek_back() const;
    dataType peek_front() const;
};

//Binary search tree

template<typename keyType, typename dataType>
struct bstNode{
    keyType key;
    LL<dataType> data;
    bstNode<keyType, dataType> *parent;
    bstNode<keyType, dataType> *left;
    bstNode<keyType, dataType> *right;
};

template<typename keyType, typename dataType>
class Map{
private:
    bstNode<keyType, dataType> *root;
    //PRIVATE METHODS

    void insert_node(bstNode<keyType,dataType>* &node, bstNode<keyType,dataType> *p,keyType k, dataType d);
    void display_node(bstNode<keyType,dataType> *node, int count);
    void destroy_recursive(bstNode<keyType,dataType>* node);

    bstNode<keyType,dataType>* find_node(bstNode<keyType,dataType>* node, keyType k);
    bstNode<keyType,dataType>* minimum(bstNode<keyType,dataType> *node);
    bstNode<keyType,dataType>* maximum(bstNode<keyType,dataType> *node);
    bstNode<keyType,dataType>* predecessor(bstNode<keyType,dataType> *node);
    bstNode<keyType,dataType>* successor(bstNode<keyType,dataType> *node);
    bstNode<keyType,dataType>* remove_node(bstNode<keyType,dataType>* &node, keyType k);

public:
  //PUBLIC METHODS

    Map(){root=nullptr;}
    ~Map(){destroy_recursive(root);}

    bool empty(){return root==nullptr;}

    void insert(keyType k, dataType d){insert_node(root,nullptr,k,d);}
    void display(){display_node(root,0);}

    bstNode<keyType,dataType>* find(keyType k){return find_node(root,k);}
    bstNode<keyType,dataType>* remove(keyType k){return remove_node(root, k);}

    LL<dataType> get(keyType key);
};


#include "MAP.cpp"
#endif


/* Hacen falta implementar:
-Método que borre un elemento de la LL.
*/
