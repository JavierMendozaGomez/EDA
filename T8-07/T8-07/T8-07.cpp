#include<iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;
void volteaPila(stack<int> &pila,int n) {
	stack<int> pilaAuxiliar;
	int i = 0;
	while (!pila.empty() && i < n) {
		pilaAuxiliar.push(pila.top());
		pila.pop();
		i++;
	}
	stack <int> pila2;
	while (!pilaAuxiliar.empty()) {
		pila2.push(pilaAuxiliar.top());
		pilaAuxiliar.pop();
	}
	while (!pila2.empty()) {
		pila.push(pila2.top());
		pila2.pop();
	}
}
int calculaVolteo(stack<int> &pilaTortitas,const vector<int> &listadoMovimientos) {
	for (int i = 0; i < listadoMovimientos.size();i++) {
		volteaPila(pilaTortitas, listadoMovimientos.at(i));
	}
	return pilaTortitas.top();
}
bool resuelve() {
	int tortita;
	cin >> tortita;
	if (tortita == 0)
		return false;
	stack<int> pilaTortitas;
	while (tortita != -1) {
		pilaTortitas.push(tortita);
		cin >> tortita;
	}
	string line;
	int movimientos;
	vector<int> listadoMovimientos;
	cin.ignore();
	getline(cin, line);
	istringstream iss(line);
	while (iss >> movimientos)
	{
		listadoMovimientos.push_back(movimientos);
	}
	cout << calculaVolteo(pilaTortitas, listadoMovimientos) << endl;
	return true;
}
int main() {
	while (resuelve());
	return 0;
}