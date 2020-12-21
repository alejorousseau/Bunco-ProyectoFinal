#ifndef PANTALLAFINALRONDA_H_INCLUDED
#define PANTALLAFINALRONDA_H_INCLUDED

void finRonda (string _nombre, int _ronda, int _puntosTotales , int _buncosTotales, int _tiros, int _tiradasFallidas){
    system("CLS");

    /// FIN DE RONDA
    cout << endl;
    cout << endl << endl << "\t\t\t\t   RONDA N " << _ronda;
    cout << endl << endl<< "\t\t   -----------------------------------------" << endl;
    cout << endl << endl << "\t\t\t   PUNTAJE DE " << _nombre << ":" << _puntosTotales << " PUNTOS";
    cout << endl << endl << "\t\t\t     CANTIDAD DE BUNCOS:" << _buncosTotales;
    cout << endl << endl << "\t\t\t      TIRADAS FALLIDAS:" << _tiradasFallidas;
    cout << endl << endl << "\t\t\t        LANZAMIENTOS:" << _tiros;
    cout << endl << endl << endl << "\t\t   -----------------------------------------";
    cout << endl  << endl << endl << "  ";

    system("PAUSE");
}


#endif // PANTALLAFINALRONDA_H_INCLUDED
