#ifndef DOSJUGADORES_H_INCLUDED
#define DOSJUGADORES_H_INCLUDED
#include "../../funciones/funciones.h"
#include "componentes/finronda.h"
#include "componentes/pantallafinaldosjugadores.h"

void dosJugadores(){
    system("Color 5F");


    //DECLARACIONES J1 Y J2
    string jugadores[2];

    int puntosTotales[2] = {0,0};

    int buncosTotales[2] = {0,0};

    int tirosTotales[2] = {0,0};

    int tiradasFallidas[2] = {0,0};

    int ronda = 0;

    //Vector puntos por ronda
    int puntosPorRonda[2] = {0,0};

    //Flag anterior turno, jugador 1 = 0 y jugador 2 = 1
    bool AJ = 1;

    //Puntos de la anterior ronda
    int antpuntos[2] = {0,0};


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
        antpuntos[0] = antpuntos [1] = 0;
        puntosPorRonda[0] = puntosPorRonda[1] = 0;
        AJ = 1;
        int tfRonda = 0;
        /// Si en el anterior turno el jugador no llegó a 21 el ciclo vuelve a comenzar
        while(antpuntos[AJ] < 21){

        /// COMIENZAN LOS 2 TURNOS J1 Y J2
        for (int j = 0; j < 2; j++){

            // PROXIMO TURNO
            if(antpuntos[AJ] < 21){

                /// Pantall entre turnos y de fin de ronda
                finRonda(jugadores, ronda, puntosTotales, buncosTotales, j);

                /// TURNO DEL JUGADOR J
                int tiros = 0;
                tfRonda = 0;
                while (puntosPorRonda[j] < 21 && tfRonda == 0){

                    /// Se trian los dados,
                      int dados[3];
                      tiros ++;
                      tirarDados(dados);

                    /// Se calculan los puntos (calcularPuntos(dados, ronda)) y los buncos, se suman al total y a la ronda
                      int puntos = calcularPuntos(dados, ronda);

                      puntosTotales[j] = puntosTotales[j] + puntos;
                      puntosPorRonda[j] = puntosPorRonda[j] + puntos;
                      buncosTotales[j] = buncosTotales[j] + (buncoRonda(dados, ronda)/21);

                      // Se guardan los puntos de esta ronda para la proxima
                      antpuntos[j] = puntosPorRonda[j];

                    /// Se agregan los tiros fallidos al total y ala ronda,
                        if (puntos == 0){
                            tiradasFallidas[j] = tiradasFallidas[j] + 1;
                            tfRonda ++;
                            }
                    /// Interfaz de usuario durante partida
                    system("CLS");
                    system("Color 5F");
                    cout << endl << "  TURNO DE " << jugadores[j];
                    cout << " | RONDA N " << ronda << " | PUNTAJE ACUMULADO: " << puntosPorRonda[j] << " PUNTOS";
                    cout << endl << " ----------------------------------------------------------";
                    cout << endl << "  VECES QUE OBTUVO BUNCO: " << buncosTotales[j];
                    cout << endl << " ----------------------------------------------------------";
                    cout << endl << "  LANZAMIENTO N " << tiros << " | Puntos obtenidos con el tiro: " << puntos;
                    cout << endl << " ----------------------------------------------------------" << endl;
                    cout << endl << "  Ha sacado: " << endl << "  " << dados[0] << " | " << dados[1] << " | " << dados[2];
                    if (puntos == 21){
                        cout << endl << "\t\t\t OBTUVISTE BUNCO!" << endl;
                    }
                    cout << endl << endl << "  Tiradas fallidas: "<<tiradasFallidas[j]<<endl<<endl;
                    cout << "  ";
                    system("pause");

                    /// Se suman los tiros totales
                    tirosTotales[j] = tirosTotales[j] + tiros;
                }

            AJ = j;
            }
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
