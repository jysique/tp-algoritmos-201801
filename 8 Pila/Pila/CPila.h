#ifndef __CPILA_H__
#define __CPILA_H__
template<typename T>
class CPila {

	struct  Nodo {
		T elemento;//Elemento o payload
		Nodo* next;//Apunta con direccion de memoria al siguiente nodo

		Nodo(T elemento = 0, Nodo* next = nullptr) :elemento(elemento), next(next) {//parametros por defecto, ": asignacion prematura de atributos"

		}
	};

	int numeroElementos;//numero de elementos de la lista
	Nodo* inicio;

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
		return Iterador(nullptr);
	}

public:
	CPila() : numeroElementos(0), inicio(nullptr) {

	}
	~CPila() {
		Nodo* aux;
		while (inicio != nullptr) {
			aux = inicio;
			inicio = inicio->next;
			delete aux;
		}
	}
	bool AgregarInicio(T elemento) {
		Nodo* nuevoNodo = new Nodo(elemento, inicio);
		if (nuevoNodo == nullptr) {
			return false;
		}
		else {
			numeroElementos++;
			inicio = nuevoNodo;
			return true;
		}
	}
	bool EliminarInicio() {
		Nodo* aux;
		if (inicio == nullptr) {
			return false;
		}
		else {
			aux = inicio;
			inicio = inicio->next;
			delete aux;
			numeroElementos--;
			return true;
		}
	}
	T GetInicio() {
		return inicio->elemento;
	}
	bool IsEmpty() {
		if (inicio == nullptr) {
			return true;
		}
		else {
			false;
		}
	}
};
#endif