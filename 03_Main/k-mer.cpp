#ifdef __K_MER_HPP__
//===============Position_LL:PUBLIC METHODS ===================
Position_LL::Position_LL(){
    head=nullptr;
    count=0;
}

Position_LL::~Position_LL(){
    clear();
    head=nullptr;
    count=0;
}

void Position_LL::clear() {
    Node *temp;
    while (head->next != nullptr) {
        temp = head->next;
        delete head;
        head = temp;
    }
    delete head;
}

void Position_LL::push_back(int pos){
    if (count==0){
        Node *temp = new Node;
        temp->pos = pos;
        temp->next = nullptr;
        head = temp;
        count++;
    }
    else{ //Si hay algo en la lista
        Node *temp=head;
        while (temp->next!=nullptr){
            temp=temp->next;
        }
        //Cuando llegue al útimo elemento
        Node*new_node= new Node;
        new_node->pos=pos;
        new_node->next=nullptr;
        temp->next=new_node;
        count++;
    }
}

bool Position_LL::find(int pos){
  Node* temp = head;
  while (temp != nullptr){
    if (temp->pos == pos)
      return true;
    temp = temp->next;
  }
  return false;
}
//===============LL: PUBLIC METHODS ===================

//Constructor
template<typename dataType>
LL1<dataType>::LL1(){
    head=nullptr;
    count=0;
}

//Destructor
template<typename dataType>
LL1<dataType>::~LL1(){
    clear();
    head=nullptr;
    count=0;
}

template<typename dataType>
void LL1<dataType>::clear() {
    while (count>0) {
        pop_back();
    }
}

template<typename dataType>
void LL1<dataType>::push_back(dataType k_mer, int position, int key){
    if (count==0){
        Info<dataType>*temp = new Info<dataType>;
        temp->k_mer = k_mer;
        Position_LL pos;
        pos.push_back(position);
        temp-> position = pos;
        temp-> key = key;
        temp->next = nullptr;
        head = temp;
        count++;
    }
    else{ //Si hay algo en la lista
        if (find(key) != nullptr){ //Si el elemento está repetido
          Info<dataType>* element = find(key);
          element->position.push_back(position);
        }
        else{
          Info<dataType>*temp=head;
          while (temp->next!=nullptr){
              temp=temp->next;
          }
          Info<dataType>*new_info= new Info<dataType>;
          new_info->k_mer = k_mer;
          Position_LL pos;
          pos.push_back(position);
          new_info-> position = pos;
          new_info-> key = key;
          new_info->next=nullptr;
          temp->next=new_info;
          count++;
      }
    }
}

template<typename dataType>
void LL1<dataType>::display_ll(){
    Info<dataType>*curr = head;
    std::cout << "HEAD(" << size() << ") -> ";
    while (curr != nullptr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "END \n";
}

template<typename dataType>
bool LL1<dataType>::empty() const{
    return count==0;
}

template<typename dataType>
int LL1<dataType>::size() const{
    return count;
}

template<typename dataType>
Info<dataType>* LL1<dataType>::find(int key){
  Info<dataType>* it= head;
  while (it!=nullptr){
    if (it->key==key)
      return it;
    it = it->next;
  }
  return nullptr;
}

template<typename dataType>
Info<dataType>* LL1<dataType>::pop_back(){
    if (head==nullptr){
        return nullptr;
    }
    Info<dataType>*temp=head, *temp2=head, *retorno;

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

template <typename dataType>
void LL1<dataType>::MergeSort(Info<dataType>* head){
  Node* head_list1;
  Node* head_list2;

  if (count > 2)
    return;

  IterSplit(head,&head_list1, &head_list2);

  MergeSort(&head_list1);
  MergeSort(&head_list2);

  *head = Merge(head_list1, head_list2);
}

template <typename dataType>
void LL1<dataType>::IterSplit(Info<dataType>* head, Info<dataType>** front, Info<dataType>** back){
  Node* fast;
  Node* slow;
  slow = head;
  fast = head->next;

  while (fast != nullptr){
    fast = fast->next;
    if (fast!= nullptr){
      slow = slow->next;
      fast = fast->next;
    }
    slow = slow->next;
    *front = head;
    *back = slow;
    slow= nullptr;
  }
}

template <typename dataType>
Info<dataType>* LL1<dataType>::Merge(Info<dataType>* head_list1, Info<dataType>* head_list2){
  Info<dataType>* result= nullptr;
  if (head_list1 == nullptr)
        return (head_list2);
    else if (head_list2 == nullptr)
        return (head_list1);

  if (head_list1->data <= head_list2->data) {
        result = head_list1;
        result->next = Merge(head_list1->next, head_list2);
    }
  else{
    result = head_list2;
    result->next = Merge(head_list1, head_list2->next);
  }
  return result;
}

#endif
