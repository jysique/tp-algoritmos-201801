#include<iostream>
#include"CCola.h"
using namespace std;

int main() {
	CCola<int> pila;
	CCola<int>::Iterador it;
	cout << "Esta vacia: " << pila.IsEmpty() << endl;
	pila.AgregarFinal(20);
	pila.AgregarFinal(30);
	pila.AgregarFinal(40);
	cout << "[ ";
	for (it = pila.Begin(); it != pila.End(); it++) {
		cout << *it << " ";
	}
	cout << "]\n";
	cout << "Inicio: " << pila.GetInicio() << endl;
	pila.EliminarInicio();
	pila.EliminarInicio();
	cout << "[ ";
	for (it = pila.Begin(); it != pila.End(); it++) {
		cout << *it << " ";
	}
	cout << "]\n";
	cout << "Esta vacia: " << pila.IsEmpty() << endl;
	
	system("pause");
	return 0;
}