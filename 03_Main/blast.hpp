#ifndef _BLAST_
#define  _BLAST_

#include "binarytreeval.hpp"
#include "BST_arr.hpp"
#include "k-mer.hpp"
#include <iostream>
#include <fstream>
#include "swa.hpp"
#include "MAP.hpp"
#include <string>
#include <vector>
#include <stack>
#include <cmath>

/*
    ===========================================================,===========
     NADA TIENE TILDES, PUES ME DA MIEDO QUE DAÑE LA COMPILACION  \|°~°|/
    =======================================================================
*/


class Blast {
private:

    int HSSP = 3;

    std::vector<std::strings> permutaciones = permut("AGCT");
    std::vector<int> permutaciones_keys;
    Forest sistema_d_clasificasion;

public:
    /*Constructors&Destructors*/
    Blast(std::stack<std::string> database, std::string query);

};


#endif /*_BLAST_*/


/*============================================,===============================*/
/*=============================| IMPLEMENTACION |=============================*/
/*============================================================================*/

Blast::Blast(std::stack<std::string> database, std::string query) {

    /*Analizar todas las lineas geneticas dentro de la base de datos*/
    while (!database.empty()) {

        /*Tomar una cadena para empezar su analisis*/
        std::string element = database.top();
        database.pop();

        /*Comparar cada permutacion con el Query para así clasificar las que superan o igualan el HSSP*/
        for (int i = 0; i < permutaciones.size(); i++){
            ScoringMatrix temp_mat(permutaciones[i],query);
            if (temp_mat.points() >= HSSP) {
                permutaciones_keys.push_back(give_key(element));
            }
        }

        /*Inicio para determinar los K_mers aptos para la comparacion*/
        LL1<std::string> k_mers; /*Linked List*/
        /*
        Modifica LL1<std::string> k_mers para que contenga unas llaves que representan
        los kmers codificados junto con las posiciones donde estos se encuentran.
        */
        add_k_mers(database,k_mers);

        /*Creacion de arbol de comparacion*/
        MAP<int,int> comparison_Tree;
        while (!k_mers.empty()) {

            Info temp = k_mers.pop(); /*Un elemento descrito en k_mers.hpp*/

            while (!temp->position.empty()) {
                /*Agregando al arbol de comparacion cada elemento valido con su respectiva posicion individualmente*/
                comparison_Tree.push_back(temp->key,temp->position.top());
                temp->position.pop();
            }

            /*Inicio de comparacion entre llaves del Query con las llaves de database*/
            for (int i = 0; i < permutaciones_keys.size();i++){
                 bstNode<int,int> temp_treeP = comparison_Tree.find(permutaciones_keys[i]);
                if (temp_treeP != nullptr) {
                    while (!temp_treeP->data.empty()) {
                        temp_treeP->data.top();
                        ScoringMatrix mat(database,query)
                    }
                }
            }
        }
    }
}
