#include<iostream>
#include"CPila.h"
using namespace std;

int main() {
	CPila<int> pila;
	CPila<int>::Iterador it;
	cout << "Esta vacia: " << pila.IsEmpty() << endl;
	pila.AgregarInicio(20);
	pila.AgregarInicio(30);
	pila.AgregarInicio(40);
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