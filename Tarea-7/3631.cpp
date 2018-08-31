#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
int rival;
int opcion;
char a;//se usa para salir del programa
void piedra();
void papel();
void tijeras();
void main() {
	locale::global(locale("spanish"));
	srand(time(NULL));
menu:
	system("cls");
	cout << "Piedra, Papel o Tijeras" << endl;
	cout << "1.Piedra" << endl;
	cout << "2.Papel" << endl;
	cout << "3.Tijeras" << endl;
	cout << "4.Salir" << endl;
	cout << "Escoge una opcion: ";
	cin >> opcion;
	rival = rand() % 3 + 1;
	switch (opcion) {
	case 1:
		cout << "Has elegido Piedra" << endl;
		piedra();
		break;
	case 2:
		cout << "Has elegido Papel" << endl;
		papel();
		break;
	case 3:
		cout << "Has elegido Tijeras" << endl;
		tijeras();
		break;
	case 4:
		break;
	}
	cout << "¿Jugar de nuevo? s/n" << endl;
	cin >> a;
	if (a == 's') {
		rival = 0;
		opcion = 0;
		goto menu;
	}
	else {
		system("pause");
	}
}
void piedra() {
	if (rival == 1) {
		cout << "Tu rival ha elegido piedra:" << rival << "\nEmpate :s" << endl;
	}
	if(rival==2){
		cout << "Tu rival ha elegido papel:" << rival << "\nPerdiste :c" << endl;
	}
	if(rival==3) {
		cout << "Tu rival ha elegido tijeras:" << rival << "\nGanaste :D" << endl;
	}
}
void papel() {
	if (rival == 1) {
		cout << "Tu rival ha elegido piedra:" << rival << "\nGanaste :D" << endl;
	}
	if (rival == 2) {
		cout << "Tu rival ha elegido papel:" << rival << "\nEmpate :s" << endl;
	}
	if (rival == 3) {
		cout << "Tu rival ha elegido tijeras:" << rival << "\nPerdiste :c" << endl;
	}
}
void tijeras() {
	if (rival == 1) {
		cout << "Tu rival ha elegido piedra:" << rival << "\nPerdiste :c" << endl;
	}
	if (rival == 2) {
		cout << "Tu rival ha elegido papel:" << rival << "\nGanaste :D" << endl;
	}
	if (rival == 3) {
		cout << "Tu rival ha elegido tijeras:" << rival << "\nEmpate :s" << endl;
	}
}

