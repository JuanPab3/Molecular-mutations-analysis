#include <iostream>
#include <fstream>
#include <string>
#include "swa.hpp"

using namespace std;



int main() {


    ifstream queryTXT("query.txt"),databaseTXT("database.txt");
    string query;
    string database;

    if (queryTXT.good()) {
        queryTXT >> query;
    } else {
      cerr << "/* UPSSSS hay un error con el txt */" << endl;
    }
    queryTXT.close();

    if (databaseTXT.good()) {
        databaseTXT >> database;
    } else {
      cerr << "/* UPSSSS hay un error con el txt */" << endl;
    }
    databaseTXT.close();


    ScoringMatrix mat(database,query);
    // mat.show();
    // mat.show_value_box();
    // mat.show_string_box();
    cout << "Points: " <<mat.points() << "\n";
    return 0;
}
