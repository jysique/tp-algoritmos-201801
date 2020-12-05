#include <iostream>
#include <conio.h>
#include <algorithm>
#include <functional>
#include <vector>
#define NONE 0
using namespace std;
template <typename T>
class AVLTree {
	struct Node{
		T elemento;
	
		Node* derecha;
		Node* izquierda;

		int longitud;
		int altura;

		Node(T elemento = NONE, int longitud = 1, int altura = 0, Node* derecha = nullptr, Node* izquierda = nullptr) :
			elemento(elemento), longitud(longitud), altura(altura), derecha(derecha), izquierda(izquierda) {}
	};
	Node* raiz;

	int longitud(Node* node) {
		return node != nullptr ? node->longitud : 0;
	}
	int longitud() {
		return longitud(raiz);
	}
	int altura(Node* node) {
		return node != nullptr ? node->altura : -1;
	}
	int altura() {
		return altura(raiz);
	}
	void actualizar(Node* node) {
		if (node!= nullptr){
			node->longitud = 1 + longitud(node->izquierda) + longitud(node->derecha);
			node->altura = 1 + max(altura(node->izquierda), altura(node->derecha));
		}
	}
	void rIzquierda(Node*& node) {
		Node* tmp = node->derecha;
		node->derecha = tmp->izquierda;
		tmp->izquierda = node;
		actualizar(tmp->izquierda);
		actualizar(tmp);
		node = tmp;
	}
	void rDerecha(Node*& node) {
		Node* tmp = node->izquierda;
		node->izquierda = tmp->derecha;
		tmp->derecha = node;
		actualizar(tmp->derecha);
		actualizar(tmp);
		node = tmp;
	}
	void Balanceo(Node*& node) {
		int hl = altura(node->izquierda);
		int hr = altura(node->derecha);
		if (hl - hr < -1) {
			hl = altura(node->derecha->izquierda);
			hr = altura(node->derecha->derecha);
			if (hl > hr) {
				rDerecha(node->derecha);
			}
			rIzquierda(node);
		}
		else if(hl-hr>1){
			hl = altura(node->izquierda->izquierda);
			hr = altura(node->izquierda->derecha);
			if (hl < hr) {
				rIzquierda(node->izquierda);
			}
			rDerecha(node);
		}
		else
		{
			actualizar(node);
		}
	}
	void añadir(Node*& node, T elemento) {
		if (node == nullptr) {
			node = new Node(elemento);
			node->elemento = elemento;
		}
		else if (elemento < node->elemento) {
				añadir(node->izquierda, elemento);
		}
		else{
				añadir(node->derecha, elemento);
		}
		Balanceo(node);
	}
	void añadir_espejo(Node*& node, T elemento) {
		if (node == nullptr) {
			node = new Node(elemento);
			node->elemento = elemento;
		}
		else if (elemento > node->elemento) {
			añadir_espejo(node->izquierda, elemento);
		}
		else {
			añadir_espejo(node->derecha, elemento);
		}
		Balanceo(node);
	}
	bool buscar(Node*& node,T a) {
		if (node != nullptr) {
			if (a == node->elemento) {
				return true;
			}
			else if(a < node->elemento){
				return buscar(node->izquierda, a);
			}
			else{
				return buscar(node->derecha, a);
			}
		}
	}
	void preOrder(Node* node, int& i, int limite) {
		if (node != nullptr && i < limite) {
			cout << node->elemento << " ";
			i++;
			preOrder(node->izquierda, i, limite);
			preOrder(node->derecha, i, limite);
		}
	}
	void inOrder(Node* node, int& i, int limite) {
		if (node != nullptr && i < limite) {
			inOrder(node->izquierda, i, limite);
			cout << node->elemento << " ";
			i++;
			inOrder(node->derecha, i, limite);
		}
	}
	void postOrder(Node* node, int& i, int limite) {
		if (node != nullptr && i < limite) {
			postOrder(node->izquierda, i, limite);
			postOrder(node->derecha, i, limite);
			cout << node->elemento << " ";
			i++;
		}
	}
	void eliminar(Node* node, T elemento) {
		if (node!= nullptr){
			if (buscar(node, elemento) == true) {
				cout << "Eliminar";
			}
			else
			{
				cout << "no se encontro el elemento";
			}
		}
	}
	void nNodos(Node*& node, int& n) {
		if (node != nullptr) {	
			n++;
			nNodos(node->izquierda,n);
			//cout << node->elemento << " ";
			nNodos(node->derecha,n);
		}
	}
	void Suma(Node*& node, int& suma) {
		if (node!= nullptr){
			suma += node->elemento;
			Suma(node->izquierda, suma);
			Suma(node->derecha, suma);
		}

	}
	void BFT(Node* node) {
		vector<Node*> list;
		list.push_back(node);
		int i = 0;
		while (i != list.size()) {
			if (list[i] != nullptr) {
				Node* n = list[i];
				cout << n->elemento << " ";
				list.push_back(n->izquierda);
				list.push_back(n->derecha);
			}
			i++;
		}
	}
	void inOrderAlt(Node* node, int& i, int limite) {
		if (node != nullptr && i < limite) {
			inOrderAlt(node->izquierda, i, limite);
			if (i % 2 == 0) { cout << node->elemento << " "; }
			i++;
			inOrderAlt(node->derecha, i, limite);
		}
	}
public:

	AVLTree() :raiz(nullptr) {

	}
	void añadir(T elemento) {
		añadir(raiz, elemento);
	}
	void añadir_espejo(T elemento) {
		añadir_espejo(raiz, elemento);
	}
	T buscar(T elemento) {
		buscar(raiz, elemento);
	}
	void preOrder(int limite) {
		int i = 0;
		preOrder(raiz, i, limite);
	}
	void inOrder(int limite) {
		int i = 0;
		inOrder(raiz, i, limite);
	}
	void postOrder(int limite) {
		int i = 0;
		postOrder(raiz, i, limite);
	}
	void eliminar(T elemento) {
		eliminar(raiz, elemento);
	}
	void nNodosI() {
		int n = 0;
		nNodos(raiz->izquierda, n);
		cout << n;
	}
	void nNodosD() {
		int n = 0;
		nNodos(raiz->derecha, n);
		cout<< n;
	}
	void Suma() {
		int suma = 0;
		Suma(raiz, suma);
		cout << suma;
	}
	int SumaI() {
		int sumaI = 0;
		Suma(raiz->izquierda, sumaI);
		return sumaI;
	}
	int SumaD() {
		int sumaD = 0;
		Suma(raiz->derecha, sumaD);
		return sumaD;
	}
	void BFT() {
		BFT(raiz);
	}
	void inOrderAlt(int limite) {
		int i = 0;
		inOrderAlt(raiz, i, limite);
	}

};

void menu() {
	cout << endl << endl;
	cout << " AVL Tree " << endl;
	cout << "0. Salir" << endl;
	cout << "1. Mostrar en orden" << endl;
	cout << "2. Mostrar espejo" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Numero de nodos" << endl;
	cout << "6. Por nivel" << endl;
	cout << "7. Suma" << endl;
	cout << "8. Diferencias de suma" << endl;
	cout << "9. En orden Alterado" << endl;
	cout << "Seleccionar opcion: ";
}

int main() {
	int op, valor;
	AVLTree<int> arbol;
	AVLTree<int> arbol2;
	/*arbol.añadir(50);
	arbol.añadir(41);
	arbol.añadir(80);
	arbol.añadir(70);
	arbol.añadir(77);
	arbol.añadir(79);
	arbol.añadir(46);
	arbol.añadir(100);*/
	arbol.añadir(30);
	arbol.añadir(11);
	arbol.añadir(1);
	arbol.añadir(13);
	arbol.añadir(111);
	arbol.añadir(31);
	/*
	arbol2.añadir_espejo(30);
	arbol2.añadir_espejo(40);
	arbol2.añadir_espejo(50);
	arbol2.añadir_espejo(80);
	arbol2.añadir_espejo(100);
	*/
	int n = 10;
	//int n=0;
	while (1){
		menu();
		cin >> op;
		switch (op) {
		case 0:
			exit(1);
			break;
		case 1:
			cout << "Arbol en orden: "<<endl;
			arbol.inOrder(n);
			break;
		case 2:
			cout << "Espejo: " << endl;
			arbol2.inOrder(n);
			break;
		case 3:
			cout << "Ingresar elemento a eliminar: ";
			cin >> valor;
			arbol.eliminar(valor);
			break;
		case 4:
			cout << "Cantidad de nodos de la raiz: "<<endl;
			cout << "Izquierda: "; arbol.nNodosI();
			cout << endl;
			cout << "Derecha: ";arbol.nNodosD();
			break;
		case 6:
			arbol.BFT();
			break;
		case 7:
			arbol.Suma();
			break;
		case 8:
			cout << "Diferencia: " << arbol.SumaI() - arbol.SumaD();
			break;
		case 9:
			arbol.inOrderAlt(n);
			break;
		}
	}
	system("pause");
	return 0;
}