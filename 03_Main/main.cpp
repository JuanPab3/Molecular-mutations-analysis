#include <fstream>
#include <string>
#include <cmath>
#include "binarytreeval.hpp"
#include "BST_arr.hpp"
#include "k-mer.hpp"
#include "swa.hpp"
#include "MAP.hpp"

#include <iostream>
#include <stack>

using namespace std;



int main() {

    stack <string> DATABASE;



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
            DATABASE.insert(database);
        } else {
            std::cerr << "/* UPSSSS hay un error con el txt  \|°~°|/ */" << endl;
        }

    } databaseTXT.close();







    ScoringMatrix mat(database,query);
    // mat.show();
    // mat.show_value_box();
    // mat.show_string_box();
    cout << "Points: " <<mat.points() << "\n";


    return 0;
}
