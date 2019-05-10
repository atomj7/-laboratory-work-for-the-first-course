#include "menu.h"
#include "fData.h"
#include "DATA.h"
#include "struct.h"
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <windows.h>
 
 
int main() {
	system("COLOR 5E");
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251	);
	SetConsoleOutputCP(1251);
	int count = 0;
	Cars *p;
	mainMenu(p,count);
	return 111;
}
