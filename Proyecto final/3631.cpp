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
void menu();
void altadealumnos();
void altadecalificaciones();
void ediciondealumnos();
void ediciondealumnos();
void borraralumno();
void manualdeusuario();
void listadealumnos();
char salida;
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
//////////////////////////////////
bool dato = false;//verifica si hay un dato en el nombre
bool buscador = false;//verifica si el alumno que se busca es encontrado
char busca[100];
int i = 0;
int j = 0;
int op;
int numerodealumnos;
/////////////////////////////////
void main() {
	locale::global(locale("spanish"));
	menu();
	_getch();
}
void menu() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Menú----------" << endl;
	cout << "1.Alta de alumnos" << endl;
	cout << "2.Alta de calificaciones" << endl;
	cout << "3.Búsqueda y Edición de alumnos" << endl;
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
		cin.ignore();
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			menu();
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
			menu();
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
			menu();
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
			menu();
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
			menu();
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
			menu();
		}
		else {
			cout << "De momento no se puede hacer otra cosa así que BREAK :c" << endl;
		}
		break;
		
	default:
		salida = 0;
		cout << "Desea salir ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			break;
		}
		if ((salida != 's') || (salida != 'S')) {
			menu();
		}
		break;
	}
}
void altadealumnos() {
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
		cout << "0.Salir." << endl;
		cout << "Escoga una opción [ ]" << endl;
			gotoxy(19, 11);
			cin >> op;
			switch (op) {
			case 1:
				if (dato) {
					i = numerodealumnos;
				}
				while (1) {
					gotoxy(11, 1);
					cin.ignore();
					cin.getline(alumno[i].nombres, 100);
					_strupr_s(alumno[i].nombres);
					cout << alumno[i].nombres << endl;
					dato = true;
					altadealumnos();
					break;
				}
				break;
			case 2:
				while (1) {
					gotoxy(13, 2);
					cin.ignore();
					cin.getline(alumno[i].apellidos, 100);
					_strupr_s(alumno[i].apellidos);
					cout << alumno[i].apellidos << endl;
					dato = true;
					altadealumnos();
					break;
				}
				break;
			case 3:
				while (1) {
					gotoxy(21, 3);
					cin.ignore();
					cin.getline(alumno[i].correo, 100);
					cout << alumno[i].correo << endl;
					dato = true;
					altadealumnos();
					break;
				}
				break;
			case 4:
				while (1) {
					gotoxy(11, 4);
					cin.ignore();
					cin.getline(alumno[i].telefono, 100);
					cout << alumno[i].telefono << endl;
					dato = true;
					altadealumnos();
					break;
				}
				break;
			case 5:
				while (1) {
					gotoxy(12, 5);
					cin.ignore();
					cin.getline(alumno[i].matricula, 100);
					cout << alumno[i].matricula << endl;
					dato = true;
					altadealumnos();
					break;
				}
				break;
			case 6:
				while (1) {
					gotoxy(19, 6);
					cin.ignore();
					cin.getline(alumno[i].calle, 100);
					cout << alumno[i].calle << endl;
					dato = true;
					altadealumnos();
					break;
				}
				break;
			case 7:
				while (1) {
					gotoxy(20, 7);
					cin.ignore();
					cin.getline(alumno[i].numerodecasa, 100);
					cout << alumno[i].numerodecasa << endl;
					dato = true;
					altadealumnos();
					break;
				}
				break;
			case 8:
				while (1) {
					gotoxy(21, 8);
					cin.ignore();
					cin.getline(alumno[i].colonia, 100);
					cout << alumno[i].colonia << endl;
					dato = true;
					altadealumnos();
					break;
				}
				break;
			case 9:
				system("cls");
				i++;
				numerodealumnos++;
				altadealumnos();
				break;

			case 0:
				numerodealumnos++;
				//main();
				break;
			}
			
			
}
void altadecalificaciones() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Alta de calificaciones----------" << endl;

}
void ediciondealumnos() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Búsqueda y Edición de alumnos----------" << endl; //tarea 14
	if (numerodealumnos == 0) {
		cout << "No hay alumnos registrados." << endl;
	}
	else {
		cout << "Inserte al alumno que desea buscar:";
		cin.ignore();
		cin.getline(busca, 100);
		_strupr_s(busca);

		for (i = 0; i < numerodealumnos; i++) {
			buscador = false;
			if (strcmp(busca, alumno[i].nombres) == 0) {
				cout << alumno[i].nombres << " " << alumno[i].matricula << endl;
				buscador = true;
				break;
			}
			if (strcmp(busca, alumno[i].matricula) == 0) {
				cout << alumno[i].nombres << " " << alumno[i].matricula << endl;
				buscador = true;
				break;
			}
			
		}
		if (!buscador) {
			cout << "No hay alumnos registrados con ese nombre." << endl;
		}
		if (buscador) {
			cout << "Desea editar al alumno? s/n" << endl;
			cin >> salida;
			if ((salida == 's') || (salida == 'S')) {
			menu:
				system("cls");
				cout << "1.Nuevo Nombre/s:" << endl;
				cout << "2.Nuevo Apellido/s:" << endl;
				cout << "3.Nuevo Correo electrónico:" << endl;
				cout << "4.Nuevo Teléfono:" << endl;
				cout << "5.Nueva Matrícula:" << endl;
				cout << "6.Nueva Dirección[Calle]:" << endl;
				cout << "7.Nueva Dirección[Número]:" << endl;
				cout << "8.Nueva Dirección[Colonia]:" << endl;
				cout << "0.Salir." << endl;
				cout << "Escoga una opción [ ]" << endl;
				gotoxy(19, 9);
				cin >> op;
				switch (op) {
				case 1:
					while (1) {
						gotoxy(17, 0);
						cin.ignore();
						cin.getline(alumno[i].nombres, 100);
						_strupr_s(alumno[i].nombres);
						goto menu;
						break;
					}
					break;
				case 2:
					while (1) {
						gotoxy(19, 1);
						cin.ignore();
						cin.getline(alumno[i].apellidos, 100);
						_strupr_s(alumno[i].apellidos);
						goto menu;
						break;
					}
					break;
				case 3:
					while (1) {
						gotoxy(27, 2);
						cin.ignore();
						cin.getline(alumno[i].correo, 100);
						goto menu;
						break;
					}
					break;
				case 4:
					while (1) {
						gotoxy(17, 3);
						cin.ignore();
						cin.getline(alumno[i].telefono, 100);
						goto menu;
						break;
					}
					break;
				case 5:
					while (1) {
						gotoxy(18, 4);
						cin.ignore();
						cin.getline(alumno[i].matricula, 100);
						goto menu;
						break;
					}
					break;
				case 6:
					while (1) {
						gotoxy(25, 5);
						cin.ignore();
						cin.getline(alumno[i].calle, 100);
						goto menu;
						break;
					}
					break;
				case 7:
					while (1) {
						gotoxy(26, 6);
						cin.ignore();
						cin.getline(alumno[i].numerodecasa, 100);
						goto menu;
						break;
					}
					break;
				case 8:
					while (1) {
						gotoxy(27, 7);
						cin.ignore();
						cin.getline(alumno[i].colonia, 100);
						goto menu;
						break;
					}
					break;
					case 0:
						break;

				}
			}
		}
	}
}
void borraralumno() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Borrar alumno----------" << endl; //tarea16
	if (numerodealumnos == 0) {
		cout << "No hay alumnos registrados." << endl;
	}
	else {
		cout << "Inserte al alumno que desea buscar:";
		cin.ignore();
		cin.getline(busca, 100);
		_strupr_s(busca);

		for (i = 0; i < numerodealumnos; i++) {
			buscador = false;
			if (strcmp(busca, alumno[i].nombres) == 0) {
				cout << alumno[i].nombres << " " << alumno[i].matricula << endl;
				buscador = true;
				break;
			}
			if (strcmp(busca, alumno[i].matricula) == 0) {
				cout << alumno[i].nombres << " " << alumno[i].matricula << endl;
				buscador = true;
				break;
			}

		}
		if (!buscador) {
			cout << "No hay alumnos registrados con ese nombre." << endl;
		}
		if (buscador) {
			cout << "Desea eliminar al alumno? s/n" << endl;
			cin >> salida;
			if ((salida == 's') || (salida == 'S')) {
				for (int j=i; j < numerodealumnos; j++) {
					alumno[j] = alumno[j + 1];
				}
				numerodealumnos--;
			}
		}
	}
}
void manualdeusuario(){
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