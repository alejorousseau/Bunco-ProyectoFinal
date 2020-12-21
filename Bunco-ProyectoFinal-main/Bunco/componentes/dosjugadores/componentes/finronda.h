#ifndef FINRONDA_H_INCLUDED
#define FINRONDA_H_INCLUDED

void finRonda (string _jugadores[2], int _ronda, int _puntosTotales[2] , int _buncosTotales[2], int _j){
    system("CLS");

    /// FIN DE RONDA
    cout << endl << endl << endl;
    cout << endl << endl << "\t\t\t\t   RONDA N " << _ronda;
    cout << endl << "\t\t\t      PROXIMO TURNO: " << _jugadores[_j];
    cout << endl << endl<< "\t\t   -----------------------------------------";
    cout << endl << endl << "\t\t\t   PUNTAJE DE " << _jugadores[0] << ": " << _puntosTotales[0] << " PUNTOS";
    cout << endl << "\t\t\t     CANTIDAD DE BUNCOS: " << _buncosTotales[0];
    cout << endl << endl<< "\t\t   -----------------------------------------";
    cout << endl << endl << "\t\t\t   PUNTAJE DE " << _jugadores[1] << ": " << _puntosTotales[1] << " PUNTOS";
    cout << endl << "\t\t\t     CANTIDAD DE BUNCOS: " << _buncosTotales[1];
    cout << endl  << endl << endl << endl << "  ";

    system("PAUSE");
}



#endif // FINRONDA_H_INCLUDED
