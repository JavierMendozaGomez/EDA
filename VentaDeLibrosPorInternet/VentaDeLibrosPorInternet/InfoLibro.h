/*Nombre: Javier Mendoza Gómez*/
#ifndef INFO_LIBRO
#define INFO_LIBRO
#include <string>
#include <iostream>
using namespace std;
class infoLibro {
	private:	
	string nombreLibro;
	int numEjemplares;
	int numVendidos;
	int ultVenta;

	public:
	infoLibro(){}
	infoLibro(string nombreLibro, int numEjemplares){
		this->nombreLibro = nombreLibro;
		this->numEjemplares = numEjemplares;
		this->numVendidos = 0;
		this->ultVenta = 0;
	}

	bool operator<(const infoLibro &info2)const{
		if (numVendidos < info2.numVendidos) {
			return true;
		}
		else if (numVendidos == info2.numVendidos) {
			return (ultVenta < info2.ultVenta);
		}
		else
			return false;
	}

	void compraLibro(){
		numVendidos++;
	}

	void setUltimaVenta(const int &ultVenta) {
		this->ultVenta = ultVenta;
	}
	void aumentaEjemplares(const int &numEjemplares) {
		this->numEjemplares += numEjemplares;
	}
	int getNumEjemplares() const {
		return this->numEjemplares;
	}
	string getNombreLibro() const {
		return this->nombreLibro;
	}
	int getNumVendidos() const {
		return this->numVendidos;
	}

};
#endif // !INFO_LIBRO
