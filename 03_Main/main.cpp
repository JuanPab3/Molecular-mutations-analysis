#include "blast.hpp"
#include <iostream>
#include <fstream>
#include <stack>


using namespace std;



int main() {

    stack <string> DATABASE;

    ifstream queryTXT("00_query.txt"),databaseTXT("00_database.txt");
    string query;
    string database;



    if (queryTXT.good()) {
        while (true) {
              queryTXT >> query;
              if (queryTXT.eof()) break;
          }
      } else {
          cerr << "/* UPSSSS hay un error con el query.txt  °~° */" << endl;
      }
      queryTXT.close();



    if (databaseTXT.good()) {
      while (!databaseTXT.eof()) {
            databaseTXT >> database;
            DATABASE.push(database);
        }
    } else {
        cerr << "/* UPSSSS hay un error con el database.txt  °~° */" << endl;
    }
    databaseTXT.close();

    Blast blast(DATABASE,query);
    for (int i = 0; i < 10; i++)
        blast.display_one(i);



    return 0;
}
