#ifndef MODOSIMULADO_H_INCLUDED
#define MODOSIMULADO_H_INCLUDED
#include "../../funciones/funciones.h"
#include "../unjugador/componentes/finronda.h"
#include "../unjugador/componentes/pantallafinalunjugador.h"

void modoSimulado();

void modoSimulado(){
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
            int dados[3], j, i;
            tiros ++;
            for(j=0;j < 3; j++){
                dados[j]=0;
            }

            for(i=0;i < 3; i++){
              while (dados[i] < 1 || dados[i] > 6) {
                system("cls");
                system("Color 1F");
                cout << endl << endl << endl << endl << endl << endl ;
                cout << endl << "\t\t Ingrese los dados (Solo numeros del 1 al 6)" << endl << "\t  ----------------------------------------------------------" << endl;
                cout << endl <<"\t\t\t\t Dado " << i+1 << ":  " ;
                cin>>dados[i];
              }
            }

            puntosTotales = puntosTotales + calcularPuntos(dados, ronda);
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
        tiradasFallidas = tiradasFallidas + fallidas;
        tirosTotales = tirosTotales + tiros;
        system("CLS");
        finRonda(nombre, ronda, puntosTotales, contadorBuncos, tiros, fallidas);
    }
    system("CLS");
    pantallaFinalUnJugador(puntosTotales, tiradasFallidas, nombre, contadorBuncos, tirosTotales);

    system("CLS");
}

#endif // MAIN_H_INCLUDED
