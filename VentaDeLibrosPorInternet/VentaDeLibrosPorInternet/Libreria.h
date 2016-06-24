#ifndef LIBRERIA
#define LIBRERIA

#include "InfoLibro.h"
#include "HashMap.h"


#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Libreria {
	HashMap<string, infoLibro> tabla;
	int ultVenta;

	public:

		   Libreria(){
				ultVenta = 0;
		   }

		   void nuevoLibro(const string & nombreLibro, const int &numEjemplares) {
			   if (!tabla.contains(nombreLibro)) {
				   infoLibro info(nombreLibro, numEjemplares);
				   tabla.insert(nombreLibro, info);
			   }
			   else {
				   infoLibro info;
				   info = tabla[nombreLibro];
				   info.aumentaEjemplares(numEjemplares);
				   tabla.insert(nombreLibro, info);
			   }
		   }
		   

		   void comprar(const string &libro){
			   if (tabla.contains(libro)) {
				   if (tabla.at(libro).getNumEjemplares() > 0) {
					   infoLibro info;
					   info = tabla[libro];
					   info.compraLibro();
					   info.setUltimaVenta(ultVenta);
					   tabla.insert(libro, info);
					   ultVenta++;
				   }
				   else {
					   throw std::out_of_range("No hay ejemplares");
				   }
			   }
			   else {
				   throw std::invalid_argument("Libro no existente");
			   }
		   }

		   bool estaLibro(const string & nombreLibro) const{
			   return tabla.contains(nombreLibro);
		   }

		   void elimLibro(const string & nombreLibro) {
			   if (tabla.contains(nombreLibro))
				   tabla.erase(nombreLibro);
		   }
		   int numEjemplares(const string &nombreLibro) const{
			   if (tabla.contains(nombreLibro))
				   return tabla.at(nombreLibro).getNumEjemplares();
			   else
				   throw std::invalid_argument("Libro no existente");
		   }

		   list<string> top10() {
			   list<string> topLibros;
			   std::vector<infoLibro> listaLibros;
			   HashMap<string, infoLibro>::ConstIterator it = tabla.cbegin();
			   while (it != tabla.cend()) {
				   if (it.value().getNumVendidos() != 0) {
					   listaLibros.push_back(it.value());
				   }
				   it.next();
			   }
			   sort(listaLibros.begin(), listaLibros.end());
			   int fin = listaLibros.size() - 10 - 1;
			   if (fin <= 0) {
				   for (int i = listaLibros.size() - 1; i >= 0; i--) {
					   topLibros.push_back(listaLibros.at(i).getNombreLibro());
				   }
			   }
			   else {
				   for (int i = listaLibros.size() - 1; i >= fin ; i--) {
					   topLibros.push_back(listaLibros.at(i).getNombreLibro());
				   }
			   }
			   return topLibros;
		   }

		   void muestraTodos() {

			   HashMap<string, infoLibro> ::ConstIterator it = tabla.cbegin();
			   while (it != tabla.cend()) {
				   cout << it.value().getNombreLibro() << endl;
				   it++;
			   }
		   }
		   


	
	
};
#endif