#pragma once

#include "CBird.h"
#include "CEscenario.h"

class CGame {
private:
	CBird jugador;
	CEscenario escenario;

	int puntaje;

public:
	CGame() {
		puntaje = 0;
	}
	~CGame()
	{

	}

	CBird get_jugador() { return jugador; }
	void setjugador(int posicionx, int posiciony, int desplazamientox, int desplazamientoy, int velocidad, int ancho, int alto){
		jugador = CBird(posicionx, posiciony, desplazamientox, desplazamientoy, velocidad, ancho, alto);
	}
	void moverjugador(int tecla) { 
		jugador.Mover(tecla);
	}
	int get_puntaje() {
		return puntaje;
	}
	void set_puntaje(int puntaje) {
		this->puntaje = puntaje;
	}

};
