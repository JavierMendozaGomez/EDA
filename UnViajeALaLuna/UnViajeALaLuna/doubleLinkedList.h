
#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class DoubleLinkedList {
public:
	// Constructor sin parámetros
	DoubleLinkedList() : _ini(nullptr) {}
    
	// Constructor copia
	DoubleLinkedList(DoubleLinkedList const& other) {
		_ini = copia(other._ini);
	}
    
	// destructor
	~DoubleLinkedList() {
		libera(_ini);
		_ini = nullptr;
	}
    
	// Operador de asignación
	DoubleLinkedList<T> &operator=(const DoubleLinkedList<T> &other) {
        if (this != &other) {
            libera(_ini);
            _ini = copia(other._ini);
        }
        return *this;
    }
    
	// Operador de comparacion
	bool operator== (DoubleLinkedList<T> const& rhs) const {
		Nodo* aux1 = _ini; Nodo* aux2 = rhs._ini;
		while (aux1 != nullptr && aux2 != nullptr){
			if (aux1->_elem != aux2->_elem) return false;
			aux1 = aux1->_sig;
			aux2 = aux2->_sig;
		}
		return (aux1 == nullptr && aux2 == nullptr);
	}
    
	// Añadir un nodo por el comienzo de la lista
	void push_front(const T &e) {
		Nodo * nuevo = new Nodo(nullptr, e, _ini);
		if (_ini != nullptr) _ini->_ant = nuevo;
        _ini = nuevo;
	}
    
	// Elimina el nodo del comienzo de la lista
	void pop_front() {
		if (_ini == nullptr) throw std::invalid_argument("lista vacia");
		Nodo *aux = _ini;
		_ini = _ini->_sig;
		if (_ini != nullptr) _ini->_ant = nullptr;
		delete aux;
	}
	template <typename Func>
	void eliminaPorFuncion(Func funcion){
		Nodo *aux = _ini;
		Nodo *anterior,*siguiente;
		while (aux != nullptr){
			siguiente = aux->_sig;
			anterior = aux->_ant;
			if (!funcion(aux->_elem)){
					if (anterior == nullptr && siguiente == nullptr){ //Si es un único elemento
						_ini = nullptr;
					}	
					else if(siguiente == nullptr){	//Si es el ultimo elemento
						anterior->_sig = nullptr;
					}
					else if(anterior == nullptr){ // Si es el primer elemento
						siguiente->_ant = nullptr;
						_ini = siguiente;
					}
					else {						//Si está entre dos nodos
						siguiente->_ant = anterior;
						anterior->_sig = siguiente;
					}
					delete aux;
				}			
			aux = siguiente;
		}
	}
	void imprimeLista(){
		Nodo *aux = _ini,*ultimoNodo = nullptr;
		while (aux != nullptr) {
			ultimoNodo = aux;
			aux = aux->_sig;
		}
		while (ultimoNodo != nullptr) {
			cout << ultimoNodo->_elem << endl;
			ultimoNodo = ultimoNodo->_ant;
		}
		cout << "---"<< endl;
	}
        
private:
	// Clase nodo que almacena internamente el elemento (de tipo T),
	// y un puntero al nodo siguiente.
	class Nodo {
    public:
		Nodo() : _sig(nullptr), _ant(nullptr) {}
		Nodo(const T &elem) : _elem(elem), _sig(nullptr), _ant(nullptr) {}
		Nodo(Nodo* ant, const T &elem, Nodo *sig) :
        _elem(elem), _sig(sig), _ant(ant) {}
        
		T _elem;
		Nodo* _sig;
		Nodo* _ant;
	};
    
	// Puntero al primer elemento
	Nodo *_ini;
    
	// libera todos los nodos de la lista
    void libera(Nodo *ini) {
		while (ini != nullptr) {
			Nodo *aux = ini;
			ini = ini->_sig;
			delete aux;
		}
	}
    
    // Copia el parámetro en la lista.
    // La lista debe estar vacia.
	Nodo* copia(Nodo* other) {
		if (other == nullptr) return nullptr;
		else if (other->_sig == nullptr) { // Un solo elemento
			Nodo* nuevo = new Nodo(other->_elem);
			return nuevo;
		}
		else {
			Nodo* aux = copia(other->_sig);
			Nodo* nuevo = new Nodo(nullptr, other->_elem, aux);
			aux->_ant = nuevo;
			aux = nuevo;
			return aux;
		}
	}
    
};

#endif // _DOUBLE_LINKED_LIST_H

