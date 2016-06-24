#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct tCarta {
	char palo;
	int numero;
};
stack<tCarta> inviertePila(stack<tCarta> &pila) {
	stack<tCarta> aux;
	while (!pila.empty()) {
		aux.push(pila.top());
		pila.pop();
	}
	return aux;
}
bool sePuedeSacar(vector<int> &cartasOrdenadas, tCarta carta) {
	switch (carta.palo) {

	case 'A': {
		if (cartasOrdenadas[0] + 1 == carta.numero) {
			cartasOrdenadas[0] += 1;
			return true;
		}}; break;

	case 'B': {
		if (cartasOrdenadas[1] + 1 == carta.numero) {
			cartasOrdenadas[1] += 1;
			return true;
		}}; break;

	case 'C': {
		if (cartasOrdenadas[2] + 1 == carta.numero) {
			cartasOrdenadas[2] += 1;
			return true;
		}}; break;

	case 'D': {
		if (cartasOrdenadas[3] + 1 == carta.numero) {
			cartasOrdenadas[3] += 1;
			return true;
		}}; break;
	}
	return false;
}
bool procesaCartas(stack<tCarta> pila, int numCartasSacadas, int &numReparticiones) {
	stack<tCarta> pilaAux;
	vector<int> cartasOrdenadas(4,0);
	int contador = 1;
	bool termina = true;
	while (!pila.empty()) {
		pilaAux.push(pila.top());
		if ((contador % numCartasSacadas) == 0) {
			while (!pilaAux.empty() && sePuedeSacar(cartasOrdenadas, pilaAux.top())) {
				termina = false;
				pilaAux.pop();
			}
		}
		pila.pop();
		contador++;
		if (pila.empty()) {
			if (termina)
				return false;
			else {
				pila = inviertePila(pilaAux);
				termina = true;
			}
			numReparticiones++;
		}
	}
	return true;
}



void resuelve() {
	int numCartas, numPalos;
	int numCartasSacadas, numReparticiones = 0;
	tCarta carta;
	stack <tCarta> pilaCartas;

	cin >> numCartas >> numPalos >> numCartasSacadas;
	for (int i = 0; i < numCartas*numPalos; i++) {
		cin >> carta.numero >> carta.palo;
		pilaCartas.push(carta);
	}

	if (procesaCartas(pilaCartas, numCartasSacadas, numReparticiones))
		cout << "SI " << numReparticiones << endl;
	else
		cout << "NO" << endl;
}


int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}