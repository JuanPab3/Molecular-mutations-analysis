#ifndef _BLAST_
#define  _BLAST_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "binarytreeval.hpp"
#include "BST_arr.hpp"
#include "k-mer.hpp"
#include "swa.hpp"
#include "MAP.hpp"

class Blast {
private:

    int HSSP = 3;



public:
    /*Constructors&Destructors*/
    Blast(std::stack<std::string> database, std::string query);

    /*Accessor Methods*/


    /*Modifier Methods*/


};


#endif /*_BLAST_*/


/*============================================================================*/
/*=============================| IMPLEMENTACIÓN |=============================*/
/*============================================================================*/

Blast::Blast(std::stack<std::string> database, std::string query) {

    while (!database.empty()) {
        std::string element = database.top();
        database.pop();
        ScoringMatrix temp_mat(element,query);
        if (temp_mat.points() >= HSSP) {
            permutaciones_keys.push_back(give_key(element));
        }
    }

    LL1<std::string> k_mers; /*Linked List*/

    add_k_mers(database,k_mers);

    MAP<int,int> comparison_Tree;

    while (!k_mers.empty()) {

        Info temp = k_mers.pop();

        while (!temp->position.empty()) {
            comparison_Tree.push_back(temp->key,temp->position.top());
            temp->position.pop();
        }

        for (int i: permutaciones_keys){
             bstNode<int,int> temp_treeP = comparison_Tree.find(i);
            if (temp_treeP != nullptr) {
                while (!temp_treeP->data.empty()) {

                    ScoringMatrix mat(database,query)
                }

            }
        }
    }
}
