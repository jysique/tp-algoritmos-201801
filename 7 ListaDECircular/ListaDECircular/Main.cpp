#include<iostream>
#include"CListaDEC.h"
using namespace std;

int main() {
	CListaDEC<int> lista;
	CListaDEC<int>::Iterador it;
	lista.AgregarInicio(10);
	lista.AgregarInicio(20);
	lista.AgregarInicio(30);
	lista.AgregarEnPosicion(40, 1);
	lista.AgregarEnPosicion(50, 4);
	lista.EliminarInicio();
	lista.EliminarEnPosicion(2);
	lista.EliminarFinal();
	
	it = lista.Begin();
	cout << "[ ";
	for (int i = 0; i != lista.GetNumeroElementos(); it++, i++) {
		cout << *it << " ";
	}
	cout << "]\n";
	cout << "Inicio: " << lista.GetInicio() << endl;
	cout << "Final: " << lista.GetFinal() << endl;
	cout << "Final apunta a: " << lista.GetNextFinal() << endl;
	cout << "El previo al inicial es: " << lista.GetFinalConPrevious() << endl;
	cout << "Elemento en posicion " << "2" << " es: " << lista.GetElemento(2) << endl;
	system("pause");
	return 0;
}