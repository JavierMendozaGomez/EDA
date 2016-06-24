#include <iostream>
#include "HashMap.h"
using namespace std;

int main() {
	HashMap<string, int> mapa;
	mapa.insert("ss", 1);
	mapa.insert("bbb", 2);
	mapa.insert("2222", 3);
	HashMap<string, int> ::ConstIterator it = mapa.cbegin();
	while (it != mapa.cend()) {
		cout << it.value() << endl;
		it++;
	}
	return 0;
}