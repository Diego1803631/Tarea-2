#include<iostream>
#include<conio.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "spanish");
	char nombre[20];
	char apellido[20];
	int edad;
	char telefono[20];
	cout << "Nombre:";
	cin >> nombre;
	cout << "Apellido:";
	cin >> apellido;
	cout << "Edad:";
	cin >> edad;
	cout << "Teléfono:";
	cin >> telefono;

	cout << "\nNombre: " << apellido << ", " << nombre << "." << endl;
	cout << "---" << endl;
	cout << "Edad: "<< edad << " años." << endl;
	cout << "Teléfono: " << "+52" << telefono << endl;


	_getch();
	return 0;
}