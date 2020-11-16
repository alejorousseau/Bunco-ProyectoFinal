#ifndef UNJUGADOR_CPP_INCLUDED
#define UNJUGADOR_CPP_INCLUDED
#include "../../funciones/funciones.h"
#include "componentes/finronda.h"
#include "componentes/pantallafinalunjugador.h"

void unJugador(){
    system("Color 1F");
    string nombre;
    int puntosTotales = 0, tiradasFallidas = 0,  contadorBuncos = 0, tirosTotales = 0;
    cout << endl << endl << endl << endl << endl << endl ;
    cout << endl << "\t\t\t\t  UN JUGADOR" << endl << "\t  ----------------------------------------------------------" << endl;
    cout << endl << "\t\t\t     Ingrese su nombre: ";
    cin >> nombre;

    for (int ronda = 1; ronda <= 6; ronda++){
            int puntosPorRonda = 0, tiros = 0, fallidas = 0;
        while(puntosPorRonda < 21){
            int dados[3];
            tiros  = tiros + 1;
            tirarDados(dados);
            puntosPorRonda = puntosPorRonda + calcularPuntos(dados, ronda);
            contadorBuncos = contadorBuncos + (buncoRonda(dados, ronda)/21);
            if (calcularPuntos(dados, ronda) == 0){
                fallidas = fallidas + 1;
            }
            system("CLS");
            system("Color 5F");
            cout << endl << "  TURNO DE " << nombre;
            cout << " | RONDA N " << ronda << " | PUNTAJE ACUMULADO: " << puntosTotales << " PUNTOS";
            cout << endl << " ----------------------------------------------------------";
            cout << endl << "  VECES QUE OBTUVO BUNCO: " << contadorBuncos;
            cout << endl << " ----------------------------------------------------------";
            cout << endl << "  LANZAMIENTO N " << tiros << " | Puntos obtenidos con el tiro: " << calcularPuntos(dados, ronda);
            cout << endl << " ----------------------------------------------------------" << endl;
            cout << endl << "  Ha sacado: " << endl << "  " << dados[0] << " | " << dados[1] << " | " << dados[2];
            if (calcularPuntos(dados, ronda) >= 21){
                cout << endl << "\t\t\t OBTUVISTE BUNCO!" << endl;
            }
            cout << endl << endl << "  Tiradas fallidas: "<<fallidas<<endl<<endl;
            cout << "  ";
            system("pause");
        }
        puntosTotales = puntosTotales + puntosPorRonda;
        tiradasFallidas = tiradasFallidas + fallidas;
        tirosTotales = tirosTotales + tiros;
        system("CLS");
        finRonda(nombre, ronda, puntosTotales, contadorBuncos, tiros, fallidas);
    }
    system("CLS");
    pantallaFinalUnJugador(puntosTotales, tiradasFallidas, nombre, contadorBuncos, tirosTotales);

    system("CLS");
}

#endif // PRINCIPAL_CPP_INCLUDED
