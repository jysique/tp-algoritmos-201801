#pragma once

#include <iostream>
using namespace System::Drawing;

class CEscenario {
private:
	int positionx;
	int positiony;
public:
	CEscenario(){}
	~CEscenario() {}
	CEscenario(int posicion_x, int posicion_y) {
		this->positionx = posicion_x;
		this->positiony = posicion_y;
	}

	void dibujar_escenario(Graphics^ gr_escenario, Bitmap^bmp_escenario, Rectangle aVisible) {
		gr_escenario->DrawImage(bmp_escenario, 0, 0, aVisible, GraphicsUnit::Pixel);
	}
};