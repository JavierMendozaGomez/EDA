#include <iostream>
using namespace std;
void paresImparesBis(int v[], int n, bool &existe, int &p){
	p = 0;
	int j = n;
	while (p < j && ((v[p] % 2 == 0) || (v[j - 1] == 1))){
		if (v[p] % 2 == 0) p = p + 1;
		if (v[j - 1] % 2 == 1) j = j - 1;
	}
	existe = (p == j);
}


void paresImpares(int v[], int n, bool &existe, int &p){
	/*PRECONDICION PROGRAMA: n>=0*/
	/*proc: paresImpares(int v[],int in n, bool inout existe, int inout p)
	  existe == exists: 0<=i<n:todospares(v,0,i) && todosImpares(v,0,n)
	  existe => 0<=p<=n:todosPares(v,0,p) && todosImpares(v,p,n)
	  *
	  
	  todosPares(int v[],int i ,int j) = forall:k i<=k<j:v[k]%2 == 0
	  todosImPares(int v[],int i ,int j) = forall:k i<=k<j:v[k]%2 == 1
	*/




	/*Requires n >= 0
	  INVARIANT= 0<=i<=n && todosPares(v,0,i)
	  ensures todosPares(v,0,i) && (i<n)
	*/

	int i = 0;
	while (i < n && (v[i] % 2 == 0))
		i = i + 1;



	/*  Requires 0<=i<=n && todosPares(v,0,i)
		INVARIANT i<=j<=n: for all t: i<= t < j : todosImpares(v,i,t)
		ensures   for all s: i<=s<n: todosImpares(v,i,s)
	*/
	int j = i;
	while (j < n && (v[j] % 2 == 1))
		j = j + 1;
	existe = (j == n);

	if (existe)
		p = i;
}
void resuelve(){
	int v[10000];
	int numElems,p;
	bool existe;
	cin >> numElems;
	for (int i = 0; i < numElems; i++)
	{
		cin >> v[i];
	};
	paresImpares(v, numElems, existe, p);
	if (existe)
		cout << "Si " << p << endl;
	else
		cout << "No" << endl;
} 


int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}