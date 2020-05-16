#ifdef __MAP_HPP__

/*=============================PUBLIC METHODS LL===================================*/

//Constructor
template<typename dataType>
LL<dataType>::LL(){
    head=nullptr;
    count=0;
}

//Destructor
template<typename dataType>
LL<dataType>::~LL(){
    clear();
    head=nullptr;
    count=0;
}

template<typename dataType>
void LL<dataType>::clear() {
    while (count>0) {
        pop_back();
    }
}

template<typename dataType>
void LL<dataType>::push_back(dataType data){
    if (count==0){
        Node<dataType>*temp = new Node<dataType>;
        temp->data = data;
        temp->next = nullptr;
        head = temp;
        count++;
    }
    else{ //Si hay algo en la lista
        Node<dataType>*temp=head;
        while (temp->next!=nullptr){
            temp=temp->next;
        }
        //Cuando llegue al útimo elemento
        Node<dataType>*new_node= new Node<dataType>;
        new_node->data=data;
        new_node->next=nullptr;
        temp->next=new_node;
        count++;
    }
}

template<typename dataType>
Node<dataType>* LL<dataType>::pop_back(){
    if (head==nullptr){
        return nullptr;
    }
    Node<dataType>*temp=head, *temp2=head, *retorno;

    while (temp->next!=nullptr){
        temp2=temp;
        temp=temp->next;
    }
    //Cuando llegue al último elemento
    retorno=temp;
    delete temp;
    temp2->next=nullptr;
    count--;
    return retorno;
}

template<typename dataType>
void LL<dataType>::display_ll(){
    Node<dataType>*curr = head;
    std::cout << "HEAD(" << size() << ") -> ";
    while (curr != nullptr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "END \n";
}

template<typename dataType>
void LL<dataType>::copy(LL<dataType> &cop){
  while (cop.size()>0) {
    Node<dataType> *curr=cop.pop_back();
    dataType value=curr->data;
    push_back(value);
  }
  reverse();
}

template<typename dataType>
void LL<dataType>::reverse(){
  if(count>=2){
    Node<dataType> *current=head, *prev=nullptr, *next=nullptr;
    while (current!=nullptr) {
      next=current->next; //Store current
      current->next=prev; //Reverse current node's pointer
      prev=current; //Move pointers one position ahead
      current=next;
    }
    head=prev;
  }
}

template<typename dataType>
bool LL<dataType>::empty() const{
    return count==0;
}

template<typename dataType>
int LL<dataType>::size() const{
    return count;
}


template<typename dataType>
dataType LL<dataType>::peek_back() const{
    dataType valor_retorno;
    if(head==nullptr){
        std::cout << "ERROR: trying peek_back() on an empty list\n";
        std::exit(EXIT_FAILURE);
    }
    if(head->next==nullptr){
        valor_retorno=head->data;
    }
    else{
        Node<dataType>*temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;//Llega hasta el elemento antes de nullptr
        }
        valor_retorno=temp->data;
    }
    return valor_retorno;
}

template<typename dataType>
dataType LL<dataType>::peek_front() const{
    if(head==nullptr){
        std::cout << "ERROR: trying peek_front() on an empty list\n";
        std::exit(EXIT_FAILURE);
    }
    return head->data;
}

/*=============================PRIVATE METHODS MAP===========================*/

template <typename keyType, typename dataType>
void Map<keyType,dataType>::insert_node(bstNode<keyType,dataType>* &node, bstNode<keyType,dataType> *p,keyType k, dataType d){
    if (node==nullptr) {
      node=new bstNode<keyType,dataType>;
      node->left=nullptr;
      node->right=nullptr;
      node->parent=p;
      node->key=k;
      (node->data).push_back(d); //data es una lista enlazada
    }else{//Si el key ya se encuentra en
      if(node->key==k){
        (node->data).push_back(d);
      }else{
        if (node->key>k) {
          insert_node(node->left,node,k,d);
        } else {
          insert_node(node->right,node,k,d);
        }
      }
    }
}

template<typename keyType, typename dataType>
void Map<keyType, dataType>::display_node(bstNode<keyType,dataType> *node, int count){
    if(node != nullptr){
      count++;
      display_node(node->left, count);
      std::cout << "("<<count-1 << ") Key: " << node->key << ", "
          << "Data: ";
          node->data.display_ll();

      display_node(node->right, count);
    }
}

template<typename keyType, typename dataType>
void Map<keyType, dataType>::destroy_recursive(bstNode<keyType,dataType>* node){
  if(node != nullptr){
    destroy_recursive(node->left);
    destroy_recursive(node->right);
    delete node;
  }
}




template<typename keyType, typename dataType>
bstNode<keyType,dataType>* Map<keyType,dataType>::find_node(bstNode<keyType, dataType>* node, keyType k){
  if(node==nullptr){return nullptr; }
  if (node->key==k){
    return node;
    node->data.display_ll();
  }
  if (node->key<k){
    return find_node(node->right,k);
  }else{
    return find_node(node->left,k);
  }

}

template<typename keyType, typename dataType>
bstNode<keyType,dataType>* Map<keyType,dataType>::minimum(bstNode<keyType,dataType> *node){
  while(node->left!=nullptr){
    node=node->left;
  }
  return node;
}

template<typename keyType, typename dataType>
bstNode<keyType,dataType>* Map<keyType,dataType>::maximum(bstNode<keyType,dataType> *node){
  while(node->right!=nullptr){
    node=node->right;
  }
  return node;
}

template<typename keyType, typename dataType>
bstNode<keyType,dataType>* Map<keyType,dataType>::predecessor(bstNode<keyType,dataType> *node){
  if(node->left != nullptr){return maximum(node->left);}

  bstNode<keyType,dataType>* p = node->parent;
  while(p != nullptr && node == p->left){
    node=p;
    p=node->parent;
  }
  return p;
}

template<typename keyType, typename dataType>
bstNode<keyType,dataType>* Map<keyType,dataType>::successor(bstNode<keyType,dataType> *node){
  if(node->right != nullptr){return minimum(node->right);}

  bstNode<keyType,dataType>* p = node->parent;
  while(p != nullptr && node == p->right){
    node = p;
    p = node->parent;
  }
  return p;
}

template<typename keyType, typename dataType>
bstNode<keyType,dataType>* Map<keyType,dataType>::remove_node(bstNode<keyType,dataType>* &node, keyType k){
  bstNode<keyType, dataType>* n = find_node(node, k);
  //((n->parent)->parent)->data.display_ll();
  if(n != nullptr){ //WORKING
    bstNode<keyType, dataType>* p = n->parent;
    //(p->parent)->data.display_ll();
    //Case 1: No children
    if(n->left == nullptr && n->right == nullptr){
        if(p == nullptr){root = nullptr;} //Si estoy borrando el root
        else{
            if(n == p->left){
                p->left = nullptr;
      //          display_node(root, 0);
            }
            else{
        //        (p->parent)->data.display_ll();
                p->right = nullptr;
          //      (p->parent)->data.display_ll();
            }
        }
        delete n;
    }

          //Case 2: One child
    else if(n->left == nullptr || n->right == nullptr){

        bstNode<keyType, dataType>* temp;
        if(p == nullptr){
            if(n->left != nullptr){temp = root = n->left;}
            else{temp = root = n->right;}
        }else{
            if(n == p->left){
                if(n->left != nullptr){temp = n->left;}
                else{temp = n->right;}
                if(p != nullptr){p->left = temp;}

            } else{
                if(n->left != nullptr){temp = n->left;}
                else{temp = n->right;}
                if(p != nullptr){p->right = temp;}
            }
        }
        temp->parent = p;
        delete n;
    }
        //Case 3: Two childs
    else{

        bstNode<keyType,dataType>* s = successor(n);
        keyType new_key = s->key;
        LL<dataType> new_data=s->data;
        new_data.display_ll();
        while (n->data.size()>0) {
          n->data.pop_back();
        }
        n->data.copy(new_data);
        p = remove_node(s->parent, s->key);
        n->key = new_key;

    }
    return p;
  }
  return nullptr;
}

/*===================================PUBLIC METHODS===================================*/
template<typename keyType, typename dataType>
LL<dataType> Map<keyType, dataType>::get(keyType key){
  if(find(key)==nullptr){
    std::cout << "ERROR: Key not in Map \n";
    std::exit(EXIT_FAILURE);
  }
  return find(key)->data;
}


#endif