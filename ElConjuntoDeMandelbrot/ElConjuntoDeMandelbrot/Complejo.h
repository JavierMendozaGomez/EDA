#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <cmath>
using namespace std;
template <class T>
class Complejo{
private:
	T a;
	T b;
public:
	Complejo() {

	}
	Complejo(T a, T b){
		this->a = a;
		this->b = b;
	}
	Complejo operator +(const Complejo & complejo2){
		Complejo aux;
		aux.a = this->a + complejo2.a;
		aux.b = this->b + complejo2.b;
		return aux;
	}
	Complejo operator *(const Complejo & complejo2){
		Complejo aux;
		aux.a = ((this->a*complejo2.a) - (this->b *complejo2.b));
		aux.b = ((this->a*complejo2.b) + (complejo2.a * this->b));
		return aux;
	}
	T modulo(){
		return sqrt((a*a) + (b*b));
	}


};
#endif