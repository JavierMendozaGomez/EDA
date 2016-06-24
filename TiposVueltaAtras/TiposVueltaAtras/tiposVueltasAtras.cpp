#include <iostream>
using namespace std;
void imprimeSol(bool marcados[], int m) {
	for (int i = 0; i < m; i++) {
		if (marcados[i]) {
			cout << i + 1 << " ";
		}
	}
	cout << endl;
}
bool esValida() { return true; }
/*Esto es como el de las actividades, todas las posibles actividades CON AL MENOS r tareas.. https://gyazo.com/91fac9cb7f77a81eeebfa7cb996eb09e  */
void procesaMinimos(int v[], bool marcados[], int N, int M, int k, int &numMarcados) {
	numMarcados += 1;
	marcados[k] = true;
	if (esValida()) {
		if (k == M - 1) {
			if (numMarcados >= N)
				imprimeSol(marcados, M);
		}
		else {
			procesaMinimos(v, marcados, N, M, k + 1, numMarcados);
		}
	}
	numMarcados -= 1;
	marcados[k] = false;
	if (k == M - 1) {
		if (numMarcados >= N)
			imprimeSol(marcados, M);
	}
	else {
		procesaMinimos(v, marcados, N, M, k + 1, numMarcados);
	}

}
/*Este nunca lo han pedido, pero es igual de probable que caiga, se trata de dar todas las posibles permutaciones que tengan COMO MAXIMO N elementos de un conjunto de M*/
void procesaMaximos(int v[], bool marcados[], int N, int M, int k, int &numMarcados) {
	numMarcados += 1;
	marcados[k] = true;
	if (esValida()) {
		if (numMarcados == N) {
			imprimeSol(marcados, M);
		}
		else if (numMarcados < N) {
			imprimeSol(marcados, M);
			if (k < M - 1)
				procesaMaximos(v, marcados, N, M, k + 1, numMarcados);
		}
		else {
			if (k < M - 1)
				procesaMaximos(v, marcados, N, M, k + 1, numMarcados);
		}
	}
	numMarcados -= 1;
	marcados[k] = false;
	if (k < M - 1)
		procesaMaximos(v, marcados, N, M, k + 1, numMarcados);
}
/*Este es como el del concierto, muestra todas las permutaciones  que tengan EXACTAMENTE N entre M artistas, https://gyazo.com/d9cdab44f68cc49458151530da5a828f */
void procesaExacto(int v[], bool marcados[], int N, int M, int k, int &numMarcados) {
	numMarcados += 1;
	marcados[k] = true;
	if (esValida()) {
		if (numMarcados == N)
			imprimeSol(marcados, M);
		else {
			if (k < M - 1)
				procesaExacto(v, marcados, N, M, k + 1, numMarcados);
		}
	}
	numMarcados -= 1;
	marcados[k] = false;
	if (k < M - 1) {
		procesaExacto(v, marcados, N, M, k + 1, numMarcados);
	}
}
bool resuelve() {
	int N, M;
	int v[1000];
	int numMarcados = 0;
	bool marcados[1000];
	cout << "tamanio de vector: ";
	cin >> M;
	cout << "subconjuntos de: ";
	cin >> N;
	for (int i = 0; i < M; i++)
		cin >> v[i];
	for (int j = 0; j < M; j++)
		marcados[j] = false;
	cout << "CONJUNTOS COMO MUCHO TIENEN UN " << N << endl;
	procesaMaximos(v, marcados, N, M, 0, numMarcados);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "CONJUNTOS EXACTAMENTE TIENEN " << N << endl;
	procesaExacto(v, marcados, N, M, 0, numMarcados);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "CONJUNTOS COMO MINIMO TIENEN " << N << endl;

	procesaMinimos(v, marcados, N, M, 0, numMarcados);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	return true;
}
int main() {
	while (resuelve());
	return 0;
}