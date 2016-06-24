#include <iostream>
using namespace std;
void procesaProductos(int precios[], int precioActual, int maxPrecio, int proteinas[], int proteinasActual, int minProteinas, int calorias[],
	int caloriasActual, int caloriasMejor, int k, bool marcados[], bool sol[],int n,int proteinasRestantes[]){
	marcados[k] = true;
	caloriasActual += calorias[k];
	proteinasActual += proteinas[k];
	precioActual += precios[k];
	if (precioActual <= maxPrecio){
		if (k == n - 1){
			if (proteinasActual >= minProteinas){
				if (caloriasActual < caloriasMejor){
					caloriasMejor = caloriasActual;
					sol = marcados;
				}
			}
		}
		else{
			if (caloriasActual < caloriasMejor)
			procesaProductos(precios, precioActual, maxPrecio, proteinas, proteinasActual, minProteinas, calorias, caloriasActual, caloriasMejor, k + 1, marcados, sol, n,proteinasRestantes);
		}

	}
	marcados[k] = false;
	proteinasActual -= proteinas[k];
	precioActual -= precios[k];
	caloriasActual -= calorias[k];

	if (k == n - 1){
		if (proteinasActual >= minProteinas){
			if (caloriasActual < caloriasMejor){
				caloriasMejor = caloriasActual;
				sol = marcados;
			}
		}
	}
	else{
		if (proteinasActual + proteinasRestantes[k] >= minProteinas && caloriasActual < caloriasMejor)
		procesaProductos(precios, precioActual, maxPrecio, proteinas, proteinasActual, minProteinas, calorias, caloriasActual, caloriasMejor, k + 1, marcados, sol, n,proteinasRestantes);
	}

}
int calculaProteinasRestantes(int proteinas[],int proteinasRestantes[], int n){
	int suma = 0;
	for (int i = n - 1; i >= 0; i--){
		proteinasRestantes[i] = suma;
		suma += proteinas[i];
	}
}
bool resuelve(){
	int numProductos;
	int precios[100];
	int calorias[100];
	int proteinas[100];
	int proteinasRestantes[100];
	bool marcados[100],solucion[100];
	int maxPrecio, minProteinas;
	cin >> numProductos;
	if (numProductos == 0)
		return false;
	for (int i = 0; i < numProductos; i++){
		cout << "Precio " << i + 1 << ": ";
		cin >> precios[i];
	}
	for (int i = 0; i < numProductos; i++){
		cout << "Proteinas " << i + 1 << ": ";
		cin >> proteinas[i];
	}
	calculaProteinasRestantes(proteinas,proteinasRestantes,numProductos);
	for (int i = 0; i < numProductos; i++){
		cout << "Calorias " << i + 1 << ": ";
		cin >> calorias[i];
	}
	cout << "MAX PRECIO: ";
	cin >> maxPrecio;
	cout << "MIN PROTEINAS: ";
	cin >> minProteinas;
	procesaProductos(precios, 0, maxPrecio, proteinas, 0, minProteinas, calorias, 0, INT_MAX, 0, marcados, solucion, numProductos, proteinasRestantes);
	return true;
}
int main(){
	while (resuelve());
}