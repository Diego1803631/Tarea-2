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
	int cal1;
	int cal2;
	int cal3;
};
datos alumno[100];
//////////////////////////////////
bool dato = false;//verifica si hay un dato en el nombre
bool buscador = false;//verifica si el alumno que se busca es encontrado
char busca[100];
int b;
int i = 0;
int j = 0;
int op;
int numerodealumnos;
float prom;
/////////////////////////////////
void main() {
	locale::global(locale("spanish"));
	/*lectura();*/
	menu();
	escribir();
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
	case 2:
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
	case 3:
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
	case 4:
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
	case 5:
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
	case 6:
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
			if (dato) {
				i = numerodealumnos;
			}
			switch (op) {
			case 1:
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
			case 4:
				while (1) {
					bool error = false;
				telefono:
					gotoxy(11, 4);
					if (error==false) {
						cin.ignore();
					}
					cin.getline(alumno[i].telefono, 100);
					/*cout << alumno[i].telefono << endl;*/
					char aux1[] = { "123456789012" };
					if (strlen(alumno[i].telefono) < strlen(aux1)){
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
					if (strlen(alumno[i].telefono) == strlen(aux1)) {
						dato = true;
						altadealumnos();
						break;
					}
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
			
			if (strcmp(busca, alumno[i].nombres) == 0) {
				cout << i << " " << alumno[i].matricula << " " << alumno[i].nombres << endl;
				buscador = true;
				/*break;*/
			}
			if (strcmp(busca, alumno[i].matricula) == 0) {
				cout << i << " " << alumno[i].matricula << " " << alumno[i].nombres << endl;
				buscador = true;
				/*break;*/
			}
		}
		if (!buscador) {
			cout << "No hay alumnos registrados con ese nombre." << endl;
		}
		cout << "Escoga al alumno que desea agregar sus calificaciones:";
		cin >> b;
		for (i = 0; i < numerodealumnos; i++)
			if (b == i) {
				if (buscador) {
					cout << "Desea agregar calificaciones a este alumno? s/n ";
					cin >> salida;
					if ((salida == 's') || (salida == 'S')) {
						cout << "1.Calificación[1]=" << endl;
						cout << "2.Calificación[2]=" << endl;
						cout << "3.Calificación[3]=" << endl;
						cout << "0.Salir." << endl;
						cout << "Escoga una opción [ ]" << endl;
					menu:
						gotoxy(19, 9);
						cin >> op;
						switch (op) {
						case 1:
							while (1) {
								gotoxy(18, 5);
								cin >> alumno[i].cal1;
								goto menu;
								break;
							}
							break;
						case 2:
							while (1) {
								gotoxy(18, 6);
								cin >> alumno[i].cal2;
								goto menu;
								break;
							}
							break;
						case 3:
							while (1) {
								gotoxy(18, 7);
								cin >> alumno[i].cal3;
								goto menu;
								break;
							}
							break;
						case 0:
							break;
						}

					}
				}
				break;
			}
	}
	for (i = 0; i < numerodealumnos; i++) {
		cout << i << " " << alumno[i].cal1 << " " << alumno[i].cal2 << " " << alumno[i].cal3 << endl;
	}

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
		buscador = false;
		for (i = 0; i < numerodealumnos; i++) {
			
			if (strcmp(busca, alumno[i].nombres) == 0) {
				cout << i << " " << alumno[i].matricula << " " << alumno[i].nombres << endl;
				buscador = true;
				/*break;*/
			}
			if (strcmp(busca, alumno[i].matricula) == 0) {
				cout << i << " " << alumno[i].matricula << " " << alumno[i].nombres << endl;
				buscador = true;
				/*break;*/
			}


		}
		
		if (!buscador) {
			cout << "No hay alumnos registrados con ese nombre." << endl;
		}
		cout << "Escoga al alumno que desea editar:";
		cin >> b;
		for(i=0;i<numerodealumnos;i++)
		if (b == i) {
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
			break;
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
		if (strlen(alumno[i].numerodecasa)>1) {
			cout << " #" << alumno[i].numerodecasa;
		}
		cout<< " " << alumno[i].colonia;
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
		y = 3;
		for (i = 0; i < numerodealumnos; i++) {
			gotoxy(0, y);
			cout << alumno[i].matricula;
			gotoxy(10, y);
			cout << alumno[i].nombres;
			gotoxy(30, y);
			cout << alumno[i].apellidos;
			gotoxy(50, y);
			cout << alumno[i].cal1;
			gotoxy(60, y);
			cout << alumno[i].cal2;
			gotoxy(70, y);
			cout << alumno[i].cal3;
			gotoxy(80, y);
			if ((alumno[i].cal1 == 0) || (alumno[i].cal2 == 0)|| (alumno[i].cal3 == 0)) {
				prom = 0;
			}
			else {
				prom = ((alumno[i].cal1*0.30) + (alumno[i].cal2*0.45) + (alumno[i].cal3*0.25));
			}
			cout << prom;
			y++;
		}
		cout << "\n" << endl;
	}

}
void lectura() {
	ifstream archivo("archivo.txt", ios::binary);
	if (archivo.is_open()) {
		i = 0;							
		while (!archivo.eof()) {
			archivo.read((char*)&alumno[i].nombres, sizeof(alumno[i].nombres));
			i++;
		}
	}
	archivo.close();
}
void escribir() {
	ofstream archivo;
	archivo.open("archivo.txt", ios::binary);
	for (int i = 0; i < numerodealumnos; i++) {
		archivo.write((char*)&alumno[i].nombres, sizeof(alumno[i].nombres));
		archivo.write((char*)&alumno[i].apellidos, sizeof(alumno[i].apellidos));
	}
	archivo.close();
}