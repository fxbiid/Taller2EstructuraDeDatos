#include <iostream>
#include "SparseMatrix.h"
using namespace std;
SparseMatrix::SparseMatrix() {
    start = nullptr;
}

void SparseMatrix::add(int value, int xPos, int yPos) {
    Nodo* nuevoNodo = new Nodo(xPos, yPos, value);
    if (start == nullptr) {
        start = nuevoNodo;
        return;
    }
    Nodo* actual = start;
    Nodo* anterior= nullptr;

}

int SparseMatrix::get(int x, int y) {

}


void SparseMatrix::remove(int xPos, int yPos) {

}


void SparseMatrix::printStoredValues() {

}

int SparseMatrix::density() {

}

SparseMatrix *SparseMatrix::multiply(SparseMatrix *second) {

}

SparseMatrix::~SparseMatrix() {

}






