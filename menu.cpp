#include "menu.h"
#include "fData.h"
#include "DATA.h"
#include <iostream>
#include <conio.h>
#include "struct.h"


using namespace std;


void showMainMenu(int mark) {
	system("cls");
	cout<< "Peremeshenie po menu   ^  and v \nChoise somthing - ENTER \nBack to main Menu ESC\n"
		<< ((mark == 1) ? "->" : " ") << "1 - 1 InputData\n"
		<< ((mark == 2) ? "->" : " ") << "2 - 2 Output Data \n"
		<< ((mark == 3) ? "->" : " ") << "3 - 3 Create DB\n"
		<< ((mark == 4) ? "->" : " ") << "4 - 4 Remove DB\n"
		<< ((mark == 5) ? "->" : " ") << "5 - 5 Clear memory\n"
		<< ((mark == 6) ? "->" : " ") << "6 - 6 From array to txt\n"
		<< ((mark == 7) ? "->" : " ") << "7 - 7 From txt to array\n"
		<< ((mark == 8) ? "->" : " ") << "8 - 8 Esc\n";
}

void mainMenu(Cars *car,int COUNT_STRUCT) {

	//first of list
	int MARK = 1;
	//last of list
	int last = 8;
	showMainMenu(MARK);

	char key;
	// 27 = ESC
	while ((key = getch()) != 27) {
		// 72 = key down
		if (key == 72) {
			if (0 < MARK - 1)
				MARK--;
			else
				MARK = last;
			showMainMenu(MARK);
		}
		// 80 = key up
		if (key == 80) {
			if (MARK < last)
				MARK++;
			else
				MARK = 1;
			showMainMenu(MARK);
		}
		// 13 = Enter
		if (key == 13) {
			switch (MARK) {
			case 1:
				inputData(car,COUNT_STRUCT);
				break;
			case 2:
				outputData(car,COUNT_STRUCT);
				break;
			case 3: 
				new_DB(car,COUNT_STRUCT);
				break;
			case 4:
				remove_DB(car,COUNT_STRUCT);
				break;
			case 5:
				clear(car,COUNT_STRUCT);
				break;
			case 6:
				save_DB(car,COUNT_STRUCT);
				break;
			case 7:
				load_DB(car,COUNT_STRUCT);
				break;	
			case 8:
				exit(111);
				break;
			}
		}
	}
}

