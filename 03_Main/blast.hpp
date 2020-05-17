#ifndef _BLAST_
#define  _BLAST_

#include <iostream>
#include <string>
#include <stack>
#include "swa.hpp"

class Blast {
private:

    int HSSP = 3;



public:
    /*Constructors&Destructors*/
    Blast(std::stack<std::string> database, std::string query);
    ~Blast();

    /*Accessor Methods*/


    /*Modifier Methods*/


};


#endif /*_BLAST_*/
