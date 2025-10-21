#include <iostream>
#include "Nodo.h"
#include "SparseMatrix.h"
using namespace std;

int main() {
SparseMatrix* A = new SparseMatrix();
    SparseMatrix* B = new SparseMatrix();
    SparseMatrix* C = new SparseMatrix();
     A->add(8,1,2);
    B->add(5,2,3);
    C = A->multiply(B);

    C->printStoredValues();

    delete A;
    delete B;
    delete C;


    return 0;
}