#include <iostream>
#include <conio.h>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
#define NONE 0
template<typename T>
class AVLTree {
	struct Node{
		T elemento;

		Node* izquierda;
		Node* derecha;

		int longitud;
		int altura;
		Node(T elemento = NONE, Node* izquierda = nullptr, Node* derecha = nullptr, int longitud = 1, int altura = 0):
			elemento(elemento), izquierda(izquierda), derecha(derecha), longitud(longitud), altura(altura){}
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
	void actualizar(Node*& node) {
		if (node != nullptr){
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
	void Balanceo(Node*& node){
		int hl = altura(node->izquierda);
		int hr = altura(node->derecha);
		if (hl -hr < -1){
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
			if (hl < hr){
				rIzquierda(node->izquierda);
			}
			rDerecha(node);
		}
		else{
			actualizar(node);
		}
	}
	void Añadir(Node*& node, T elemento) {
		if (node== nullptr){
			node = new Node(elemento);
			node->elemento = elemento;
		}else if( compare(elemento,node->elemento)< 0){
			Añadir(node->izquierda, elemento);
		}
		else
		{
			Añadir(node->derecha, elemento);
		}
	}
	void inOrden(Node* node, function<void(T)> proc, int& i, int limite) {
		if (node!= nullptr && i < limite){
			inOrden(node->izquierda, proc, i, limite);
			proc(node->elemento);
			i++;
			inOrden(node->derecha, proc, i, limite);
		}
	}
	void bfs(Node* node, function<void(T)> proc, int limite) {
		vector<Node*> list;
		list.push_back(node);
		int i = 0;
		while (i <limite){
			if (list[i] != nullptr) {
				Node* n = list[i];
				proc(n->elemento);
				list.push_back(n->izquierda);
				list.push_back(n->derecha);
			}
			i++;
		}
	}
	void buscar(Node* node, function<void(T)> proc, int & i,int limite, T elemento) {
		if (node!= nullptr && i <limite){
			if (compare(elemento, node->elemento) == 0) {
				proc(node->elemento);
			}
			else if (compare(elemento, node->elemento) < 0){
				buscar(node->izquierda, proc, i, limite, elemento);
			}
			else {
				buscar(node->derecha, proc, i, limite, elemento);
			}
			i++;
			cout << i;
		}
	}
public:
	AVLTree() : raiz(nullptr) {
		compare = [](T a, T b) {return a - b; };
	}
	AVLTree(function<int(T, T)> compare): compare(compare){}
	void Añadir(T elemento) {
		Añadir(raiz, elemento);
	}
	void inOrden(function<void(T)>proc, int limite) {
		int i = 0;
		inOrden(raiz, proc, i, limite);
	}
	void bfs(function<void(T)> proc, int limite) {
		bfs(raiz, proc, limite);
	}
	void buscar(function<void(T)> proc,int limite, T elemento) {
		int i = 0;
		buscar(raiz,proc, i, limite, elemento);
	}
};
class Puntos {
	int x;
	int y;
	int z;
public:
	Puntos(int x = 0, int y = 0, int z= 0):
		x(x), y(y),z(z){}

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
	cout << " 0. Salir " << endl;
	cout << " 1. Numeros de elementos" << endl;
	cout << " 2. Insertar " << endl;
	cout << " 3. En orden " << endl;
	cout << " 4. BFS " << endl;
	cout << " 5. Buscar " << endl;
	cout << " Ingresar opcion: ";
}
void menu2() {
	cout << endl;
	cout << " 1. X " << endl;
	cout << " 2. Y" << endl;
	cout << " 3. Z " << endl;
	cout << " Ingresar opcion: ";
}
int random() {
	return rand() % 100 + 1;
}
int main() {
	int op,l, valorX, valorY, valorZ;
	int n = 100;
	auto compareX = [](Puntos* a, Puntos* b) {
		if (a->getX() < b->getX()){
			return -1;
		}
		else if (a->getX() > b->getX()) {
			return 1;
		}
		else
		{
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
		else
		{
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
		else
		{
			return 0;
		}
	};
	AVLTree<Puntos*>* tPuntosX = new AVLTree<Puntos*>(compareX);
	AVLTree<Puntos*>* tPuntosY = new AVLTree<Puntos*>(compareY);
	AVLTree<Puntos*>* tPuntosZ = new AVLTree<Puntos*>(compareZ);
	Puntos* dummy;
	for (int i = 0; i < n; i++){
		dummy = new Puntos(random(), random(), random());
		tPuntosX->Añadir(dummy);
		tPuntosY->Añadir(dummy);
		tPuntosZ->Añadir(dummy);
	}
	while (true){
		menu();
		cin >> op;
		switch (op)
		{
		case 1:
			cout << endl;
			cout << n;
			break;
		case 2: 
			cout << endl;
			cout << "** INSERTAR **" << endl;
			cout << "X:"; cin >> valorX;
			cout << "Y:"; cin >> valorY;
			cout << "Z:"; cin >> valorZ;
			dummy = new Puntos(valorX, valorY, valorZ);
			tPuntosX->Añadir(dummy);
			tPuntosY->Añadir(dummy);
			tPuntosZ->Añadir(dummy);
			n++;
			break;
		case 3:
			cout << endl;
			cout << "** EN ORDEN ** " << endl;
			menu2();
			cin >> op;
			switch (op)
			{
			case 1:
				cout << endl;
				cout << "limite: "; cin >> l;
				tPuntosX->inOrden([](Puntos* a) { cout << "(" << a->getX() << "," << a->getY() << "," << a->getZ() << ")" << endl; }, l);
				break;
			case 2:
				cout << endl;
				cout << "limite: "; cin >> l;
				tPuntosY->inOrden([](Puntos* a) { cout << "(" << a->getX() << "," << a->getY() << "," << a->getZ() << ")" << endl; }, l);
				break;
			case 3:
				cout << endl;
				cout << "limite: "; cin >> l;
				tPuntosZ->inOrden([](Puntos* a) { cout << "(" << a->getX() << "," << a->getY() << "," << a->getZ() << ")" << endl; }, l);
				break;
			}
			break;
		case 4:
			cout << endl;
			cout << "** BFS ** " << endl;
			menu2();
			cin >> op;
			switch (op)
			{
			case 1:
				cout << endl;
				cout << "limite: "; cin >> l;
				tPuntosX->bfs([](Puntos* a) { cout << "(" << a->getX() << "," << a->getY() << "," << a->getZ() << ")" << endl; }, l);
				break;
			case 2:
				cout << endl;
				cout << "limite: "; cin >> l;
				tPuntosY->bfs([](Puntos* a) { cout << "(" << a->getX() << "," << a->getY() << "," << a->getZ() << ")" << endl; }, l);
				break;
			case 3:
				cout << endl;
				cout << "limite: "; cin >> l;
				tPuntosZ->bfs([](Puntos* a) { cout << "(" << a->getX() << "," << a->getY() << "," << a->getZ() << ")" << endl; }, l);
				break;
			}
			break;
		case 5:
			cout << endl;
			cout << "** BUSCAR ** " << endl;
			menu2();
			cin >> op;
			switch (op)
			{
			case 1:
				cout << endl;
				cout << " Elemento a buscar: "; cin >> valorX;
				dummy = new Puntos(valorX, 0, 0);
				tPuntosX->buscar([](Puntos* a) { cout << "(" << a->getX() << "," << a->getY() << "," << a->getZ() << ")" << endl; },n, dummy);
				break;
			}
			break;
		case 0:
			exit(0);
			break;
		}
	}
	system("pause");

}