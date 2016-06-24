#include <iostream>
using namespace std;
void buscaFila(int matriz[100][100], const int & aFila, const int &bFila, bool & existe,const int &col, int &solFila){
	if (aFila == bFila){
		if (matriz[aFila][col] == 1){
			existe = true;
			solFila = aFila;
		}
		else
			existe = false;
	}
	else{
		int m = (aFila + bFila) / 2;
		buscaFila(matriz, aFila, m, existe, col, solFila);
		if (!existe)
			buscaFila(matriz, m + 1, bFila, existe, col, solFila);
	}
}
void buscaRectanguloAux(int matriz[100][100], const int & aCol,const int &bCol,const int &numFilas, bool &existe, int &solFila, int &solCol){
	if (aCol == bCol){
		int aFila = 0;
		buscaFila(matriz, aFila, numFilas - 1, existe, aCol,solFila);
		if (existe)
			solCol = aCol;
	}
	else{
		int m = (aCol + bCol) / 2;
		buscaRectanguloAux(matriz, aCol, m, numFilas, existe, solFila, solCol);
		if (!existe)
			buscaRectanguloAux(matriz, m + 1, bCol, numFilas, existe, solFila, solCol);
	}
}
void buscaRectangulo(int matriz[100][100], const int & numFilas, const int &numCols,bool &existe, int& solFila, int &solCol){
	int aCol = 0;
	buscaRectanguloAux(matriz, aCol, numCols - 1, numFilas,existe,solFila,solCol);
}
bool resuelve(){
	int N, M;
	int solFila, solCol;
	bool existe;
	cin >> N;
	if (!cin)
		return false;
	cin >> M;
	int matriz[100][100];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
			cin >> matriz[i][j];
	}
	buscaRectangulo(matriz, N, M, existe, solFila, solCol);
	cout << solFila << " " << solCol << endl;
	return true;
}
int main(){
	while (resuelve());
}