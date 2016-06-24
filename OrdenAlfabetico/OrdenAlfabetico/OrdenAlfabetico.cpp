#include <iostream>
#include <string>
using namespace std;
void procesaPalabra(string entrada, string & salida, int &longitud){
	if (entrada.size() <= 1){
		longitud = entrada.size();
		salida = entrada;
	}
		
	else{
		salida = entrada[0];
		size_t i = 1;
		while  (i != (entrada.size())  && (entrada[i-1] <= entrada[i])){
			salida += entrada[i];
			i++;
		}
		longitud = i;
		size_t j = i;
		int longActual = 0;
		string salidaActual, salidaFinal;
		while (j != (entrada.size())){
			if ((longActual == 0) || entrada[j - 1] <= entrada[j]){
				longActual++;
				salidaActual += entrada[j];
			}
			else{
				if (longActual >= longitud){
					longitud = longActual;
					salida = salidaActual;
				}
				salidaActual = entrada[j];
				longActual = 1;
			}
			j++;
		}
		if (longActual >= longitud){
			longitud = longActual;
			salida = salidaActual;
		}
	}
	
}
bool resuelve(){
	string entrada,salida;
	int longitud;
	cin >> entrada;
	if (entrada == "XXX")
		return false;
	procesaPalabra(entrada, salida, longitud);
	cout << entrada.size() << " " << longitud << " " << salida << endl;
	return true;
}
int main(){
	while (resuelve());
	return 0;
}