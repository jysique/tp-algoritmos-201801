#include <iostream>
#include <conio.h>
#include <functional>
#include <algorithm>
#include <vector>
#define NONE 0
#define INF 2000000
using namespace std;
template<typename T>
class AVLTree {
	struct Node{
		T elemento;

		Node* izquierda;
		Node* derecha;

		int longitud;
		int altura;

		Node(T elemento = NONE, Node* izquierda= nullptr, Node* derecha = nullptr, int longitud=1, int altura = 0):
			elemento(elemento), izquierda(izquierda), derecha(derecha),longitud(longitud), altura(altura){}
	};
	Node* raiz;
	function<int(T, T)> compare;

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
			node->altura = 1 + max(altura(node->izquierda),altura(node->derecha));
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
				if (hl>hr){
					rDerecha(node->derecha);
				}
				rIzquierda(node);
			}
			else if (hl-hr > 1){
				hl = altura(node->izquierda->izquierda);
				hr = altura(node->izquierda->derecha);
				if (hl< hr){
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
		if (node== nullptr){
			node = new Node(elemento);
		}
		else if (compare(elemento,node->elemento)<0){
			añadir(node->izquierda, elemento);
		}
		else {
			añadir(node->derecha, elemento);
		}
		Balanceo(node);
	}
	void inOrden(Node* node, function<void(T)>proc, int& i, int limite = INF) {
		if (node!= nullptr && i< limite){
			inOrden(node->izquierda, proc, i, limite);
			proc(node->elemento);
			i++;
			inOrden(node->derecha, proc, i, limite);
		}
	}
	void bfs(Node* node, function<void(T)>proc, int limite) {
		vector<Node*> list;
		list.push_back(node);
		int i = 0;
		while (i!= list.size() && i < limite){
			if (list[i]!= nullptr) {
				Node* n = list[i];
				proc(n->elemento);
				list.push_back(n->izquierda);
				list.push_back(n->derecha);
			}
			i++;
		}
	}
public:
	AVLTree():raiz(nullptr){
		compare = [](T a, T b) {return a - b; };
	}
	AVLTree(function<int(T, T)> compare):compare(compare){}
	void añadir(T elemento) {
		añadir(raiz, elemento);
	}
	void inOrden(function<void(T)> proc, int limite) {
		int i = 0;
		inOrden(raiz, proc, i, limite);
	}
	void bfs(function<void(T)> proc,int limite) {
		bfs(raiz, proc, limite);
	}
};
class Puntos {
	int x;
	int y;
	int z;
public:
	Puntos(int x = 0, int y = 0, int z = 0) :
		x(x), y(y), z(z) {}

	int getX() { return this->x; }
	int getY() { return this->y; }
	int getZ() { return this->z; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setZ(int z) { this->z = z; }
};
void menu() {
	cout << endl;
	cout << " AVL Tree " << endl;
	cout << " 0. Salir" << endl;
	cout << " 1. Insertar" << endl;
	cout << " 2. En orden" << endl;
	cout << " 3. Por nivel" << endl;
	cout << " Ingresar Opcion: ";
}
void menu2() {
	cout << endl;
	cout << "   0. Salir" << endl;
	cout << "   1. X" << endl;
	cout << "   2. Y" << endl;
	cout << "   3. Z" << endl;
	cout << " Ingresar Opcion: ";
}
void titulo() {
	cout << "X\tY\tZ" << endl;
}
int rndm() {
	return rand() % 100 + 1;
}
int main() {
	int op, valor1, valor2, valor3;
	auto compareX = [](Puntos* a, Puntos* b) {
		if (a->getX() < b->getX()) {
			return -1;
		}
		else if (a->getX() > b->getX()) {
			return 1;
		}
		else {
			return 0;
		}
	};
	auto compareY = [](Puntos* a, Puntos* b) {
		if (a->getY() < b->getY()) {
			return -1;
		}
		else if (a->getY() > b->getY()) {
			return 1;
		}
		else {
			return 0;
		}
	};
	auto compareZ = [](Puntos* a, Puntos* b) {
		if (a->getZ() < b->getZ()) {
			return -1;
		}
		else if (a->getZ() > b->getZ()) {
			return 1;
		}
		else {
			return 0;
		}
	};
	AVLTree<Puntos*>*tX = new AVLTree<Puntos*>(compareX);
	AVLTree<Puntos*>*tY = new AVLTree<Puntos*>(compareY);
	AVLTree<Puntos*>*tZ = new AVLTree<Puntos*>(compareZ);
	int n = 100;
	Puntos* dummy;
	for (int i = 0; i < n; i++){
		dummy = new Puntos(rndm(), rndm(), rndm());
		tX->añadir(dummy);
		tY->añadir(dummy);
		tZ->añadir(dummy);
	}
	while (1){
		menu();
		cin >> op;
		cout << endl;
		switch (op)
		{
		case 1:
			cout << "*** INSERTAR ***" << endl;
			cout << "X: "; cin >> valor1;
			cout << "Y: "; cin >> valor2;
			cout << "Z: "; cin >> valor3;
			dummy = new Puntos();
			dummy->setX(valor1);
			dummy->setY(valor2);
			dummy->setZ(valor3);
			tX->añadir(dummy);
			tY->añadir(dummy);
			tZ->añadir(dummy);
			n++;
			break;
		case 2:
			cout << "*** POR ORDEN ***" << endl;
			menu2();
			cin >> op;
			switch (op)
			{
			case 1:
				cout << "** X **"<<endl;
				titulo();
				tX->inOrden([](Puntos* a) { cout << a->getX() << "\t" << a->getY() << "\t" << a->getZ() << endl; }, 10);
				break;
			case 2:
				cout << "** Y **" << endl;
				titulo();
				tY->inOrden([](Puntos* a) { cout << a->getX() << "\t" << a->getY() << "\t" << a->getZ() << endl; }, 10);
				break;
			case 3:
				cout << "** Z **" << endl;
				titulo();
				tZ->inOrden([](Puntos* a) { cout << a->getX() << "\t" << a->getY() << "\t" << a->getZ() << endl; }, 10);
				break;
			case 0:
				exit(1);
			}
			break;
		case 3:
			cout << "*** POR NIVEL ***" << endl;
			menu2();
			cin >> op;
			switch (op)
			{
			case 1:
				cout << "** X **" << endl;
				titulo();
				tX->bfs([](Puntos* a) { cout << a->getX() << "\t" << a->getY() << "\t" << a->getZ() << endl; }, 10);
				break;
			case 2:
				cout << "** Y **" << endl;
				titulo();
				tY->bfs([](Puntos* a) { cout << a->getX() << "\t" << a->getY() << "\t" << a->getZ() << endl; }, 10);
			case 3:
				break;
				cout << "** Z **" << endl;
				titulo();
				tZ->bfs([](Puntos* a) { cout << a->getX() << "\t" << a->getY() << "\t" << a->getZ() << endl; }, 10);
				break;
			case 0:
				exit(1);
			}
			break;
		case 0:
			exit(1);
			break;
		}
	}
	system("pause");
}
