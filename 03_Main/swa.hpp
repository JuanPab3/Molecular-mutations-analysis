#ifndef _SW_A_ /*Smith–Waterman Algorithm*/
#define  _SW_A_

#include <iostream>
#include <string>
#include <stack>


class ScoringMatrix {
private:
    /*Class Structs*/
    struct ValBox { /*Contenedor para los valores importantes en matrix*/
        int ival;
        int jval;
    };

    ValBox create_val_box(int i, int j);

    struct AlignedCode {
        std::string codeA = "";
        std::string codeB = "";
    };

    /*Private Containers*/
    std::stack<ValBox> ValueBox;
    std::stack<AlignedCode> StringBox;


    int max  =  0;  /*Es el numero con el valor más alto dentro de toda la tabla*/
    int penE = -1,  /*Penalización por Cuadro Vacio Estandar*/
        penD = -3,  /*Penalización por Desigualdad*/
        ganI =  3;  /*Ganancia por Igualdad */

    std::string codeString1;
    std::string codeString2;
    int **matrix;
    int N;  /*Cantidad de Columnas*/
    int M;  /*Cantidad de Filas*/

    /*Private Methods*/
    void max_val (int** matrix, int i, int j, char iChar, char jChar); /*O(st.size())*/
    int int_max(std::stack<int> & st); /*O(st.size())*/
    int s (char & a,char & b); /*O(1)*/

    void valBox_to_string(ScoringMatrix::AlignedCode & alig,  int i, int j);
    void string_to_box(std::stack<ValBox> ValueBox);

public:
    /*Constructors&Destructors*/
    ScoringMatrix(std::string cd1, std::string cd2); /*O(M*N)*/
    ~ScoringMatrix(); /*O(N)*/

    /*Accessor Methods*/ /*Estas funciones estan para comprobar los resultados*/
    void show_value_box () const;
    void show_string_box () const;
    int points () const;
    void show () const; /*O(M*N)*/ /*Representa a ScoringMatrix como una matriz*/


};


#endif /*_SW_A_*/
