/*GIS-A51: Javier Mendoza Gomez*/
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <iostream>
#include <climits>
/*Descripcion del programa, dado un listado de trabajos, las ordena , e imprime por pantalla aquel intervalo de tiempo de horas de mayor duracion*/
using namespace std;
/*Clase horas que guarda en formato horas,minutos y segundos la hora*/
class Horas {
public:
	/*Constructora del programa,coste constante*/
	Horas();
	Horas( int &numSegundos);
	int getNumSegundos()const;
	/*Compara 2 horas y devuelve true si es menor estricto que la primera,coste constante*/
	bool operator<(const Horas &hora2)const;
	Horas operator +(const Horas &hora2);
	/*Compara 2 horas y devuelve true si es menor o igual que la primera,coste constante*/
	bool operator<=(const Horas &hora2)const;
	/*Compara las dos horas y devuelve true si las horas son iguales,coste constante*/
	bool operator ==(const Horas &hora2)const;
	/*Obtiene los datos de la hora,coste constante*/
	friend istream& operator >> (istream &i, Horas &hora);
	/*Imprime la hora,coste constante*/
	friend ostream& operator << (ostream &o, const Horas &hora);

private:
	int _horas;
	int _minutos;
	int _segundos;

};

Horas::Horas() {
	_horas = 0;
	_minutos = 0;
	_segundos = 0;
}
Horas::Horas( int &numSegundos) {
	_horas = numSegundos / 3600;
	numSegundos = numSegundos - _horas*3600;
	_minutos = numSegundos / 60;
	_segundos = numSegundos - _minutos * 60;
}
int Horas::getNumSegundos()const {
	return _horas * 3600 + _minutos * 60 + _segundos;
}
Horas Horas::operator+(const Horas &hora2) {
	Horas hora;
	hora._horas = _horas + hora2._horas;
	hora._minutos = _minutos + hora2._minutos;
	hora._segundos = _segundos + hora2._segundos;

	if (hora._segundos > 59) {
		hora._segundos -= 60;
		hora._minutos += 1;
	}
	if (hora._minutos > 59) {
		hora._minutos -= 60;
		hora._horas += 1;
	}
	if (hora._horas > 23)
		throw std::invalid_argument("Horas del dia superadas");
	return hora;
}
bool Horas::operator<(const Horas &hora2)const {
	if (_horas < hora2._horas)
		return true;
	else if (_horas == hora2._horas && _minutos < hora2._minutos)
		return true;
	else if (_horas == hora2._horas && _minutos == hora2._minutos && _segundos < hora2._segundos)
		return true;
	return false;

}
bool Horas::operator<=(const Horas &hora2)const {
	if (_horas < hora2._horas)
		return true;
	else if (_horas == hora2._horas && _minutos < hora2._minutos)
		return true;
	else if (_horas == hora2._horas && _minutos == hora2._minutos && _segundos < hora2._segundos)
		return true;
	else if (_horas == hora2._horas && _minutos == hora2._minutos && _segundos == hora2._segundos)
		return true;
	return false;

}
bool Horas::operator==(const Horas &hora2)const {
	return ((_horas == hora2._horas) && (_minutos == hora2._minutos) && (_segundos == hora2._segundos));
}
istream& operator >> (istream &i, Horas &hora) {
	char c;
	i >> hora._horas >> c >> hora._minutos >> c >> hora._segundos;
	if (hora._horas < 0 || hora._horas > 23 || hora._minutos < 0 || hora._minutos > 59 || hora._segundos < 0 || hora._segundos > 59) {
		throw std::invalid_argument("ERROR");
	}
	return i;
}
ostream& operator << (ostream &o, const Horas & hora) {
	o << setw(2) << setfill('0') << hora._horas << ":" << setw(2) << setfill('0') << hora._minutos << ":" << setw(2) << setfill('0') << hora._segundos;
	return o;
}
/*Coste lineal en el numero de trabajos*/
void procesaTrabajos(const vector<int> &listaTrabajos) {
	int maxDuracion = INT_MIN;
	int duracionActual = INT_MIN;
	int  horaInicio;
	for (int i = listaTrabajos.size()-1; i >= 1; i--) {
		duracionActual = listaTrabajos.at(i) - listaTrabajos.at(i - 1);
		if (duracionActual >= maxDuracion) {
			horaInicio = listaTrabajos.at(i - 1);
			maxDuracion = duracionActual;
		}
	}
	cout << Horas(horaInicio) << " " << Horas(maxDuracion) << endl;
}
/*Coste nlogn siendo n el numero de trabajos*/
bool resuelve() {
	int numTrabajos;
	cin >> numTrabajos;
	if (numTrabajos == 0)
		return false;
	Horas hora;
	std::vector<int> listaTrabajos;
	for (int i = 0; i < numTrabajos; i++) {
		cin >> hora;
		listaTrabajos.push_back(hora.getNumSegundos());
	}
	sort(listaTrabajos.begin(), listaTrabajos.end());
	procesaTrabajos(listaTrabajos);
	return true;
}
int main() {
	while (resuelve());
	return 0;
}