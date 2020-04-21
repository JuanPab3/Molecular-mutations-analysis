#include "simple_vector.hpp"

/*
    B I D I R I T E R A T O R   C L A S S
*/


/*===============BidirIterator_CONSTRUCTORS_&_DESTRUCTOR===============*/
BidirIterator::BidirIterator() {
    ptr = nullptr;
}

BidirIterator::BidirIterator(double *beg) {
    ptr = beg;
}

BidirIterator::BidirIterator(const BidirIterator& it) {
    *this = it;
}

BidirIterator::~BidirIterator() {
    delete ptr;
    ptr = nullptr;
}
/*====================BidirIterator_CLASS_OPERATORS====================*/
double & BidirIterator::operator*() {
    double *doub = ptr;
    return *doub;
}


BidirIterator & BidirIterator::operator++() {
    ptr = ptr + 1;
    std::cout << "lol" << std::endl;
    return *this;
}

BidirIterator BidirIterator::operator++(int) {
    BidirIterator temp = ptr;
    ptr = ptr + 1;
    return temp;
}

BidirIterator & BidirIterator::operator--() {
    ptr = ptr - 1;
    return *this;
}

BidirIterator BidirIterator::operator--(int) {
    BidirIterator temp = ptr;
    ptr = ptr - 1;
    return temp;
}


void BidirIterator::operator=(const BidirIterator it) {
    *this = it;
}

bool BidirIterator::operator==(const BidirIterator it) const{
    return *this == it;
}

bool BidirIterator::operator!=(const BidirIterator it) const{
        return *this != it;
}
/*=====================================================================*/

/*
    S I M P L E V E C   C L A S S
*/

/*======================SimpleVec_PRIVATE_METHODS=====================*/
void SimpleVec::expandCapacity() {
    double *oldArray = array;
    capacity *= 2;
    array = new double[capacity];
    for(int i = 0; i < length; ++i)
        array[i] = oldArray[i];
    delete[] oldArray;
}
/*=================SimpleVec_ITERATOR_RELATED_METHODS=================*/
// typedef BidirIterator iterator;
// iterator SimpleVec::begin(){
//     BidirIterator tmp;
//     tmp = array;
//     return tmp;
// }
//
// typedef BidirIterator iterator;
// iterator SimpleVec::end(){
//
// }
/*================SimpleVec_CONSTRUCTORS_&_DESTRUCTOR=================*/
SimpleVec::SimpleVec() : capacity(INITIAL_CAPACITY), length(0) {
    array = new double[capacity];
 }

SimpleVec::SimpleVec(const SimpleVec& rhs) {
    capacity = rhs.capacity;
    length = rhs.length;
    array = new double[capacity];
    for(int i = 0; i < length; ++i)
        array[i] = rhs.array[i];
}

SimpleVec::~SimpleVec() {
    delete[] array;
}
/*=====================SimpleVec_MODIFIER_METHODS=====================*/
void SimpleVec::insert(int index, double value) {
    if(length == capacity) expandCapacity();
        for(int i = length-1; i > index; --i)
        array[i] = array[i-1];
        array[index] = value;
    length++;
}

void SimpleVec::modify(int index, double value) {
    array[index] = value;
}

void SimpleVec::push(double value) {
    if(length == capacity) expandCapacity();
    array[length++] = value;
}

void SimpleVec::erase(int index) {
    for(int i = index; i < length-1; ++i)
        array[i] = array[i+1];
    length--;
}

void SimpleVec::clear() {
    length = 0;
}
/*=====================SimpleVec_ACCESSOR_METHODS=====================*/
double SimpleVec::retrieve(int index) {
    return array[index];
}

bool SimpleVec::empty() {
    return length == 0;
}

int SimpleVec::size() {
    return length;
}
/*=====================SimpleVec_CLASS_OPERATORS======================*/
SimpleVec & SimpleVec::operator=(const SimpleVec& rhs) {
    delete[] array;
    capacity = rhs.capacity;
    length = rhs.length;
    array = new double[capacity];
    for(int i = 0; i < length; ++i)
        array[i] = rhs.array[i];

    return *this;
}
/*=====================================================================*/
