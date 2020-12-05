#include <iostream>
#include <conio.h>

using namespace std;

template<typename T>
class CSEList {
	struct Nodo{
		T elemento;
		Nodo *next;

		Nodo(T elemento = 0, Nodo* next = nullptr) : elemento(elemento), next(next) {
		
		}
	};
	size_t n;
	Nodo* inicio;

public:
	CSEList() : n(0), inicio(nullptr) {
	}

	~CSEList()
	{
		while (inicio != nullptr){
			Nodo* aux = inicio;
			inicio = inicio->next;
			delete aux;
		}
	}

	size_t get_size() { return n; }


	T get_Elemento(size_t posicion) {
		if (posicion<0 || n <= posicion) return 0;
		if (posicion == 0) return inicio->elemento;
		Nodo* aux = inicio;
		for (int i = 0; i < posicion; i++){
			aux = aux->next;
		}
		return aux->elemento;
	}

	void actualizar() {
		cout << "Lista:" << endl;
		for (int i = 0; i < get_size(); i++){
			cout << get_Elemento(i) << endl;
		}
	}

	bool AgregarInicio(T elemento) {
		Nodo* nuevo = new Nodo(elemento,inicio);
		if (nuevo == nullptr)	{
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
		while (contador < n){
			aux = aux->next;
			contador++;
		}
		Nodo* nuevo = new Nodo(elemento, aux->next);
		if (nuevo == nullptr) {
			return false;
		}
		else
		{
			n++;
			aux->next = nuevo;
			
			return true;
		}
	}
	void AgregarFinal(T elemento) {
		AgregarPosicion(elemento, n);
	}
	bool EliminarInicio() {
		Nodo* aux;
		if (inicio == nullptr) return false;
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
		if (posicion<0 || posicion>n)return false;
		if (posicion == 0) return EliminarInicio();
		Nodo* aux = inicio;
		Nodo* aux2 = inicio->next;
		size_t contador = 1;
		while (contador<posicion){
			aux = aux->next;
			aux2 = aux2->next;
			contador++;
		}
		aux->next = aux2->next;
		delete aux2;
		n--;
	}
	bool EliminarFinal() {
		return EliminarPosicion(n-1);
	}

};




int main() {
	CSEList <int>* lista = new CSEList<int>();
	lista->AgregarInicio(20);
	lista->AgregarInicio(30);
	lista->AgregarInicio(40);
	lista->actualizar();
	lista->AgregarPosicion(10, 2);
	lista->AgregarFinal(50);
	lista->actualizar();
	lista->EliminarInicio();
	lista->EliminarPosicion(2);
	lista->EliminarFinal();
	lista->actualizar();

	_getch();
}