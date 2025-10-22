#include <iostream>
#include "Nodo.h"
#include "SparseMatrix.h"
#include<ctime>
using namespace std;

int main() {
    srand(time(NULL));
    //prueba en add
    int cants[] = {50,250,500,1000,5000};
    cout<<"Pruebas en funcion add"<<endl;
    for(int i=0;i<5;i++) {
        int n = cants[i];
        SparseMatrix matrix;
        clock_t inicioPruebaAdd = clock();

        for (int j = 0; j < n; j++) {
            int x = rand() % 100;
            int y = rand() % 100;
            int valor = rand()+1 % 100;
            matrix.add(valor, x, y);

        }
        clock_t finPruebaAdd = clock();
        double tiempoFin = double(finPruebaAdd - inicioPruebaAdd) / CLOCKS_PER_SEC;
        cout<<"add"<<n<<" = "<<tiempoFin<<" seg"<<endl;
    }
    //prueba en get
    cout<<"\n";
    cout<<"Pruebas en funcion get"<<endl;
    for (int i = 0; i < 5; i++) {
        int n = cants[i];
        SparseMatrix matrix2;
        for (int x = 0; x < n; x++) {
            matrix2.add(rand()+1 % 100, rand() % 100, rand() % 100);
        }
        clock_t inicioPruebaGet = clock();
        for (int j = 0; j < n; j++) {
            matrix2.get(rand() % 100, rand() % 100);
        }
        clock_t finPruebaGet = clock();
        double tiempoFinGet = double(finPruebaGet-inicioPruebaGet)/CLOCKS_PER_SEC;
        cout<<"get"<<n<<" = "<<tiempoFinGet<<" seg"<<endl;
    }
    //prueba en multiply
    cout<<"\n";
    cout<<"Pruebas en funcion multiply"<<endl;
    for (int i = 0; i < 5; i++) {
        int n = cants[i];
        SparseMatrix A,B;
        for (int x = 0; x < n; x++) {
            A.add(rand() % 100, rand() % 100, rand() % 100);
            B.add(rand() % 100, rand() % 100, rand() % 100);
        }
        clock_t inicioPruebaMulti = clock();
        SparseMatrix* C = A.multiply(&B);
        clock_t finPruebaMulti = clock();
        double tiempoFinMulti = double(finPruebaMulti-inicioPruebaMulti)/CLOCKS_PER_SEC;
        cout<<"multiply"<<n<<" = "<<tiempoFinMulti<<" seg"<<endl;

        delete C;

    }

    return 0;
}