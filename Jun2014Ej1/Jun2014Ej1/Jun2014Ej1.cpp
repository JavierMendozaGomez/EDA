#include <iostream>
using namespace std;
bool esValida(int stockMercados[], int i){
	return stockMercados[i] < 3;
}
void procesaProductos(int matriz[100][100],bool marcaje[100][100],bool solucion[100][100],int costeActual,int &costeMejor, int n,int numMercados,int k,int stockMercados[]){
	for (int i = 0; i < numMercados;i++){
		if (esValida(stockMercados, i)){
			stockMercados[i] = stockMercados[i] + 1;
			costeActual += matriz[k][i];
			marcaje[k][i] = true;
			if (k == n - 1){
				if (costeMejor > costeActual){
					costeMejor = costeActual;
					for (int i = 0; i < n; i++){
						for (int j = 0; j < numMercados; j++){
							solucion[i][j] = marcaje[i][j];
						}
					}
				}
			}
			else{
				if (costeActual < costeMejor)
					procesaProductos(matriz, marcaje, solucion, costeActual, costeMejor, n, numMercados, k + 1, stockMercados);
			}
			marcaje[k][i] = false;
			costeActual -= matriz[k][i];
			stockMercados[i] = stockMercados[i] - 1;
		}
		
	}

}
void imprimeSol(bool solucion[100][100], int n, int m){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (solucion[i][j])
				cout << "El producto " << i + 1 << " se compra en el mercado " << j +1 << endl;
		}
	}
}

bool resuelve(){
	int matriz[100][100];/*Matriz que tiene como filas los productos y como columnas los mercados*/
	int stockMercados[100];
	int minCoste = 8000;
	int numProductos,numMercados;
	bool marcaje[100][100];
	bool solucion[100][100];
	cin >> numProductos;
	if (numProductos == 0)
		return false;
	cin >> numMercados;
	for (int i = 0; i < numProductos; i++){
		for (int j = 0; j < numMercados; j++){
			cin >> matriz[i][j];
			solucion[i][j] = false;
			marcaje[i][j] = false;
		}
	}
	for (int i = 0; i < numMercados;i++){
		stockMercados[i] = 0;
	}
	procesaProductos(matriz, marcaje, solucion, 0, minCoste, numProductos, numMercados, 0, stockMercados);
	imprimeSol(solucion, numProductos, numMercados);
	cout << "el min coste es" << minCoste;
	return true;
}
int main(){
	while (resuelve());
	return 0;
} 