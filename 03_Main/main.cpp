#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "binarytreeval.hpp"
#include "BST_arr.hpp"
#include "swa.hpp"
#include "k-mer.cpp"

using namespace std;



int main() {

    Forest storage;

    storage.insert(15.5,"ESTEFANIA");
    storage.insert(15.4,"JUAN LUIS");
    storage.insert(15.4,"JUAN LUIS2");
    storage.insert(0.5,"JUAN PABLO");
    storage.insert(15.6,"DANIEL");
    //
    storage.insert(20.5,"ANDRES");
    storage.insert(17.5,"MARIAN0");
    storage.insert(18.5,"NICOLASA");
    //
    // storage.insert(68.5,"ABCD");
    // storage.insert(57.5,"AXDF");
    // storage.insert(64.5,"HPJ");


    storage.full_display();

    // ifstream queryTXT("query.txt"),databaseTXT("database.txt");
    // string query;
    // string database;
    //
    // if (queryTXT.good()) {
    //     queryTXT >> query;
    // } else {
    //   cerr << "/* UPSSSS hay un error con el txt */" << endl;
    // }
    // queryTXT.close();
    //
    // if (databaseTXT.good()) {
    //     databaseTXT >> database;
    // } else {
    //   cerr << "/* UPSSSS hay un error con el txt */" << endl;
    // }
    // databaseTXT.close();
    //
    //
    // ScoringMatrix mat(database,query);
    // // mat.show();
    // // mat.show_value_box();
    // // mat.show_string_box();
    // cout << "Points: " <<mat.points() << "\n";


    return 0;
}
