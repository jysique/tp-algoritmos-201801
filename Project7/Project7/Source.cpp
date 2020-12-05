#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define NONE 0
#define INF 2147483647
using namespace std;
template <typename T>
class AVLTree {
private:
	struct Node {
		T elemento;

		Node* izquierda ;
		Node* derecha ;

		int longitud;
		int altura;

		Node(T elemento = NONE,int longitud = 1, int altura = 0,Node* izquierda  = nullptr, Node* derecha  = nullptr)
			: elemento(elemento), longitud(longitud), altura(altura), izquierda (izquierda ), derecha (derecha ) {}
	};
	Node* raiz;
	 function<int(T, T)> compare;

	int longitud(Node* node) {
		return node != nullptr ? node->longitud : 0;
	}
	int altura(Node* node) {
		return node != nullptr ? node->altura : -1;
	}
	void actualizar(Node* node) {
		if (node != nullptr) {
			node->longitud = 1 + longitud(node->izquierda ) + longitud(node->derecha );
			node->altura = 1 +  max(altura(node->izquierda ), altura(node->derecha ));
		}
	}
	void rIzquierda(Node*& node) {
		Node* d = node->derecha ;
		node->derecha  = d->izquierda ;
		d->izquierda  = node;
		actualizar(d->izquierda );
		actualizar(d);
		node = d;
	}
	void rDerecha(Node*& node) {
		Node* b = node->izquierda ;
		node->izquierda  = b->derecha ;
		b->derecha  = node;
		actualizar(b->derecha );
		actualizar(b);
		node = b;
	}


	void balance(Node*& node) {
		int hl = altura(node->izquierda );
		int hr = altura(node->derecha );
		if (hl - hr < -1) {
			hl = altura(node->derecha ->izquierda );
			hr = altura(node->derecha ->derecha );
			if (hl > hr) {
				rDerecha(node->derecha );
			}
			rIzquierda(node);
		}
		else if (hl - hr > 1) {
			hl = altura(node->izquierda ->izquierda );
			hr = altura(node->izquierda ->derecha );
			if (hl < hr) {
				rIzquierda(node->izquierda );
			}
			rDerecha(node);
		}
		else {
			actualizar(node);
		}
	}
		
	void insertar(Node*& node, T elemento) {
		if (node == nullptr) {
			node = new Node(elemento);
		}
		else {
			if (compare(elemento, node->elemento) < 0) {
				insertar(node->izquierda , elemento);
			}
			else {
				insertar(node->derecha , elemento);
			}
			balance(node);
		}
	}
	
	T buscar(Node* node, T key) {
		if (node != nullptr) {
			if (compare(key, node->elemento) == 0) {
				return node->elemento;
			}
			else if (compare(key, node->elemento) < 0) {
				return buscar(key, node->izquierda );
			}
			else {
				return buscar(key, node->derecha );
			}
		}
		else {
			return NONE;
		}
	}

	void inOrder(Node* node,  function<void(T)> proc, int& i, int limit) {
		if (node != nullptr && i < limit) {
			inOrder(node->izquierda , proc, i, limit);
			if (i < limit) {
				proc(node->elemento);
				i++;
			}
			inOrder(node->derecha , proc, i, limit);
		}
	}
	void bfs(Node* node,  function<void(T)> proc, int limit = INF) {
		vector<Node*> list;
		list.push_back(node);
		int i = 0;
		while (i != list.size() && i< limit) {
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
	AVLTree() : raiz(nullptr){
		compare = [](T a, T b) { return a - b; };
	}
	AVLTree( function<int(T, T)> compare) : compare(compare) {}

	int longitud() {
		return longitud(raiz);
	}
	int altura() {
		return altura(raiz);
	}
	void insertar(T elemento) {
		insertar(raiz, elemento);
	}
	T buscar(T key) {
		return buscar(raiz, key);
	}
	void inOrder( function<void(T)> proc, int limit = INF) {
		int i = 0;
		inOrder(raiz, proc, i, limit);
	}
	void bfs( function<void(T)> proc,int limit = INF) {
		bfs(raiz, proc, limit);
	}
	
};
void menu() {
	cout << endl;
	cout << " AVL Tree " << endl;
	cout << " 1. Insertar" << endl;
	cout << " 2. En Orden" << endl;
	cout << " 3. Por nivel" << endl;
	cout << " 4. Ejemplo" << endl;
	cout << "Ingresar opcion: ";
}

void menu2() {
	cout << endl;
	cout << "	1.Carne" << endl;
	cout << "	2.Calorias" << endl;
	cout << "	3.Peso" << endl;
	cout << "	Ingresar opcion:";
}
void titulo() {
	cout << endl;
	cout << "Carne\tCalorias\tPeso" << endl;
}
int randDbl() {
	return rand() % 100 +1;
}

class Bacon {
	int fat;
	int meat;
	int calories;
public:
	Bacon(int fat = 0, int meat = 0, int calories = 0)
		: fat(fat), meat(meat), calories(calories) {}

	int getFat() { return fat; }
	int getMeat() { return meat; }
	int getCalories() { return calories; }

	void setFat(int fat) { this->fat = fat; }
	void setMeat(int meat) { this->meat = meat; }
	void setCalories(int calories) { this->calories = calories; }
};

int main() {
	int op, valor1, valor2, valor3;
	auto compareFat = [](Bacon* a, Bacon* b) {
		if (a->getFat() < b->getFat()) {
			return -1;
		}
		else if (a->getFat() > b->getFat()) {
			return 1;
		}
		else {
			return 0;
		}
	};
	auto compareMeat = [](Bacon* a, Bacon* b) {
		if (a->getMeat() < b->getMeat()) {
			return -1;
		}
		else if (a->getMeat() > b->getMeat()) {
			return 1;
		}
		else {
			return 0;
		}
	};
	auto compareCalories = [](Bacon* a, Bacon* b) {
		if (a->getCalories() < b->getCalories()) {
			return -1;
		}
		else if (a->getCalories() > b->getCalories()) {
			return 1;
		}
		else {
			return 0;
		}
	};
	auto m = [](Bacon* a) { 
		cout << a->getMeat() << "\t-\t" << a->getCalories() << "\t-\t" << a->getFat() << endl;
	};
	AVLTree<Bacon*>* tFat = new AVLTree<Bacon*>(compareFat);
	AVLTree<Bacon*>* tMeat = new AVLTree<Bacon*>(compareMeat);
	AVLTree<Bacon*>* tCalories = new AVLTree<Bacon*>(compareCalories);
	int n = 100;
	Bacon* piggy;
	for (int i = 0; i < n; i++) {
		piggy = new Bacon(randDbl(), randDbl(), randDbl());
		tFat->insertar(piggy);
		tMeat->insertar(piggy);
		tCalories->insertar(piggy);
	}
	while (true) {
		menu();
		cin >> op;
		switch (op) {
		case 1:

			cout << endl;

			cout << " ** Insertar ** " << endl;

			cout << "Peso: "; cin >> valor1;

			cout << "Carne: "; cin >> valor2;

			cout << "Calorias: "; cin >> valor3;

			piggy = new Bacon();

			piggy->setFat(valor1);

			piggy->setMeat(valor2);

			piggy->setCalories(valor3);

			tFat->insertar(piggy);

			tCalories->insertar(piggy);

			tMeat->insertar(piggy);

			n++;

			break;
		case 2:
			cout << endl;
			cout << " ** En orden ** " << endl;
			menu2();
			cin >> op;
			switch (op)
			{
			case 1:
				cout << "Por peso: " << endl;
				titulo();
				tMeat->inOrder(m, 10);

				break;
			case 2:
				cout << "Por carne:" << endl;
				titulo();
				tCalories->inOrder(m, 10);
				break;
			case 3:
				cout << "Por calorias: " << endl;
				titulo();
				tFat->inOrder(m,10);
				break;
			}
			break;
		case 3:
			cout << endl;
			cout << " ** Por nivel ** " << endl;
			menu2();
			cin >> op;
			switch (op)
			{
			case 1:
				cout << "Por peso: " << endl;
				tFat->bfs(m);

				break;
			case 2:
				cout << "Por carne:" << endl;
				tMeat->bfs(m);
				break;
			case 3:
				cout << "Por calorias:" << endl;
				tCalories->bfs(m);
				break;
			}
			break;
		case 4:
			//arbol.inorder2(4);
			break;
		}
	}	
	system("pause");
	return 0;
}