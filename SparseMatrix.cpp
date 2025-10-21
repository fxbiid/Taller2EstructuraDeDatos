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

    while (actual!=nullptr && (actual -> x <xPos || actual -> x == xPos && actual -> y <yPos)) {
        anterior = actual;
        actual = actual -> next;

    }
    //por si existe ya un nodo en esa posicion borramos el nodo nuevo pq ya esta ocupada solo actualizamos su valor
   if (actual!=nullptr && actual->x == xPos && actual->y == yPos) {
       actual -> value = value;
       delete nuevoNodo;
       return;
   }
    //para ponerlo entre el anterior y el actual (anterior vacio actual) en vacio seria
    if (anterior == nullptr) { // si el anterior esta en nulo lo ponemos en el principio entonces seria nuevo , start (nuevo | start )
        nuevoNodo -> next = start;
        start = nuevoNodo;
    }else { //si tiene anterior hacemos lo de ponerlo entremedio de los 2
        anterior -> next = nuevoNodo;
        nuevoNodo -> next = actual;

    }

}

int SparseMatrix::get(int x, int y) {
    Nodo* actual = start;
    while (actual!=nullptr) {
        if (actual -> x == x && actual -> y == y) {
            return actual -> value;
        }
        if (actual ->x >x || actual -> x == x && actual -> y >y) {
            break;

        }
        actual = actual -> next;
    }
    return 0;
}


void SparseMatrix::remove(int xPos, int yPos) {
 Nodo* actual = start;
    Nodo* anterior = nullptr;
    while (actual!=nullptr) {
        if (actual -> x == xPos && actual -> y == yPos) {
            if (anterior!=nullptr) {
                anterior -> next = actual -> next;
            }else {
                start = actual -> next;

            }
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual -> next;
    }
}


void SparseMatrix::printStoredValues() {
    if (!start) {
        cout<<"Matriz vacia"<<endl;
        return;
    }
        Nodo* actual = start;
        while (actual!=nullptr) {
            cout<<actual -> x<<","<<actual -> y<<" valor en esa posicion: "<<actual -> value<<endl;
            actual = actual -> next;
        }

}

int SparseMatrix::density() {

}

SparseMatrix *SparseMatrix::multiply(SparseMatrix *second) {
    if (!second) {
        return nullptr;
    }
    SparseMatrix* resultado = new SparseMatrix();
    //esto lo vemos asi resultado= A*B
    for (Nodo* a = this->start; a != nullptr; a = a->next) {
        int i = a ->x;
        int k = a ->y;

        for (Nodo* b = second->start; b != nullptr; b = b->next) {
            if (b ->x <k) {
                continue;
            }
            if (b ->x > k) {
                break;
            }
            int j = b ->y;
            long long resu = 1LL * a->value * b->value;
            if (resu==0) {
                continue;
            }
            int ac = resultado -> get(i,j);
            long long nuevitoo = ac+resu;

            resultado -> add(static_cast<int>(nuevitoo),i,j);


        }
    }

    return resultado;

}

SparseMatrix::~SparseMatrix() {
 Nodo* actual = start;
    while (actual!=nullptr) {
        Nodo* temp = actual;
        actual = actual -> next;
        delete temp;
    }
}






