#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "spanish");
	float radio;
	float alfa;
	float x, y;
	float coseno, seno;
	cout << "Ingrese el radio y el ángulo sexagesimal para encontrar las coordenadas (x, y):" << endl;
	cout << "Ingrese el radio: ";
	cin >> radio;
	cout << "Ingrese el ángulo sexagesimal: ";
	cin >> alfa;
	x = radio * (cos(alfa*3.14159 / 180.0));
	y = radio * (sin(alfa*2.0*3.14159 / 360.0));
	/*coseno = (cos(alfa*3.14159 / 180.0));
	seno = (sin(alfa*2.0*3.14159 / 360.0));
	cout << coseno << endl;
	cout << seno << endl;*/
	x = round(x);
	y = round(y);
	cout << "\nLas coordenadas (x, y) son: (" << x << ", " << y << ")" << endl;
	_getch();
}
