#ifndef LIBRERIA_H
#define LIBRERIA_H
#include "TreeMap.h"
#include "HashMap.h"
#include "List.h"
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;
typedef string libro;
typedef List<libro> listaLibros;
typedef struct infoLibro {
	int numEjemplares;
	int numVendidos;
};
class Libreria {
public: Libreria() {}
		void nuevoLibro(const libro &l, const int &numEjemplares){ // Operacion modificadora  de coste constante
			mapaLibros[l].numEjemplares += numEjemplares;
		}
		void comprar(const libro &l) { 
			if (!mapaLibros.contains(l))							//Operacion constante
				throw invalid_argument("Libro no existente");
			if (mapaLibros.at(l).numEjemplares == 0)
				throw out_of_range("No hay ejemplares");

			//Si ha vendido algun ejemplar borramos el libro de la lista de numVendidos antigua
			if(mapaLibros.at(l).numVendidos != 0)
				elimLibroDeLista(l);		
			//Actualizamos la informacion del libro y lo añadimos a la nueva lista de vendidos
			mapaLibros[l].numVendidos++;
			mapaVentas[mapaLibros.at(l).numVendidos].push_front(l);
		}

		bool estaLibro(const libro & l)const {	//Operacion observadora de coste constante
			return mapaLibros.contains(l);
		}

		void elimLibroDeLista( const libro & l) {
			listaLibros lista = mapaVentas.at(mapaLibros.at(l).numVendidos);
			listaLibros::Iterator it = lista.begin();
			listaLibros::Iterator itFin = lista.end();
			bool eliminado = false;
			while (it != itFin && !eliminado) {
				if (it.elem() == l) {
					it = lista.erase(it);
					eliminado = true;
				}
				else
					it.next();
			}
			mapaVentas.insert(mapaLibros.at(l).numVendidos, lista);
		}

		void elimLibro(const libro &l) {
			if (mapaLibros.contains(l)) {
				elimLibroDeLista(l);
				mapaLibros.erase(l);
			}
		}

		int numEjemplares(const libro &l) const {
			if (!mapaLibros.contains(l))
				throw invalid_argument("Libro no existente");
			return mapaLibros.at(l).numEjemplares;
		}

		const List<libro> top10()const {
			listaLibros lista,miLista;
			TreeMap<int, listaLibros>::ConstIterator it = mapaVentas.cbegin();
			TreeMap<int, listaLibros>::ConstIterator itFin = mapaVentas.cend();
			while (it != itFin) {
				lista = it.value();
				listaLibros::ConstIterator itLista = lista.cbegin();
				listaLibros::ConstIterator itFinLista = lista.cend();
				while (itLista != itFinLista) {
					miLista.push_front(itLista.elem());
					itLista.next();
				}
				it.next();
			}
			if (miLista.size() > 10) {
				listaLibros listaAux;
				int contador = 0;
				listaLibros::ConstIterator itLista = miLista.cbegin();
				while (contador != 10) {
					listaAux.push_back(itLista.elem());
					itLista.next();
				}
				miLista = listaAux;
			}
			return miLista;
		}
private:
	HashMap<libro, infoLibro> mapaLibros;
	TreeMap<int, listaLibros> mapaVentas;
};


#endif // !LIBRERIA_H

#pragma once
