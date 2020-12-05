

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;

typedef unsigned char Byte;


void printMem(Byte* mem, int initaddr, int size) {
	int addr = initaddr;
	cout << " Address  +0 +1 +2 +3 +4 +5 +6 +7  +8 +9 +a +b +c +d +e +f\n"
		<< "--------++--+--+--+--+--+--+--+--++--+--+--+--+--+--+--+--+"
		<< setfill('0') << hex;
	for (int i = 0; i < size; i++) {
		if (i % 16 == 0) cout << endl << setw(8) << (addr + i) << " "; // direcciones
		else if (i % 8 == 0) cout << " "; // espacio central extra
		cout << " " << setw(2) << (int)mem[addr + i];
	}
	cout << dec << endl; // regresamos a impresión normal (sistema decimal)
}

void writeMem(Byte* mem, int addr, Byte* data, int numBytes) {
	for (int i = 0; i < numBytes; i++) {
		mem[addr + i] = data[i];
	}
}
void readMem(Byte* mem, int addr, Byte* data, int numBytes) {
	for (int i = 0; i < numBytes; i++) {
		data[i] = mem[addr + i];
	}
}

void inicializar() {
	int size = 1 << 20;
	cout << "Tamano de long long: " << sizeof(long long) << " bytes\n";
	cout << "Tamano de memoria: " << size << " bytes\n";
	cout << "Tamano de memoria: " << hex << size << " bytes\n";
}


//template <typename T>

void menu() {
	char opcion, var;
	string type;
	int valor;
	int size = 1 << 20;
	int addr = 0;
	Byte* mem = new Byte[size];
	do
	{

		cout << "*************************************" << endl;
		cout << "*                                   *" << endl;
		cout << "*               Menu                *" << endl;
		cout << "*                                   *" << endl;
		cout << "*1. INFORMACION                     *" << endl;
		cout << "*2. MOSTRAR MEMORIA                 *" << endl;
		cout << "*3. DECLARAR VARIABLE               *" << endl;
		cout << "*4. DECLARAR PUNTERO                *" << endl;
		cout << "*5. REINICIAR VALORES               *" << endl;
		cout << "*                                   *" << endl;
		cout << "*************************************" << endl;
		cout << "INGRESAR OPCION: "; cin >> opcion;
		switch (opcion)
		{
		case '1': inicializar(); break;
		case '2': printMem(mem, 0, 200); break;
		case '3':
			cout << "Tipo: "; cin >> type;
			cout << "Variable:"; cin >> var;
			cout << "Valor "; cin >> valor;
			int a = valor;
			if (type == "int") { writeMem(mem, addr, (Byte*)&a, sizeof(int)); }
			if (type == "float") { writeMem(mem, addr, (Byte*)&a, sizeof(float)); }
			break;
		}
		cout << endl << endl << endl;
	} while (opcion != '0');
	delete[] mem;
}


int main()
{
	menu();
	_getch;
}