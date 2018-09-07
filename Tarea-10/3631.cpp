#include <iostream>
#include<conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

int main() {
	int a[100] = {}; 
	int pos = 49;
	int contador = 0;
	for (int i = 0; i < 100; i++)
	{
		system("cls");
		srand(time(NULL));
		int r = 1 - rand() % 2 * 2;
		pos += r;

		//////////////////////////
		pos = pos < 0 ? 99 : pos;
		pos = pos > 99 ? 0 : pos;
		if (pos == 49) {
			contador++;
		}
		/////////////////////////
		for (int j = 0; j < 100; j++)
		{
			if (j == pos) {
				cout << "@";
			}
			else if (j == 49) {
				cout << "0";
			}
			
			else {
				cout << "*";
			}
		}
		
		Sleep(30);
	}
	cout << "\nPasos por el inicio: ";
	cout << contador;
	cout << "\nPresiona enter para salir.";
	_getch();

}