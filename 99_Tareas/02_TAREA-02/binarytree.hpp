// Integrantes: Estefanía Laverde, Juan Luis Ávila, Juan Pablo Sierra

#ifndef _BINARYTREE_HPP
#define _BINARYTREE_HPP

#include <iostream>

template <typename T>
struct BSTNode {
  int reps; //Duplicate of keys
  T key;
  BSTNode<T> *left;
  BSTNode<T> *right;
  BSTNode<T> *parent;
};


template <typename T>
class BST {
private:
  BSTNode<T> *root;

  int insert_node(BSTNode<T>* &node, BSTNode<T>* p, T k);
  void destroy_recursive(BSTNode<T> *node);
  void display_node(BSTNode<T> *node, int count);
  int node_capacity( BSTNode<T> *node);

  BSTNode<T>* find_node(BSTNode<T> *node, T k);
  BSTNode<T>* minimum(BSTNode<T> *node);
  BSTNode<T>* maximum(BSTNode<T> *node);
  BSTNode<T>* predecessor(BSTNode<T> *node);
  BSTNode<T>* successor(BSTNode<T> *node);
  BSTNode<T>* remove_node(BSTNode<T>* &node, T k);

public:
  BST() { root = nullptr; }
  ~BST() { destroy_recursive(root); }

  bool empty() { return root == nullptr; }
  void display();
  int insert(T k) { return insert_node(root, nullptr, k); }
  int capacity() {return node_capacity(root);}

  BSTNode<T>* find(T k) { return find_node(root, k); }
  BSTNode<T>* remove(T k) { return remove_node(root, k); }

  /*--------*/
  void test();
  /*--------*/
};

//===============|MODIFIED METHOD a|==============================
template <typename T>
int BST<T>::insert_node(BSTNode<T>* &node, BSTNode<T> *p, T k) {
  if(node == nullptr){
    node = new BSTNode<T>;
    node->key = k;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = p;
    node->reps=0;
  } else{
    if (k==node->key){
      (node->reps)++;
    }
    else if (k != node->key){
      if(k < node->key){
        insert_node(node->left, node, k);
      }
      else{
        insert_node(node->right, node, k);
      }
    }
  }
  return node->reps;
}

//===============|MODIFIED METHOD d|==============================
template <typename T>
void BST<T>::display_node(BSTNode<T> *node, int count) {
  if(node != nullptr){
    count++;
    display_node(node->left, count);
    std::cout << "(" << count-1 << ")(" << node->key <<", reps "<< node->reps << ") ";
    display_node(node->right, count);
  }
}

template <typename T>
void BST<T>::display() {
  display_node(root, 0);
  std::cout << std::endl;
}

template <typename T>
void BST<T>::destroy_recursive(BSTNode<T> *node) {
  if(node != nullptr){
    destroy_recursive(node->left);
    destroy_recursive(node->right);
    delete node;
  }
}

//==============|MODIFIED METHOD b|===============================
template <typename T>
BSTNode<T>* BST<T>::find_node(BSTNode<T> *node, T k) {
  if(node == nullptr) {return nullptr;}
  if(node->key == k) {return node;}
  if(node->key < k){
    return find_node(node->right, k);
  }
  else{
    return find_node(node->left, k);
  }
}

template <typename T>
BSTNode<T>* BST<T>::minimum(BSTNode<T> *node) {
  while(node->left != nullptr)
    node = node->left;
  return node;
}

template <typename T>
BSTNode<T>* BST<T>::maximum(BSTNode<T> *node) {
  while(node->right != nullptr)
    node = node->right;
  return node;
}

template <typename T>
BSTNode<T>* BST<T>::predecessor(BSTNode<T> *node) {
  if(node->left != nullptr)
    return maximum(node->left);
  else{
    BSTNode<T>* p = node->parent;
    while(p != nullptr && node == p->left){
      node = p;
      p = node->parent;
    }
    return p;
  }
}

template <typename T>
BSTNode<T>* BST<T>::successor(BSTNode<T> *node) {
  if(node->right != nullptr)
    return minimum(node->right);
  else{
    BSTNode<T>* p = node->parent;
    while(p != nullptr && node == p->right){
      node = p;
      p = node->parent;
    }
    return p;
  }
}

//===============|MODIFIED METHOD c|=============================
template <typename T>
BSTNode<T>* BST<T>::remove_node(BSTNode<T>* &node, T k) {
    BSTNode<T>* n = find_node(node, k);
    if (n->reps > 0) {
      (n->reps) --;
      return n;
    }
    else{
      if(n != nullptr){
          BSTNode<T>* p = n->parent;
          //Case 1: No children
          if(n->left == nullptr && n->right == nullptr){
              //
              std::cout<<"Case1\n";
              //
              if(p == nullptr){ //if node is root
                  root = nullptr;
              } else{
                  if(n == p->left) //if n is left child
                      p->left = nullptr;
                  else
                      p->right = nullptr;
              }
              delete n;
          }

          //Case 2: One child
          else if(n->left == nullptr || n->right == nullptr){
              //
              std::cout<<"Case2\n";
              //
              BSTNode<T>* c;
              if(p == nullptr){
                  if(n->left != nullptr)
                      c = root = n->left;
                  else
                      c = root = n->right;
              } else{
                  if(n == p->left){ //if n is left child
                      if(n->left != nullptr) //if child was left
                          c = n->left;
                      else //if child was right
                          c = n->right;
                      if(p != nullptr) p->left = c;
                  } else{ //if n is right child
                      if(n->left != nullptr) //if child was left
                          c = n->left;
                      else //if child was right
                          c = n->right;
                      if(p != nullptr) p->right = c;
                  }
              }
              c->parent = p;
              delete n;
          }

          //Case 3: Two children
          else{
              //
              std::cout<<"Case3\n";
              //
              BSTNode<T>* s = successor(n);
              T new_key = s->key;
              p = remove_node(s->parent, s->key);
              n->key = new_key;
          }

          return p;
      }
      return nullptr;
}
}

//===============|NEW METHOD e|=================================
template<typename T>
int BST<T>::node_capacity(BSTNode<T> * node){
  int count=0;
  if (node!=nullptr){
    count+=(node->reps)+1;
    count+= node_capacity(node->left);
    count+= node_capacity(node->right);
  }
  return count;
}

/*--------*/
template <typename T>
void BST<T>::test() {
  std::cout << "Lowest element: " << minimum(root)->key << "\n";
  std::cout << "Highest element: " << maximum(root)->key << "\n";

  std::cout << "Predecessor of Sneezy is "
  	    << predecessor(find("Sneezy"))->key
  	    << "\n";
  std::cout << "Successor of Dopey is "
  	    << successor(find("Dopey"))->key
  	    << "\n";
}
/*--------*/

#endif
