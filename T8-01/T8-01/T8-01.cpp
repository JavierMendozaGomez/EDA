#include<iostream>
#include <stack>
using namespace std;
bool resuelve() {
	int num;
	cin >> num;
	if (num < 0)
		return false;
	stack<long long int> pila;
	long long int suma = 0,mod;
	if (num == 0)
		pila.push(0);
	while (num != 0) {
		pila.push(num % 10);
		num = num / 10;
	}

	while (!pila.empty()) {
		cout << pila.top();
		suma += pila.top();
		pila.pop();
		if (pila.empty())
			cout << " = ";
		else {
			cout << " + ";
		}
	}
	cout << suma << endl;
	return true;
}
int main(){
	while (resuelve());
	return 0;
}