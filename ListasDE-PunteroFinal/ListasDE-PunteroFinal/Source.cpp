#include <iostream>
#include <conio.h>

using namespace std;
template<typename T>

class CDEPFList {
	struct Nodo {
		T elemento;
		Nodo* next;
		Nodo* pre;

		Nodo(T elemento = 0, Nodo* next = nullptr, Nodo* pre = nullptr) :elemento(elemento), next(next), pre(pre) {

		}
	};
	size_t n;
	Nodo* inicio;
	Nodo* final;
public:
	CDEPFList() : n(0), inicio(nullptr), final(nullptr) {
	}
	~CDEPFList(){
		Nodo*aux = inicio;
		while (aux!= nullptr){
			inicio = inicio->next;
			delete aux;
		}
	}
	size_t get_size() { return n; }
	T get_elemento(size_t posicion) {
		if (posicion <0 || posicion>n)return false;
		if (posicion == 0)return inicio->elemento;
		Nodo* aux = inicio;
		size_t contador = 0;
		while (contador<posicion){
			aux = aux->next;
			contador++;
		}
		return aux->elemento;
	}
	T get_inicio() { return inicio->elemento; }
	T get_final() { return final->elemento; }

	void actualizar() {
		cout << "Lista:"<<endl;
		size_t contador = 0;
		while (contador<get_size())
		{
			cout << get_elemento(contador) << endl;
			contador++;
		}
		
		/*for (size_t i = 0; i < get_size(); i++){
			cout << get_elemento(i)<<endl;
		}*/

	}
	bool AgregarInicio(T elemento) {
		Nodo* nuevo = new Nodo(elemento, inicio);
		if (nuevo == nullptr)return false;
		else
		{
			if (n > 0) inicio->pre = nuevo;
			if (n == 0) final = nuevo;
			n++;
			inicio = nuevo;
			return true;
		}
	}
	bool AgregarPosicion(T elemento, size_t posicion) {
		if (posicion< 0 || posicion> n)return false;
		if (posicion == 0)return AgregarInicio(elemento);
		Nodo* aux1 = inicio;
		Nodo* aux2 = inicio->next;
		size_t contador = 1;
		while (contador < posicion)	{
			aux1 = aux1->next;
			aux2 = aux2->next;
			contador++;
		}
		Nodo* nuevo = new Nodo(elemento, aux1->next);
		if (nuevo == nullptr){
			return false;
		}
		else {
			if (posicion != n){
				aux2->pre = nuevo;
			}
			if (posicion == n){
				final = nuevo;
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

	bool EliminarInicio() {
		Nodo* aux;
		if (inicio == nullptr){
			return false;
		}
		else {
			aux = inicio;
			inicio = inicio->next;
			delete aux;
			n--;
			return true;
		}
	}
	bool EliminarPosicion(size_t posicion) {
		if (posicion<0 || posicion > n)return false;
		if (posicion == 0)return EliminarInicio();
		Nodo* aux1 = inicio;
		Nodo* aux2 = inicio->next;
		size_t contador = 1;
		while (contador<posicion){
			aux1=aux1->next;
			aux2=aux2->next;
			contador++;
		}
		aux1->next = aux2->next;
		if (posicion != n - 1){
			aux2->next->pre = aux1;
		}
		if (posicion== n -1){
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
	CDEPFList<int>*lista = new CDEPFList<int>;
	lista->AgregarInicio(30);
	lista->AgregarInicio(20);
	lista->AgregarInicio(10);
	lista->actualizar();
	lista->AgregarPosicion(25, 2);
	lista->AgregarFinal(35);
	lista->actualizar();
	cout << "Inicio:" << lista->get_inicio() << endl;
	cout << "final:" << lista->get_final() << endl;
	lista->EliminarInicio();
	lista->EliminarPosicion(2);
	lista->EliminarFinal();
	lista->actualizar();
	_getch();
}

