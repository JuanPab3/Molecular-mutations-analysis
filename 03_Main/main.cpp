#include <iostream>
#include <string>
#include "swa.hpp"

using namespace std;



int main() {

    // string a = "TGTTACGG";
    // string b = "GGTTGACTA";

    string a = "ACCGTGA";
    string b = "GTGAATA";


    ScoringMatrix mat(a,b);
    mat.show();
    mat.show_value_box();
    mat.show_string_box();

    return 0;
}
