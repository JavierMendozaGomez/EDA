/**
 @file TreeMap.h
 
 ImplementaciÛn din·mica del TAD Dictionary utilizando
 ·rboles de b˙squeda.
 
 Estructura de Datos y Algoritmos
 Facultad de Inform·tica
 Universidad Complutense de Madrid
 
 (c) Marco Antonio GÛmez MartÌn, 2012
 */
#ifndef __TREEMAP_H
#define __TREEMAP_H


#include <stdexcept>
#include <stack>
#include <assert.h>

/**
 ImplementaciÛn din·mica del TAD Dictionary utilizando
 ·rboles de b˙squeda (no auto-balanceados).
 
 Las operaciones son:
 
 - TreeMapVacio: operaciÛn generadora que construye
 un ·rbol de b˙squeda vacÌo.
 
 - Insert(clave, valor): generadora que aÒade una
 nueva pareja (clave, valor) al ·rbol. Si la
 clave ya estaba se sustituye el valor.
 
 - erase(clave): operaciÛn modificadora. Elimina la
 clave del ·rbol de b˙squeda.  Si la clave no est·,
 la operaciÛn no tiene efecto.
 
 - at(clave): operaciÛn observadora que devuelve
 el valor asociado a una clave. Es un error preguntar
 por una clave que no existe.
 
 - contains(clave): operaciÛn observadora. Sirve para
 averiguar si se ha introducido una clave en el
 ·rbol.
 
 - empty(): operacion observadora que indica si
 el ·rbol de b˙squeda tiene alguna clave introducida.
 
 @author Marco Antonio GÛmez MartÌn
 
 Modificado por Isabel Pita
 Se utilizan las librerias estandar de manejo de excepciones y de pilas
 */
template <class Clave, class Valor>
class TreeMap {
private:
	/**
	 Clase nodo que almacena internamente la pareja (clave, valor)
	 y los punteros al hijo izquierdo y al hijo derecho.
	 */
	class Nodo {
	public:
		Nodo() : _iz(nullptr), _dr(nullptr) {}
		Nodo(const Clave &clave, const Valor &valor)
        : _clave(clave), _valor(valor), _iz(nullptr), _dr(nullptr) {}
		Nodo(Nodo *iz, const Clave &clave, const Valor &valor, Nodo *dr)
        : _clave(clave), _valor(valor), _iz(iz), _dr(dr) {}
        
		Clave _clave;
		Valor _valor;
		Nodo *_iz;
		Nodo *_dr;
	};
    
public:
    
	/** Constructor; operacion EmptyTreeMap */
	TreeMap() : _ra(nullptr) {
	}
    
	/** Destructor; elimina la estructura jer·rquica de nodos. */
	~TreeMap() {
		libera();
		_ra = nullptr;
	}
    
	/**
	 OperaciÛn generadora que aÒade una nueva clave/valor
	 a un ·rbol de b˙squeda.
	 @param clave Clave nueva.
	 @param valor Valor asociado a esa clave. Si la clave
	 ya se habÌa insertado previamente, sustituimos el valor
	 viejo por el nuevo.
	 */
	void insert(const Clave &clave, const Valor &valor) {
		_ra = insertaAux(clave, valor, _ra);
	}
    
	/**
	 OperaciÛn modificadora que elimina una clave del ·rbol.
	 Si la clave no existÌa la operaciÛn no tiene efecto.
     
     erase(elem, EmptyTreeMap) = TreeMapVacio
     erase(e, insert(c, v, arbol)) =
     inserta(c, v, erase(e, arbol)) si c != e
     erase(e, insert(c, v, arbol)) = erase(e, arbol) si c == e
     
	 @param clave Clave a eliminar.
	 */
	void erase(const Clave &clave) {
		_ra = borraAux(_ra, clave);
	}
    
	/**
	 OperaciÛn observadora que devuelve el valor asociado
	 a una clave dada.
     
	 at(e, insert(c, v, arbol)) = v si e == c
	 at(e, insert(c, v, arbol)) = at(e, arbol) si e != c
	 error at(EmptyTreeMap)
     
	 @param clave Clave por la que se pregunta.
	 */
	const Valor &at(const Clave &clave) const {
		Nodo *p = buscaAux(_ra, clave);
		if (p == nullptr)
			throw std::domain_error("clave erronea");
        
		return p->_valor;
	}
    
	/**
	 OperaciÛn observadora que permite averiguar si una clave
	 determinada est· o no en el ·rbol de b˙squeda.
     
	 contains(e, EmptyTreeMap) = false
	 contains(e, insert(c, v, arbol)) = true si e == c
	 contains(e, insert(c, v, arbol)) = contains(e, arbol) si e != c
     
	 @param clave Clave por la que se pregunta.
	 @return true si el diccionario contiene un valor asociado
	 a esa clave.
	 */
	bool contains(const Clave &clave) const {
		return (buscaAux(_ra, clave) != nullptr) ? true : false;
	}
    
	/**
	 OperaciÛn observadora que devuelve si el ·rbol
	 es vacÌo (no contiene elementos) o no.
     
	 empty(EmptyTreeMap) = true
	 empty(insert(c, v, arbol)) = false
	 */
	bool empty() const {
		return _ra == nullptr;
	}
    
	/**
	 Sobrecarga del operador [] que permite acceder
	 al valor asociado a una clave y modificarlo.
	 Si el elemento buscado no estaba, se inserta uno
	 con el valor por defecto del tipo Valor.
	 */
	Valor &operator[](const Clave &clave) {
		// Buscamos. SerÌa mejor hacerlo in-line; asÌ en
		// caso de no encontrarlo no hace falta buscar otra
		// vez dÛnde insertar la clave.
		Nodo * ret = buscaAux(_ra, clave);
		if (ret == nullptr) {
			// No est·, lo aÒadimos y vemos dÛnde
			// quedÛ. Hay formas m·s eficientes para evitar
			// recorridos por el ·rbol.
			insert(clave, Valor());
			ret = buscaAux(_ra, clave);
		}
        
		return ret->_valor;
	}
    
	// //
	// ITERADOR CONSTANTE Y FUNCIONES RELACIONADAS
	// //
    
	/**
	 Clase interna que implementa un iterador sobre
	 la lista que permite recorrer el ·rbol pero no
	 permite modificarlo.
	 */
	class ConstIterator {
	public:
		void next() {
			if (_act == nullptr) throw std::domain_error("acceso invalido");
            
			// Si hay hijo derecho, saltamos al primero
			// en inorden del hijo derecho
			if (_act->_dr!=nullptr)
				_act = primeroInOrden(_act->_dr);
			else {
				// Si no, vamos al primer ascendiente
				// no visitado. Para eso consultamos
				// la pila; si ya est· vacÌa, no quedan
				// ascendientes por visitar
				if (_ascendientes.empty())
					_act = nullptr;
				else {
					_act = _ascendientes.top();
					_ascendientes.pop();
				}
			}
		}
        
		const Clave &key() const {
			if (_act == nullptr) throw std::domain_error("acceso invalido");
			return _act->_clave;
		}
        
		const Valor &value() const {
			if (_act == nullptr) throw std::domain_error("acceso invalido");
			return _act->_valor;
		}
        
		bool operator==(const ConstIterator &other) const {
			return _act == other._act;
		}
        
		bool operator!=(const ConstIterator &other) const {
			return !(this->operator==(other));
		}
        
		ConstIterator &operator++() {
			next();
			return *this;
		}
        
		ConstIterator operator++(int) {
			ConstIterator ret(*this);
			operator++();
			return ret;
		}
        
	protected:
		// Para que pueda construir objetos del
		// tipo iterador
		friend class TreeMap;
        
		ConstIterator() : _act(nullptr) {}
		ConstIterator(Nodo *act) {
			_act = primeroInOrden(act);
		}
        
		/**
		 Busca el primer elemento en inorden de
		 la estructura jer·rquica de nodos pasada
		 como par·metro; va apilando sus ascendientes
		 para poder "ir hacia atr·s" cuando sea necesario.
		 @param p Puntero a la raÌz de la subestructura.
		 */
		Nodo *primeroInOrden(Nodo *p) {
			if (p == nullptr)
				return nullptr;
            
			while (p->_iz != nullptr) {
				_ascendientes.push(p);
				p = p->_iz;
			}
			return p;
		}
        
		// Puntero al nodo actual del recorrido
		// nullptr si hemos llegado al final.
		Nodo *_act;
        
		// Ascendientes del nodo actual
		// a˙n por visitar
		std::stack<Nodo*> _ascendientes;
	};
    
	/**
	 Devuelve el iterador constante al principio del
	 diccionario (clave m·s pequeÒa).
	 @return iterador al principio del recorrido;
	 coincidir· con cend() si el diccionario est· vacÌo.
	 */
	ConstIterator cbegin() const {
		return ConstIterator(_ra);
	}
    
	/**
	 @return Devuelve un iterador al final del recorrido
	 (fuera de Èste).
	 */
	ConstIterator cend() const {
		return ConstIterator(nullptr);
	}
    
	ConstIterator find(const Clave &c) const {
		std::stack<Nodo*> ascendientes;
		Nodo *p = _ra;
		while ((p != nullptr) && (p->_clave != c)) {
			if (p->_clave > c) {
				ascendientes.push(p);
				p = p->_iz;
			} else
				p = p->_dr;
		}
		ConstIterator ret;
		ret._act = p;
		if (p != nullptr)
			ret._ascendientes = ascendientes;
		return ret;
	}
    
	// //
	// ITERADOR NO CONSTANTE Y FUNCIONES RELACIONADAS
	// //
    
	/**
	 Clase interna que implementa un iterador sobre
	 la ·rbol de b˙squeda que permite recorrer la lista e incluso
	 alterar el valor de sus elementos.
	 */
	class Iterator {
	public:
		void next() {
			if (_act == nullptr) throw std::domain_error("acceso invalido");
            
			// Si hay hijo derecho, saltamos al primero
			// en inorden del hijo derecho
			if (_act->_dr!=nullptr)
				_act = primeroInOrden(_act->_dr);
			else {
				// Si no, vamos al primer ascendiente
				// no visitado. Para eso consultamos
				// la pila; si ya est· vacÌa, no quedan
				// ascendientes por visitar
				if (_ascendientes.empty())
					_act = nullptr;
				else {
					_act = _ascendientes.top();
					_ascendientes.pop();
				}
			}
		}
        
		const Clave &key() const {
			if (_act == nullptr) throw std::domain_error("acceso invalido");
			return _act->_clave;
		}
        
		Valor &value() const {
			if (_act == nullptr) throw std::domain_error("acceso invalido");
			return _act->_valor;
		}
        
		bool operator==(const Iterator &other) const {
			return _act == other._act;
		}
        
		bool operator!=(const Iterator &other) const {
			return !(this->operator==(other));
		}
        
		Iterator &operator++() {
			next();
			return *this;
		}
        
		Iterator operator++(int) {
			Iterator ret(*this);
			operator++();
			return ret;
		}
        
	protected:
		// Para que pueda construir objetos del
		// tipo iterador
		friend class TreeMap;
        
		Iterator() : _act(nullptr) {}
		Iterator(Nodo *act) {
			_act = primeroInOrden(act);
		}
        
		/**
		 Busca el primer elemento en inorden de
		 la estructura jer·rquica de nodos pasada
		 como par·metro; va apilando sus ascendientes
		 para poder "ir hacia atr·s" cuando sea necesario.
		 @param p Puntero a la raÌz de la subestructura.
		 */
		Nodo *primeroInOrden(Nodo *p) {
			if (p == nullptr)
				return nullptr;
            
			while (p->_iz != nullptr) {
				_ascendientes.push(p);
				p = p->_iz;
			}
			return p;
		}
        
		// Puntero al nodo actual del recorrido
		// nullptr si hemos llegado al final.
		Nodo *_act;
        
		// Ascendientes del nodo actual
		// a˙n por visitar
		std::stack<Nodo*> _ascendientes;
	};
    
	/**
	 Devuelve el iterador al principio de la lista.
	 @return iterador al principio de la lista;
	 coincidir· con final() si la lista est· vacÌa.
	 */
	Iterator begin() {
		return Iterator(_ra);
	}
    
	/**
	 @return Devuelve un iterador al final del recorrido
	 (fuera de Èste).
	 */
	Iterator end() const {
		return Iterator(nullptr);
	}
    
	Iterator find(const Clave &c) {
		std::stack<Nodo*> ascendientes;
		Nodo *p = _ra;
		while ((p != nullptr) && (p->_clave != c)) {
			if (p->_clave > c) {
				ascendientes.push(p);
				p = p->_iz;
			} else
				p = p->_dr;
		}
		Iterator ret;
		ret._act = p;
		if (p != nullptr)
			ret._ascendientes = ascendientes;
		return ret;
	}
    
    
	// //
	// M…TODOS DE "FONTANERÕA" DE C++ QUE HACEN VERS¡TIL
	// A LA CLASE
	// //
    
	/** Constructor copia */
	TreeMap(const TreeMap<Clave, Valor> &other) : _ra(nullptr) {
		copia(other);
	}
    
	/** Operador de asignaciÛn */
	TreeMap<Clave, Valor> &operator=(const TreeMap<Clave, Valor> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}
    
protected:
    
	/**
	 Constructor protegido que crea un ·rbol
	 a partir de una estructura jer·rquica de nodos
	 previamente creada.
	 Se utiliza en hijoIz e hijoDr.
	 */
	TreeMap(Nodo *raiz) : _ra(raiz) {
	}
    
	void libera() {
		libera(_ra);
	}
    
	void copia(const TreeMap &other) {
		_ra = copiaAux(other._ra);
	}
    
private:
    
	/**
	 Elimina todos los nodos de una estructura arbÛrea
	 que comienza con el puntero ra.
	 Se admite que el nodo sea nullptr (no habr· nada que
	 liberar).
	 */
	static void libera(Nodo *ra) {
		if (ra != nullptr) {
			libera(ra->_iz);
			libera(ra->_dr);
			delete ra;
		}
	}
    
	/**
	 Copia la estructura jer·rquica de nodos pasada
	 como par·metro (puntero a su raiz) y devuelve un
	 puntero a una nueva estructura jer·rquica, copia
	 de anterior (y que, por tanto, habr· que liberar).
	 */
	static Nodo *copiaAux(Nodo *ra) {
		if (ra == nullptr)
			return nullptr;
        
		return new Nodo(copiaAux(ra->_iz),
						ra->_clave, ra->_valor,
						copiaAux(ra->_dr));
	}
    
	/**
	 Inserta una pareja (clave, valor) en la estructura
	 jer·rquica que comienza en el puntero pasado como par·metro.
	 Ese puntero se admite que sea nullptr, por lo que se crear·
	 un nuevo nodo que pasar· a ser la nueva raÌz de esa
	 estructura jer·rquica. El mÈtodo devuelve un puntero a la
	 raÌz de la estructura modificada. En condiciones normales
	 coincidir· con el par·metro recibido; sÛlo cambiar· si
	 la estructura era vacÌa.
	 @param clave Clave a insertar. Si ya aparecÌa en la
	 estructura de nodos, se sobreescribe el valor.
	 @param valor Valor a insertar.
	 @param p Puntero al nodo raÌz donde insertar la pareja.
	 @return Nueva raÌz (o p si no cambia).
	 */
	static Nodo *insertaAux(const Clave &clave, const Valor &valor, Nodo *p) {
        
		if (p == nullptr) {
			return new Nodo(clave, valor);
		} else if (p->_clave == clave) {
			p->_valor = valor;
			return p;
		} else if (clave < p->_clave) {
			p->_iz = insertaAux(clave, valor, p->_iz);
			return p;
		} else { // (clave > p->_clave)
			p->_dr = insertaAux(clave, valor, p->_dr);
			return p;
		}
	}
    
	/**
	 Busca una clave en la estructura jer·rquica de
	 nodos cuya raÌz se pasa como par·metro, y devuelve
	 el nodo en la que se encuentra (o nullptr si no est·).
	 @param p Puntero a la raÌz de la estructura de nodos
	 @param clave Clave a buscar
	 */
	static Nodo *buscaAux(Nodo *p, const Clave &clave) {
		if (p == nullptr)
			return nullptr;
        
		if (p->_clave == clave)
			return p;
        
		if (clave < p->_clave)
			return buscaAux(p->_iz, clave);
		else
			return buscaAux(p->_dr, clave);
	}
    
	/**
	 Elimina (si existe) la clave/valor de la estructura jer·rquica
	 de nodos apuntada por p. Si la clave aparecÌa en la propia raÌz,
	 Èsta cambiar·, por lo que se devuelve la nueva raÌz. Si no cambia
	 se devuelve p.
     
	 @param p RaÌz de la estructura jer·rquica donde borrar la clave.
	 @param clave Clave a borrar.
	 @return Nueva raÌz de la estructura, tras el borrado. Si la raÌz
	 no cambia, se devuelve el propio p.
     */
	static Nodo *borraAux(Nodo *p, const Clave &clave) {
        
		if (p == nullptr)
			return nullptr;
        
		if (clave == p->_clave) {
			return borraRaiz(p);
		} else if (clave < p->_clave) {
			p->_iz = borraAux(p->_iz, clave);
			return p;
		} else { // clave > p->_clave
			p->_dr = borraAux(p->_dr, clave);
			return p;
		}
	}
    
	/**
	 Borra la raÌz de la estructura jer·rquica de nodos
	 y devuelve el puntero a la nueva raÌz que garantiza
	 que la estructura sigue siendo v·lida para un ·rbol de
	 b˙squeda (claves ordenadas).
	 */
	static Nodo *borraRaiz(Nodo *p) {
        
		Nodo *aux;
        
		// Si no hay hijo izquierdo, la raÌz pasa a ser
		// el hijo derecho
		if (p->_iz == nullptr) {
			aux = p->_dr;
			delete p;
			return aux;
		} else
            // Si no hay hijo derecho, la raÌz pasa a ser
            // el hijo izquierdo
            if (p->_dr == nullptr) {
                aux = p->_iz;
                delete p;
                return aux;
            } else {
                // Convertimos el elemento m·s pequeÒo del hijo derecho
                // en la raÌz.
                return mueveMinYBorra(p);
            }
	}
    
	/**
	 MÈtodo auxiliar para el borrado; recibe un puntero a la
	 raÌz a borrar. Busca el elemento m·s pequeÒo del hijo derecho
	 que se convertir· en la raÌz (que devolver·), borra la antigua
	 raÌz (p) y "cose" todos los punteros, de forma que ahora:
     
     - El mÌnimo pasa a ser la raÌz, cuyo hijo izquierdo y
     derecho eran los hijos izquierdo y derecho de la raÌz
     antigua.
     - El hijo izquierdo del padre del elemento m·s pequeÒo
     pasa a ser el antiguo hijo derecho de ese mÌnimo.
	 */
	static Nodo *mueveMinYBorra(Nodo *p) {
        
		// Vamos bajando hasta que encontramos el elemento
		// m·s pequeÒo (aquel que no tiene hijo izquierdo).
		// Vamos guardando tambiÈn el padre (que ser· nullptr
		// si el hijo derecho es directamente el elemento
		// m·s pequeÒo).
		Nodo *padre = nullptr;
		Nodo *aux = p->_dr;
		while (aux->_iz != nullptr) {
			padre = aux;
			aux = aux->_iz;
		}
        
		// aux apunta al elemento m·s pequeÒo.
		// padre apunta a su padre (si el nodo es hijo izquierdo)
        
		// Dos casos dependiendo de si el padre del nodo con
		// el mÌnimo es o no la raÌz a eliminar
		// (=> padre != nullptr)
		if (padre != nullptr) {
			padre->_iz = aux->_dr;
			aux->_iz = p->_iz;
			aux->_dr = p->_dr;
		} else {
			aux->_iz = p->_iz;
		}
        
		delete p;
		return aux;
	}
    
	/**
	 Puntero a la raÌz de la estructura jer·rquica
	 de nodos.
	 */
	Nodo *_ra;
};

#endif // __TREEMAP_H
