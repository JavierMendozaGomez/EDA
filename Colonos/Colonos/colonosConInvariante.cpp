/*Grupo GIS-A23 Javier Mendoza Gomez y Daniel Martin Barrios*/
#include <iostream>
using namespace std;

/*Especificacion*/
/*requires: n>=0*/
/*ensures:contador = #i: 0<= i<= n:sehaColado(v,i,n)
*/
/*Invariante
I= 0 <=i<= n-1:contador = #m i <= m < n: seHaColado(v,m,n)
   && posMenor = min s: (i <= s < n && (for all k: s < k < n :v[k] > v[s])):s
   
 predicate seHaColado ( v:array<int>,i: int, n:int)
  reads a; 
  requires 0<=i<=n<=a.Length
{
  exists k :: i < k < n && v[k] < v[i]
}

*/

int numColados(int v[], int n){
	int contador = 0;
	int i = n-1;
	int posMenor = n-1;//Guarda el indice del elemento mas bajo
	while (0 < i){
		if (v[i - 1] > v[posMenor])
			contador++;
		else
			posMenor = i - 1;
		i--;
	}
	return contador;
}
void resuelve(){
	int v[100000];
	int numElems;
	cin >> numElems;
	for (int i = 0; i < numElems; i++)
	{
		cin >> v[i];
	};
	
	cout << numColados(v, numElems) << endl;
}

int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}