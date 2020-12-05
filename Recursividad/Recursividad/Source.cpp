//Recursividad

#include <iostream>
#include <conio.h>

using namespace std;

int funcion_factorial(int n) {
	if (n ==0) //CASO BASE
	{
		n = 1;
	}
	else      //CASO GENERAl
	{
		n = n*funcion_factorial(n - 1); //SE LLAMA A SI MISMO
	}
	return n;
}

int funcion_sumar(int n) {
	int _suma = 0;
	if (n==1){	//CASO BASE
		_suma = 1;
	}
	else		//CASO BASE
	{
		_suma = n + funcion_sumar(n - 1);
	}
	return _suma;
}

int funcion_potencia(int base, int exponente) {
	int potencia;
	if (exponente ==1)//CASE BASE
	{
		potencia = base;
	}
	else {
		potencia = base*funcion_potencia(base,exponente - 1);
	}
	return potencia;
}

int main() {
	int nro_elementos;

	cout << "FACTORIAL :" << endl;
	cout << funcion_factorial(3) << endl;
	cout << funcion_factorial(4) << endl;
	cout << funcion_factorial(5) << endl;
	cout << endl;
	cout << "-------------------------------" << endl;
	cout << endl;
	do
	{
		cout << "SUMA :" << endl;
		cout << "Nro de elementos: ";
		cin >> nro_elementos;
	} while (nro_elementos <= 0);
	cout << funcion_sumar(nro_elementos) << endl;
	cout << endl;
	cout << "-------------------------------" << endl;
	int base, exponente;
	cout << "Digite la base:      "; cin >> base;
	cout << "Digite la exponente: "; cin >> exponente;
	cout << funcion_potencia(base, exponente)<<endl;


	_getch();
	return 0;
}