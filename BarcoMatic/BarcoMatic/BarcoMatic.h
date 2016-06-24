/*Javier Mendoza*/
#ifndef BARCO_MATIC_H
#define BARCO_MATIC_H
#include "HashMap.h"
#include "List.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

typedef string pescador;
typedef string especie;
typedef int kilos;
typedef pair<especie, kilos> captura;
typedef struct infoPescador{
	List<captura> listaCapturas;
	kilos kilosPescados;
};
class BarcoMatic{
public:
	void nuevo(const int &numKilos);		//Operacion generadora de coste constante
	void altaPescador(const pescador & p); //Operacion modificadora de coste constante
	void nuevaCaptura(const pescador &p, const especie &e, const kilos &kilosPescados); //Operacion modificadora de coste constante
	List<captura> capturasPescador(const pescador & p) const; //Operacion observadora de coste lineal en el numero de capturas del pescador p
	int kilosEspecie(const especie &e)const; //Operacion observadora de coste constante
	int kilosPescador(const pescador &p) const; //Operacion obscervadora de coste constante
	int bodegaRestante()const;//Operacion observadora de coste constante
private: HashMap<pescador, infoPescador> mapaPescadores;
		 HashMap<especie, kilos> mapaEspecie;
		 int numKilosRestantes;
};
void BarcoMatic::nuevo(const int &numKilos) {
	this->numKilosRestantes = numKilos;
}
void BarcoMatic::altaPescador(const pescador & p) {
	if (mapaPescadores.contains(p))
		throw out_of_range("El pescador ya existe");
	mapaPescadores.insert(p, infoPescador());
}
void BarcoMatic::nuevaCaptura(const pescador &p, const especie &e, const kilos &kilosPescados) {
	if (!mapaPescadores.contains(p)) {
		throw out_of_range("No existe el pescador");
	}
	if (numKilosRestantes < kilosPescados) {
		throw invalid_argument("Los kilos pescados exceden el tamaño maximo de la bodega");
	}
	captura cap(e, kilosPescados);
	mapaPescadores[p].listaCapturas.push_back(cap);
	mapaPescadores[p].kilosPescados += kilosPescados;
	mapaEspecie[e] += kilosPescados;
	numKilosRestantes -= kilosPescados;
}
List<captura> BarcoMatic::capturasPescador(const pescador & p) const {
	if (!mapaPescadores.contains(p))
		throw out_of_range("El pescador no existe");
	return mapaPescadores.at(p).listaCapturas;
}
int BarcoMatic::kilosEspecie(const especie &e)const {
	return mapaEspecie.at(e);
}
int BarcoMatic::bodegaRestante() const {
	return numKilosRestantes;
}
int BarcoMatic::kilosPescador(const pescador &p) const {
	return mapaPescadores.at(p).kilosPescados;
}



#endif // !BARCO_MATIC_H
#pragma once
