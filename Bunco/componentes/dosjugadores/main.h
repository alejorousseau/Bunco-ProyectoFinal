#ifndef DOSJUGADORES_H_INCLUDED
#define DOSJUGADORES_H_INCLUDED
#include "../../funciones/funciones.h"
#include "componentes/finronda.h"
#include "componentes/pantallafinaldosjugadores.h"

void dosJugadores(){
    system("Color 5F");
    int ronda = 0;

    //DECLARACIONES J1 Y J2
    string jugadores[2];

    int puntosTotales[2];
    puntosTotales[0] = 0, puntosTotales[1] = 0;

    int buncosTotales[2];
    buncosTotales[0] = 0, buncosTotales[1] = 0;

    int tirosTotales[2];
    tirosTotales[0] = 0, tirosTotales[1] = 0;

    int tiradasFallidas[2];
    tiradasFallidas[0] = 0, tiradasFallidas[1] = 0;

    /// INGRESO DE NOMBRES J1 Y J2
    for (int i = 0; i < 2; i++){
    system("CLS");
    cout << endl << endl << endl << endl << endl << endl ;
    cout << endl << "\t\t\t\t   JUGADOR " << i+1 << endl << "\t  ----------------------------------------------------------" << endl;
    cout << endl << "\t\t\t     Ingrese su nombre: ";
    cin >> jugadores[i];
    }

    /// COMIENZAN LAS 6 RONDAS
    for (ronda = 1; ronda <= 6; ronda++){
        system("CLS");

        /// COMIENZAN LOS 2 TURNOS J1 Y J2
        for (int j = 0; j < 2; j++){

            int puntosPorRonda = 0;

            // PROXIMO TURNO
            finRonda(jugadores, ronda, puntosTotales, buncosTotales, j);
            int tiros = 0;
            /// TURNO DEL JUGADOR J
            while (puntosPorRonda < 21){

                int dados[3];
                tiros ++;
                tirarDados(dados);
                puntosTotales[j] = puntosTotales[j] + calcularPuntos(dados, ronda);
                puntosPorRonda = puntosPorRonda + calcularPuntos(dados, ronda);
                buncosTotales[j] = buncosTotales[j] + (buncoRonda(dados, ronda)/21);
                if (calcularPuntos(dados, ronda) == 0){
                    tiradasFallidas[j] = tiradasFallidas[j] + 1;
                }
                system("CLS");
                system("Color 5F");
                cout << endl << "  TURNO DE " << jugadores[j];
                cout << " | RONDA N " << ronda << " | PUNTAJE ACUMULADO: " << puntosTotales[j] << " PUNTOS";
                cout << endl << " ----------------------------------------------------------";
                cout << endl << "  VECES QUE OBTUVO BUNCO: " << buncosTotales[j];
                cout << endl << " ----------------------------------------------------------";
                cout << endl << "  LANZAMIENTO N " << tiros << " | Puntos obtenidos con el tiro: " << calcularPuntos(dados, ronda);
                cout << endl << " ----------------------------------------------------------" << endl;
                cout << endl << "  Ha sacado: " << endl << "  " << dados[0] << " | " << dados[1] << " | " << dados[2];
                if (calcularPuntos(dados, ronda) >= 21){
                    cout << endl << "\t\t\t OBTUVISTE BUNCO!" << endl;
                }
                cout << endl << endl << "  Tiradas fallidas: "<<tiradasFallidas[j]<<endl<<endl;
                cout << "  ";
                system("pause");
                tirosTotales[j] = tirosTotales[j] + tiros;
            }
        }
    }

    if ((puntosTotales[0]-(tiradasFallidas[0]*2)) > (puntosTotales[1]-(tiradasFallidas[1]*2))){
        pantallaFinal(puntosTotales[0], tiradasFallidas[0], jugadores[0], buncosTotales[0]);
    }else{
        if ((puntosTotales[0]-(tiradasFallidas[0]*2)) < (puntosTotales[1]-(tiradasFallidas[1]*2))){
            pantallaFinal(puntosTotales[1], tiradasFallidas[1], jugadores[1], buncosTotales[1]);
        }else{
            if (buncosTotales[0] > buncosTotales [1]){
                pantallaFinal(puntosTotales[0], tiradasFallidas[0], jugadores[0], buncosTotales[0]);
            }else{
                if (buncosTotales[0] < buncosTotales[1]){
                    pantallaFinal(puntosTotales[1], tiradasFallidas[1], jugadores[1], buncosTotales[1]);
                }else{
                    system("CLS");
                    cout << endl << endl << endl << endl << endl << endl;
                    cout << "\t\t\t\t    EMPATE!" << endl << endl;
                    cout << "\t  **********************************************************" << endl;
                    cout << endl << "   HAN OBTENIDO LA MISMA CANTIDAD DE PUNTOS Y LA MISMA CANTIDAD DE BUNCO!" << endl << endl;
                    cout << "\t  **********************************************************" << endl;
                    cout << endl << "\t  ";
                    system("PAUSE");
                }
            }
        }
    }

}

#endif // MAIN_H_INCLUDED
