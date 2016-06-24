#include "Consultorio.h"
#include <iostream>
using namespace std;
void mostrar(const List<Cita> &lista) {
	List<Cita>::ConstIterator it = lista.cbegin();
	List<Cita>::ConstIterator itFin = lista.cend();
	while (it != itFin) {
		cout << it.elem().pac << " " << it.elem().fecha  << endl;
		it.next();
	}
	if (lista.size() == 0)
		cout << endl;
}
bool resolverCaso() {
		Consultorio c;
		string nombreMedico;
		string nombrePaciente;
		Fecha fecha;
		string nombreOp;
		int numOp;
		cin >> numOp;
		if (!cin) return false;
		for (int i = 0; i < numOp; ++i) {
			cin >> nombreOp;
			if (nombreOp == "nuevoMedico") {
				cin >> nombreMedico;
				c.nuevoMedico(nombreMedico);
			}
			else if (nombreOp == "pideConsulta") {
				cin >> nombreMedico >> nombrePaciente >> fecha;
				try {
					c.pideConsulta(nombreMedico, nombrePaciente,fecha);
				}
				catch (invalid_argument const& e) {
					cout << e.what() << '\n';
					cout << "---" << endl;
				}
			}
			else if (nombreOp == "siguientePaciente") {
				cin >> nombreMedico;
				try {
					cout << c.siguientePaciente(nombreMedico) << endl;
				}
				catch (invalid_argument const& e) {
					cout << e.what() << '\n';
				}
				catch (out_of_range const& e) {
					cout << e.what() << '\n';
				}
				cout << "---" << endl;

			}
			else if (nombreOp == "atiendeConsulta") {
				cin >> nombreMedico;
				try {
					c.atiendeConsulta(nombreMedico);
				}
				catch (invalid_argument const& e) {
					cout << e.what() << '\n';
					cout << "---" << endl;
				}
				catch (out_of_range const& e) {
					cout << e.what() << '\n';
					cout << "---" << endl;
				}
			}
			else if (nombreOp == "listaPacientes") {
				int dia;
				cin >> nombreMedico >> dia;
				mostrar(c.getListaPacientes(nombreMedico,dia));
				cout << "---" << endl;
			}
		}
		cout << "------" << endl;
		return true;
	}
int main() {
	while (resolverCaso());
	return 0;
}