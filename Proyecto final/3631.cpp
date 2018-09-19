#include<iostream>
#include<conio.h>
#include <string>
#include<windows.h>
#include<fstream>
using namespace std;
int gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
	return 0;
}
void altadealumnos();
void altadecalificaciones();
void ediciondealumnos();
void ediciondealumnos();
void borraralumno();
void manualdeusuario();
void listadealumnos();
char salida;
/////////////////////////////
struct datos {
	char nombres[100];
	char apellidos[100];
	char correo[100];
	char telefono[100];
	char matricula[100];
	char calle[100];
	char numerodecasa[100];
	char colonia[100];
	int cal1;
	int cal2;
	int cal3;
};
datos alumno[100];
/////////////////////////////
int i = 0;
int j = 0;
int op;
int numerodealumnos;
int main() {
	locale::global(locale("spanish"));
	menu:
	system("cls");
	gotoxy(7, 0);
	cout << "----------Menú----------" << endl;
	cout << "1.Alta de alumnos" << endl;
	cout << "2.Alta de calificaciones" << endl;
	cout << "3.Edición de alumnos" << endl;
	cout << "4.Borrar alumno" << endl;
	cout << "5.Manual de usuario" << endl;
	cout << "6.Lista de alumnos y calificaciones" << endl;
	cout << "7.Salir" << endl;
	cout << "Escoga una opción [ ]" << endl;
	gotoxy(19, 8);
	cin >> op;
	switch (op) {
	case 1:
		system("cls");
		altadealumnos();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			goto menu;
		}
		else {
			cout << "De momento no se puede hacer otra cosa así que BREAK :c" << endl;
		}
		break;
	case 2:
		altadecalificaciones();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			goto menu;
		}
		else {
			cout << "De momento no se puede hacer otra cosa así que BREAK :c" << endl;
		}
		break;
	case 3:
		ediciondealumnos();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			goto menu;
		}
		else {
			cout << "De momento no se puede hacer otra cosa así que BREAK :c" << endl;
		}
		break;
	case 4:
		borraralumno();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			goto menu;
		}
		else {
			cout << "De momento no se puede hacer otra cosa así que BREAK :c" << endl;
		}
		break;
	case 5:
		manualdeusuario();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			goto menu;
		}
		else {
			cout << "De momento no se puede hacer otra cosa así que BREAK :c" << endl;
		}
		break;
	case 6:
		listadealumnos();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			goto menu;
		}
		else {
			cout << "De momento no se puede hacer otra cosa así que BREAK :c" << endl;
		}
		break;
		//no detecto el error, se rompe el programa cuando ingreso un nombre y regreso al menu ya no me deja salir. 
	default:
		cout << "Desea salir ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			system("pause");
		}
		else {
			goto menu;
		}
	}
	_getch();
	return 0;
}
void altadealumnos() {
	menu2:
		gotoxy(7, 0);
		cout << "----------Alta de alumnos----------" << endl;
		cout << "1.Nombre/s:" << endl;
		cout << "2.Apellido/s:" << endl;
		cout << "3.Correo electrónico:" << endl;
		cout << "4.Teléfono:" << endl;
		cout << "5.Matrícula:" << endl;
		cout << "6.Dirección[Calle]:" << endl;
		cout << "7.Dirección[Número]:" << endl;
		cout << "8.Dirección[Colonia]:" << endl;
		cout << "9.Ingresar otro alumno." << endl;
		cout << "10.Salir." << endl;
		cout << "Escoga una opción [  ]" << endl;
			gotoxy(19, 11);
			cin >> op;
			switch (op) {
			case 1:
				while (1) {
					gotoxy(11, 1);
					cin.ignore();
					cin.getline(alumno[i].nombres, 100);
					_strupr_s(alumno[i].nombres);
					cout << alumno[i].nombres << endl;
					numerodealumnos++;
					altadealumnos();
				}
				break;
			case 2:
				while (1) {
					gotoxy(13, 2);
					cin.ignore();
					cin.getline(alumno[i].apellidos, 100);
					_strupr_s(alumno[i].apellidos);
					cout << alumno[i].apellidos << endl;
					altadealumnos();
				}
				break;
			case 3:
				while (1) {
					gotoxy(21, 3);
					cin.ignore();
					cin.getline(alumno[i].correo, 100);
					cout << alumno[i].correo << endl;
					altadealumnos();
				}
				break;
			case 4:
				while (1) {
					gotoxy(11, 4);
					cin.ignore();
					cin.getline(alumno[i].telefono, 100);
					cout << alumno[i].telefono << endl;
					altadealumnos();
				}
				break;
			case 5:
				while (1) {
					gotoxy(12, 5);
					cin.ignore();
					cin.getline(alumno[i].matricula, 100);
					cout << alumno[i].matricula << endl;
					altadealumnos();
				}
				break;
			case 6:
				while (1) {
					gotoxy(19, 6);
					cin.ignore();
					cin.getline(alumno[i].calle, 100);
					cout << alumno[i].calle << endl;
					altadealumnos();
				}
				break;
			case 7:
				while (1) {
					gotoxy(20, 7);
					cin.ignore();
					cin.getline(alumno[i].numerodecasa, 100);
					cout << alumno[i].numerodecasa << endl;
					altadealumnos();
				}
				break;
			case 8:
				while (1) {
					gotoxy(21, 8);
					cin.ignore();
					cin.getline(alumno[i].colonia, 100);
					cout << alumno[i].colonia << endl;
					altadealumnos();
				}
				break;
			case 9:
				system("cls");
				i++;
				altadealumnos();
				break;

			default:
				break;
			}
			main();
			
}
void altadecalificaciones() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Alta de calificaciones----------" << endl;

}
void ediciondealumnos() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Edición de alumnos----------" << endl;
}
void borraralumno() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Borrar alumno----------" << endl;
}
void manualdeusuario() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Manual de usuario----------" << endl;
}
void listadealumnos() {
	system("cls");
	cout << "----------Lista de alumnos y calificaciones----------" << endl;
	for (i = 0; i < numerodealumnos; i++) {
		cout << "\n[" << i << "]=" << alumno[i].nombres << " " << alumno[i].apellidos << " " << alumno[i].matricula << endl;
	}
	
}