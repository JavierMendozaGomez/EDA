#include <iostream>
/*
Grupo GISA-23: Javier Mendoza Gomez y Daniel Martin Barrios
*/


/*Especificacion:
 requires:: n>=0
 func hacerMedia (int v[],int n) return bool b
 ensures:: b =  (for all k :: 0<=k<n : v[k] > 0) || 
  exists m: 0<=m<n:v[k] >= 9);
*/
bool hacerMedia(float v[], int n){
	int i = 0;
	int j;
	/*
	Invariante:0<=i<=n :: forall k:: 0<=k < i ::v[k] != 0 && v[k] < 9
	*/
	while ((i < n) && !(v[i] == 0) && !(v[i] >= 9)){//Sal del bucle cuando encuentres un 0 o alguna nota mayor igual que 9
		i = i + 1;
	}
	if (i != n){
		j = i;
		/*
		Invariante: i <= j <= n: forall l:: i<=l<n: v[l] < 9
		*/
		while ((j < n) && !(v[j] >= 9)){ //Hasta que encuentres algun nueve
			j++;
		}
	}
	return ((i == n) || (j != n));
}
void resuelve()
{
	int nElems;
	std::cin >> nElems;
	float v[100000];
	for (int i = 0; i<nElems; i++)
	{
		std::cin >> v[i];
	};
	if (hacerMedia(v, nElems))
		std::cout << "MEDIA" << std::endl;
	else
		std::cout << "SUSPENSO" << std::endl;
}
int main(){
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}