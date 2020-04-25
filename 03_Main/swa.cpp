#include "swa.hpp"

/*===========================PRIVATE_METHODS===========================*/
void ScoringMatrix::maxVal (int** matrix, int i, int j, char iChar, char jChar){
    std::stack<int> tempST;
    tempST.push(matrix[i][j-1] + penE);
    tempST.push(matrix[i-1][j] + penE);
    tempST.push(0);

    matrix[i][j] = intMax(tempST);

}

int ScoringMatrix::intMax (std::stack<int> & st) {

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

/*======================CONSTRUCTORS_&_DESTRUCTOR======================*/
ScoringMatrix::ScoringMatrix (std::string cd1, std::string cd2) {
    M = cd1.size() + 1;
    std::cout << N << '\n';
    N = cd2.size() + 1;
    std::cout << M << '\n';
    matrix = new int*[N];

    for (int i = 0; i < N; i++) {
        matrix[i] = new int[M];
        char iChar = cd2[i-1];

        for (int j = 0; j < M; j++){
            if (i == 0 or j == 0) {
                matrix[i][j] = 0;

            } else {
                char jChar = cd1[j-1];

                maxVal(matrix, i, j, iChar, jChar);

            }
        }
    }
}

ScoringMatrix::~ScoringMatrix () {
    for (int i = 0; i < N; i++){
        delete[] matrix[i];
    }

    M = 0;
    N = 0;
    delete[] matrix;
    matrix = nullptr;
}

/*==========================ACCESSOR_METHODS==========================*/
void ScoringMatrix::show () const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << matrix[i][j]  << " ";
        }
        std::cout << '\n';;
    }
    std::cout << '\n';;
}

/*==========================MODIFIER_METHODS==========================*/

/*==============================OPERATORS==============================*/

/*=====================================================================*/
