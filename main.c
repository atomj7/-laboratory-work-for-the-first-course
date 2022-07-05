#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include "menu.h"
#include "task's.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL," ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color 5E");
	mainMenu();
	return 0;
}
