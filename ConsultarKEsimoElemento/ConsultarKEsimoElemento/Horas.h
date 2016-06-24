#ifndef  HORAS_H
#define HORAS_H
#include <iostream>
#include <iomanip>
using namespace std;

/*Clase horas que guarda en formato horas,minutos y segundos la hora*/
class Horas {
public:
	/*Constructora del programa,coste constante*/
	Horas();
	Horas(int &numSegundos);
	int getNumSegundos()const;
	/*Compara 2 horas y devuelve true si es menor estricto que la primera,coste constante*/
	bool operator<(const Horas &hora2)const;
	Horas operator +(const Horas &hora2);
	/*Compara 2 horas y devuelve true si es menor o igual que la primera,coste constante*/
	bool operator<=(const Horas &hora2)const;
	/*Compara las dos horas y devuelve true si las horas son iguales,coste constante*/
	bool operator==(const Horas &hora2)const;
	/*Compara las dos horas y devuelve true si las horas son distintas,coste constante*/
	bool operator!=(const Horas &hora2)const;
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
Horas::Horas(int &numSegundos) {
	_horas = numSegundos / 3600;
	numSegundos = numSegundos - _horas * 3600;
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
bool Horas::operator!=(const Horas &hora2)const {
	return ((_horas != hora2._horas) || (_minutos != hora2._minutos) || (_segundos != hora2._segundos));
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
#endif