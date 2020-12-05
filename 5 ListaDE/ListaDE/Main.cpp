#include<iostream>
#include"CListaDE.h"
using namespace std;

int main() {
	CListaDE<int> lista;
	CListaDE<int>::Iterador it;
	lista.AgregarEnPosicion(10,0);
	lista.AgregarInicio(20);
	lista.AgregarInicio(30);
	lista.AgregarInicio(40);
	lista.AgregarEnPosicion(50, 4);
	lista.AgregarFinal(60);
	lista.EliminarInicio();
	lista.EliminarEnPosicion(2);
	lista.EliminarEnPosicion(3);
	lista.EliminarFinal();
	
	cout << "[ ";
	for (it = lista.Begin(); it != lista.End(); it++) {
		cout << *it << " ";
	}
	cout << "]\n";
	cout << "Inicio: " << lista.GetInicio() << endl;
	cout << "Elemento en posicion " << "2" << " es: " << lista.GetElemento(2) << endl;
	system("pause");
	return 0;
}