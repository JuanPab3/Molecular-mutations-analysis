#ifndef __K_MER_HPP__
#define __K_MER_HPP__

#include<iostream>
using namespace std;

struct Node{
  int pos;
  Node *next;
};

class Position_LL{
  private:
    Node *head;
    int count;

  public:
    Position_LL();
    ~Position_LL();

    void clear();
    void push_back(int pos);
    bool find(int pos);
    void display();
    int size() const;

};

//Linked list that saves the k-mer, its postition and its key as a numerical
//representation

template<typename dataType>
struct Info{
    dataType k_mer;
    Position_LL position;
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
    //Info<dataType>* pop_back();

    bool empty() const;
    Info<dataType>** get_pointer_to_head(){return &head;};
    int size() const;

    void MergeSort(Info<dataType>** head);
    void IterSplit(Info<dataType>* head, Info<dataType>** front, Info<dataType>** back);
    Info<dataType>* Merge(Info<dataType>* head_list1, Info<dataType>* head_list2);
  };
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
      std::cout << "ERROR: Invalid character \n";
      std::exit(EXIT_FAILURE);
    }
    exponente--;
  }
    return key;
  }

template <typename T>
void add_k_mers(string cadena, LL1<T> list){
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
    std::cout << k_mer << " , " << key << '\n';
    //list.empty();
    list.push_back(k_mer, position, key);
    list.size();
    position++;
    }
  }

#include "k-mer.cpp"
#endif
