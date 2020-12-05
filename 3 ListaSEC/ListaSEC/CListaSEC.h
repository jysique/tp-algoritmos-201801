#ifndef __CLISTASEC_H__
#define __CLISTASEC_H__
template<typename T>
class CListaSEC {//lista simplemente enlazada circular

	struct  Nodo {
		T elemento;//Elemento o payload
		Nodo* next;//Apunta con direccion de memoria al siguiente nodo

		Nodo(T elemento = 0, Nodo* next = nullptr) :elemento(elemento), next(next) {//parametros por defecto, ": asignacion prematura de atributos"

		}
	};

	int numeroElementos;//numero de elementos de la lista
	Nodo* inicio;
	Nodo* final;

public:
	class Iterador {
		Nodo* nodo;
	public:
		Iterador(Nodo* nodo = nullptr) : nodo(nodo) {

		}
		void operator ++(int dummy) {//si tiene sobrecarga es el de la derecha, sino es a la izquierda
			nodo = nodo->next;
		}
		T operator *() {
			return nodo->elemento;
		}
		bool operator !=(Iterador it) {
			return nodo != it.nodo;
		}
	};

	Iterador Begin() {
		return Iterador(inicio);
	}
	Iterador End() {
		return Iterador(inicio);
	}

public:
	CListaSEC() : numeroElementos(0), inicio(nullptr), final(nullptr) {

	}
	~CListaSEC() {
		Nodo* aux;
		while (numeroElementos > 0) {
			aux = inicio;
			inicio = inicio->next;
			delete aux;
			numeroElementos--;
		}
	}
	bool AgregarInicio(T elemento) {
		Nodo* nuevoNodo = new Nodo(elemento, inicio);
		if (nuevoNodo == nullptr) {
			return false;
		}
		else {
			if (numeroElementos == 0) {
				inicio = nuevoNodo;
			}
			numeroElementos++;
			nuevoNodo->next = inicio;
			inicio = nuevoNodo;
		
			return true;
		}
	}
	bool AgregarEnPosicion(T elemento, int posicion) {
		if (posicion < 0 || posicion>numeroElementos) {
			return false;
		}
		if (posicion == 0) {
			return	AgregarInicio(elemento);
		}
		int contador = 1;
		Nodo* aux = inicio;
		while (contador < posicion) {
			aux = aux->next;
			contador++;
		}
		Nodo* nuevoNodo = new Nodo(elemento, aux->next);
		if (nuevoNodo == nullptr) {
			return false;
		}
		else {
			if (posicion == numeroElementos) {
				nuevoNodo->next = inicio;
			}
			numeroElementos++;
			aux->next = nuevoNodo;
			return true;
		}
	}
	bool AgregarFinal(T elemento) {
		return AgregarEnPosicion(elemento, numeroElementos);
	}
	bool EliminarInicio() {
		Nodo* aux;
		if (inicio == nullptr) {
			return false;
		}
		else {
			int contador = 1;
			Nodo* aux2 = inicio;
			while (contador < numeroElementos) {
				aux2 = aux2->next;
				contador++;
			}
			aux = inicio;
			inicio = inicio->next;
			aux2->next = inicio;
			delete aux;
			numeroElementos--;
			return true;
		}
	}
	bool EliminarEnPosicion(int posicion) {
		if (posicion < 0 || posicion >= numeroElementos) {
			return false;
		}
		if (posicion == 0) {
			return	EliminarInicio();
		}
		int contador = 1;
		Nodo* aux = inicio;
		Nodo* aux2 = inicio->next;
		while (contador < posicion) {
			aux = aux->next;
			aux2 = aux2->next;
			contador++;
		}
		aux->next = aux2->next;
		if (posicion == numeroElementos - 1) {
			aux->next = inicio;
		}
		delete aux2;
		numeroElementos--;
	}
	bool EliminarFinal() {
		return EliminarEnPosicion(numeroElementos - 1);
	}
	T GetInicio() {
		if (numeroElementos == 0) {
			return false;
		}
		return inicio->elemento;
	}
	T GetFinal() {
		if (numeroElementos == 0) {
			return false;
		}
		int contador = 1;
		Nodo* aux2 = inicio;
		while (contador < numeroElementos) {
			aux2 = aux2->next;
			contador++;
		}
		return aux2->elemento;
	}
	T GetNextFinal() {
		if (numeroElementos == 0) {
			return false;
		}
		int contador = 1;
		Nodo* aux2 = inicio;
		while (contador < numeroElementos) {
			aux2 = aux2->next;
			contador++;
		}
		return aux2->next->elemento;
	}
	int GetNumeroElementos() {
		return numeroElementos;
	}
	T GetElemento(int posicion) {
		if (posicion < 0 || posicion>numeroElementos) {
			return false;
		}
		if (posicion == 0) {
			return GetInicio();
		}
		int contador = 1;
		Nodo* aux = inicio;
		while (contador < posicion) {
			aux = aux->next;
			contador++;
		}
		return aux->elemento;
	}
};
#endif