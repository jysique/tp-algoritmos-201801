#include<iostream>
#include"CListaSECPF.h"
using namespace std;

int main() {
	CListaSECPF<int> lista;
	CListaSECPF<int>::Iterador it;
	lista.AgregarEnPosicion(10,0);
	lista.AgregarInicio(20);
	lista.AgregarInicio(30);
	lista.AgregarFinal(40);
	lista.AgregarEnPosicion(50, 4);
	lista.EliminarInicio();
	lista.EliminarFinal();
	lista.EliminarEnPosicion(1);
	
	it = lista.Begin();
	cout << "[ ";
	for (int i = 0; i != lista.GetNumeroElementos(); it++, i++) {
		cout << *it << " ";
	}
	cout << "]\n";

	cout << "Inicio: " << lista.GetInicio() << endl;
	cout << "Final: " << lista.GetFinal() << endl;
	cout << "Final apunta a: " << lista.GetNextFinal() << endl;
	cout << "Elemento en posicion " << "2" << " es: " << lista.GetElemento(2) << endl;
	system("pause");
	return 0;
}