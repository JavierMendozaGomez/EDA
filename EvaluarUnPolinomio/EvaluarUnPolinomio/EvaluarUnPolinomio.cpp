#include <iostream>
#include <vector>
template <class T>
class Polinomio{
public: Polinomio(const size_t& grado);
		void escribeResultado(const T &valor)const;
private:void leer(const size_t &grado);
		std::vector <T>_v;
		void escribe(const T &valor)const;
};
template<class T>
Polinomio<T>::Polinomio(const size_t& grado){
			leer(grado);
}

template<class T>
void Polinomio<T>::leer(const size_t &grado) {
	T valor;
	for (size_t i = 0; i <= grado; i++) {
		std::cin >> valor;
		_v.push_back(valor);
	}
}
template<class T>
void Polinomio<T>::escribeResultado(const T & valor)const {
	escribe(valor);
}
template<class T>
void Polinomio<T>::escribe(const T &valor)const {
	T suma = _v.at(_v.size()-1);
	T potencia = valor;
	for (int i = _v.size() - 2; i >= 0; i--) {
		suma += potencia*_v.at(i);
		potencia = potencia*valor;
	}
	std::cout << suma << std::endl;
}
bool resuelve(){
	std::size_t grado;
	std::cin >> grado;
	if (!std::cin)
		 return false;
	Polinomio<long long int> polinomio(grado);
	int valorBuscado;
	std::cin >> valorBuscado;
	while (valorBuscado != 0) {
		polinomio.escribeResultado(valorBuscado);
		std::cin >> valorBuscado;
	}
	return true;
}
int main(){
	while (resuelve());
	return 0;
}