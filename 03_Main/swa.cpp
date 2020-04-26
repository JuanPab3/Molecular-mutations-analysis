#include "swa.hpp"

/*===========================PRIVATE_METHODS===========================*/
ScoringMatrix::ValBox ScoringMatrix::create_val_box(int i, int j){
    ValBox tempvalbox;
    tempvalbox.ival = i;
    tempvalbox.jval = j;
    return tempvalbox;
}


void ScoringMatrix::max_val (int** matrix, int i, int j, char iChar, char jChar){
    std::stack<int> tempST;
    tempST.push(matrix[i-1][j-1] + s(iChar,jChar));
    tempST.push(matrix[i][j-1] + penE);
    tempST.push(matrix[i-1][j] + penE);
    tempST.push(0);

    matrix[i][j] = int_max(tempST);

}

int ScoringMatrix::int_max (std::stack<int> & st) {

    int max = st.top();
    st.pop();

    while (!st.empty()) {
        if (st.top() > max)
            max = st.top();
        st.pop();
    }

    return max;
}

int ScoringMatrix::s (char & a,char & b) {
    int tempVal;
    if (a == b) {
        tempVal = ganI;
    } else {
        tempVal = penD;
    }
    return tempVal;
}


void ScoringMatrix::valBox_to_string(ScoringMatrix::AlignedCode & alig,  int i, int j){
    // std::cout << "A: " << codeString1 << alig.codeA << '\n';
    // std::cout << "B: " << codeString2 << alig.codeB << '\n'<< '\n';
    int diagonal = matrix[i-1][j-1],
        arriba = matrix[i][j-1],
        lado = matrix[i-1][j],
        actual = matrix[i][j];

    std::cout << "Actual:   " << actual << '\n';
    std::cout << "Diagonal: " << diagonal << '\n';
    std::cout << "Arriba:   " << arriba << '\n';
    std::cout << "Al Lado:  " << lado << '\n';

    if (diagonal == 0 or arriba == 0 or lado == 0) {
        std::cout << "BASE" << '\n';
        std::cout << j <<": " << codeString1[j-1] << '\n';
        std::cout << i <<": " << codeString2[i-1] << '\n';
        std::cout << j-1 <<": " << codeString1[j-2] << '\n';
        std::cout << i-1 <<": " << codeString2[i-2] << '\n'<< '\n';
        if (codeString1[j-1] == codeString2[i-1]) {
            alig.codeA = codeString1[j-1] + alig.codeA;
            alig.codeB = codeString2[i-1] + alig.codeB;
        } else {
            alig.codeB = "@" + alig.codeB;
            alig.codeA = "@" + alig.codeA;
        }
    } else {
        if (diagonal >= arriba and diagonal >= lado ){
            std::cout << "DIAGONAL" << '\n';
            std::cout << j <<": " << codeString1[j-1] << '\n';
            std::cout << i <<": " << codeString2[i-1] << '\n';
            std::cout << j-1 <<": " << codeString1[j-2] << '\n';
            std::cout << i-1 <<": " << codeString2[i-2] << '\n'<< '\n';
            alig.codeA = codeString1[j-1] + alig.codeA;
            alig.codeB = codeString2[i-1] + alig.codeB;

            valBox_to_string(alig,i-1,j-1);
        } else if (lado > diagonal and lado > arriba and codeString1[j-1] != codeString2[i-1]) {
            std::cout << "AL  LADO" << '\n';
            std::cout << j <<": " << codeString1[j-1] << '\n';
            std::cout << i <<": " << codeString2[i-1] << '\n';
            std::cout << j-1 <<": " << codeString1[j-2] << '\n';
            std::cout << i-1 <<": " << codeString2[i-2] << '\n'<< '\n';
            alig.codeA = "@"+ alig.codeA;
            alig.codeB = codeString2[i-1] + alig.codeB;

            valBox_to_string(alig,i-1,j);
        } else if (arriba > diagonal and arriba > lado and codeString1[j-1] != codeString2[i-1]) {
            std::cout << "ARRIBA" << '\n';
            std::cout << j <<": " << codeString1[j-1] << '\n';
            std::cout << i <<": " << codeString2[i-1] << '\n';
            std::cout << j-1 <<": " << codeString1[j-2] << '\n';
            std::cout << i-1 <<": " << codeString2[i-2] << '\n'<< '\n';
            alig.codeA = codeString1[j-1] + alig.codeA;
            alig.codeB = "@" + alig.codeB;

            valBox_to_string(alig,i,j-1);
        }
    }
}

void ScoringMatrix::string_to_box(std::stack<ScoringMatrix::ValBox> ValueBox) {
        std::stack<ScoringMatrix::ValBox> tempVal(ValueBox);
        while (!tempVal.empty()) {
            ScoringMatrix::AlignedCode alig;
            int i = tempVal.top().ival;
            int j = tempVal.top().jval;

            valBox_to_string(alig,i,j);
            StringBox.push(alig);
            // std::cout << StringBox.size() << '\n';
            tempVal.pop();
    }
}

/*======================CONSTRUCTORS_&_DESTRUCTOR======================*/
ScoringMatrix::ScoringMatrix (std::string cd1, std::string cd2) {
    codeString1 = cd1;
    codeString2 = cd2;
    M = codeString1.size() + 1;
    N = codeString2.size() + 1;
    matrix = new int*[N];

    for (int i = 0; i < N; i++) {
        matrix[i] = new int[M];
        char iChar = codeString2[i-1];

        for (int j = 0; j < M; j++){
            if (i == 0 or j == 0) {
                matrix[i][j] = 0;

            } else {
                char jChar = codeString1[j-1];
                max_val(matrix, i, j, iChar, jChar);

                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                    while (!ValueBox.empty()) {
                        ValueBox.pop();
                    }
                }
                if (matrix[i][j] >= max) {
                    ValueBox.push(create_val_box(i,j));
                }
            }
        }
    }
    string_to_box(ValueBox);
}

ScoringMatrix::~ScoringMatrix () {
    for (int i = 0; i < N; i++)
        delete[] matrix[i];

    M = 0;
    N = 0;
    delete[] matrix;
    matrix = nullptr;
}

/*==========================ACCESSOR_METHODS==========================*/
void ScoringMatrix::show_value_box () const {
    std::stack<ValBox> tempBox(ValueBox);
    while (!tempBox.empty()) {
        std::cout << "max val: " << max << '\n';
        std::cout << "index i: " << tempBox.top().ival << '\n';
        std::cout << "index j: " << tempBox.top().jval << '\n' ;
        std::cout << "size :   " << tempBox.size() << '\n'<< '\n';
        tempBox.pop();
    }
}

void ScoringMatrix::show_string_box () const {
    std::stack<AlignedCode> tempBox(StringBox);
    while (!tempBox.empty()) {
        std::cout << tempBox.top().codeB << '\n';
        std::cout << tempBox.top().codeA << '\n'<< '\n';

        tempBox.pop();
    }

}

void ScoringMatrix::show () const {
    std::cout << "Max: " << max << std::endl;
    std::cout << "M.size() = " << M-1 << '\n';
    std::cout << "N.size() = " << N-1 << '\n' << '\n';


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << matrix[i][j]  << " ";
        }
        std::cout << '\n';;
    }
    std::cout << '\n';;
}

/*=====================================================================*/
