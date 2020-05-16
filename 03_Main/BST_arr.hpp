#ifndef _BST_ARR_
#define  _BST_ARR_

#include "binarytreeval.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>


class Forest {
private:

    BST *forest = new BST[10];
    int sz = 0;


public:
    /*Constructors&Destructors*/
    Forest();
    // ~Forest();

    /*Accessor Methods*/
    std::vector<std::string> find_porcent(float porcent) const;
    void full_display() const;
    void tree_display(int & index) const;
    bool empty() const;
    int size() const;


    /*Modifier Methods*/
    void insert(float porcent, std::string code);

    BST operator[](int index);


};

BST Forest::operator[](int index) {
    if (index < 0 or index >= 10) { throw std::runtime_error("OOOOPS! El valor ingresado no es valido °_° "); }
    for (int i = 0; i < index;i++){
        forest++;
    }
    return *forest;
}
/*======================CONSTRUCTORS_&_DESTRUCTOR======================*/

Forest::Forest() {
    for (int i = 0; i<10;i++){
        BST new_BST;
        forest[i] = new_BST;
    }
}

// Forest::~Forest() {
//     for (int i = 0; i<10;i++){
//         std::cout << forest[i].size() << " DESTROY IS WORKING" << '\n';
//         (*forest).clear();
//         forest++;
//     }
//     sz = 0;
//     delete[] forest;
// }
/*==========================ACCESSOR_METHODS===========================*/

std::vector<std::string> Forest::find_porcent(float  porcent) const {
    int index = porcent/10;
    BST temp = forest[index];
    return temp.get(porcent);
}

void Forest::full_display() const {
    for (int index = 0; index < 10; index++) {
        BST temp = forest[index];
        if (temp.size() != 0){
            std::cout << "\nDESDE " << index*10 << "%, HASTA " << (index+1)*10 << "%" << std::endl;
            temp.display();
        }
    }
}

void Forest::tree_display(int & index) const {
    if (index < 0 or index >= 10) { throw std::runtime_error("OOOOPS! El valor ingresado no es valido °_° "); }
    BST temp = forest[index];
    std::cout << "\nDESDE " << index*10 << "% , HASTA " << (index+1)*10 << "%" << std::endl;
    temp.display();

}

bool Forest::empty() const {
    return sz == 0;
}

int Forest::size() const {
    return sz;
}

/*==========================MODIFIER_METHODS===========================*/
void Forest::insert(float porcent, std::string code) {
    int index = porcent/10;
    sz++;

    forest[index].insert(porcent,code);
}

/*=====================================================================*/




#endif /*_BST_ARR_*/
