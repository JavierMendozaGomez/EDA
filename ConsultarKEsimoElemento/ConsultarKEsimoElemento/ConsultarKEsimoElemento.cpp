#include <iostream>
#include <string>
#include "TreeMapKesimo.h"
#include "Horas.h"
using namespace std;
bool resuelve() {
	int kEsimo;
	cin >> kEsimo;
	if (!cin)
		return false;
	Horas hora,horaFin;
	TreeMap<Horas,string> listaTareas;
	cin >> hora;
	string nombreTarea;
	while (hora != horaFin) {
		cin >> nombreTarea;
		listaTareas.insert(hora, nombreTarea);
		cin >> hora;
	}
	cout << "si" << endl;
	return true;
}
int main() {
	while (resuelve());
	return 0;
}