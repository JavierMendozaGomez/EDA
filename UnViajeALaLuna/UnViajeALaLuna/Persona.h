#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
using namespace std;
class Persona{
public:
	Persona(){}
	Persona(string nombre,int edad){
		this->_edad = edad;
		this->_nombre = nombre;
	}
	int getEdad(){
		return this->_edad;
	}
	string getNombre(){
		return this->_nombre;
	}
	friend istream& operator >> (istream &i, Persona &p){
		i >> p._edad;
		i.ignore();
		getline(i, p._nombre);
		return i;
	}
	friend ostream& operator << (ostream &o, Persona &p){
		o << p.getNombre();
		return o;
	}

private:
	string _nombre;
	int _edad;
};
#endif