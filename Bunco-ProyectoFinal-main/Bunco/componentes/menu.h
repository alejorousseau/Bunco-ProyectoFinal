#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "unjugador/unjugador.h"
#include "simulado/simulado.h"
#include "dosjugadores/dosjugadores.h"
#include "maxpuntuacion/maxpuntuacion.h"
#include "../funciones/funciones.h"
#include "dosjugadores/componentes/pantallafinaldosjugadores.h"


void menu(){
    int a = true;
    while (a == true){
        system("Color 1F");
        system("CLS");
        int opcion = 0;
        cout << endl << endl << endl << endl;
        cout << endl <<"\t\t\t\t     BUNCO" << endl << endl <<  "\t  **********************************************************" << endl;
        cout << endl << "\t\t\t1 - Juego nuevo para un jugador";
        cout << endl << "\t\t\t2 - Juego nuevo para dos jugadores";
        cout << endl << "\t\t\t3 - Mostrar puntuacion mas alta";
        cout << endl << "\t\t\t4 - Modo Simulado";
        cout << endl << "\t\t\t0 - Salir";
        cout << endl << endl << "\t  **********************************************************" << endl;
        cout << endl << "\t  Opcion: ";
        cin >> opcion;

        system("CLS");
        switch (opcion){
        case 1: unJugador();
            break;
        case 2: dosJugadores();
            break;
        case 3: maxPuntuacion();
            break;
        case 4: modoSimulado();
            break;
        case 0: a = false;
            break;
        default: pantallaError();
            break;
        }
    cout << endl;
    }
}

#endif // MENU_H_INCLUDED
