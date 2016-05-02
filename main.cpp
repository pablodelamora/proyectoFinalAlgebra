#include <iostream>
#include<stdlib.h>
#include <time.h>

using namespace std;
#define N 9


// Declaracion de funciones
void generaMatriz(int[N], int);
void escogeMatriz(int[N], int);
void resuelveProblema(int[N], int[N], int[N], int[N][N], int, int);
void gaussJordan(int A[][N], int* b, int mod);



int main(){

	int matOriginal[N][N] = {
			{ 1, 1, 0, 1, 0, 0, 0, 0, 0 },
			{ 1, 1, 1, 0, 1, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0, 1, 0, 0, 0 },
			{ 1, 0, 0, 1, 1, 0, 1, 0, 0 },
			{ 1, 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 0, 0, 1, 0, 1, 1, 0, 0, 1 },
			{ 0, 0, 0, 1, 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 1, 0, 1, 1, 1 },
			{ 0, 0, 0, 0, 0, 1, 0, 1, 1 }
	};

	int matPersonalizada[N][N]{
			{ 1, 1, 0, 1, 0, 0, 0, 0, 0 },
			{ 1, 1, 1, 0, 1, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0, 1, 0, 0, 0 },
			{ 1, 0, 0, 1, 1, 0, 1, 0, 0 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 1, 0, 1, 1, 0, 0, 1 },
			{ 0, 0, 0, 1, 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 1, 0, 1, 1, 1 },
			{ 0, 0, 0, 0, 0, 1, 0, 1, 1 }
	};

	//int inicial[9] = { 1, 0, 1, 0, 0, 0, 1, 1, 0 };
	//int fin[9] = { 1, 1, 1, 1, 0, 1, 1, 1, 1 };


	//int inversaMat[N][N];

//	gaussJordan(matOriginal, fin, 2);

	//for (int i = 0; i < 9; i++){
	//	cout << fin[i] << " ";
	//}



	srand(time(NULL));

	// Matrices de apoyo para la resolucion del problema
	int matInicial[9];
	int matFinal[9];
	int restaMatInicialFinal[9];
	int matResultado[9];

	// Matriz de la suma inicializada en 0
	for (int i = 0; i < 9; i++){
		matResultado[i] = 0;
	}

	cout << "Escribe el numero del modulo que se desea aplicar (2 o 3)" << endl;
	int mod;
	cin >> mod;

	cout << "Que transformaciones deseas usar: \n1-Originales\n2-De nuestro equipo" << endl;
	int op;
	cin >> op;

	while (mod != 2 && mod != 3){
		cout << "Opcion no valida, por favor entra 2 o 3" << endl;
		cin >> mod;
	}

	// Menu de opciones y sus acciones
	int m;
	cout << "\t\t\tElija una opcion\n\n";
	cout << "1  Introducir Matriz Inicial y Final\n";
	cout << "2  Generar Matriz Inicial y Final\n";
	cout << "3  Salir\n\n";
	cin >> m;

	while (m != 3){
		switch (m)
		{
		case 1: cout << "\t\t\tCrear la matriz inicial\n\n";
			escogeMatriz(matInicial, mod);
			cout << "\t\t\tCrear la matriz final\n\n";
			escogeMatriz(matFinal, mod);
			if (op == 1){
				resuelveProblema(restaMatInicialFinal, matInicial, matFinal, matOriginal, mod, op);
			}
			else if (op == 2){
				resuelveProblema(restaMatInicialFinal, matInicial, matFinal, matPersonalizada, mod, op);
			}
			break;

		case 2: cout << "\t\t\tCrear la matriz inicial\n\n";
			generaMatriz(matInicial, mod);
			cout << "\t\t\tCrear la matriz final\n\n";
			generaMatriz(matFinal, mod);
			if (op == 1){
				resuelveProblema(restaMatInicialFinal, matInicial, matFinal, matOriginal, mod, op);
			}
			else if (op == 2){
				resuelveProblema(restaMatInicialFinal, matInicial, matFinal, matPersonalizada, mod, op);
			}
			break;

		case 3: cout << "Adios" << endl;
			break;
		default: cout << "El valor ingresado no esta en el menu" << endl;
		}

		for (int i = 0; i < 9; i++){
			//matResultado[i] = 0;
			restaMatInicialFinal[i] = 0;

		}

		cout << endl << "Selecciona una opcion: \n";
		cout << "1  Introducir Matriz Inicial y Final\n";
		cout << "2  Generar Matriz Inicial y Final\n";
		cout << "3  Salir\n\n";
		cin >> m;
	}


	system("pause");
	return 0;
}

//funcion que genera aleatoriamente una matriz segun el modulo seleccionado
void generaMatriz(int matInicial[9], int mod){
	for (int i = 0; i < 9; i++){
		matInicial[i] = rand() % mod;
		if (i != 0 && i % (3) == 0){
			cout << endl;
		}
		cout << matInicial[i] << " ";
	}
	cout << endl;
}

// Funcion que ayuda al usuario a generar la matriz inicial
void escogeMatriz(int matInicial[9], int mod){
	cout << "Siguiendo el esquema: " << endl << "1 2 3" << endl << "4 5 6" << endl << "7 8 9" << endl;
	cout << "Si su numero no va de acuerdo con el modulo que escogio, se le hara automaticamente el modulo";
	for (int i = 0; i < 9; i++){
		cout << endl << "Dame la posicion:  " << i + 1 << endl;
		cin >> matInicial[i];
		matInicial[i] = matInicial[i] % mod;
	}
	cout << endl << endl;
	for (int i = 0; i < 9; i++){
		if (i != 0 && i % (3) == 0){
			cout << endl;
		}
		cout << matInicial[i] << " ";
	}
	cout << endl;
}

// Funcion que resuleve el problema.
void resuelveProblema(int restaMatInicialFinal[9], int matInicial[9], int matFinal[9], int matTransf[N][N], int mod, int op){
	for (int i = 0; i < 9; i++){
		// GEneracion de la matriz suma
		if ((matFinal[i] - matInicial[i]) < 0){
			restaMatInicialFinal[i] = ((matFinal[i] - matInicial[i]) + mod);
		}
		else{
			restaMatInicialFinal[i] = (matFinal[i] - matInicial[i]) % mod;
		}
		cout << restaMatInicialFinal[i] << endl;
	}

	gaussJordan(matTransf, restaMatInicialFinal, mod);

	for (int i = 0; i < N; i++){
		cout <<"Picar el boton " << i+1 << ":  " << restaMatInicialFinal[i] << " veces \n";
	}


}



int modulo(int x, int m) {
	if (x >= 0)
		return x % m;
	else {
		int k = floor((x + 0.0) / m);
		return x - (k * m);
	}
}


int inversoMultiplicativo(int x, int m) {
	for (int i = 1; i < m; ++i)
		if ((x * i) % m == 1)
			return i;
	return -1;
}


void intercambiarRenglones(int* x, int* y, int n) {
	int temp;
	for (int i = 0; i < n; ++i) {
		temp = x[i];
		x[i] = y[i];
		y[i] = temp;
	}
}

void escalarRenglon(int* x, int alfa, int mod, int n) {
	for (int i = 0; i < n; ++i)
		x[i] = modulo(x[i] * alfa, mod);
}

void sumarRenglon(int* x, int* y, int alfa, int mod, int n) {
	for (int i = 0; i < n; ++i)
		x[i] = modulo(x[i] + (alfa * y[i]), mod);
}



void gaussJordan(int A [][N], int* b, int mod) {
	int inverso, alfa;

	for (int i = 0; i < N; ++i) {
		if (inversoMultiplicativo(A[i][i], mod) == -1) {
			int j = i + 1;
			while (j < N && inversoMultiplicativo(A[j][i], mod) == -1)
				++j;

			if (j != N) {
				intercambiarRenglones(A[i], A[j], N);
				intercambiarRenglones(b + i, b + j, 1);
			}

			else {
				cout << "La matriz no se puede invertir" << endl;
				exit(-1);
			}
		}

		inverso = inversoMultiplicativo(A[i][i], mod);

		escalarRenglon(A[i], inverso, mod, N);
		escalarRenglon(b + i, inverso, mod, 1);

		for (int j = 0; j < N; ++j) {
			if (j != i) {
				alfa = -1 * A[j][i];
				sumarRenglon(A[j], A[i], alfa, mod, N);
				sumarRenglon(b + j, b + i, alfa, mod, 1);
			}
		}
	}
}