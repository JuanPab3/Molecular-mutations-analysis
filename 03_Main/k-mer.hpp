#ifndef __K_MER_HPP__
#define __K_MER_HPP__

#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

//struct Node{
//  int pos;
//  Node *next;
//};
//
//class Position_LL{
//  private:
//    Node *head;
//    int count;
//
//  public:
//    Position_LL();
//    ~Position_LL();
//
//    void clear();
//    void push_back(int pos);
//    bool find(int pos);
//    void display();
//    int size() const;
//
//};

//Linked list that saves the k-mer, its postition and its key as a numerical
//representation

template<typename dataType>
struct Info{
    dataType k_mer;
    stack<int> position;
    int key;
    Info *next;
};
template<typename dataType>
class LL1{
private:

    int count;
    Info<dataType> *head;

public:
    LL1();
    ~LL1();

    void clear();
    void push_back(dataType k_mer, int position, int key);
    void display_ll();
    Info<dataType>* find(int key);
    Info<dataType> pop();
    //Info<dataType>* pop_back();

    bool empty() const;
    Info<dataType>** get_pointer_to_head(){return &head;};
    int size() const;

    void MergeSort(Info<dataType>** head);
    void IterSplit(Info<dataType>* head, Info<dataType>** front, Info<dataType>** back);
    Info<dataType>* Merge(Info<dataType>* head_list1, Info<dataType>* head_list2);
  };

  //======FUNCIONES INDEPENDIENTES PARA RECORRER DATABASE E INCLUIR  =====
  //================= LOS K-MERS A UNA LISTA LL1 =========================
int give_key(string k_mer){
  int key = 0;
  unsigned int size = k_mer.size();
  int exponente = size-1;
   for(std::string::iterator it = k_mer.begin(); it != k_mer.end(); ++it){
    if (*it == 'A')
      key += 0;
    else if (*it == 'C'){
      key += pow(4,exponente)*1;}
    else if (*it == 'G'){
      key += pow(4,exponente)*2;}
    else if (*it == 'T'){
        key += pow(4,exponente)*3;}
    else{
      std::cout << "ERROR: Invalid character °~°\n";
      std::exit(EXIT_FAILURE);
    }
    exponente--;
  }
    return key;
  }

std::string key_to_string(int key){
  int div = key;
  stack<int> potencias;
  string result;
  char ch;
  while (div>4){
    potencias.push(div%4);
    div = div/4;
  }
  potencias.push(div);
  while (!potencias.empty()){
      if (potencias.top() == 0)
        ch = 'A';
      else if (potencias.top() == 1)
        ch = 'C';
      else if (potencias.top() == 2)
        ch = 'G';
      else if (potencias.top() == 3)
        ch = 'T';
      result += ch;
      potencias.pop();
  }
  return result;
}

template <typename T>
void add_k_mers(string cadena, LL1<T> &list){
  int position = 0;
  for(std::string::iterator it = cadena.begin(); it != cadena.end()-2; ++it) {
    string k_mer="";
    char a= *it;
    char b = *(it+1);
    char c = *(it+2);
    k_mer+=a;
    k_mer+=b;
    k_mer+=c;
    int key = give_key(k_mer);
    //std::cout << "k-mer:" << k_mer << "pos:" << position << ", " << key << '\n';
    //list.empty();
    list.push_back(k_mer, position, key);
    position++;
    }
  }

  // stack<string> permutaciones (string cad){
  //   set <string> strset;
  //   set <char> set;
  //   stack <string> st;
  //   for(std::string::iterator it = cad.begin(); it != cad.end(); ++it){
  //     if (set.find(*it) == set.end())
  //      set.insert(*it);
  //   }
  //   for (std::string::iterator it = cad.begin(); it != cad.end(); ++it){
  //     string per (1,*it);
  //
  //       for (std::string::iterator it = cad.begin(); it != cad.end(); ++it){
  //         per += *it;
  //
  //         for (std::string::iterator it = cad.begin(); it != cad.end(); ++it){
  //           per += *it;
  //           //cout << per << endl;
  //           if (strset.find(per) == strset.end())
  //           strset.insert(per);
  //           per.pop_back();
  //         }
  //       per.pop_back();
  //       }
  //     per.pop_back();
  //   }
  //   for (std::set<string>::iterator it= strset.begin(); it != strset.end();++it)
  //     st.push(*it);
  //   return st;
  // }

  //===============Position_LL:PUBLIC METHODS ===================
  //Position_LL::Position_LL(){
  //    head=nullptr;
  //    count=0;
  //}

  //Position_LL::~Position_LL(){
  //    clear();
  //    head=nullptr;
  //    count=0;
  //}

  //void Position_LL::clear() {
  //    Node *temp;
  //    while (head != nullptr) {
  //        temp = head->next;
  //        delete head;
  //        head = temp;
  //    }
  //}

  //void Position_LL::push_back(int pos){
  //    if (count==0){
  //        Node *temp = new Node;
  //        temp->pos = pos;
  //        temp->next = nullptr;
  //        head = temp;
  //        count++;
  //    }
  //    else{ //Si hay algo en la lista
  //        Node *temp=head;
  //        while (temp->next!=nullptr){
  //            temp=temp->next;
  //        }
  //        //Cuando llegue al útimo elemento
  //        Node*new_node= new Node;
  //        new_node->pos=pos;
  //        new_node->next=nullptr;
  //        temp->next=new_node;
  //        count++;
  //    }
  //}

  //bool Position_LL::find(int pos){
  //  Node* temp = head;
  //  while (temp != nullptr){
  //    if (temp->pos == pos)
  //      return true;
  //    temp = temp->next;
  //  }
  //  return false;
  //}

  //void Position_LL::display(){
  //    Node*curr = head;
  //    std::cout << "HEAD(" << size() << ") -> ";
  //    while (curr != nullptr) {
  //        std::cout << curr->pos<< " -> ";
  //        curr = curr->next;
  //    }
  //    std::cout << "END \n";
  //}

  //int Position_LL::size() const{
  //  return count;
  //}
  ////===============LL: PUBLIC METHODS ===================

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
      //while (count>0) {
      //    pop_back();
      //}
      Info<dataType>* temp;
      while (head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
      }
  }

  template<typename dataType>
  void LL1<dataType>::push_back(dataType k_mer, int position, int key){
      if (count==0){
          Info<dataType>*temp = new Info<dataType>;
          temp->k_mer = k_mer;
          temp-> position.push(position);
          temp-> key = key;
          temp->next = nullptr;
          head = temp;
          count++;
      }
      else{ //Si hay algo en la lista
          if (find(key) != nullptr){ //Si el elemento está repetido
            Info<dataType>* element = find(key);
            std::cout << element->key << '\n';
            element->position.push(position);
          }
          else{
            Info<dataType>*temp=head;
            while (temp->next!=nullptr){
                temp=temp->next;
            }
            Info<dataType>*new_info= new Info<dataType>;
            new_info->k_mer = k_mer;
            new_info-> position.push(position);
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
          std::cout << "K-mer:"<< curr->k_mer << " , ";
          stack <int> tempo;
          std::cout << "Position:";
          tempo = curr->position;
          while (!tempo.empty()){
            std::cout << tempo.top() << ", ";
            tempo.pop();
          }
          //curr->position.display();
          std::cout << "Key:"<< curr->key << " -> ";
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
      if (it->key==key){
        return it;
      }
      it = it->next;
    }

    return nullptr;
  }

  template<typename dataType>
  Info<dataType> LL1<dataType>::pop(){
    if (head==nullptr){
      std::cout << "ERROR: List is empty °~°\n";
      std::exit(EXIT_FAILURE);
      }
    else{
      Info<dataType>* temp = head;
      head = head->next;

      return *temp;
    }
  }


  template <typename dataType>
  void LL1<dataType>::MergeSort(Info<dataType>** pointer_to_head){
    Info<dataType>* head = *pointer_to_head;
    Info<dataType>* head_list1;
    Info<dataType>* head_list2;

    if ((head == nullptr) || (head->next == nullptr))
      return;

    IterSplit(head,&head_list1, &head_list2);

    MergeSort(&head_list1);
    std::cout << "Llegué" << '\n';
    MergeSort(&head_list2);

    *pointer_to_head = Merge(head_list1, head_list2);
  }

  template <typename dataType>
  void LL1<dataType>::IterSplit(Info<dataType>* head, Info<dataType>** front, Info<dataType>** back){
    Info<dataType>* fast;
    Info<dataType>* slow;
    slow = head;
    fast = head->next;

    while (fast != nullptr){
      fast = fast->next;
      if (fast!= nullptr){
        slow = slow->next;
        fast = fast->next;
      }
      *front = head;
      *back = slow->next;
      slow->next = nullptr;
    }
  }

  template <typename dataType>
  Info<dataType>* LL1<dataType>::Merge(Info<dataType>* head_list1, Info<dataType>* head_list2){
    Info<dataType>* result= nullptr;
    if (head_list1 == nullptr)
          return (head_list2);
      else if (head_list2 == nullptr)
          return (head_list1);

    if (head_list1->key <= head_list2->key) {
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
