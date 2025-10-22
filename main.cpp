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

    //prueba en multiply


    return 0;
}