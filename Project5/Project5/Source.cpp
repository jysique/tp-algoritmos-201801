#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include "Header.h"



double randDbl() {
	return  rand()/10000. ;
}

class Bacon {
	double fat;
	double meat;
	double calories;
	double weight;


public:
	Bacon(double fat = 0.,	double meat = 0.,	double calories = 0.,	double weight = 0.) :
		fat(fat), meat(meat), calories(calories), weight(weight) {}

	double getFat() { return fat; }
	double getMeat() { return meat; }
	double getCalories() { return calories; }
	double getWeight() { return weight; }


	void setFat(double fat) { this->fat = fat; }
	void setMeat(double meat) { this->meat = meat; }
	void setCalories(double calories) { this->calories = calories; }
	void setWeight(double weight) { this->weight = weight; }


};


int main() {
	auto compareFat = [](Bacon* a, Bacon* b) {
		return (int)(a->getFat() - b->getFat());
	};
	auto compareMeat = [](Bacon* a, Bacon* b) {
		return (int)(a->getMeat() - b->getMeat());
	};
	auto compareCalories = [](Bacon* a, Bacon* b) {
		return (int)(a->getCalories() - b->getCalories());
	};
	auto compareWeight = [](Bacon* a, Bacon* b) {
		return (int)(a->getWeight() - b->getWeight());
	};

	AVLTree<Bacon*>* tFat = new AVLTree<Bacon*>(compareFat);
	AVLTree<Bacon*>* tMeat = new AVLTree<Bacon*>(compareFat);
	AVLTree<Bacon*>* tCalories = new AVLTree<Bacon*>(compareFat);
	AVLTree<Bacon*>* tWeight = new AVLTree<Bacon*>(compareFat);

	int n = 100;
	Bacon* piggy;


	for (int i = 0; i < n; i++) {
		piggy = new Bacon(randDbl(), randDbl(), randDbl(), randDbl());
		tFat->add(piggy);
		tMeat->add(piggy);
		tCalories->add(piggy);
		tWeight->add(piggy);
		
	}

	std::cout << "\n";
	std::cout << tFat->height() << "\n";
	std::cout << tMeat->height() << "\n";
	std::cout << tCalories->height() << "\n";
	std::cout << tWeight->height() << "\n";
	

	tCalories->preorder([](Bacon* a) { std::cout << a->getCalories() << std::endl; }, 1);
	std::cout << "\n";
	//tCalories->postorder([](Bacon* a) { std::cout << a->getCalories() << std::endl; }, 10);
	//tCalories->inorder([](Bacon* a) { std::cout << a->getCalories() << std::endl; }, 10);

	delete tFat;
	delete tMeat;
	delete tCalories;
	delete tWeight;

	_getch();
}