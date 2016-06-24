#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool evalua(char top, char caracter) {
	switch (caracter) {
	case ')': return (top == '('); break;
	case ']': return (top == '['); break;
	case '}': return (top == '{'); break;
	default: return false;
	}
}
bool procesaLinea(const string &linea) {
	stack<char> pila;
	for (size_t i = 0; i < linea.length(); i++) {
		if (linea[i] == '(' || linea[i] == '[' || linea[i] == '{')
			pila.push(linea[i]);
		else if (linea[i] == ')' || linea[i] == ']' || linea[i] == '}') {
			if (!pila.empty() && evalua(pila.top(), linea[i]))
				pila.pop();
			else {
				return false;
			}
		}
	}
	return (pila.empty());
}
bool resuelve() {
	string linea;
	getline(cin, linea);
	if (linea == ".")
		return false;
	if (procesaLinea(linea))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return true;
}
int main() {
	while (resuelve());
	return 0;
}