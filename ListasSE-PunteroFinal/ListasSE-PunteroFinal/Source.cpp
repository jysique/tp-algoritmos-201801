#include <iostream>
#include <conio.h>

using namespace std;

template <typename T>
class CSEFList {
	struct Nodo{
		T elemento;
		Nodo* next;
		
		Nodo(T elemento = 0, Nodo* next = nullptr) : elemento(elemento), next(next) {
		}
	};
	size_t n;
	Nodo* inicio;
	Nodo* final;

public:
	CSEFList(): n(0), inicio(nullptr){

	}
	~CSEFList(){
		Nodo* aux = inicio;
		while (inicio != nullptr){
			inicio = inicio->next;
			delete aux;
		}
	}

	size_t get_size() { return n; }

	T get_Elemento(size_t posicion) {
		if (posicion < 0 || posicion>=n)return 0;
		if (posicion == 0) return inicio->elemento;
		Nodo*aux = inicio;
		for (int i = 0; i < posicion; i++){
			aux = aux->next;
		}
		return aux->elemento;
	}

	void actualizar() {
		cout << "Lista:" << endl;
		for (int i = 0; i < get_size(); i++) {
			cout << get_Elemento(i) << endl;
		}
	}

	bool AgregarInicio(T elemento) {
		Nodo* nuevo = new Nodo(elemento, inicio);
		if (nuevo == nullptr) {
			return false;
		}
		inicio = nuevo;
		n++;
		return true;
	}

	bool AgregarPosicion(T elemento, size_t posicion) {
		if (posicion<0 || posicion> n)return false;
		if (posicion == 0) return AgregarInicio(elemento);

		size_t contador = 1;
		Nodo* aux = inicio;
		while (contador < n) {
			aux = aux->next;
			contador++;
		}
		Nodo* nuevo = new Nodo(elemento, aux->next);
		if (nuevo == nullptr) { 
			return false;
		}
		else
		{
			if (posicion == n)	{
				final = nuevo;
			}
			n++;
			aux->next = nuevo;
			return true;
		}
	}
	bool AgregarFinal(T elemento) {
		return AgregarPosicion(elemento, n);

	}

	bool EliminarInicio() {
		Nodo*aux;
		if (inicio==nullptr){
			return false;
		}
		else
		{
			aux = inicio;
			inicio = inicio->next;
			delete aux;
			n--;
			return true;
		}
	}
	bool EliminarPosicion(size_t posicion) {
		if (posicion <0 || posicion > n) return false;
		if (posicion == 0) return EliminarInicio();
		size_t contador = 1;
		Nodo* aux1= inicio;
		Nodo* aux2 = inicio->next;
		while (contador<posicion){
			aux1 = aux1->next;
			aux2 = aux2->next;
			contador++;
		}
		aux1->next = aux2->next;
		if (posicion== n-1){
			final = aux1;
		}
		delete aux2;
		n--;
	}

	bool EliminarFinal() {
		return EliminarPosicion(n - 1);

	}
};

int main() {
	CSEFList<int>* lista = new CSEFList <int>();
	lista->AgregarInicio(30);
	lista->AgregarInicio(20);
	lista->AgregarInicio(10);
	lista->actualizar();
	lista->AgregarPosicion(25, 2);
	lista->AgregarFinal(15);
	lista->actualizar();
	lista->EliminarInicio();
	lista->EliminarPosicion(3);
	lista->EliminarFinal();
	lista->actualizar();
	_getch();
}