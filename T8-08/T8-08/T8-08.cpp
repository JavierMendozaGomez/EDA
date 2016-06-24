#include<iostream>
#include <stack>
#include <string>
#include <vector>
#include <exception>
using namespace std;
int calculaRes(const int & operando1, const int &operando2, const char &c) {
	switch (c) {
	case '+': {return operando1 + operando2; }; break;
	case '-': {return operando1 - operando2; }; break;
	case '*': {return operando1 * operando2; }; break;
	case '/': {return operando1 / operando2; }; break;
	default: return 0;
	}
}
bool resuelve() {
	string linea;
	getline(cin, linea);
	if (!cin)
		return false;
	stack<int> pila;
	int operando1, operando2;
	try {
		for (int i = 0; i < linea.length(); i++) {
			if (isdigit(linea[i]))
				pila.push(linea[i] - '0');
			else {
				operando2 = pila.top();
				pila.pop();
				operando1 = pila.top();
				pila.pop();
				pila.push(calculaRes(operando1, operando2, linea[i]));
			}
		}
		cout << pila.top() << endl;
	}
	catch (std::exception e) {
		cout << "ERROR" << endl;
	}
}
int main() {
	while (resuelve());
	return 0;
}