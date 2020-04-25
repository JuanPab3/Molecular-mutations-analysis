#ifndef _SWA_
#define  _SWA_

#include <iostream>
#include <string>
#include <stack>


class ScoringMatrix {
private:

    int penE = -1,  /*Penalización por Cuadro Vacio Estandar*/
        penD = -1,  /*Penalización por Desigualdad*/
        ganI =  1;  /*Ganancia por Igualdad */

    int M;  /*Cantidad de Filas*/
    int N;  /*Cantidad de Columnas*/

    /*Private Methods*/
    void maxVal (int** matrix, int i, int j, char iChar, char jChar); /*O(st.size())*/
    int intMax(std::stack<int> & st); /*O(st.size())*/
    int s (char & a,char & b); /*O(1)*/

public:
    int **matrix;
    /*Constructors&Destructors*/
    ScoringMatrix(std::string cd1, std::string cd2); /*O(M*N)*/
    ~ScoringMatrix(); /*O(N)*/

    /*Accessor Methods*/
    void show() const; /*O(M*N)*/

};




























#endif /*_SWA_*/
