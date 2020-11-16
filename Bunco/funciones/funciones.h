#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstdlib>
#include <ctime>

/// MAXPUNTUACION
int TotalMaximo = 0;
string nombMAX = "Nadie";
int maxBuncos;

/// Calcular Puntos
int calcularPuntos(int vDados[], int nRonda);
int coincidirRonda(int _Dados[], int _Ronda);
int buncoRonda(int _Dados[], int _Ronda);
int dadosIguales(int _Dados[], int _Ronda);
int totalFinal (int _puntosTotales, int _tiradasFallidas);
int calcularEscalera(int _Dados[]);
int sumaDados(int _Dados[]);

/// Tirar dados
void tirarDados();

/// Pantalla de error
void pantallaError();

///Total de puntos recolectados
int calcularPuntos(int vDados[], int nRonda){
    int puntos;
    puntos = coincidirRonda(vDados, nRonda) + calcularEscalera(vDados) + sumaDados(vDados) + dadosIguales(vDados, nRonda) + buncoRonda(vDados, nRonda);
    return puntos;
}


///Tirar dados
void tirarDados(int vDados[]){
    srand(time(0));
    for (int tirada = 0; tirada <=2; tirada++){
        vDados[tirada] = (rand() % 6 + 1);
    }
}



///1 punto por cada dado que coincida con el número de la ronda.
int coincidirRonda(int _Dados[], int _Ronda){
    int _contador = 0;
    for (int i = 0; i <=2; i++){
        if (_Ronda == _Dados[i]){
            _contador++;
        }
    }
    if (_contador >0 && _contador <= 2){
        return _contador;
    }else{
        return 0;
    }
}


///2 puntos si los tres dados forman una escalera.
int calcularEscalera(int _dados[]){
    int menor = 0, esc = 0, medio = 0, grande = 0;

    /// ENCONTRAR MENOR
    for (int i = 0; i <=2; i++){
        if (i == 0){
            menor = _dados[0];
        }else{
            if (_dados[i] < menor){
                menor = _dados[i];
                esc ++;
                i = 2;
            }
        }
    }

    /// ENCONTRAR AL MEDIO
    for (int i = 0; i < 3; i ++){
        if (_dados[i] == menor + 1){
            esc ++;
            medio = _dados[i];
            i = 2;
        }
    }

    /// ENCONTRAR EL MAS GRANDE
    for (int i = 0; i < 3; i ++){
        if (_dados[i] == medio + 1){
            esc ++;
            grande = _dados[i];
            i = 2;
        }
    }

    if (esc == 3){
        return 2;
    }else{
        return 0;
    }
}

///3 puntos si la suma de los tres dados es divisible por 5.
int sumaDados(int _Dados[]){
    int total = 0;
    for (int i = 0; i <=2; i++){
        total = total + _Dados[i];
    }
    if (total%5 == 0){
        return 3;
    }else{
        return 0;
    }

}


///5 puntos si los tres dados son iguales pero no coinciden con la ronda en curso.
int dadosIguales(int _Dados[], int _Ronda){
    int ant = 0, contador = 0;
    for (int i = 0; i <=2; i++){
        if (i == 0){
            ant = _Dados[i];
            contador++;
        }else{
            if (ant == _Dados[i]){
                contador++;
            }
        }
    }
    if (contador == 3 && _Dados[0] != _Ronda){
        return 5;
    }else{
        return 0;
    }
}


///21 puntos si los tres dados coinciden con el número de la ronda que se está jugando (a esta tirada se la denomina “Bunco”).
int buncoRonda(int _Dados[], int _Ronda){
    int ant = 0, contador = 0;
    for (int i = 0; i <=2; i++){
        if (i == 0){
            ant = _Dados[0];
            contador++;
        }else{
            if (ant == _Dados[i]){
                contador++;
            }
        }
    }
    if (contador == 3 && _Dados[0] == _Ronda){
        return 21;
    }else{
        return 0;
    }
}

/// Total de puntos acumulados menos tiradas fallidas
int totalFinal (int _puntosTotales, int _tiradasFallidas){
    int Total;
    Total   =  _puntosTotales - (_tiradasFallidas*2);
    return Total;
}

///Pantalla de error
void pantallaError(){
    system("CLS");
    system ("Color 0A");
    cout << endl << "\t   ----------------------------------------------------------";
    cout << endl << endl << "\t\t\t   Ingrese una opcion correcta";
    cout << endl << endl << "\t   ----------------------------------------------------------" << endl;
    cout << endl << "\t\t     ";
    system("PAUSE");
}


/// Declarar/Revisar Maximo
void revisaMax(int total, string nombre, int buncos){
    if(total > TotalMaximo && buncos >= maxBuncos){
        TotalMaximo = total;
        nombMAX = nombre;
        maxBuncos = buncos;
    }
}




#endif // FUNCIONES_H_INCLUDED
