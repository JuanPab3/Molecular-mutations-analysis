#ifndef _BINARYTREE_HPP
#define _BINARYTREE_HPP

#include <stdexcept>
#include <iostream>
#include <vector>

struct BSTNode {
  float key;
  std::vector<std::string> value;
  BSTNode *left;
  BSTNode *right;
  BSTNode *parent;
};

class BST {
private:
  BSTNode *root;

  void insert_node(BSTNode* &node, BSTNode *p, float k, std::string v);
  void display_node(BSTNode *node, int count);
  void destroy_recursive(BSTNode* node);
  BSTNode* find_node(BSTNode* node, float k);
  BSTNode* minimum(BSTNode *node);
  BSTNode* maximum(BSTNode *node);
  BSTNode* predecessor(BSTNode *node);
  BSTNode* successor(BSTNode *node);
  BSTNode* remove_node(BSTNode* &node, float k);

public:
  BST() { root = nullptr; }
  ~BST() { destroy_recursive(root); }

  bool empty() { return root == nullptr; }
  void clear() { destroy_recursive(root); }
  /**/
  void insert(float k, std::string v) { insert_node(root, nullptr, k, v); }
  /**/
  void display();
  BSTNode* find(float k) { return find_node(root, k); }
  BSTNode* remove(float k) { return remove_node(root, k); }
  /**/
  std::vector<std::string> get(float k);
  /**/
};


/**/
void BST::insert_node(BSTNode* &node, BSTNode *p,float k, std::string v) {
    if(node == nullptr){
        std::vector<std::string> new_vec;
        node = new BSTNode;
        node->key = k;
        node->value = new_vec;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = p;
    } else {
        if(k == node->key) {
            node->value.push_back(v);
        } else {
            // std::cout << "INSERT IS WORKING \n";
            if (k < node->key) {
                insert_node(node->left, node, k, v);
            } else {
                insert_node(node->right, node, k, v);
            }
        }
    }
}

std::vector<std::string> BST::get(float k) {
    if (root == nullptr )
        throw std::runtime_error("OOOOPS! Al parecer tu arbol está vasio °_° ");
    BSTNode* temp = find(k);
    if (temp == nullptr) {
        throw std::runtime_error("OOOOPS! Al parecer la llave que buscas, no está en tu arbol °_° ");
    } else {
        return temp->value;
    }
}

/**/

void BST::display_node(BSTNode *node, int count) {
   if(node != nullptr){
    count++;
    display_node(node->left, count);
    std::cout << count-1 << ":" << node->key << "%\n";
    int s = node->value.size();
    for (int i = 0; i < s; i++) {
        std::cout << "Código #" << i+1 << "\n";
        std::cout << node->value[i] << "\n";
    }
    display_node(node->right, count);
  }
}

void BST::display() {
  int count = 0;
  display_node(root, count);
  std::cout << std::endl;
}

void BST::destroy_recursive(BSTNode* node) {
  if(node != nullptr){
    destroy_recursive(node->left);
    destroy_recursive(node->right);
    delete node;
  }
}

BSTNode* BST::find_node(BSTNode *node, float k) {
  if(node == nullptr) return nullptr;
  if(node->key == k) return node;
  if(node->key < k)
    return find_node(node->right, k);
  else
    return find_node(node->left, k);
}

BSTNode* BST::minimum(BSTNode *node) {
  while(node->left != nullptr)
    node = node->left;
  return node;
}

BSTNode* BST::maximum(BSTNode *node) {
  while(node->right != nullptr)
    node = node->right;
  return node;
}

BSTNode* BST::predecessor(BSTNode *node) {
  if(node->left != nullptr)
    return maximum(node->left);
  //If no left child predecessor might one of the ancestors
  BSTNode* p = node->parent;
  while(p != nullptr && node == p->left){ //while I'm left child
    node = p;
    p = node->parent;
  }
  return p;
}

BSTNode* BST::successor(BSTNode *node) {
  if(node->right != nullptr)
    return minimum(node->right);
  //If no right child successor might one of the ancestors
  BSTNode* p = node->parent;
  while(p != nullptr && node == p->right){ //while I'm right child
    node = p;
    p = node->parent;
  }
  return p;
}

// BSTNode* BST::remove_node(BSTNode* &node, float k) {
//   BSTNode* n = find_node(node, k);
//   if(n != nullptr){
//     BSTNode* p = n->parent;
//
//     //Case 1: No children
//     if(n->left == nullptr && n->right == nullptr){
//       //
//       std::cout<<"Case1\n";
//       //
//       if(p == nullptr){ //if node is root
// 	root = nullptr;
//       }else{
// 	if(n == p->left) //if n is left child
// 	  p->left = nullptr;
// 	else
// 	  p->right = nullptr;
//       }
//       delete n;
//     }
//
//     //Case 2: One child
//     else if(n->left == nullptr || n->right == nullptr){
//       //
//       std::cout<<"Case2\n";
//       //
//       BSTNode* c;
//       if(n == p->left){ //if n is left child
// 	if(n->left != nullptr) //if child was left
// 	  c = n->left;
// 	else //if child was right
// 	  c = n->right;
// 	if(p != nullptr) p->left = c;
//       }else{ //if n is right child
// 	if(n->left != nullptr) //if child was left
// 	  c = n->left;
// 	else //if child was right
// 	  c = n->right;
// 	if(p != nullptr) p->right = c;
//       }
//       c->parent = p;
//       delete n;
//     }
//
//     //Case 3: Two children
//     else{
//       //
//       std::cout<<"Case3\n";
//       //
//       BSTNode* s = successor(n);
//       float new_key = s->key;
//       p = remove_node(s->parent, s->key);
//       n->key = new_key;
//     }
//
//     return p;
//   }
//   return nullptr;
// }


#endif
