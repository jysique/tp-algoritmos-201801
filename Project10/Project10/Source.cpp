#include <iostream>
#include <conio.h>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
template<typename T>
class AVLTree {
	struct Node{
		T elemento;
		Node* izquierda;
		Node* derecha;
		int longitud;
		int altura;
		Node(T elemento = 0, Node* izquierda = nullptr, Node* derecha = nullptr, int longitud = 1, int altura = 0) :
			elemento(elemento), izquierda(izquierda), derecha(derecha), longitud(longitud), altura(altura){}

	};
	Node* raiz;
	function<int(T, T)>compare;

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
	void actualizar(Node*& node) {
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
		if (hl - hr < -1){
			hl = altura(node->derecha->izquierda);
			hr = altura(node->derecha->derecha);
			if (hl > hr ){
				rDerecha(node->derecha);
			}
			rIzquierda(node);
		}else if (hl - hr > 1) {
			hl = altura(node->izquierda->izquierda);
			hr = altura(node->izquierda->derecha);
			if (hl< hr) {
				rIzquierda(node->izquierda);
			}
			rDerecha(node);
		}
		else
		{
			actualizar(node);
		}
	}
	void insertar(Node*& node, T elemento) {
		if (node== nullptr){
			node = new Node(elemento);
		}
		else if (compare(elemento,node->elemento)<0){
			insertar(node->izquierda, elemento);
		}
		else {
			insertar(node->derecha, elemento);
		}
		Balanceo(node);
	}
	void inOrden(Node* node, function<void(T)>proc, int& i, int limite) {
		if (node!= nullptr && i<limite){
			inOrden(node->izquierda, proc, i, limite);
			if (i<limite){
				proc(node->elemento);
				i++;
			}
			inOrden(node->derecha, proc, i, limite);
		}
	}

public:
	AVLTree() :raiz(nullptr) {
		compare = [](T a, T b) {return a - b; };
	}
	AVLTree(function<int(T, T)>compare) :compare(compare) {

	}
	void insertar(T elemento) {
		insertar(raiz, elemento);
	}
	void inOrden(function<void(T)>proc, int limite) {
		int i = 0;
		inOrden(raiz, proc, i, limite);
	}
};
class Puntos {
	int x;
	int y;
public:
	Puntos(int x = 0, int y = 0) :x(x), y(y) {

	}
	int getX() { return this->x; }
	int getY() { return this->y; }
};
int r() {
	return rand() % 100 + 1;
}
int main() {
	int op, valorX, valorY;
	int n = 100;
	auto compareX = [](Puntos* a,Puntos* b){
		if (a->getX()< b->getX()){
			return -1;
		}
		else if (a->getX() > b->getX()){
			return 1;
		}
		else {
			return 0;
		}
	};
	auto compareY = [](Puntos* a, Puntos* b) {
		if (a->getY()< b->getY()) {
			return -1;
		}
		else if (a->getY() > b->getY()) {
			return 1;
		}
		else {
			return 0;
		}
	};
	auto mostrar = [](Puntos* a) {
		cout << a->getX() << " " << a->getY() << endl;
	};
	AVLTree<Puntos*>* TpuntosX = new AVLTree<Puntos*>(compareX);
	AVLTree<Puntos*>* TpuntosY = new AVLTree<Puntos*>(compareY);
	Puntos* dummy;
	for (int i = 0; i < n; i++){
		dummy = new Puntos(r(), r());
		TpuntosX->insertar(dummy);
		TpuntosY->insertar(dummy);
	}
	while (1){
		cin >> op;
		switch (op)
		{
		case 1:
			TpuntosX->inOrden(mostrar, 10);
			break;
		}
	}
	system("pause");
}
