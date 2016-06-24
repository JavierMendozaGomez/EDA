#include <iostream>
using namespace std;
int jacobsthal(int n){
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else{
		return jacobsthalAux(n,2, 0, 1);
	}
}
int jacobsthalAux(int n,int i, int x, int y){
	if (i == n)
		return 2 * x + y;
	else{
		return jacobsthalAux(n, i + 1, y, 2 * x + y);
	}

}
bool resuelve(){
	int n;
	cin >> n;
	if (n == -1)
		return false;
	jacobsthal(n);
	return true;
}
int main(){
	while (resuelve());
	return 0;
}