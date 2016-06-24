#include <iostream>
#include "Persona.h"
#include "doubleLinkedList.h"
using namespace std;
bool resuelve(){
	int numPersonas, edadMinima, edadMaxima;
	cin >> numPersonas;
	if (numPersonas == 0)
		return false;
	cin >> edadMinima >> edadMaxima;
	Persona persona;
	DoubleLinkedList<Persona> lista;

	for (int i = 0; i < numPersonas; i++){
		cin >> persona;
		lista.push_front(persona);
	}
	
	lista.eliminaPorFuncion([edadMinima, edadMaxima](Persona p) {
		return (edadMinima <= p.getEdad()) && (p.getEdad() <= edadMaxima);
	});
	lista.imprimeLista();
	return true;
}
int main(){
	while (resuelve());
	return 0;
}