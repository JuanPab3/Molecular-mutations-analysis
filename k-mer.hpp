#ifndef __K-MER_HPP__
#define __K-MER_HPP__

#include<iostream>
using namespace std;

struct Node{
  int pos;
  Node *next;
};

class Position_LL{
  private:
    Node *head;

  public:
    Position_LL();
    ~Position_LL();

    void clear();
    void push_back(int pos);
    bool find(int pos);

}

//Linked list that saves the k-mer, its postition and its key as a numerical
//representation

template<typename dataType>
struct Info{
    dataType k_mer;
    Position_LL position;
    int key;
    info *next;
};
template<typename dataType>
class LL{
private:

    int count;
    Info<dataType> *head;

public:
    LL();
    ~LL();

    void clear();
    void push_back(dataType data);
    void display_ll();
    Info<dataType>* find(dataType k_mer);
    Info<dataType>* pop_back();

    bool empty() const;

    int size() const;

    void MergeSort(Info<dataType>* head);
    void IterSplit(Info* head, Info** front, Info** back);
    void Merge(Info* head_list1, Info* head_list2);
  }

  for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
    do_things_with(*it);
