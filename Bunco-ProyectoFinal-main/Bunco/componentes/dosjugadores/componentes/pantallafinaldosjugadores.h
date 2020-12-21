#ifndef PANTALLAFINALDOSJUGADORES_H_INCLUDED
#define PANTALLAFINALDOSJUGADORES_H_INCLUDED


#include "../../../funciones/funciones.h"
void pantallaFinal(int _totalPuntos, int tiradasFallidas, string nomb, int buncos){
    system("CLS");
    system("Color 5F");
    cout << endl << endl << endl << endl;
    cout << endl << "\t\t\t         GANADOR: " << nomb << endl;
    cout << endl << "\t  **********************************************************" << endl;
    cout << endl << "\t\t\t      Buncos conseguidos: " << buncos;
    cout << endl << "\t\t\t      Puntos acumulados: " << _totalPuntos;
    cout << endl << "\t\t\t      Puntos totales: " << totalFinal(_totalPuntos, tiradasFallidas) << endl;
    cout << endl << "\t  **********************************************************" << endl;
    revisaMax(totalFinal(_totalPuntos, tiradasFallidas), nomb, buncos);
    cout << endl;
    cout << "\t  ";
    system ("PAUSE");
}


#endif // PANTALLAFINALDOSJUGADORES_H_INCLUDED
