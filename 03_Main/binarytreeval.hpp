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
    int sz = 0;
    BSTNode *root;

    void insert_node(BSTNode* &node, BSTNode *p, float k, std::string v);
    void display_node(BSTNode *node, int count);
    void destroy_recursive(BSTNode* node);
    BSTNode* find_node(BSTNode* node, float k);
    BSTNode* minimum(BSTNode *node);
    BSTNode* maximum(BSTNode *node);
    BSTNode* predecessor(BSTNode *node);
    BSTNode* successor(BSTNode *node);

public:
    BST() { root = nullptr; }
    ~BST() { destroy_recursive(root); }

    bool empty() { return root == nullptr; }
    void clear() { destroy_recursive(root); sz = 0;}
    /**/
    void insert(float k, std::string v) { insert_node(root, nullptr, k, v); }
    /**/
    void display();
    int size() const;
    BSTNode* find(float k) { return find_node(root, k); }
    /**/
    std::vector<std::string> get(float k);
    /**/
};


/**/
int BST::size() const {
    return sz;
}


void BST::insert_node(BSTNode* &node, BSTNode *p,float k, std::string v) {
    if(node == nullptr){
        std::vector<std::string> new_vec;
        new_vec.push_back(v);
        node = new BSTNode;
        node->key = k;
        node->value = new_vec;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = p;
        sz++;
    } else {
        if(k == node->key) {
            node->value.push_back(v);
            sz++;
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
        throw std::runtime_error("OOOOPS! Al parecer tu arbol está vasio °~° ");
    BSTNode* temp = find(k);
    if (temp == nullptr) {
        throw std::runtime_error("OOOOPS! Al parecer la llave que buscas, no está en tu arbol °~° ");
    } else {
        return temp->value;
    }
}

/**/

void BST::display_node(BSTNode *node, int count) {
   if(node != nullptr){
    count++;
    display_node(node->left, count);
    std::cout << "\n===| " << count-1 << ":" << node->key << "% |===\n";
    int s = node->value.size();
    for (int i = 0; i < s; i++) {
        std::cout << "\nCódigo #" << i+1 << "\n";
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




#endif
