#include <iostream>
#include<conio.h>
using namespace std;
void main() {

	setlocale(LC_ALL, "spanish");
	int numero;
	int angulo;
	cout << "Escribe el n�mero de lados de un pol�gono regular: ";
	cin >> numero;
	angulo = 180 * (numero - 2) / numero;
	cout << "El �ngulo interior de tu pol�gono es: " << angulo << "�." << endl;

	_getch();
}