#include <iostream>
using namespace std;
bool esPalindroma(int v[], int i, int j){
	if (i == j){
		return (v[i] == v[j]);
	}
	else{
		if (v[i] == v[j]){
			return esPalindroma(v, i + 1, j - 1);
		}
		return false;
	}

}
int main(){
		int n;
		int v[10] = { 0, 1, 1, 0 };
		int x[10] = { 0, 1, 2, 1, 0 };

		if (esPalindroma(v, 0, 3))
			cout << "SI" << endl;
		if (esPalindroma(x, 0, 4))
			cout << "SI" << endl;
	return 0;
}