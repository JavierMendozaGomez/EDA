/*GIS-A51: Javier Mendoza Gomez*/
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <iostream>
/*Descripcion del programa, dado un listado de peliculas, las ordena, y las imprime por pantalla, solamente si acaban antes de las 00:00*/
using namespace std;
/*Clase horas que guarda en formato horas,minutos y segundos la hora*/
class Horas {
public:
	/*Constructora del programa,coste constante*/
	Horas();
	/*Compara 2 horas y devuelve true si es menor estricto que la primera,coste constante*/
	bool operator<(const Horas &hora2)const;
	Horas operator +(const Horas & hora2);
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
Horas Horas::operator+(const Horas &hora2){
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
bool Horas::operator<(const Horas &hora2)const{
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
bool Horas::operator==(const Horas &hora2)const{
	return ((_horas == hora2._horas) && (_minutos == hora2._minutos) && (_segundos == hora2._segundos));
}
istream& operator >> (istream &i, Horas &hora) {
	char c;
	i >> hora._horas >> c >> hora._minutos >> c >> hora._segundos;
	if(hora._horas < 0 || hora._horas > 23 || hora._minutos < 0 || hora._minutos > 59 || hora._segundos < 0 || hora._segundos > 59 ){
		throw std::invalid_argument("ERROR");
	}
	return i;
}
ostream& operator << (ostream &o, const Horas & hora) {
	o << setw(2) << setfill('0') << hora._horas << ":" << setw(2) << setfill('0') << hora._minutos << ":" << setw(2) << setfill('0') << hora._segundos;
	return o;
}
/*Clase pelicula que guarda la informacion de la hora de finalizacion,titulo y un booleano que indica si empezo antes de la 00:00 y acabo despues de las 00:00*/
class Pelicula {
public:
		 /*Constructora del programa coste constante*/
		 Pelicula();
		 /*Devuelve true si la pelicula deberia estar antes que la pelicula2, coste constante*/
		 bool operator <(const Pelicula & pelicula2)const;
		 /*Obtiene los datos de la pelicula coste constante*/
		 friend istream& operator >> (istream &i, Pelicula &pelicula);
		 /*Imprime la pelicula: coste constante*/
		 friend ostream& operator << (ostream &o, Pelicula &pelicula);
private: Horas horaFinalizacion;
		 string titulo;
		 bool valida;
};
Pelicula::Pelicula() {
}
bool Pelicula::operator<(const Pelicula &pelicula2)const{
	if (horaFinalizacion < pelicula2.horaFinalizacion)
		return true;
	else if (horaFinalizacion == pelicula2.horaFinalizacion)
		return titulo < pelicula2.titulo;
	return false;
}
istream &operator >>(istream &i, Pelicula &pelicula) {
	char aux;
	Horas horaInicio, duracion;
	i >> horaInicio >> duracion;
	cin.get(aux);
	getline(cin, pelicula.titulo);

	try {
		pelicula.horaFinalizacion = horaInicio+duracion;
	}
	catch (const invalid_argument &ia) {
		throw invalid_argument("La pelicula supera las horas del dia");
	}
	return i;
}
ostream &operator << (ostream &o, Pelicula &pelicula) {
	o << pelicula.horaFinalizacion <<" " <<  pelicula.titulo;
	return o;
}
bool resuelve() {
	int numPeliculas;
	Pelicula pelicula;
	cin >> numPeliculas;
	if (numPeliculas == 0)
		return false;
	std::vector<Pelicula> listaPeliculas;
	for (int i = 0; i < numPeliculas; i++) {
		try {
			cin >> pelicula;
			listaPeliculas.push_back(pelicula);
		}
		catch (const std::invalid_argument &ia) {
		}
	}

	sort(listaPeliculas.begin(), listaPeliculas.end());

	for (size_t j = 0; j < listaPeliculas.size(); j++) {
			cout << listaPeliculas.at(j) << endl;
	}
	cout << "---" << endl;
	return true;
}

int main() {
	while (resuelve());
	return 0;
}



