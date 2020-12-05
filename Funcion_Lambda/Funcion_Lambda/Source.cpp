#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <functional>
using namespace std;


void muestra(int i) {
	cout << i << endl;
}

int main(){

	vector<int> vector{ 1,2,3,4,5 };

	//Punteros a funcion
	cout << " ** LAMBDA ** " << endl;
	cout << " ** EJEMPLO 1 ** " << endl;
	int (*suma1)(int)=[](int numero) {
	return  numero + 1;
	};
	cout << suma1(5)<<endl;

	//-----------------------------------------

	//Auto = int(*suma1)(int)
	cout << " ** EJEMPLO 2 ** " << endl;
	auto suma2 = [](int num) {
		return num + 2;
	};
	cout << suma2(7) << endl;;

	//-----------------------------------------

	cout << " ** EJEMPLO 3 ** " << endl;
	int v = 5;

	auto calculadora = [v](int x, int y) { // La variable v reconoce el dato declarado
			return x * y + v; 
		};
	cout << calculadora(2, 3) << endl;

	//------------------------------------------

	cout << " ** EJEMPLO 4 ** " << endl;
	string s = "Hola a todos. ";

	auto mensaje = [s](string msj) {
			cout << s << msj << endl;
		};
	mensaje("Buenos dias. ");
	mensaje("Compadre"); //Llama el mensaje cuantas veces quiera

	//------------------------------------------

	cout << " ** EJEMPLO 5 ** " << endl;

	function<int(int, int)>f2 = [](int x, int y) { //tipo de template
		//f2 : objeto
		return x / y;
	};

	cout << f2(8, 4) << endl;






	_getch();
	return 0;
}