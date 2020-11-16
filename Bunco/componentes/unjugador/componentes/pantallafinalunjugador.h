#ifndef PANTALLAFINALUNJUGADOR_H_INCLUDED
#define PANTALLAFINALUNJUGADOR_H_INCLUDED

#include "../../../funciones/funciones.h"
void pantallaFinalUnJugador(int ujTotalPuntos, int tiradasFallidas, string nomb, int buncos, int lanzamientos){
    system("CLS");
    system("Color 5F");
    cout << endl << endl;
    cout << endl << "\t\t\t         GANADOR - " << nomb << endl;
    cout << endl << "\t  **********************************************************" << endl;
    cout << endl << "\t\t\t      Buncos conseguidos: " << buncos << endl;
    cout << endl << "\t\t\t      Tiradas fallidas: " << tiradasFallidas << endl;
    cout << endl << "\t\t\t      Lanzamientos: " << lanzamientos << endl;
    cout << endl << "\t\t\t      Puntos acumulados: " << ujTotalPuntos << endl;
    cout << endl << "\t\t\t      Puntos totales: " << totalFinal(ujTotalPuntos, tiradasFallidas) << endl;
    cout << endl << "\t  **********************************************************" << endl;
    cout << endl;
    revisaMax(totalFinal(ujTotalPuntos, tiradasFallidas), nomb, buncos);
    cout << "\t  ";
    system ("PAUSE");
}

#endif // PANTALLAFINALUNJUGADOR_H_INCLUDED
