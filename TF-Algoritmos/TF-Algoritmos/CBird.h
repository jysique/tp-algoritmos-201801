#pragma once
using namespace System::Drawing;

class CBird {
private:
	int posicionx;
	int posiciony;

	double desplazamientox;
	double desplazamientoy;
	int direccionx;
	int direcciony;

	int velocidad;

	int ancho;
	int alto;
	int idspritex;	
	int idspritey;

public:
	CBird() {

	}
	CBird(int posicionx, int posiciony, int desplazamientox, int desplazamientoy,int velocidad, int ancho, int alto) {
		this->posicionx = posicionx;
		this->posiciony = posiciony;
		this->desplazamientox = desplazamientox;
		this->desplazamientoy = desplazamientoy;
		this->velocidad = velocidad;

		this->ancho = ancho;
		this->alto = alto;

		ancho = 22;
		alto = 24, 6;

		direccionx = 1;
		direcciony = 1;
		idspritex = 0;
		idspritey = 0;
	}
	void dibujar_jugador(Graphics^gr_jugador, Bitmap^bmp_jugador, Rectangle aVisible) {
		gr_jugador->DrawImage(bmp_jugador, posicionx, posiciony, aVisible, GraphicsUnit::Pixel);
	}
	void Mover(int tecla) {
		if (tecla==1){
			direccionx = -1;
			posicionx = posicionx + desplazamientox * direccionx;
		}
		if (tecla==2) {
			direccionx = 1;
			posicionx = posicionx + desplazamientox * direccionx;
		}
		if (tecla==3){
			direcciony = -1;
			posiciony = posiciony + desplazamientoy * direcciony;
		}
		if (tecla==4){
			direcciony = 1;
			posiciony = posiciony + desplazamientoy * direcciony;
		}
	}
	int get_posicionx() { return posicionx; }
	int get_posiciony() { return posiciony; }
	int get_ancho() { return ancho; }
	int get_alto() { return alto; }

	void set_posicionx(int posicionx) { this->posicionx = posicionx; }
	void set_posicionx(int posiciony) { this->posiciony = posiciony; }

	int get_idspritex() { return idspritex; }
	int get_idspritey() { return idspritey; }


};
