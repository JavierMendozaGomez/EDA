#include <iostream>
using namespace std;
/*SOL FINAL*/
int fobinacciAux(int n, int i, int x, int y){
	if (i == n)
		return x + y;
	else
		return fobinacciAux(n, i + 1, y, x+y);
}
/*SOL NO FINAL*/
void fibonacciNoFinal(int n, int &fib1, int &fib2){
	if (n == 2){
		int aux = fib1;
		fib1 = fib2;
		fib2 = aux + fib2;
	}
	else{
		fibonacciNoFinal(n - 1, fib1, fib2);
		int aux = fib1;
		fib1 = fib2;
		fib2 = aux + fib2;
	}
}

int fobinacci(int n,int x,int y){
	if (n == 0)
		return x;
	else if (n == 1)
		return y;
	else{
//		return fobinacciAux(n, 2, x, y);
		fibonacciNoFinal(n, x, y);
		return y;
	}
}

bool resuelve(){
	int n, x, y;
	cin >> n;
	if (n == -1)
		return false;
	cin >> x >> y;
	cout << "El res es " << fobinacci(n, x, y) << endl;
	return true;
}
int main(){
	while (resuelve());
}
