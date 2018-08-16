#include <iostream>
#include<conio.h>
using namespace std;
void main() {

	setlocale(LC_ALL, "spanish");
	int numero;
	int angulo;
	cout << "Escribe el número de lados de un polígono regular: ";
	cin >> numero;
	angulo = 180 * (numero - 2) / numero;
	cout << "El ángulo interior de tu polígono es: " << angulo << "°." << endl;

	_getch();
}