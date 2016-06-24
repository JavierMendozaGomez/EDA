#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
void atiendeCliente(vector<long long int> & cajas, const int &minEstimados, int &caja) {
	int min = INT_MAX;
	for (long int i = 0; i < 3; i++) {
		if (cajas[i] < min) {
			caja = i;
			min = cajas[i];
		}
	}
	cajas[caja] += minEstimados;
}
void procesaClientes(queue<int> colaClientes,queue<int> colaVecinos) {
	vector<long long int> cajas(3,0);	//Inicializar el vector de tamaño 3 con valor 0
	int caja;
	int contador = 0;
	while (!colaVecinos.empty()) {
		atiendeCliente(cajas, colaClientes.front(), caja);
		if (contador+1 == colaVecinos.front()) {
			colaVecinos.pop();
			cout << caja + 1;
			if (!colaVecinos.empty())
				cout << " ";
			else
				cout << endl;
		}
		colaClientes.pop();
		contador++;
	}
}
bool resuelve() {
	int numClientes, numVecinos, tiempoEstimado, posVecino;
	cin >> numClientes >> numVecinos;
	if (numClientes == 0 && numVecinos == 0)
		return false;
	queue<int> colaClientes;
	queue<int> colaVecinos;

	for (int i = 0; i < numClientes; i++) {
		cin >> tiempoEstimado;
		colaClientes.push(tiempoEstimado);
	}
	for (int i = 0; i < numVecinos; i++) {
		cin >> posVecino;
		colaVecinos.push(posVecino);
	}
	procesaClientes(colaClientes, colaVecinos);
	return true;
}
int main() {
	while (resuelve());
	return 0;
}