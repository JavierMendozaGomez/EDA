#include "TreeMap.h"
#include <iostream>
using namespace std;

int main() {
	TreeMap<int, int> mapa;
	mapa.insert(8, 0);
	mapa.insert(2, 0);
	mapa.insert(1, 0);
	mapa.insert(5, 0);
	mapa.insert(3, 0);
	cout << mapa.siguienteClave(1) << endl;
	cout << mapa.siguienteClave(2) << endl;
	cout << mapa.siguienteClave(3) << endl;
	cout << mapa.siguienteClave(5) << endl;
	cout << mapa.siguienteClave(8) << endl;

	return 0;
}