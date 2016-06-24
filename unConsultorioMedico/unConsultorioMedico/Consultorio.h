#ifndef  CONSULTORIO_H
#define CONSULTORIO_H
#include "HashMap.h"
#include "TreeMap.h"
#include "List.h"
#include "Fecha.h"
#include <stdexcept>
typedef string medico;
typedef string paciente;
typedef TreeMap<Fecha, paciente> listaPacientes;
typedef struct Cita{
	Fecha fecha;
	paciente pac;
};
class Consultorio {
	public:
		Consultorio(){}
		void nuevoMedico(const medico & med) {			//Orden constante?, crear un treemap vacio cuanto cuesta?
			if (!mapaMedico.contains(med)) {
				mapaMedico.insert(med, listaPacientes());
			}
		}
		
		void pideConsulta(const paciente pac, const medico &med, const Fecha & f) {	//Operacion modificadora con coste logaritmico en el numero de citas del medico
			//Comprobamos que el medico exista
			if (!mapaMedico.contains(med)) {               //O(1)
				throw invalid_argument("Medico no existente");
			}
			else {
				listaPacientes lista = mapaMedico.at(med);
				//Comprobamos que la fecha no este ocupada
				if (lista.contains(f)) {					//O(logaritmico en el numero de citas del medico
					throw invalid_argument("Fecha ocupada");
				}
				//Si no esta ocupada, entonces insertamos en la cola de pacientes
				else {
					lista.insert(f, pac);					 ///Logaritmico en el numero de citas
					mapaMedico.insert(med, lista);	//O(1)
				}
			}
		}

		paciente siguientePaciente(const medico &med) const { //Operacion observadora CON orden constante
			//Comprobamos que el medico no existe
			if (!mapaMedico.contains(med))//O(1)
				throw invalid_argument("Medico no existente");
			else { 
				cout << "Siguiente Paciente doctor " << med << endl;
				listaPacientes lista = mapaMedico.at(med); //¿ O(1) o logaritmico en el numero de citas del medico Copiaaa?
				//Comprobamos que tenga algun paciente		
				if (lista.empty())						//O(1)
					throw invalid_argument("No hay pacientes");
				else {
					listaPacientes::ConstIterator it = mapaMedico.at(med).cbegin();		//O(1)
					return it.value();	
				}
			}
		}

		void atiendeConsulta(const medico & med) { //Operacion modificadora con coste logaritmico en el numero  de citas del medico
				//Comprobamos que el medico existe
			if (!mapaMedico.contains(med))
				throw invalid_argument("Medico no existente"); //o(1)
			else {
				//Comprobamos que quedan pacientes
				if (mapaMedico.at(med).empty())
					throw invalid_argument("No hay pacientes"); //o(1)
				//Borramos el primer paciente
				else {
					listaPacientes::Iterator it = mapaMedico[med].begin();// Apuntamos al primer paciente de la cola o(1)
					mapaMedico[med].erase(it.key()); //O(logaritmico en el numero de citas del medico)
				}
			}
		}

		List<Cita> getListaPacientes(const medico & med, const int  &dia)const {	//operacion observadora con coste constante en el numero de citas
			Cita cita;
			if (!mapaMedico.contains(med))
				throw invalid_argument("Medico no existente");
			cout << "Doctor " << med << " dia " << dia << endl;
			List<Cita> miLista;
			Fecha fechaInicio(dia);												//O(1)
			Fecha fechaFin(dia+1);												//O(1)
			listaPacientes::ConstIterator it = mapaMedico.at(med).cbegin();		//O(1)
			listaPacientes::ConstIterator itFin = mapaMedico.at(med).cend();	 //O(1)

			while (it != itFin && (it.key() < fechaInicio)) {		//O(lineal en numero de citas)	
				it.next();
			}
			while (it != itFin && (it.key() < fechaFin)){			//O(lineal en el numero de citas)
				cita.fecha = it.key();
				cita.pac = it.value();
				miLista.push_back(cita);
				it.next();
			}
			return miLista;
		}
		
	private:
		HashMap<medico, listaPacientes> mapaMedico;

};

#endif // ! CONSULTORIO_H
