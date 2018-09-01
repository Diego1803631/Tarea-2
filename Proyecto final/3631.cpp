#include<iostream>
#include<conio.h>
#include<windows.h>
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
int op;
char salida;
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
		altadealumnos();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida =='s')||(salida == 'S')) {
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
	default:
		cout << "Desea salir ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			system("pause");
		}
		else {
			goto menu;
		}
		break;
	}
	_getch();
	return 0;
}
void altadealumnos() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Alta de alumnos----------" << endl;
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
}