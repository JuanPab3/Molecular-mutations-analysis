#include <iostream>
#include <string>
#include "swa.hpp"

using namespace std;



int main() {

    string a = "ACCGTGA";
    string b = "GTGAATA";

    ScoringMatrix mat(a,b);

    mat.show();

    return 0;
}
