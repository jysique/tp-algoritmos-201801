#include<iostream>
#include"CListaSE.h"
using namespace std;

int main() {
	CListaSE<int> lista;
	CListaSE<int>::Iterador it;
	lista.AgregarEnPosicion(10,0);
	lista.AgregarFinal(20);
	lista.AgregarFinal(30);
	lista.AgregarFinal(40);
	lista.AgregarFinal(50);
	lista.EliminarEnPosicion(3);
	lista.AgregarFinal(60);
	lista.EliminarFinal();
	cout << "[ ";
	for (it = lista.Begin(); it != lista.End(); it++) {
		cout << *it << " ";
	}
	cout << "]\n";
	cout << "Inicio: " << lista.GetInicio() << endl;
	cout << "Elemento en posicion " << "2" << " es: " << lista.GetElemento(2)<<endl;
	system("pause");
	return 0;
}