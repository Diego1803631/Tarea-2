#include<iostream>
#include<conio.h>
#include<string>
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
void borraralumno();
void manualdeusuario();
void listadealumnos();
void busqueda();
void lectura();
void escribir();
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
	char cal1[100];
	char cal2[100];
	char cal3[100];
	float temp1;
	float temp2;
	float temp3;
};
datos alumno[100];
bool dato = false;//verifica si hay un dato en el nombre
bool buscador = false;//verifica si el alumno que se busca es encontrado
char busca[100];
int i = 0;
int j = 0;
int b;//controla la seleccion si se repiten alumnos en la busqueda
int c;//cuenta si resultados repetidos en la busqueda
char op;
int numerodealumnos;
int conta;
float prom;
void main() {
	for (int i = 0; i < numerodealumnos; i++) {
		strcpy_s(alumno[j].cal1, "0");
		strcpy_s(alumno[j].cal2, "0");
		strcpy_s(alumno[j].cal3, "0");
	}
	locale::global(locale("spanish"));
	lectura();
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
	cout << "Escoga una opción:" << endl;
	gotoxy(19, 8);
	cin >> op;
	switch (op) {
	case '1':
	alta:
		system("cls");
		altadealumnos();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin.ignore();
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			menu();
		}
		else {
			goto alta;
		}
		break;
	case '2':
	cal:
		altadecalificaciones();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			menu();
		}
		else {
			goto cal;
		}
		break;
	case '3':
	edicion:
		ediciondealumnos();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			menu();
		}
		else {
			goto edicion;
		}
		break;
	case '4':
	borrar:
		borraralumno();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			menu();
		}
		else {
			goto borrar;
		}
		break;
	case '5':
	manual:
		manualdeusuario();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			menu();
		}
		else {
			goto manual;
		}
		break;
	case '6':
	lista:
		listadealumnos();
		cout << "Regresar al menú ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			menu();
		}
		else {
			goto lista;
		}
		break;

	default:
		salida = 0;
		cout << "Desea salir ¿s/n?" << endl;
		cin >> salida;
		if ((salida == 's') || (salida == 'S')) {
			escribir();
			exit(1);
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
	cout << "Escoga una opción:" << endl;
	gotoxy(19, 11);
	cin >> op;
	if (dato) {
		i = numerodealumnos;
	}
	switch (op) {
	case '1':
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
	case '2':
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
	case '3':
		while (1) {
		correo:
			gotoxy(21, 3);
			cin.ignore();
			cin.getline(alumno[i].correo, 100);
			/*cout << alumno[i].correo << endl;*/
			string str = alumno[i].correo;
			int encontrar1 = str.find('@');
			int encontrar2 = str.find('.com');
			if ((encontrar1 >= 0) && (encontrar2 >= 0)) {
				dato = true;
				altadealumnos();
				break;
			}
			else {
				gotoxy(21, 3);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << "El correo es invalido porfavor introdusca otro";
				system("pause>nul");
				gotoxy(21, 3);
				cout << "                                                " << endl;//crea un espacio en blanco
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				goto correo;
				break;
			}
		}
		break;
	case '4':
		while (1) {
			bool error = false;
		telefono:
			gotoxy(11, 4);
			if (error == false) {
				cin.ignore();
			}
			cin.getline(alumno[i].telefono, 100);
			/*cout << alumno[i].telefono << endl;*/
			char aux1[] = { "123456789012" };
			char aux2[] = { "12345678" };
			if (strlen(alumno[i].telefono) > strlen(aux1) || strlen(alumno[i].telefono) < strlen(aux2)) {
				gotoxy(11, 4);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				error = true;
				cout << "El teléfono es invalido porfavor introdusca otro";
				system("pause>nul");
				gotoxy(11, 4);
				cout << "                                                " << endl;//crea un espacio en blanco
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				goto telefono;
				break;

			}
			/*if (strlen(alumno[i].telefono) == strlen(aux1))*/ else {
				dato = true;
				altadealumnos();
				break;
			}
		}
		break;
	case '5':
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
	case '6':
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
	case '7':
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
	case '8':
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
	case '9':
		system("cls");
		i++;
		numerodealumnos++;
		altadealumnos();
		break;

	default:
		if (dato) {
			numerodealumnos++;
		}
		break;
	}


}
void altadecalificaciones() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Alta de calificaciones----------" << endl;
	int y = 8;
	int y2 = 4;
	c = 0;
	if (numerodealumnos == 0) {
		cout << "No hay alumnos registrados." << endl;
		altadecalificaciones();
	}
	else {
		cout << "Inserte al alumno que desea buscar:";
		cin.ignore();
		cin.getline(busca, 100);
		_strupr_s(busca);
		buscador = false;
		for (i = 0; i < numerodealumnos; i++) {
			if (strcmp(busca, alumno[i].matricula) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "[" << i << "]" << "" << alumno[i].matricula << " " << alumno[i].nombres << " " << alumno[i].apellidos << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				buscador = true;
				c++;
				b = i;
				y++;
				y2++;//incrementa el gotoxy
				/*break;*/
			}
			if (strcmp(busca, alumno[i].nombres) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "[" << i << "]" << "" << alumno[i].matricula << " " << alumno[i].nombres << " " << alumno[i].apellidos << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				buscador = true;
				c++;
				b = i;
				y++;
				y2++;//incrementa el gotoxy
				/*break;*/
			}
			if (strcmp(busca, alumno[i].apellidos) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "[" << i << "]" << "" << alumno[i].matricula << " " << alumno[i].nombres << " " << alumno[i].apellidos << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				buscador = true;
				c++;
				b = i;
				y++;
				y2++;//incrementa el gotoxy
				/*break;*/
			}
		}
		if (!buscador) {
			cout << "No hay alumnos registrados con ese nombre." << endl;
			altadecalificaciones();
		}
		if (c > 1) {
			cout << "Se encontraron resultados similares, escoga al alumno que desea agregar sus calificaciones: ";
			cin >> b;
		}
		for (i = 0; i < numerodealumnos; i++)
			if (b == i) {
				if (buscador) {
					cout << "Desea agregar calificaciones a este alumno? s/n ";
					cin >> salida;
					if ((salida == 's') || (salida == 'S')) {
						cout << "Calificación[1]=";
						cin >> alumno[i].cal1;
						cout << "Calificación[2]=";
						cin >> alumno[i].cal2;
						cout << "Calificación[3]=";
						cin >> alumno[i].cal3;
						cout << "" << endl;

					}
				}
				break;
			}
	}
}
void ediciondealumnos() {
	c = 0;
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
		buscador = false;
		for (i = 0; i < numerodealumnos; i++) {
			if (strcmp(busca, alumno[i].matricula) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "[" << i << "]" << "" << alumno[i].matricula << " " << alumno[i].nombres << " " << alumno[i].apellidos << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				buscador = true;
				c++;
				b = i;
				/*break;*/
			}
			if (strcmp(busca, alumno[i].nombres) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "[" << i << "]" << "" << alumno[i].matricula << " " << alumno[i].nombres << " " << alumno[i].apellidos << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				buscador = true;
				c++;
				b = i;
				/*break;*/
			}
			if (strcmp(busca, alumno[i].apellidos) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "[" << i << "]" << "" << alumno[i].matricula << " " << alumno[i].nombres << " " << alumno[i].apellidos << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				buscador = true;
				c++;
				b = i;
				/*break;*/
			}
		}
		if (!buscador) {
			cout << "No hay alumnos registrados con ese nombre." << endl;
			ediciondealumnos();
		}
		if (c > 1) {
			cout << "Se encontraron resultados similares, escoja el alumno que desea mostrar sus datos: ";
			cin >> b;
		}
		for (i = 0; i < numerodealumnos; i++) {
			if (b == i) {
				cout << "Matricula: " << alumno[i].matricula << endl;
				cout << "Nombre/s: " << alumno[i].nombres << endl;
				cout << "Apellido/s: " << alumno[i].apellidos << endl;
				cout << "Correo: " << alumno[i].correo << endl;
				cout << "Teléfono: " << alumno[i].telefono << endl;
				cout << "Calle: " << alumno[i].calle << endl;
				cout << "Numero #" << alumno[i].numerodecasa << endl;
				cout << "Colonia: " << alumno[i].colonia << endl;
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
						cout << "Escoga una opción:" << endl;
						gotoxy(19, 9);
						cin >> op;
						switch (op) {
						case '1':
							while (1) {
								gotoxy(17, 0);
								cin.ignore();
								cin.getline(alumno[i].nombres, 100);
								_strupr_s(alumno[i].nombres);
								goto menu;
								break;
							}
							break;
						case '2':
							while (1) {
								gotoxy(19, 1);
								cin.ignore();
								cin.getline(alumno[i].apellidos, 100);
								_strupr_s(alumno[i].apellidos);
								goto menu;
								break;
							}
							break;
						case '3':
							while (1) {
								gotoxy(27, 2);
								cin.ignore();
								cin.getline(alumno[i].correo, 100);
								goto menu;
								break;
							}
							break;
						case '4':
							while (1) {
								gotoxy(17, 3);
								cin.ignore();
								cin.getline(alumno[i].telefono, 100);
								goto menu;
								break;
							}
							break;
						case '5':
							while (1) {
								gotoxy(18, 4);
								cin.ignore();
								cin.getline(alumno[i].matricula, 100);
								goto menu;
								break;
							}
							break;
						case '6':
							while (1) {
								gotoxy(25, 5);
								cin.ignore();
								cin.getline(alumno[i].calle, 100);
								goto menu;
								break;
							}
							break;
						case '7':
							while (1) {
								gotoxy(26, 6);
								cin.ignore();
								cin.getline(alumno[i].numerodecasa, 100);
								goto menu;
								break;
							}
							break;
						case '8':
							while (1) {
								gotoxy(27, 7);
								cin.ignore();
								cin.getline(alumno[i].colonia, 100);
								goto menu;
								break;
							}
							break;
						case '0':
							break;
						}
					}
				}
				break;
			}
		}
	}
}
void borraralumno() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Borrar alumno----------" << endl;
	busqueda();
	cout << "Desea eliminar al alumno? s/n" << endl;
	cin >> salida;
	if ((salida == 's') || (salida == 'S')) {
		for (int j = b; j < numerodealumnos; j++) {
			alumno[j] = alumno[j + 1];
		}
		numerodealumnos--;
	}
}
void manualdeusuario() {
	system("cls");
	gotoxy(7, 0);
	cout << "----------Manual de usuario----------" << endl;
	cout << "Diego Alberto Flores González 1803631" << endl;
	cout << "------------------Instrucciones------------------" << endl;
	cout << "MENÚ" << endl;
	cout << "El menú estara dividido en 7 apartados los cuales son :" << endl;
	cout << "->Alta de alumnos" << endl;
	cout << "->Alta de calificaciones" << endl;
	cout << "->Búsqueda y Edición de alumnos" << endl;
	cout << "->Borrar alumno" << endl;
	cout << "->Manual de usuario" << endl;
	cout << "->Lista de alumnos y calificaciones" << endl;
	cout << "->Salir" << endl;
	cout << "Para poder navegar por el menú solo es necesario ingresar el número de la opción a la que quiera entrar." << endl;
	cout << "I.ALTA DE ALUMNOS" << endl;
	cout << "Aquí podra dar de alta a los alumnos, desde su nombre, apellido, matricula, etc." << endl;
	cout << "Si aparece un letrero en rojo es porque inserto un dato invalido." << endl;
	cout << "El número telefónico debe de ser de entre 8 a 12 números; el correo debe de llevar @ y.com." << endl;
	cout << "II.ALTA DE CALIFICACIONES" << endl;
	cout << "Aquí podra dar de alta las calificaciones de los alumnos, se podran insertar solo 3 calificaciones por c/u." << endl;
	cout << "III.BÚSQUEDA Y EDICIÓN DE ALUMNOS" << endl;
	cout << "Aquí se podran buscar los datos del alumno que dese, asi como editar su información." << endl;
	cout << "IV.BORRAR ALUMNO" << endl;
	cout << "Aquí se podran borrar todos los datos del alumno y quitarlo de la base de datos." << endl;
	cout << "V.MANUAL DE USUARIO" << endl;
	cout << "Instrucciones del programa" << endl;
	cout << "VI.LISTA DE ALUMNOS Y CALIFICACIONES" << endl;
	cout << "Se desplegara una lista con toda la información de los alumnos(presione 'c' para mostrar calificaciones)." << endl;
	cout << "VII.SALIR" << endl;
	cout << "Esta opción sale del programa." << endl;
	cout << "Más información en: https://github.com/Diego1803631/Tareas/blob/master/ManualDeUsuario.md" << endl;
	cout << "-------------------------------------------" << endl;
}
void listadealumnos() {
	system("cls");
	cout << "----------Lista de alumnos y calificaciones----------" << endl;
	if (numerodealumnos == 0) {
		cout << "No hay alumnos registrados." << endl;
	}
	gotoxy(0, 2);
	cout << "Matricula" << endl;
	gotoxy(10, 2);
	cout << "Nombre/s" << endl;
	gotoxy(30, 2);
	cout << "Apellido/s" << endl;
	gotoxy(50, 2);
	cout << "Teléfono" << endl;
	gotoxy(64, 2);
	cout << "Correo" << endl;
	gotoxy(90, 2);
	cout << "Dirección" << endl;


	int y = 3;
	for (i = 0; i < numerodealumnos; i++) {
		gotoxy(0, y);
		cout << alumno[i].matricula;
		gotoxy(10, y);
		cout << alumno[i].nombres;
		gotoxy(30, y);
		cout << alumno[i].apellidos;
		gotoxy(50, y);
		cout << alumno[i].telefono;
		gotoxy(64, y);
		cout << alumno[i].correo;
		gotoxy(90, y);
		cout << alumno[i].calle;
		if (strlen(alumno[i].numerodecasa) > 1) {
			cout << " #" << alumno[i].numerodecasa;
		}
		cout << " " << alumno[i].colonia;
		y++;
		/*<< "|" << alumno[i].telefono << "|"
		<< alumno[i].correo << "|" << alumno[i].calle << "|" << alumno[i].numerodecasa << "|" << alumno[i].colonia << "|" << endl;*/
	}
	cout << "\n" << endl;//mod
	char mc;
	cout << "Precione 'c' para mostrar calificaciónes  o 's' para salir: ";
	cin >> mc;
	if ((mc == 'c') || (mc == 'C')) {
		system("cls");
		cout << "Calificaciones" << endl;
		gotoxy(0, 2);
		cout << "Matricula" << endl;
		gotoxy(10, 2);
		cout << "Nombre/s" << endl;
		gotoxy(30, 2);
		cout << "Apellido/s" << endl;
		gotoxy(50, 2);
		cout << "Cal 1" << endl;
		gotoxy(60, 2);
		cout << "Cal 2" << endl;
		gotoxy(70, 2);
		cout << "Cal 3" << endl;
		gotoxy(80, 2);
		cout << "Promedio" << endl;
		for (int i = 0; i < numerodealumnos; i++) {
			alumno[i].temp1 = atof(alumno[i].cal1);
			alumno[i].temp2 = atof(alumno[i].cal2);
			alumno[i].temp3 = atof(alumno[i].cal3);
		}
		y = 3;
		for (i = 0; i < numerodealumnos; i++) {
			gotoxy(0, y);
			cout << alumno[i].matricula;
			gotoxy(10, y);
			cout << alumno[i].nombres;
			gotoxy(30, y);
			cout << alumno[i].apellidos;
			gotoxy(50, y);
			cout << alumno[i].temp1;
			gotoxy(60, y);
			cout << alumno[i].temp2;
			gotoxy(70, y);
			cout << alumno[i].temp3;
			gotoxy(80, y);
			if ((alumno[i].temp1 == 0) || (alumno[i].temp2 == 0) || (alumno[i].temp3 == 0)) {
				prom = 0;
			}
			else {
				prom = ((alumno[i].temp1*0.30) + (alumno[i].temp2*0.45) + (alumno[i].temp3*0.25));
			}
			cout << prom;
			y++;
		}
		cout << "\n" << endl;
	}

}
void busqueda() {
	c = 0;
	if (numerodealumnos == 0) {
		cout << "No hay alumnos registrados." << endl;
	}
	else {
		cout << "Inserte al alumno que desea buscar:";
		cin.ignore();
		cin.getline(busca, 100);
		_strupr_s(busca);
		buscador = false;
		for (i = 0; i < numerodealumnos; i++) {
			if (strcmp(busca, alumno[i].matricula) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "[" << i << "]" << "" << alumno[i].matricula << " " << alumno[i].nombres << " " << alumno[i].apellidos << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				buscador = true;
				c++;
				b = i;
				/*break;*/
			}
			if (strcmp(busca, alumno[i].nombres) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "[" << i << "]" << "" << alumno[i].matricula << " " << alumno[i].nombres << " " << alumno[i].apellidos << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				buscador = true;
				c++;
				b = i;
				/*break;*/
			}
			if (strcmp(busca, alumno[i].apellidos) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "[" << i << "]" << "" << alumno[i].matricula << " " << alumno[i].nombres << " " << alumno[i].apellidos << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				buscador = true;
				c++;
				b = i;
				/*break;*/
			}
		}
		if (!buscador) {
			cout << "No hay alumnos registrados con ese nombre." << endl;
			busqueda();
		}
		if (c > 1) {
			cout << "Se encontraron resultados similares, escoja el alumno que desea eliminar: ";
			cin >> b;
		}
	}
}
void lectura() {
	j = 0;
	numerodealumnos = 0;
	dato = true;
	bool vacio = false;
	ifstream archivo;
	archivo.open("archivo.txt");
	if (!archivo.fail())
	{
		while (!archivo.eof())
		{
			struct guardar {
				char lectura[100];
			};
			guardar d[100];
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].matricula, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].matricula, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].nombres, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].nombres, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].apellidos, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].apellidos, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].telefono, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].telefono, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].correo, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].correo, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].calle, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].calle, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].numerodecasa, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].numerodecasa, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].colonia, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].colonia, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].cal1, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].cal1, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].cal2, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].cal2, d->lectura);
			}
			archivo.getline(d->lectura, 100);
			if (strcmp(d->lectura, "") == 0)
			{
				strcpy_s(alumno[j].cal3, "");
				vacio = true;
			}
			else
			{
				strcpy_s(alumno[j].cal3, d->lectura);
			}
			j++;
			numerodealumnos++;
		}
	}
	archivo.close();
}
void escribir() {
	ofstream archivo;
	archivo.open("archivo.txt");
	i = 0;
	while (i < numerodealumnos)
	{
		char guardados[100];
		if (strcmp(alumno[i].matricula, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		else
		{
			strcpy_s(guardados, alumno[i].matricula);
			strcat_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		if (strcmp(alumno[i].nombres, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		else
		{
			strcpy_s(guardados, alumno[i].nombres);
			strcat_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		if (strcmp(alumno[i].apellidos, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		else
		{
			strcpy_s(guardados, alumno[i].apellidos);
			strcat_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		if (strcmp(alumno[i].telefono, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		else
		{
			strcpy_s(guardados, alumno[i].telefono);
			strcat_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		if (strcmp(alumno[i].correo, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		else
		{
			strcpy_s(guardados, alumno[i].correo);
			strcat_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		if (strcmp(alumno[i].calle, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		else
		{
			strcpy_s(guardados, alumno[i].calle);
			strcat_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		if (strcmp(alumno[i].numerodecasa, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		else
		{
			strcpy_s(guardados, alumno[i].numerodecasa);
			strcat_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		if (strcmp(alumno[i].colonia, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		else
		{
			strcpy_s(guardados, alumno[i].colonia);
			strcat_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		/*if (strcmp(alumno[i].cal1, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}*/
		/*else
		{*/
		strcpy_s(guardados, alumno[i].cal1);
		strcat_s(guardados, "\n");
		archivo.write(guardados, strlen(guardados));
		/*}*/
		/*if (strcmp(alumno[i].cal2, "") == 0)
		{
			strcpy_s(guardados, "\n");
			archivo.write(guardados, strlen(guardados));
		}
		else
		{*/
		strcpy_s(guardados, alumno[i].cal2);
		strcat_s(guardados, "\n");
		archivo.write(guardados, strlen(guardados));
		/*}*/
		/*if (strcmp(alumno[i].cal3, "") == 0)
		{*/
		/*strcpy_s(guardados, "\n");
		archivo.write(guardados, strlen(guardados));*/
		/*}*/
		/*else
		{*/
		strcpy_s(guardados, alumno[i].cal3);
		if (i + 1 != numerodealumnos) {
			strcat_s(guardados, "\n");
		}
		archivo.write(guardados, strlen(guardados));
		/*}*/
		i++;
	}
	archivo.close();
}