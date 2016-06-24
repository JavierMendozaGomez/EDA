#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int beneficioEstimado(int beneficio, int n, int k, int beneficioMaximo, int maximos[]){
	//Opcion 1: multiplicando por el maximo beneficio de la matriz
	//return beneficio + (n - k-1)*beneficioMaximo;
	//Opcion 2:LLevando la suma maxima de beneficios maximos*/
	return beneficio + maximos[k];
}
void trabajadores(int satisfaccion[100][100], int beneficios[100][100], int &beneficio, int k, int n, int &beneficioMejor, bool tarMarcadas[], int & minSatisfaccion,int &maxSatisfaccion, int beneficioMaximo, int &nodos, int maximos[],int sol[]){
	nodos = nodos + 1;
	for (int j = 0; j < n; j++){
		if ((!tarMarcadas[j]) && ((k == 0) || ((maxSatisfaccion/2 < satisfaccion[k][j])&&(satisfaccion[k][j] < 2*minSatisfaccion)))){
			tarMarcadas[j] = true;
			beneficio = beneficio + beneficios[k][j];
			sol[k] = beneficios[k][j];
			if (beneficioEstimado(beneficio, n, k, beneficioMaximo, maximos) > beneficioMejor){
				if (k == 0){
					minSatisfaccion = satisfaccion[k][j];
					maxSatisfaccion = satisfaccion[k][j];
					trabajadores(satisfaccion, beneficios, beneficio, k + 1, n, beneficioMejor, tarMarcadas, minSatisfaccion,maxSatisfaccion, beneficioMaximo, nodos, maximos,sol);

				}
				else if (k < n - 1){
					minSatisfaccion = std::min(minSatisfaccion, satisfaccion[k][j]);
					maxSatisfaccion = std::max(maxSatisfaccion, satisfaccion[k][j]);
					trabajadores(satisfaccion, beneficios, beneficio, k + 1, n, beneficioMejor, tarMarcadas, minSatisfaccion, maxSatisfaccion, beneficioMaximo, nodos, maximos,sol);

				}
				else{
					for (int i = 0; i < n; i++)
						cout << sol[i] << " " ;
					cout << beneficio << endl;

					beneficioMejor = std::max(beneficio, beneficioMejor);
				}
			}
			tarMarcadas[j] = false;
			beneficio = beneficio - beneficios[k][j];
		}


	}


}

void resuelve(){
	int beneficioMaximo = INT_MIN;
	int beneficios[100][100];
	int satisfaccion[100][100];
	int maximos[100];
	bool tarMarcadas[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> satisfaccion[i][j];
		}
	}
	for (int i = 0; i < n; i++)
		maximos[i] = INT_MIN;

	/*Opcion 1 y 2*/
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> beneficios[i][j];
			maximos[i] = std::max(maximos[i], beneficios[i][j]);        ///Asignamos a cada fila su valor maximo
			beneficioMaximo = std::max(beneficioMaximo, beneficios[i][j]);
		}
	}
	int suma = 0;
	int aux;

	/*Opcion2:Guardamos en cada máximo el sumatorio de k+1 hasta los n-1 siguientes*/
	for (int i = n - 1; i >= 0; i--){
		aux = maximos[i];
		maximos[i] = suma;
		suma = suma + aux;
	}

	for (int i = 0; i < n; i++){	//Lista que representa si se le ha asignado una tarea al empleado
		tarMarcadas[i] = false;
	}

	int sol[100];
	int beneficio = 0;
	int k = 0;
	int minSatisfaccion,maxSatisfaccion;
	int beneficioMejor = INT_MIN;
	int nodos = 0;
	trabajadores(satisfaccion, beneficios, beneficio, k, n, beneficioMejor, tarMarcadas, minSatisfaccion, maxSatisfaccion, beneficioMaximo, nodos, maximos,sol);
	if (beneficioMejor != INT_MIN){
		cout << beneficioMejor << endl;
//		cout << "El numero de llamadas es " << nodos << endl;
	}
	else
		cout << "Sin solucion factible" << endl;
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
}