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
int maximo(int vec[], int n);


/// Tirar dados
void tirarDados();

/// Pantalla de error
void pantallaError();

///Total de puntos recolectados
int calcularPuntos(int vDados[], int nRonda){
    int puntaje[5];

    //Definir puntos
    puntaje[0] = coincidirRonda(vDados, nRonda);
    puntaje[1] = calcularEscalera(vDados);
    puntaje[2] = sumaDados(vDados);
    puntaje[3] = dadosIguales(vDados,nRonda);
    puntaje[4] = buncoRonda(vDados, nRonda);

    return maximo(puntaje, 5);
}


///Maximo puntaje
int maximo(int vec[], int n){
    int maxv;

    for(int i = 0; i < n; i++){
        if(i == 0){
            maxv = vec[i];
        }else{
            if (vec[i] > maxv){
                maxv = vec[i];
            }
        }
    }
    return maxv;
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
    int i, j, aux, mini;
	for(i=0;i<3;i++){
		mini = i;
		for(j=i+1;j<3;j++){
			if(_dados[j] < _dados[mini]){
				mini = j;
			}
		}
		aux = _dados[i];
		_dados[i] = _dados[mini];
		_dados[mini] = aux;
	}

    if(_dados[0]+1 == _dados[1] && _dados[1]+1 == _dados[2]){
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
