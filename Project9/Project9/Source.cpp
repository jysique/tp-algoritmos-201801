#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
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

		Node(T elemento = 0, Node* izquierda = nullptr, Node* derecha = nullptr, int longitud = 1, int altura = 0 ):
		 elemento(elemento),izquierda(izquierda), derecha(derecha), longitud(longitud), altura(altura) {}
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
				if (hl > hr){
					rDerecha(node->derecha);
				}
				rIzquierda(node);
			}
			else if (hl - hr > 1) {
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
		if (node == nullptr){
			node = new Node(elemento);
		}
		else if (compare(elemento,node->elemento)< 0){
			añadir(node->izquierda, elemento);
		}
		else
		{
			añadir(node->derecha, elemento);
		}
		Balanceo(node);
	}
	void InOrden(Node* node, function<void(T)>proc, int& i, int limite) {
		if (node!= nullptr && i < limite){
			InOrden(node->izquierda, proc, i, limite);
			if (i < limite) {
				proc(node->elemento);
				i++;
			}
			InOrden(node->derecha, proc, i, limite);
		}
	}
	void BFS(Node* node, function<void(T)>proc, int limite) {
		vector<Node*> list;
		list.push_back(node);
		int i = 0;
		while (i< limite){
			if (list[i] != nullptr) {
				Node* n = list[i];
				proc(n->elemento);
				list.push_back(n->izquierda);
				list.push_back(n->derecha);
			}
			i++;
		}
	}
public:
	AVLTree() :raiz(nullptr) {
		compare = [](T a, T b) {return a - b; };
	}
	AVLTree(function<int(T, T)> compare ): compare(compare){}
	void añadir(T elemento) {
		añadir(raiz, elemento);
	}
	void InOrden(function<void(T)> proc, int limite) {
		int i = 0;
		InOrden(raiz, proc, i, limite);
	}
	void BFS(function <void(T)> proc, int limite) {
		BFS(raiz, proc, limite);
	}
};

class Puntos {
	int x;
	int y;
	int z;
public:
	Puntos(int x = 0, int y= 0, int z= 0): x(x), y(y), z(z){}

	int getX() { return this->x; }
	int getY() { return this->y; }
	int getZ() { return this->z; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setZ(int z) { this->z = z; }
};

void menu() {
	cout << endl << endl;
	cout << " AVL Tree " << endl;
	cout << " 0. Salir " << endl;
	cout << " 1. Nro Elementos" << endl;
	cout << " 2. Insertar " << endl;
	cout << " 3. En orden" << endl;
	cout << " 4. En orden alt" << endl;
	cout << " 5. Por nivel" << endl;
	cout << " Inserte una opcion: ";
}
void menu2() {
	cout << endl;
	cout << " 1. X" << endl;
	cout << " 2. Y" << endl;
	cout << " 3. Z" << endl;
	cout << " Inserte una opcion: ";
}
int numeroRandom() {
	return rand() % 100 + 1;
}
int main() {
	int op, valorX, valorY, valorZ, limite;
	int n = 1000;
	auto compareX = [](Puntos* a, Puntos* b) {
		if (a->getX()< b->getX()){
			return -1;
		}
		else if (a->getX()> b->getX())
		{
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
		else if (a->getY()> b->getY())
		{
			return 1;
		}
		else {
			return 0;
		}
	};
	auto compareZ = [](Puntos* a, Puntos* b) {
		if (a->getZ()< b->getZ()) {
			return -1;
		}
		else if (a->getZ()> b->getZ())
		{
			return 1;
		}
		else {
			return 0;
		}
	};
	auto mostrar = [](Puntos* a) {cout << "(" << a->getX() << "," << a->getY() << "," << a->getZ() << ")"<<endl; };

	AVLTree<Puntos*>* tpuntosX = new AVLTree<Puntos*>(compareX);
	AVLTree<Puntos*>* tpuntosY = new AVLTree<Puntos*>(compareY);
	AVLTree<Puntos*>* tpuntosZ = new AVLTree<Puntos*>(compareZ);
	Puntos * dummy;
	for (int i = 0; i < n; i++){
		dummy = new Puntos(numeroRandom(), numeroRandom(), numeroRandom());
		tpuntosX->añadir(dummy);
		tpuntosY->añadir(dummy);
		tpuntosZ->añadir(dummy);
	}
	while (1){
		menu();
		cin >> op;
		switch (op)
		{
		case 0:
			exit(1);
			break;
		case 1:
			cout << endl << "** Nro Elementos **" << endl;
			cout << " n:  " << n;
			break;
		case 2:
			cout << endl << "** Insertar **" << endl;
			cout << " X: "; cin >> valorX;
			cout << " Y: "; cin >> valorY;
			cout << " Z: "; cin >> valorZ;
			dummy = new Puntos(valorX, valorY, valorZ);
			tpuntosX->añadir(dummy);
			tpuntosY->añadir(dummy);
			tpuntosZ->añadir(dummy);
			n++;
			break;
		case 3:
			cout << endl << "** En orden **" << endl;
			cout << "Limite: "; cin >> limite;
			menu2();
			cin >> op;
			switch (op){
			case 1:
				tpuntosX->InOrden(mostrar, limite);
				break;
			case 2:
				tpuntosY->InOrden(mostrar, limite);
				break;
			case 3:
				tpuntosZ->InOrden(mostrar, limite);
				break;
			}
			break;
		case 4:
			break;
		case 5:
			cout << endl << " ** Por nivel **" << endl;
			menu2();
			cin >> op;
			switch (op) {
			case 1:
				tpuntosX->BFS(mostrar, 10);
				break;
			case 2:
				tpuntosY->BFS(mostrar, 10);
				break;
			case 3:
				tpuntosZ->BFS(mostrar, 10);
				break;
			}
		}
	}
	system("pause");

}
