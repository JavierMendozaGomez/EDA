#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <iomanip>
using namespace std;
class Fecha {
public:
	Fecha() {}
	Fecha(const int &dias) {
		this->dias = dias;
		this->horas = 0;
		this->minutos = 0;
	}
	friend istream& operator >> (istream& i, Fecha & f);
	friend ostream& operator << (ostream &o, const Fecha &f);
	bool operator < (const Fecha & f2)const{
		return (dias * 1440 + horas * 60 + minutos) < (f2.dias * 1440 + f2.horas * 60 + f2.minutos);
	}
	bool operator == (const Fecha &f2) const {
		return (dias * 1440 + horas * 60 + minutos) == (f2.dias * 1440 + f2.horas * 60 + f2.minutos);
	}
private:
	int dias, horas, minutos;
};
 istream& operator >> (istream& i, Fecha & f){
	i >> f.dias >> f.horas >> f.minutos;
	return i;
}
 ostream& operator << (ostream& o, const Fecha &f) {
	o  << setw(2) << setfill('0') << f.horas << ":" << setw(2) << setfill('0') << f.minutos;
	 return o;
 }

#endif