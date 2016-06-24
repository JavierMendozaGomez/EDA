#include <iostream>
#include <algorithm>
using namespace std;
/*Función que dada una columna, nos devolverá la posicion de  fila mínima que tenga un 1*/
int buscaFila(int matriz[100][100], const int & a, const int &b,const int &col){
	if (b - a + 1 == 1){
		if (matriz[a][col] != 0)
			return a;
		return 999;
		}
	else{
		int mitad = (a + b)/ 2;
		return std::min(buscaFila(matriz, a, mitad, col), buscaFila(matriz, mitad + 1, b,col));
		}
	}

int buscaCol(int matriz[100][100], const int &a, const int &b,const int &numFilas, int &solFila){
	/*Si la columna es única*/
	if (b - a + 1 == 1){
		int aFila = 0;
		int aux = buscaFila(matriz, aFila, numFilas - 1, a);
		/*Si no existen 1's en esa columna*/
		if (aux == 999)
			return 999;
		solFila = std::min(solFila, aux);
		return a;
	}
	else{
		int mitad = (a + b) / 2;
		return std::min(buscaCol(matriz, a, mitad,numFilas,solFila),buscaCol(matriz, mitad + 1, b,numFilas,solFila));
	}
}
void buscaTriangulo(int matriz[100][100], const int & numFilas, const int &numCols, int& solFila, int &solCol){
	int a = 0;
	solCol = buscaCol(matriz, a, numCols - 1, numFilas, solFila);
}
	bool resuelve(){
	int N, M;
	int solFila=999, solCol;
	cin >> N;
	if (!cin)
		return false;
	cin >> M;
	int matriz[100][100];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
			cin >> matriz[i][j];
	}
	buscaTriangulo(matriz, N, M,solFila,solCol);
	cout << solFila << " " <<  solCol << endl;
	return true;
}
int main(){
	while (resuelve());
}