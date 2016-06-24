#include <iostream>
using namespace std;
int fibonacciAux(int n, int i, int x, int y){
	if (i == n)
		return x + y;
	else
		return fibonacciAux(n, i + 1, y, x + y);
}
int fibonacci(int n){
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacciAux(n, 2, 0, 1);
}
int main(){
	int n;
	cin >> n;
	cout << fibonacci(n);
	return 0;
}