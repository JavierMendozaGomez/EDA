#include <iostream>
using namespace std;


struct tActividad{
	int inicio;
	int fin;
	int indice;
};
bool esValida(tActividad ultimoMarcado,tActividad actividades[],int k){
	return((k == 0) || (ultimoMarcado.fin <= actividades[k].inicio));
}
void imprimeSol(tActividad actividades[],bool marcados[] ,int n){
	for (int i = 0; i < n; i++){
		if (marcados[i])
			cout << actividades[i].indice << " ";
	}
	cout << endl;

}
void procesaActividades(tActividad actividades[], int n, int k, int r, bool marcados[], int &numActivades, tActividad ultimoMarcado,int &nodos){
	nodos++;
	marcados[k] = true;
	numActivades = numActivades + 1;
	if (esValida(ultimoMarcado, actividades, k)){
		if (k == n - 1){
			if (numActivades >= r)
				imprimeSol(actividades, marcados, n);
		}
		else{
			procesaActividades(actividades, n, k+1, r, marcados, numActivades, actividades[k],nodos);
	
		}
	}
	numActivades = numActivades - 1;
	marcados[k] = false;
	
	if (k == n - 1){
		if (numActivades >= r)
			imprimeSol(actividades, marcados, n);
	}
	else{
		if (numActivades+(n-k-1) >= r)
			procesaActividades(actividades, n, k + 1, r, marcados, numActivades, ultimoMarcado,nodos);

		}
	

}
/*
void procesaActividades(tActividad actividades[], int n, int k, int r, bool marcados[], int &numActivades, tActividad ultimoMarcado,int &nodos){
	nodos++;
	marcados[k] = true;
	numActivades = numActivades + 1;
	if (esValida(ultimoMarcado, actividades, k)){
		if (numActivades >= r){
			imprimeSol(actividades, marcados, n);
			procesaActividades(actividades, n, k + 1, r, marcados, numActivades, actividades[k],nodos);
			}

		else{
			procesaActividades(actividades, n, k + 1, r, marcados, numActivades, actividades[k],nodos);
		}
	}
	numActivades = numActivades - 1;
	if (numActivades + (n - k - 1) >= r){
		marcados[k] = false;
		if (k < n){
			procesaActividades(actividades, n, k + 1, r, marcados, numActivades, ultimoMarcado,nodos);
		}
	}


}*/
void resuelve(){
	int n,r;
	int nodos = 0;
	int numActividades = 0;
	tActividad actividades[1000];
	cout << "Num Actividades: ";
	cin >> n;
	cout << "Actividades minimas: ";
	cin >> r;
	for (int i = 0; i < n; i++){
		cin >> actividades[i].inicio;
		cin >> actividades[i].fin;
		actividades[i].indice = i + 1;
	}
	bool marcados[100];
	for (int j = 0; j < n; j++)
		marcados[j] = false;
	procesaActividades(actividades, n, 0, r, marcados,numActividades,actividades[0],nodos);
	cout << "el numero de llamadas es " << nodos << endl;
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
}