#include <iostream>
#include <string>
#include <conio.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// definición de struct para clientes

struct t_cliente {
	int id_cliente;
	char nombre[15];
};

// prototipo de funciones

void mostrar_cadena(char[]);
void listar_vector_struct(t_cliente[], int);

// prototipos de templates

template < typename T1 > void cargar_vector(T1[], int, T1);
template < typename T2 > void listar_vector(T2[], int);

// prototipo de funcion:valor absoluto

template<class T3> //T3 engloba diferentes tipos de datos (prefijo de plantilla)

void mostrar_valor_absoluto(T3 numero){
	if (numero<0){
		numero = numero*-1;
	}
	cout << "El valor absoulto del numero es: " << numero << endl;
}


int main() {
	int vect_1[2];
	char vect_2[2];
	t_cliente vect_3[2];

	int i;

	// empieza la carga del primer vector

	int valor;

	for (i = 0; i < 2; i++) {
		cout << "ingrese un numero entero: ";
		cin >> valor;
		cout << endl;
		cargar_vector <int>(vect_1, i, valor); // le envío el vector 1, posición donde grabar y el valor
	}

	// empieza la carga del segundo vector

	char caracter;

	for (i = 0; i < 2; i++) {
		cout << "ingrese un caracter: ";
		cin >> caracter;
		cout << endl;
		cargar_vector <char>(vect_2, i, caracter); // le envío el vector 2, posición y caracter
	}

	// empieza la carga del tercer vector

	t_cliente cliente;
	string nombre;


	for (i = 0; i < 2; i++) {
		cout << "ingrese numero de identificacion: ";
		cin >> cliente.id_cliente;
		cout << endl;

		cin.ignore();
		cout << "ingrese el nombre: ";
		getline(std::cin, nombre);
		strcpy_s(cliente.nombre, nombre.c_str());  // copio una vez convertido el string a array de char al campo nombre del struct
		
		cargar_vector <t_cliente>(vect_3, i, cliente); // le envío el vector 3, posición y struct
		cout << endl;
	}

	cout << "  LISTADO DE VECTORES:" << endl;
	cout << "  ====================" << endl;
	cout << endl;

	cout << "  VECTOR 1 DE TIPO int:" << endl;
	cout << endl;

	listar_vector <int>(vect_1, 2);
	cout << endl;

	cout << "  VECTOR 2 DE TIPO char:" << endl;
	cout << endl;

	listar_vector <char>(vect_2, 2);
	cout << endl;

	// para este vector hay una diferencia, la cual impide utilizar este template
	// listar_vector <t_cliente> (vect_3, 5);
	// en su lugar debo hacer otro template

	cout << "  VECTOR 3 DE TIPO t_cliente:" << endl;
	cout << endl;

	listar_vector_struct(vect_3, 2);
	cout << endl;
	//------------------------------------------------

	int num1 = 4;
	float num2 = -56.67;
	double num3 = 123.5678;

	mostrar_valor_absoluto(num1);
	mostrar_valor_absoluto(num2);
	mostrar_valor_absoluto(num3);
	_getch();
	return 0;
}

template < typename T1 > void cargar_vector(T1 vect[], int pos, T1 dato) {
	vect[pos] = dato;
	return;
}

template < typename T2 > void listar_vector(T2 vect[], int longitud) {
	int i;

	for (i = 0; i < longitud; i++) {
		cout << "  " << vect[i] << endl;
	}
	return;
}

// pero este template SOLAMENTE sirve para vectores de tipo t_cliente!!
// lo cual lo hace poco útil desde el punto de vista de template

/*
template < typename T3 > void listar_vector_struct( T3 vect[], int longitud ){
int i;

for( i = 0; i < longitud; i++ ){
cout << "  " << vect[i].id_cliente << "  .....  ";
mostrar_cadena(vect[i].nombre);
cout << endl;
}

return;
}
*/

// en realidad debería hacer una función y listo como por ej esta:

void listar_vector_struct(t_cliente vect[], int longitud) {
	int i;

	for (i = 0; i < longitud; i++) {
		cout << "  " << vect[i].id_cliente << "  .....  ";
		mostrar_cadena(vect[i].nombre);  // al ser una función que devuelve void no corresponde incluirla en el cout
		cout << endl;
	}

	return;

}

// función auxiliar para mostrar un array de char ( CADENA )

void mostrar_cadena(char cad[]) {
	int j = 0;

	while (cad[j] != '\0') {
		cout << cad[j];
		j++;
	}

	return;
}

