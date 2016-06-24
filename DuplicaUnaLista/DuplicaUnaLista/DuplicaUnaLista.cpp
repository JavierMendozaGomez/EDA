#include<iostream>
#include "SinglyLinkedList.h"
using namespace std;
bool resuelve() {
	int n;
	cin >> n;
	if (n == 0)
		return false;

	SinglyLinkedList<int> listaDuplicada;
	while(n != 0){
		listaDuplicada.push_front(n);
		listaDuplicada.duplica();
		cin >> n;
	}
	listaDuplicada.imprime();	
	return true;
}
int main() {
	while (resuelve());
	return 0;
}