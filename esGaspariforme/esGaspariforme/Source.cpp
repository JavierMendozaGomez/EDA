/*Autor:Javier Mendoza Gomez*/
#include <iostream>
/*Orden lineal: en el numero de vectores del vector*/
bool esGaspariforme(const int v[], const int&n){
	int sumaTotal = 0;
	int i = 0;
	while (i < n){
		if (!((sumaTotal += v[i]) >= 0))   
			return false;
		i++;
	}
	return (sumaTotal == 0);
}

void resuelve()
{
	int nElems;
	std::cin >> nElems;
	int v[10000];
	for (int i = 0; i<nElems; i++)
	{
		std::cin >> v[i];
	};
		std::cout << esGaspariforme(v, nElems) << std::endl;

}

int main() {
	int nCasos;
	std::cin >> nCasos;
	for (int i = 0; i<nCasos; i++) {
		resuelve();
	}

	return 0;
}
