#include "blast.hpp"
#include <iostream>
#include <stack>


using namespace std;



int main() {

    stack <string> DATABASE;

    ifstream queryTXT("query.txt"),databaseTXT("database.txt");
    string query;
    string database;

    if (queryTXT.good()) {
        queryTXT >> query;
    } else {
      cerr << "/* UPSSSS hay un error con el txt \|°~°|/ */" << endl;
    }
    queryTXT.close();

    while (!databaseTXT.otf()) {
        if (databaseTXT.good()) {
            databaseTXT >> database;
            DATABASE.insert(database);
        } else {
            cerr << "/* UPSSSS hay un error con el txt  \|°~°|/ */" << endl;
        }
    } databaseTXT.close();

    Blast blast(DATABASE,query);




    return 0;
}
