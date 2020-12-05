#include<iostream>
#include"CListaSEPF.h"
using namespace std;

int main() {
	CListaSEPF<int> lista;
	CListaSEPF<int>::Iterador it;
	
	lista.AgregarInicio(10);
	lista.AgregarFinal(40);
	lista.AgregarInicio(30);
	lista.AgregarEnPosicion(20,2);
	lista.EliminarFinal();
	lista.AgregarFinal(50);
	lista.EliminarInicio();
	lista.EliminarEnPosicion(1);
	cout << "[ ";
	for (it = lista.Begin(); it != lista.End(); it++) {
		cout << *it << " ";
	}
	cout << "]\n";
	cout << "Inicio: " << lista.GetInicio() << endl;
	cout << "Final: " << lista.GetFinal() << endl;
	cout << "Elemento en posicion " << "1" << " es: " << lista.GetElemento(1) << endl;
	system("pause");
	return 0;
}