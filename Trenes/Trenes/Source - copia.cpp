/*GIS-A51: Javier Mendoza Gomez*/
#include <stdexcept>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
/*Descripcion del programa, dado un listado de horas, y unas horas buscadas se devuelve en tiempo logartimico si es posible encontrar una hora posterior a la hora buscada
o tambien se indica si alguna hora insertada tiene un formato no permitido*/
using namespace std;
/*Clase horas que guarda en formato horas,minutos y segundos la hora*/
class Horas{
public:
	   /*Constructora del programa,coste constante*/
	   Horas();
	   /*Compara 2 horas y devuelve true si es menor estricto que la primera*/
	   bool operator<(const Horas &hora2)const;
	   /*Compara 2 horas y devuelve true si es menor o igual que la primera*/
	   bool operator<=(const Horas &hora2)const;
	   /*Inicializa la hora*/
	   friend istream& operator >> (istream &i, Horas &hora);
	   /*Imprime la hora*/
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
istream& operator >> (istream &i, Horas &hora) {
	char c;
	i >> hora._horas >> c >> hora._minutos >> c >> hora._segundos;
	if (!((0 <= hora._horas) && (hora._horas <= 23) && (0 <= hora._minutos) && (hora._minutos <= 59) && (0 <= hora._segundos) && (hora._segundos <= 59))) {
		throw std::invalid_argument("ERROR");
	}
	return i;
}
ostream& operator << (ostream &o, const Horas & hora) {
	o << setw(2) << setfill('0') << hora._horas << ":" << setw(2) << setfill('0') << hora._minutos << ":" << setw(2) <<  setfill('0') << hora._segundos;
	return o;
}

/*Busqueda logaritmica en el numero de elementos del vector 'v' que devuelve un booleano  indicando si se ha encontrado una hora posterior a la hora pasada por parámetro*/
bool buscar(vector<Horas> const &v, const size_t &a , const size_t &b ,const Horas &horaBuscada, size_t &pos){
	if (a == b) {
		if (horaBuscada <= v[a]) {
			pos = a;
			return true;
		}
		return false;			
	}
	else {
		int m = (a + b) / 2;
		if(horaBuscada <= v[m]) {		//Si es posterior a la hora buscada
			return buscar(v, a, m, horaBuscada, pos);
		}
		else {								//Si es anterior a la hora buscada
			return buscar(v, m + 1, b, horaBuscada, pos);
		}
	}
}
/*Busqueda lineal en el numero de elementos del vector 'v' que devuelve un booleano  indicando si se ha encontrado una hora posterior a la hora pasada por parámetro*/
bool buscarLineal(vector<Horas> const &v,const  Horas &horaBuscada, size_t &pos) {
	size_t i = 0;
	while (i != v.size() && v[i] < horaBuscada) {
		i = i + 1;
	}
	if (i != v.size()) {
		pos = i;
	}
	return i != v.size();
}
/*Funcion que dado un listado de horas y una hora concreta, nos dice la hora posterior mas cercana a la hora buscada, coste logaritmico en el numero de elementos del vector*/
void procesaHora(vector<Horas> const &trenes, const Horas &horaBuscada){
	size_t pos;
	if (buscar(trenes, 0, trenes.size() - 1, horaBuscada, pos))
		cout << trenes.at(pos) << endl;
   	else
		cout << "NO" << endl;

}
/*Resuelve el programa, lineal en el maximo entre el numero de elementos del vector y el numero de horas Buscadas*/
bool resuelve(){
	int numTrenes, numHoras;
	Horas hora,horaBuscada;
	std::vector<Horas> trenes;
	cin >> numTrenes >> numHoras;

	if ((numTrenes == 0) && (numHoras == 0))
		return false;
	for (int i = 0; i < numTrenes; i++){
		try{
			cin >> hora;
			trenes.push_back(hora);
		}
		catch (const invalid_argument &ia){
			cout << ia.what() << '\n';
		}
	}
	for (int i = 0; i < numHoras; i++){
		try{
			cin >> horaBuscada;
			procesaHora(trenes, horaBuscada);
		}
		catch (const invalid_argument &ia){
			cout << ia.what() << '\n';
		}
	}
	cout << "---" << endl;
	return true;
}
int main(){
	while (resuelve());
	return 0;
}