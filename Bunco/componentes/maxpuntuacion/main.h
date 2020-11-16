#ifndef PRINCIPAL_H_INCLUDED
#define PRINCIPAL_H_INCLUDED
#include "../../funciones/funciones.h"


void maxPuntuacion(){
    system("Color 5F");
    cout << endl << endl << endl << endl;
    cout << endl << "\t\t\t\tPuntuacion Maxima" << endl;
    cout << endl << "\t  **********************************************************" << endl;
    cout << endl << "\t\t\t\t      " << nombMAX<< endl << "\t\t\t\t-----------------";
    cout << endl << "\t\t\t\tPuntos obtenidos: " << TotalMaximo;
    cout << endl << "\t\t\t\tBuncos obtenidos: " << maxBuncos;
    cout << endl << endl << "\t  **********************************************************" << endl;
    cout << endl;
    cout << "\t  ";
    system("pause");
}

#endif // PRINCIPAL_H_INCLUDED
