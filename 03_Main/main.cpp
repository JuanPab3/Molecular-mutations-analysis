#include <iostream>
#include <fstream>
#include <std::string>
#include <vector>
#include <cmath>
#include "binarytreeval.hpp"
#include "BST_arr.hpp"
#include "k-mer.hpp"
#include "swa.hpp"
#include "MAP.hpp"

using namespace std;



int main() {

    int HSSP = 3;
    std::vector<std::strings> permutaciones = permut("AGCT");
    std::vector<int> permutaciones_keys;

    ifstream queryTXT("query.txt"),databaseTXT("database.txt");
    std::string query;
    std::string database;

    if (queryTXT.good()) {
        queryTXT >> query;
    } else {
      std::cerr << "/* UPSSSS hay un error con el txt \|°~°|/ */" << endl;
    }
    queryTXT.close();

    while (!databaseTXT.otf()) {
        if (databaseTXT.good()) {
            databaseTXT >> database;
        } else {
            std::cerr << "/* UPSSSS hay un error con el txt  \|°~°|/ */" << endl;
        }

        for (std::string element: permutaciones) {
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







    } databaseTXT.close();







    ScoringMatrix mat(database,query);
    // mat.show();
    // mat.show_value_box();
    // mat.show_string_box();
    cout << "Points: " <<mat.points() << "\n";


    return 0;
}
