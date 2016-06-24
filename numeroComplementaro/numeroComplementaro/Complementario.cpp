/*GRUPO GIAS23: JAVIER MENDOZA GOMEZ Y DANIEL MARTIN BARRIOS*/
#include <iostream>
using namespace std;

/*VERSION FINAL*/
void calculaCompFinal(const int &num,  int &cociente,int &res){
	if (num < 10)
		res += (9-num)*cociente;
	else{
		int mod = num % 10;
		res = res + cociente*(9-mod);
		cociente = cociente * 10;
		calculaCompFinal(num / 10, cociente, res);
	}

}

bool resuelveFinal(){
	int numero;
	int cociente = 1;
	int res = 0;
	cin >> numero;
	if (numero == -1)
		return false;
	calculaCompFinal(numero, cociente, res);
	cout << res << endl;
	return true;
}


/*VERSION NO FINAL*/
int calculaCompAux(const int &num,  int &cociente){
	int res;
	int mod = num % 10;
	if (num < 10)
		res = (9 - num)*cociente;
	else{
		cociente = cociente * 10;
		res = calculaCompAux(num / 10, cociente) + ((9 - mod)*cociente);
	}
	cociente = cociente / 10;
	
	return res;
}

int calculaComp(const int &num){
	int cociente = 1;
	return calculaCompAux(num, cociente);
}

bool resuelve(){
	int numero;
	cin >> numero;
	if (numero == -1)
		return false;
	cout << calculaComp(numero) << endl;

	return true;
}
int main(){
	while (resuelve());
	return 0;
}