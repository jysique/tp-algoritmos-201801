#include <iostream>
#include <conio.h>

using namespace std;

template<typename T>
class CDEList {
	struct Nodo{
		T elemento;
		Nodo* next;
		Nodo* pre;
		
		Nodo(T elemento = 0, Nodo* next = nullptr, Nodo* pre = nullptr) :elemento(elemento), next(next), pre(pre) {

		}
	};
	size_t n;
	Nodo* inicio;
public:

	CDEList() :n(0), inicio(nullptr) {
	}
	~CDEList(){
		Nodo*aux = inicio;
		while (inicio!= nullptr){
			inicio = aux->next;
			delete aux;
		}
	}

	size_t get_size() { return n; }

	T get_Elemento(size_t posicion) {
		if (posicion< 0 || posicion > n) return false;
		if (posicion == 0) return inicio->elemento;
		size_t contador = 0;
		Nodo * aux = inicio;
		while (contador<posicion){
			aux = aux->next;
			contador++;
		}
		return aux->elemento;
	}
	bool AgregarInicio(T elemento) {
		Nodo* nuevo = new Nodo(elemento, inicio);
		if (nuevo == nullptr) return false;
		else
		{
			if (n>0){
				inicio->pre = nuevo;
			}
			n++;
			inicio = nuevo;
			return true;
		}
	}
	bool AgregarPosicion(T elemento, size_t posicion) {
		if (posicion < 0 || posicion > n) return false;
		if (posicion == 0) return AgregarInicio(elemento);
		size_t contador = 1;
		Nodo* aux1 = inicio;
		Nodo* aux2 = inicio->next;
		while (contador < posicion){
			aux1 = aux1->next;
			aux2 = aux2->next;
			contador++;
		}
		Nodo* nuevo = new Nodo(elemento, aux1->next);
		if (nuevo == nullptr) return false;
		else
		{
			if (posicion != n){
				aux2->pre = nuevo;
			}
			n++;
			nuevo->pre = aux1;
			aux1->next = nuevo;
			return true;
		}
	}
	bool AgregarFinal(T elemento) {
		return AgregarPosicion(elemento, n);
	}

	void actualizar() {
		cout << "Listas:" << endl;
		for (int i = 0; i < get_size(); i++){
			cout << get_Elemento(i) << endl;
		}

	}

	bool EliminarInicio() {
		Nodo* aux; 
		if (inicio== nullptr){
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
		if (posicion < 0 || posicion> n)return false;
		if (posicion == 0)return EliminarInicio();
		size_t contador = 1;
		Nodo* aux1 = inicio;
		Nodo* aux2 = inicio->next;
		while (contador < posicion){
			aux1 = aux1->next;
			aux2 = aux2->next;
			contador++;
		}
		aux1->next = aux2->next;
		if (posicion != n-1){
			aux2->next->pre = aux1;
		}
		delete aux2;
		n--;
	}
	bool EliminarFinal() {
		return EliminarPosicion(n-1);
	}
};

int main() {
	CDEList<int>*lista = new CDEList<int>();
	lista->AgregarInicio(30);
	lista->AgregarInicio(20);
	lista->AgregarInicio(10);
	lista->actualizar();
	lista->AgregarPosicion(15, 2);
	lista->AgregarFinal(25);
	lista->actualizar();
	lista->EliminarInicio();
	lista->EliminarPosicion(2);
	lista->EliminarFinal();
	lista->actualizar();

	_getch();
}