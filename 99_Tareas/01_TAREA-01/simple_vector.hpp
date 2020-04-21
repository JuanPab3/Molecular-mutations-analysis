#ifndef __SIMPLE_VECTOR_HPP
#define __SIMPLE_VECTOR_HPP

#include <iostream>
using namespace std;

const int INITIAL_CAPACITY = 10;

// define a bidirectional iterator structure for doubles
// this class is basically a wrapper for a pointer ptr
class BidirIterator {
private:
    /*Class properties*/
    double *ptr;

public:
    /*Constructors & Destructor*/
    BidirIterator();// { ptr = nullptr; }      /* default constructor */
    BidirIterator(double *beg);             /* constructor */
    BidirIterator(const BidirIterator& it); /* copy constructor */
    ~BidirIterator();                       /* destructor */


    /*Class operators*/
    double & operator* (); // dereference operator

    BidirIterator & operator++();  /* ++it (prefix ++ operator)*/
    BidirIterator operator++(int); /* it++ (postfix ++ operator)*/
    BidirIterator & operator--();  /* --it (prefix -- operator) */
    BidirIterator operator--(int); /* it-- (postfix -- operator)*/

    void operator=(const BidirIterator it);     /* assignment const operator*/

    bool operator==(const BidirIterator it) const;     /* comparison operators*/
    bool operator!=(const BidirIterator it) const;    /* comparison operators*/

};


class SimpleVec {
private:
    /*Class properties*/
    double *array;
    int capacity, length;

    /*Private Methods*/
    void expandCapacity();

public:
    /*Iterator Related Methods*/
    // typedef BidirIterator iterator;
    // iterator begin();
    // iterator end();

    /*Constructors & Destructor*/
    SimpleVec();
    SimpleVec(const SimpleVec& rhs);
    ~SimpleVec();

    /*Modifier Methods*/
    void insert(int index, double value);
    void modify(int index, double value);
    void push(double value);
    void erase(int index);
    void clear();

    /*Accessor Methods*/
    double retrieve(int index);
    bool empty();
    int size();

    /*Class Operators*/
    SimpleVec & operator=(const SimpleVec &rhs);

};

#endif
