#include<iostream>
#include <queue>
#include <string>
#include <vector>
#include <exception>
using namespace std;
int calculaRes(const int & operando1, const int &operando2, const char &c) {
	switch (c) {
	case '+': {return operando1 + operando2; }; break;
	case '-': {return operando1 - operando2; }; break;
	case '*': {return operando1 * operando2; }; break;
	case '/': {try { return operando1 / operando2; }
			}
			  catch (exception e) {
			  }; break;
	default: return 0;
	}
}
bool resuelve() {
	string linea;
	getline(cin, linea);
	if (!cin)
		return false;
	queue<int> cola;
	int operando1, operando2;
	try {
		for (int i = 0; i < linea.length(); i++) {
			if (isdigit(linea[i]))
				cola.push(linea[i] - '0');
			else {
				operando2 = cola.front();
				cola.pop();
				operando1 = cola.front();
				cola.pop();
				cola.push(calculaRes(operando1, operando2, linea[i]));
			}
		}
		cout << cola.front() << endl;
	}
	catch (std::exception e) {
		cout << "ERROR" << endl;
	}
}
int main() {
	while (resuelve());
	return 0;
}