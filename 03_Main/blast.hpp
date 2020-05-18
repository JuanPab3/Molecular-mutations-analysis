#ifndef _BLAST_
#define  _BLAST_

#include "binarytreeval.hpp"
#include "BST_arr.hpp"
#include "k-mer.hpp"
#include <iostream>
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

    std::vector<std::string> permutaciones = {"ACT","AGT","GTA","GAC"}/*permut("AGCT")*/;
    std::vector<int> permutaciones_keys;
    Forest sistema_d_clasificasion;

public:
    /*Constructors&Destructors*/
    Blast(std::stack<std::string> database, std::string query);

    void display_one(int & num) const;
};


#endif /*_BLAST_*/


/*============================================,===============================*/
/*=============================| IMPLEMENTACION |=============================*/
/*============================================================================*/

Blast::Blast(std::stack<std::string> database, std::string query) {
    /*Analizar todas las lineas geneticas dentro de la base de datos*/
    while (!database.empty()) {

        float total_points = 0;

        /*Tomar una cadena para empezar su analisis*/
        std::string element = database.top();
        float max_size = element.size()*3;
        database.pop();

        /*Comparar cada permutacion con el Query para así clasificar las que superan o igualan el HSSP*/
        int sz1 = permutaciones.size();
        for (int i = 0; i < sz1; i++){
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
        std::cout << "element: " << element << '\n';
        std::cout << "k_mers size: " << k_mers.size() << '\n';
        // std::cout << "WORKING: " << /*key_to_string(value)*/"LOL" << '\n';
        add_k_mers(element,k_mers);

        // k_mers.display_ll();
        /*Creacion de arbol de comparacion*/
        Map<int,int> comparison_Tree;
        while (!k_mers.empty()) {

            Info<std::string> temp = k_mers.pop(); /*Un elemento descrito en k_mers.hpp*/

            while (!temp.position.empty()) {
                /*Agregando al arbol de comparacion cada elemento valido con su respectiva posicion individualmente*/
                comparison_Tree.insert(temp.key,temp.position.top());
                temp.position.pop();
            }

            /*Inicio de comparacion entre llaves del Query con las llaves de database*/
            int sz2 = permutaciones_keys.size();

            for (int i = 0; i < sz2;i++){

                /*Buscar coincidencias entre las permutaciones validas (entre AGTC) con los k_mers*/
                bstNode<int,int> *temp_treeP = comparison_Tree.find(permutaciones_keys[i]);


                if (temp_treeP != nullptr) {
                    while (!temp_treeP->data.empty()) {
                        int value = temp_treeP->data.top();
                        temp_treeP->data.pop();

                        /*Watermelon algorithm applied*/
                        int val = permutaciones_keys[i];


                        std::string pki = key_to_string(val);
                        ScoringMatrix mat(key_to_string(value),pki);
                        total_points += mat.points();
                    }
                }
            }
            float porcent = (total_points * 100.0)/max_size;
            sistema_d_clasificasion.insert(porcent, element);
        }
    }
}


void Blast::display_one(int & num) const {
    sistema_d_clasificasion.tree_display(num);
}
