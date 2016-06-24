#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool resuelve() {
	string linea;
	getline(cin, linea);
	if (linea == "")
		return false;
	stack<char> frase;
	for (int i = 0; i < linea.length(); i++) {
		if(linea[i] != ' ')
			frase.push(linea[i]);
	}
	stack<char> fraseOriginal = frase;
	stack<char>	fraseInvertida;
	while (!frase.empty()) {
		fraseInvertida.push(frase.top());
		frase.pop();
	}
	if (fraseOriginal == fraseInvertida)
		cout << "si es palindroma" << endl;
	else
		cout << "no es palindroma" << endl;

}
int main() {
	while (resuelve());
	return 0;
}