#ifndef HORAS
#define HORAS
#include <stdexcept>
class Horas{
public:Horas(int horas, int minutos, int segundos);
	   int getHoras() const;
	   int getMinutos()const;
	   int getSegundos()const;
	   bool esMasTardeQue(const Horas &hora2)const;
private:
	int _horas;
	int _minutos;
	int _segundos;
};

Horas::Horas(int horas, int minutos, int segundos){
	if ((0 <= horas) && (horas <= 23) && (0 <= minutos) && (minutos <= 59) && (0 <= segundos) && (segundos <= 59)){
		_horas = horas;
		_minutos = minutos;
		_segundos = segundos;
	}
	else
		throw std::invalid_argument("ERROR");

}
int Horas::getHoras()const{
	return _horas;
}

int Horas::getMinutos()const{
	return _minutos;
}

int Horas::getSegundos()const{
	return _segundos;
}

bool Horas::esMasTardeQue(const Horas &hora2)const{
	if (getHoras() >= hora2.getHoras())
		return true;
	else if (getHoras() == hora2.getHoras() && getMinutos() >= hora2.getMinutos())
		return true;
	else if (getHoras() == hora2.getHoras() && getMinutos() == hora2.getMinutos() && getSegundos() >= hora2.getSegundos())
		return true;
	return false;
}
#endif