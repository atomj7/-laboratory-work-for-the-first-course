#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//проверить как работает память и пофиксить

struct Date {
	int month;
	int day;
	int year;
};

struct Cars {
	Date release;
	char mark[20];
	int max_Speed;
	int torque;
	char model[20];
	char color[20];
	int enginePower;
	char  manufacturer_country[20];
};

//some func for qsort 
int sort_Mark_In(const void* a, const void* b) {
	return strcmp(((Cars*)a)->mark, ((Cars*)b)->mark);
}
int sort_Mark_Dec(const void* a, const void* b) {
	return -strcmp(((Cars*)a)->mark, ((Cars*)b)->mark);
}
int sort_Model_In(const void* a, const void* b) {
	return strcmp(((Cars*)a)->model, ((Cars*)b)->model);
}
int sort_Model_Dec(const void* a, const void* b) {
	return -strcmp(((Cars*)a)->model, ((Cars*)b)->model);
}
int sort_Color_In(const void* a, const void* b) {
	return strcmp(((Cars*)a)->color, ((Cars*)b)->color);
}
int sort_Color_Dec(const void* a, const void* b) {
	return -strcmp(((Cars*)a)->color, ((Cars*)b)->color);
}
int sort_Country_In(const void* a, const void* b) {
	return strcmp(((Cars*)a)->manufacturer_country, ((Cars*)b)->manufacturer_country);
}
int sort_Country_Dec(const void* a, const void* b) {
	return -strcmp(((Cars*)a)->manufacturer_country, ((Cars*)b)->manufacturer_country);
}
int sort_EnginePower_In(const void* a, const void* b) {
	return ((Cars*)a)->enginePower - ((Cars*)b)->enginePower;
}
int sort_EnginePower_Dec(const void* a, const void* b) {
	return ((Cars*)b)->enginePower - ((Cars*)a)->enginePower ;
}
int sort_Speed_In(const void* a, const void* b) {
	return ((Cars*)a)->max_Speed - ((Cars*)b)->max_Speed ;
}
int sort_Speed_Dec(const void* a, const void* b) {
	return ((Cars*)b)->max_Speed - ((Cars*)a)->max_Speed;
}
int sort_Torque_In(const void* a, const void* b) {
	return ((Cars*)a)->torque - ((Cars*)b)->torque;
}
int sort_Torque_Dec(const void* a, const void* b) {
	return ((Cars*)b)->torque - ((Cars*)a)->torque;
}
void sort_Date(Cars *car,int COUNT_STRUCT, bool derection ) {
	struct Cars temp;
	//sort by years 
	if (derection == 1) {
		for (int i = 0; i < COUNT_STRUCT; i++) {
			for (int j = 0; j < COUNT_STRUCT; j++) {
				if (car[i].release.year > car[j].release.year) {
					temp = car[j];
					car[j] = car[i];
					car[i] = temp;
				}
			}
		}
		//sort by month
		for (int i = 0; i < COUNT_STRUCT; i++) {
			for (int j = 0; j < COUNT_STRUCT; j++) {
				if (car[i].release.year == car[j].release.year && car[i].release.month > car[j].release.month) {
					temp = car[j];
					car[j] = car[i];
					car[i] = temp;
				}
			}
		}
		//sort by day
		for (int i = 0; i < COUNT_STRUCT; i++) {
			for (int j = 0; j < COUNT_STRUCT; j++) {
				if (car[i].release.year == car[j].release.year && car[i].release.month == car[j].release.month && car[i].release.day > car[j].release.day) {
					temp = car[j];
					car[j] = car[i];
					car[i] = temp;
				}
			}
		}
	}
	else {
		for (int i = 0; i < COUNT_STRUCT; i++) {
			for (int j = 0; j < COUNT_STRUCT; j++) {
				if (car[i].release.year < car[j].release.year) {
					temp = car[j];
					car[j] = car[i];
					car[i] = temp;
				}
			}
		}
		//sort by month
		for (int i = 0; i < COUNT_STRUCT; i++) {
			for (int j = 0; j < COUNT_STRUCT; j++) {
				if (car[i].release.year == car[j].release.year && car[i].release.month < car[j].release.month) {
					temp = car[j];
					car[j] = car[i];
					car[i] = temp;
				}
			}
		}
		//sort by day
		for (int i = 0; i < COUNT_STRUCT; i++) {
			for (int j = 0; j < COUNT_STRUCT; j++) {
				if (car[i].release.year == car[j].release.year && car[i].release.month == car[j].release.month && car[i].release.day < car[j].release.day) {
					temp = car[j];
					car[j] = car[i];
					car[i] = temp;
				}
			}
		}
	}
}
void sort(Cars* car, int COUNT_STRUCT);

//menuFunc
void mainMenu(Cars* car, int COUNT_STRUCT);
void showMainMenu(int mark);
void showChangeMenu(int mark);
void showSearchMenu(int mark);
void showSortMenu(int mark);

//some func for put info
void inputData(Cars* car, int COUNT_STRUCT);
void outputData(Cars* car, int COUNT_STRUCT);
//FILE
void new_DB(Cars* car, int COUNT_STRUCT);
void remove_DB(Cars* car, int COUNT_STRUCT);
void clear(Cars* car, int COUNT_STRUCT);
void save_DB(Cars* car, int COUNT_STRUCT);
void load_DB(Cars* car, int COUNT_STRUCT);
//work with struct 
void global_cleaner(Cars* car, int COUNT_STRUCT) {
	car = NULL;
	COUNT_STRUCT = 0;
}
void del(Cars* car, int COUNT_STRUCT);
void change(Cars* car, int COUNT_STRUCT);
void Search(Cars* car, int COUNT_STRUCT);
void filter(Cars* car, int COUNT_STRUCT);




//main 
int main() {
	system("COLOR 5E");
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count = 0;
	Cars* p = (Cars*)malloc(sizeof(Cars));
	mainMenu(p, count);
	free(p);
	return 111;
}

void showChangeMenu(int mark) {
	system("cls");
	cout << ((mark == 1) ? "->" : " ") << "1-Change the Date of releasse  \n"
		<< ((mark == 2) ? "->" : " ") << "2-Change the Color \n"
		<< ((mark == 3) ? "->" : " ") << "3-Change the Mark\n"
		<< ((mark == 4) ? "->" : " ") << "4-Change the Model\n"
		<< ((mark == 5) ? "->" : " ") << "5-Change the Manufacturer County \n"
		<< ((mark == 6) ? "->" : " ") << "6-Change the Torque\n"
		<< ((mark == 7) ? "->" : " ") << "7-Change the Max Speed\n"
		<< ((mark == 8) ? "->" : " ") << "8-Change the Engine Power\n"
		<< ((mark == 9) ? "->" : " ") << "9-Exit";
}

void showSearchMenu(int mark) {
	system("cls");
	cout << ((mark == 1) ? "->" : " ") << "1-Search the  Date of release  \n"
		<< ((mark == 2) ? "->" : " ") << "2-Search the  Mark\n"
		<< ((mark == 3) ? "->" : " ") << "3-Search the Model\n"
		<< ((mark == 4) ? "->" : " ") << "4-Search the Manufacturer country\n"
		<< ((mark == 5) ? "->" : " ") << "5-Search the Color\n"
		<< ((mark == 6) ? "->" : " ") << "6-Search the Engine power\n"
		<< ((mark == 7) ? "->" : " ") << "7-Search the Max speed\n"
		<< ((mark == 8) ? "->" : " ") << "8-Search the Torque \n"
		<< ((mark == 9) ? "->" : " ") << "0-Exit\n";
}

void showSortMenu(int mark) {
	system("cls");
	cout << ((mark == 1) ? "->" : " ") << "1-Sort the  Date of release  \n"
		<< ((mark == 2) ? "->" : " ") << "2-Sort the  Mark\n"
		<< ((mark == 3) ? "->" : " ") << "3-Sort the Model\n"
		<< ((mark == 4) ? "->" : " ") << "4-Sort the Manufacturer country\n"
		<< ((mark == 5) ? "->" : " ") << "5-Sort the Color\n"
		<< ((mark == 6) ? "->" : " ") << "6-Sort the Engine power\n"
		<< ((mark == 7) ? "->" : " ") << "7-Sort the Max speed\n"
		<< ((mark == 8) ? "->" : " ") << "8-Sort the Torque \n"
		<< ((mark == 9) ? "->" : " ") << "0-Exit\n";
}

void showMainMenu(int mark) {
	system("cls");
	cout << "Peremeshenie po menu   ^  and v \nChoise somthing - ENTER \nBack to main Menu ESC\n"
		<< ((mark == 1) ? "->" : " ") << "1 - 1 InputData\n"
		<< ((mark == 2) ? "->" : " ") << "2 - 2 Output Data \n"
		<< ((mark == 3) ? "->" : " ") << "3 - 3 Create DB\n"
		<< ((mark == 4) ? "->" : " ") << "4 - 4 Remove DB\n"
		<< ((mark == 5) ? "->" : " ") << "5 - 5 Clear memory\n"
		<< ((mark == 6) ? "->" : " ") << "6 - 6 From array to File\n"
		<< ((mark == 7) ? "->" : " ") << "7 - 7 From File to array\n"
		<< ((mark == 8) ? "->" : " ") << "8 - 8 Delete \n"
		<< ((mark == 9) ? "->" : " ") << "9 - 9 Search\n"
		<< ((mark == 10) ? "->" : " ") << "10 - 10 Change\n"
		<< ((mark == 11) ? "->" : " ") << "11 - 11 Sort\n"
		<< ((mark == 12) ? "->" : " ") << "12 - 12 Filter\n"
		<< ((mark == 13) ? "->" : " ") << "13 - 13 Esc\n";
}

void inputData(Cars* car, int COUNT_STRUCT) {
	if (COUNT_STRUCT != 0) {
		car = (Cars*)realloc(car,COUNT_STRUCT + 1 * sizeof(Cars));
		for (int i = COUNT_STRUCT ; i < (i + 1); i++) {
			system("cls");
			cout << "Enter the information about the  " << i + 1 << " Car :" << endl;
			//input month
			cout << "Enter month of car release :";
			while (!(cin >> car[i].release.month) || car[i].release.month <= 0 || car[i].release.month > 12) {
				
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops! Something went wrong! Try again: ";
			}
			//input day
			cout << "Enter day of car release :";
			while (!(cin >> car[i].release.day) || car[i].release.day <= 0 || car[i].release.day > 31) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops! Something went wrong! Try again:";
			}
			//input year
			cout << "Enter year of car release day of car release  :";
			while (!(cin >> car[i].release.year) || car[i].release.year <= 1787 || car[i].release.year > 2019) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops! Something went wrong! Try again:";
			}
			//input the MARK
			cin.ignore();
			cout << "Enter the MARK of the auto : ";
			cin.getline(car[i].mark,20);
			//input the model 
	
			cout << "Enter the model of  the auto:";
			cin.getline(car[i].model,20);
			//input the color

			cout << "Enter the color of the auto:";
			cin.getline(car[i].color,20);
			//input the country
			cout << "Enter the manufacture country of the auto :";
			cin.getline(car[i].manufacturer_country,20);
			//input the max speed
			cout << "Enter the max speed of car : ";
			while (!(cin >> car[i].max_Speed) || car[i].max_Speed <= 0 || car[i].max_Speed >= 1270) {
				cout << "Oops! Something went wrong! Try again:";
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
			//input the torque
			cout << "Enter the torque of auto :";
			while (!(cin >> car[i].torque) || car[i].torque <= 0 || car[i].torque >= 2000) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops! Something went wrong! Try again:";
			}
			//input the engine POwer
			cout << "Enter the  Engine Power of the auto :";
			while (!(cin >> car[i].enginePower) || car[i].enginePower <= 0 || car[i].enginePower >= 2000) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops! Something went wrong! Try again:";
			}

			system("cls");
			cout << "DO you want  to input more structs ?\n 1 - Yes \n0 - No :";
			bool flag;
			while (!(cin >> flag)) {
				cout << "Oops! Something went wrong! Try again:";
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}

			if (flag == 1) {
				COUNT_STRUCT++;
				car = (Cars*)realloc(car, (COUNT_STRUCT) * sizeof(Cars));
				
			}
			else mainMenu(car, COUNT_STRUCT);
		}
	}
	else {
		COUNT_STRUCT = 1;
		car = (Cars*)realloc(car, COUNT_STRUCT * sizeof(Cars));
		for (int i = 0; i < COUNT_STRUCT; i++) {
			system("cls");
			cout << "Enter the information about the  " << i + 1 << " Car :" << endl;
			//input month
			cout << "Enter month of car release :";
			while (!(cin >> car[i].release.month) || car[i].release.month <= 0 || car[i].release.month > 12) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops! Something went wrong! Try again:";

			}
			//input day
			cout << "Enter day of car release :";
			while (!(cin >> car[i].release.day) || car[i].release.day <= 0 || car[i].release.day > 31) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops! Something went wrong! Try again:";
			}
			//input year
			cout << "Enter year of car release day of car release  :";
			while (!(cin >> car[i].release.year) || car[i].release.year <= 1787 || car[i].release.year > 2019) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops! Something went wrong! Try again:";
			}
			//input the MARK
			cin.ignore();
			cout << "Enter the MARK of the auto : ";
			cin.getline(car[i].mark,20);
			//input the model 
			cout << "Enter the model of  the auto:";
			cin.getline(car[i].model,20);
			//input the color
			cout << "Enter the color of the auto:";
			cin.getline(car[i].color,20);
			//input the country
			cout << "Enter the manufacture country of the auto :";
			cin.getline(car[i].manufacturer_country,20);
			//input the max speed
			cout << "Enter the max speed of car : ";
			while (!(cin >> car[i].max_Speed) || car[i].max_Speed <= 0 || car[i].max_Speed >= 1270) {
				cout << "Oops! Something went wrong! Try again:";
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
			//input the torque
			cout << "Enter the torque of auto :";
			while (!(cin >> car[i].torque) || car[i].torque <= 0 || car[i].torque >= 2000) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops!Something went wrong!Try again : ";
			}
			//input the engine POwer
			cout << "Enter the  Engine Power of the auto :";
			while (!(cin >> car[i].enginePower) || car[i].enginePower <= 0 || car[i].enginePower >= 2000) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Oops! Something went wrong! Try again: ";
			}

			system("cls");
			cout << "DO you want  to input more structs ?\n 1 - Yes \n0 - No :";
			bool flag;
			while (!(cin >> flag)) {
				cout << "Oops! Something went wrong! Try again:";
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}

			if (flag == 1) {
				COUNT_STRUCT++;
				car = (Cars*)realloc(car, (COUNT_STRUCT) * sizeof(Cars));
			}
			else 	mainMenu(car, COUNT_STRUCT);
		}
	}
}

void mainMenu(Cars * car, int COUNT_STRUCT) {

	//first of list
	int MARK = 1;
	//last of list
	int last = 13;
	showMainMenu(MARK);

	char key;
	// 27 = ESC
	while ((key = _getch()) != 27) {
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
				inputData(car, COUNT_STRUCT);
				break;
			case 2:
				outputData(car, COUNT_STRUCT);
				break;
			case 3:
				new_DB(car, COUNT_STRUCT);
				break;
			case 4:
				remove_DB(car, COUNT_STRUCT);
				break;
			case 5:
				clear(car, COUNT_STRUCT);
				break;
			case 6:
				save_DB(car, COUNT_STRUCT);
				break;
			case 7:
				load_DB(car, COUNT_STRUCT);
				break;
			case 8:
				del(car, COUNT_STRUCT);
				break;
			case 9:
				Search(car, COUNT_STRUCT);
				break;
			case 10:
				change(car, COUNT_STRUCT);
				break;
			case 11:
				sort(car, COUNT_STRUCT);
				break;
			case 12:
				filter(car, COUNT_STRUCT);
				break;
			case 13:
				exit(111);
				break;
			}
		}
	}
}

void outputData(Cars * car, int COUNT_STRUCT) {

	system("cls");
	if (COUNT_STRUCT == 0 || !car) cout << "DATA IS OUT";
	else {
		cout << "  ----------------------------------------------------------------------------------------------------------------------------------------- \n";
		cout << setw(10) << "№"
			<< setw(15) << "Mark"
			<< setw(15) << "Model"
			<< setw(15) << "Country"
			<< setw(15) << "Color"
			<< setw(15) << "Date"
			<< setw(20) << "Max speed"
			<< setw(15) << "Engine power"
			<< setw(15) << "torque" << endl;


		for (int i = 0; i < COUNT_STRUCT; i++) {
			cout << setw(10) << i + 1
				<< setw(15) << car[i].mark
				<< setw(15) << car[i].model
				<< setw(15) << car[i].manufacturer_country
				<< setw(15) << car[i].color
				<< setw(10) << car[i].release.day << "." << car[i].release.month << "." << car[i].release.year
				<< setw(15) << car[i].max_Speed
				<< setw(10) << car[i].enginePower
				<< setw(20) << car[i].torque << endl;
		}
		cout << "  ----------------------------------------------------------------------------------------------------------------------------------------- \n";
	}
	cout << "\nPress any key to return in main Menu...";
	_getch();
	mainMenu(car, COUNT_STRUCT);
}

void new_DB(Cars * car, int COUNT_STRUCT) {
	bool next = 1;
	while (next == true) {
		system("cls");
		char FNAME[30];
		cout << "Enter file name :";
		fflush(stdin);
		cin.getline(FNAME,30);

		ofstream fout;
		fout.open(FNAME);
		if (fout.is_open()) cout << "File has been opened";
		else cout << "File hasn't been opened";
		cout << "\nPress...\n1-Countinue \n0-Exit in main menu\n";
		while (!(cin >> next)) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\nTry again : ";
		}
	}
	mainMenu(car, COUNT_STRUCT);
}

void remove_DB(Cars * car, int COUNT_STRUCT) {
	bool next = 1;
	char FNAME[30];
	while (next == true) {
		system("cls");
		cout << "Enter name what you want to delete :";
		fflush(stdin);
		cin.getline(FNAME, 30);

		if (remove(FNAME) != 0) cout << "File hasn't been deleted";
		else cout << "File has been deleted";
		cout << "\nPress...\n1-Countinue \n0-Exit in main menu\n";
		while (!(cin >> next)) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\nTry again : ";
		}
	}
	mainMenu(car, COUNT_STRUCT);
}

void clear(Cars * car, int COUNT_STRUCT) {

	system("cls");
	if (COUNT_STRUCT == 0) cout << "DATA IS OUT";
	else {
		delete(car);
		car = NULL;
		COUNT_STRUCT = 0;
		cout << "Cleanning was succsessfull";
	}

	cout << "\nPress any key to return in main Menu...";
	_getch();
	mainMenu(car, COUNT_STRUCT);
}

void save_DB(Cars * car, int COUNT_STRUCT) {
	system("cls");
	char FNAME[30];
	char wordXML[] = { "xml" };
	if (COUNT_STRUCT == 0) cout << "DATA IS OUT";
	else {
		cout << "\nEnter outfile name :";
		cin.getline(FNAME, 30);
		ofstream fout;
		fout.open(FNAME);
		if (fout.is_open()) {
			cout << "File Open";
			if (FNAME[strlen(FNAME) - 1] == wordXML[2] && FNAME[strlen(FNAME) - 2] == wordXML[1] && FNAME[strlen(FNAME) - 3] == wordXML[0]) {
				fout << "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n";
				for (int i = 0; i < COUNT_STRUCT; i++) {
					fout << "<" << i + 1 << ">\n"
						<< "\t<Mark>" << car[i].mark << "<\\Mark>\n"
						<< "\t<Model>" << car[i].model << "<\\Model>\n"
						<< "\t<Manufacturer_Country>" << car[i].manufacturer_country << "<\\Manufacturer_Country>\n"
						<< "\t<Color>" << car[i].color << "<\\Color>\n"
						<< "\t<Release_Date>" << car[i].release.day << "." << car[i].release.month << "." << car[i].release.year << "<\\Release_Date>\n"
						<< "\t<Max_Speed>" << car[i].max_Speed << "<\\Max_Speed>\n"
						<< "\t<Engine_Power>" << car[i].enginePower << "<\\Engine_Power>\n"
						<< "\t<Torque>" << car[i].torque << "<\\Torque>\n"
						<< "<\\" << i + 1 << ">" << endl;
				}
			}
			else {
				for (int i = 0; i < COUNT_STRUCT; i++) {
					fout << i + 1 << "|"
						<< car[i].mark << "|"
						<< car[i].model << "|"
						<< car[i].manufacturer_country << "|"
						<< car[i].color << "|"
						<< car[i].release.day << "." << car[i].release.month << "." << car[i].release.year << "|"
						<< car[i].max_Speed << "|"
						<< car[i].enginePower << "|"
						<< car[i].torque << "|" << endl;
				}
				cout << "\nSuccsess!";
				fout.close();
			}
		}
		
		else cout << "\nFILE HAS NOT  OPENED";
		fout.close();
	}
	cout << "\nPress any key to return in main Menu...";
	_getch();
	mainMenu(car, COUNT_STRUCT);

}

void load_DB(Cars * car, int COUNT_STRUCT) {
	system("cls");
	char str[100];
	char firstString[100];
	int index = 0;
	int lineCount = 0;
	int iter_index;
	char FNAME[30];
	char wordXML[] = { "xml" };
	int size;
	cout << "Enter out name :";
	cin.getline(FNAME, 30);
	ifstream fin;
	fin.open(FNAME);
	int while_is_right = 0;
	if (fin.is_open()) {

		if (FNAME[strlen(FNAME) - 1] == wordXML[2] && FNAME[strlen(FNAME) - 2] == wordXML[1] && FNAME[strlen(FNAME) - 3] == wordXML[0]) {
			while (!fin.eof()) {
				fin.getline(firstString, 100);
				while (fin.getline(str, 100)) {

					while_is_right = 1;
					lineCount++;
					iter_index = 0;
					COUNT_STRUCT = (lineCount - 1 )/10 + 1 ;
					size = (lineCount - 1) / 10 ;
					car = (Cars*)realloc(car, COUNT_STRUCT* sizeof(Cars));
					char* temp = strtok(str, ".\\<>");
					while (temp != NULL) {
						if (iter_index == 2 ||( (index == 5 && iter_index == 2 ) || (index == 5 && iter_index == 3) || (index == 5 && iter_index == 4))) {
							
							switch (index) {
							case 1: {
								strcpy(car[size].mark, temp);
								if (strlen(car[size].mark) > 20) {
									cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
									global_cleaner(car, COUNT_STRUCT);
								}
								break;
							}
							case 2: {
								strcpy(car[size].model, temp);
								if (strlen(car[size].model) > 20) {
									cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
									global_cleaner(car, COUNT_STRUCT);
								}
								break;
							}
							case 3: {
								strcpy(car[size].manufacturer_country, temp);
								if (strlen(car[size].manufacturer_country) > 20) {
									cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
									global_cleaner(car, COUNT_STRUCT);
								}
								break;
							}
							case 4: {
								strcpy(car[size].color, temp);
								if (strlen(car[size].color) > 20) {
									cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
									global_cleaner(car, COUNT_STRUCT);
								}
								break;
							}
							case 5: {
								switch (iter_index) {
								case 2:
									car[size].release.day = atoi(temp);
									break;
								case 3:
									car[size].release.month = atoi(temp);
									break;
								case 4:
									car[size].release.year = atoi(temp);
									break;
								}
								break;
							}
							case 6: {
								car[size].max_Speed = atoi(temp);
								if (!car[size].max_Speed || car[size].max_Speed < 0 || car[size].max_Speed > 500) {
									cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
									global_cleaner(car, COUNT_STRUCT);
								}
								break;
							}
							case 7: {
								car[size].enginePower = atoi(temp);
								if (!car[size].enginePower || car[size].enginePower < 0 || car[size].enginePower > 1500) {
									cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
									global_cleaner(car, COUNT_STRUCT);
								}
								break;
							}
							case 8: {
								car[size].torque = atoi(temp);
								if (!car[size].torque || car[size].torque < 0 || car[size].torque > 1500) {
									cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
									global_cleaner(car, COUNT_STRUCT);
								}
								break;
							}
							}
					}
						
						temp = strtok(NULL, ".\\<>");
						iter_index++;
					}
					index++;
					index %= 10;
				}

			}
		}
		else {
			while (!fin.eof()) {

				while (fin.getline(str, 100)) {

					while_is_right = 1;
					lineCount++;
					iter_index = 0;
					COUNT_STRUCT = lineCount;
					car = (Cars*)realloc(car, COUNT_STRUCT * sizeof(Cars));
					//cout << "STRUCt  = = " << COUNT_STRUCT << endl;
					char* temp = strtok(str, "|.");
					while (temp != NULL) {
						switch (iter_index) {
						case 1: {
							strcpy(car[index].mark, temp);
							if (strlen(car[index].mark) > 20) {
								cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
								global_cleaner(car, COUNT_STRUCT);
							}
							break;
						}
						case 2: {
							strcpy(car[index].model, temp);
							if (strlen(car[index].model) > 20) {
								cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
								global_cleaner(car, COUNT_STRUCT);
							}
							break;
						}
						case 3: {
							strcpy(car[index].manufacturer_country, temp);
							if (strlen(car[index].manufacturer_country) > 20) {
								cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
								global_cleaner(car, COUNT_STRUCT);
							}
							break;
						}
						case 4: {
							strcpy(car[index].color, temp);
							if (strlen(car[index].color) > 20) {
								cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
								global_cleaner(car, COUNT_STRUCT);
							}
							break;
						}
						case 5: {
							car[index].release.day = atoi(temp);
							break;
						}
						case 6: {
							car[index].release.month = atoi(temp);
							break;
						}
						case 7: {
							car[index].release.year = atoi(temp);
							break;
						}
						case 8: {
							car[index].max_Speed = atoi(temp);
							if (!car[index].max_Speed || car[index].max_Speed < 0 || car[index].max_Speed > 500) {
								cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
								global_cleaner(car, COUNT_STRUCT);
							}
							break;
						}
						case 9: {
							car[index].enginePower = atoi(temp);
							if (!car[index].enginePower || car[index].enginePower < 0 || car[index].enginePower > 1500) {
								cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
								global_cleaner(car, COUNT_STRUCT);
							}
							break;
						}
						case 10: {
							car[index].torque = atoi(temp);
							if (!car[index].torque || car[index].torque < 0 || car[index].torque > 1500) {
								cout << "Error! In the " << iter_index << " column and  " << index + 1 << "row are incorrect data" << endl;
								global_cleaner(car, COUNT_STRUCT);
							}
							break;
						}
						}

						temp = strtok(NULL, "|.");
						iter_index++;
					}
					index++;
				}

			}
		}
		fin.close();
		cout << ((while_is_right == 1) ? "Succsess!\nPress any key to return in main Menu..." : "\nFile is empty\nPress any key to return in main Menu...");
		_getch();
		mainMenu(car, COUNT_STRUCT);
	}
	else {
		cout << "\nFILE HAS NOT  OPENED\nPress any key to return in main Menu...";
		_getch();
		mainMenu(car, COUNT_STRUCT);
	}
	
}

void del(Cars * car, int COUNT_STRUCT) {
	system("cls");
		if (COUNT_STRUCT == 0) cout << "Data is empty : \n";
		else {
			int key;        //номер записи, которую нужно удалить
			cout << "\nВведите номер записи, которую необходимо удалить\n";
			cout << "Если необходимо удалить все записи,введите  0: ";
			while (!(cin >> key) || key < 0 || key > COUNT_STRUCT) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nTry again : ";
			}
			if (key != 0) {
				for (int i = (key - 1); i < COUNT_STRUCT; i++) //from key to COUNT
					car[i] = car[i + 1]; 
				COUNT_STRUCT -= 1; //уменяьшаем счетчик полных записей на 1
			}
			else if (key == 0 && COUNT_STRUCT == 1) {
				COUNT_STRUCT = 0;
			}
			else {
				car = NULL; //замещаем каждую структуру в массиве пустой структурой
				COUNT_STRUCT = 0; //счетчик структур обнуляем, т.к. все записи удалены
			}
			cout << "\nDELETING IS SUCCSEFULL";
		}
	cout << "Press any button to return to the menu.";
	_getch();
	mainMenu(car, COUNT_STRUCT);
}

void Search(Cars* car, int COUNT_STRUCT) {
	system("cls");
		if (COUNT_STRUCT == 0) cout << "Data is empty : \n";
		else {
			int i;
			int day, month, year, enginePower, speed, torque;
			char color[30], country[30], mark[30], model[30];

			system("cls");
			// first of list
			int MARK = 1;
			//last of list
			int last = 9;
			showSearchMenu(MARK);

			char key;
			// 27 = ESC
			while ((key = _getch()) != 27) {
				// 72 = key down
				if (key == 72) {
					if (0 < MARK - 1)
						MARK--;
					else
						MARK = last;
					showSearchMenu(MARK);
				}
				// 80 = key up
				if (key == 80) {
					if (MARK < last)
						MARK++;
					else
						MARK = 1;
					showSearchMenu(MARK);
				}
				// 13 = Enter
				if (key == 13) {
					switch (MARK) {
						case 1: {
							system("cls");
							fflush(stdin);
							cout << "Input the date of struct  what you want to Search (dd.mm,yy)\n";
							scanf("%d %d %d", &day, &month, &year);
							for (i = 0; i < COUNT_STRUCT; i++) {
								if (day == car[i].release.day && month == car[i].release.month && car[i].release.year == year) {
									cout << "Found value in structure number : " << i + 1
										<< "\nPress any button to return to the menu.";
									_getch();
									mainMenu(car, COUNT_STRUCT);
								}
								else  cout << "Value was not found";
							}
							break;
						}
						case 2: {
							system("cls");
							fflush(stdin);
							cout << "Input the mark of struct  what do you want to Search ";
							cin.getline(mark, 20);
							for (i = 0; i < COUNT_STRUCT; i++) {
								if (strcmp(car[i].mark, mark) == 0) {
									cout << "Found value in structure number : " << i + 1
										<< "\nPress any button to return to the menu...";
									_getch();
									mainMenu(car, COUNT_STRUCT);
								}
								else  cout << "Value was not found";
							}
							break;
						}
						case 3: {
							system("cls");
							fflush(stdin);
							printf("Input the Model of struct what do  you want to Search");
							cin.getline(model, 20);
							for (i = 0; i < COUNT_STRUCT; i++) {
								if (strcmp(car[i].model, model) == 0) {
									cout << "Found value in structure number : " << i + 1
										<< "\nPress any button to return to the menu...";
									_getch();
									mainMenu(car, COUNT_STRUCT);
								}
								else  cout << "Value was not found";
							}
							break;
						}
						case 4: {
							system("cls");
							fflush(stdin);
							cout << "Input the Manufacturer country of struct what you want to Search:";
							cin.getline(country, 20);;
							for (i = 0; i < COUNT_STRUCT; i++) {
								if (strcmp(car[i].manufacturer_country, country) == 0) {
									cout << "Found value in structure number : " << i + 1
										<< "\nPress any button to return to the menu...";
									_getch();
									mainMenu(car, COUNT_STRUCT);
								}
								else  cout << "Value was not found";
							}
							break;
						}
						case 5: {
							system("cls");
							fflush(stdin);
							cout << "Input the Color  what you want to Search :";
							cin.getline(color, 20);;
							for (i = 0; i < COUNT_STRUCT; i++) {
								if (strcmp(car[i].color, color) == 0) {
									cout << "Found value in structure number : " << i + 1
										<< "\nPress any button to return to the menu.";
									_getch();
									mainMenu(car, COUNT_STRUCT);
								}
								else  cout << "Value was not found";
							}
							break;
						}
						case 6: {
							system("cls");
							fflush(stdin);
							cout << "Input the Engine power  what you want to Search: ";
							cin >> enginePower;
							for (i = 0; i < COUNT_STRUCT; i++) {
								if (car[i].enginePower == enginePower) {
									cout << "Found value in structure number :  " << i + 1
										<< "\nPress any button to return to the menu.";
									_getch();
									mainMenu(car, COUNT_STRUCT);
								}
								else  cout << "Value was not found";
							}
							break;
						}
						case 7: {
							system("cls");
							fflush(stdin);
							cout << "Input the Max speed  what you want to Search: ";
							cin >> speed;
							for (i = 0; i < COUNT_STRUCT; i++) {
								if (car[i].max_Speed == speed) {
									cout << "Found value in structure number :  " << i + 1
										<< "\nPress any button to return to the menu.";
									_getch();
									mainMenu(car, COUNT_STRUCT);
								}
								else  cout << "Value was not found";
							}
							break;
						}
						case 8: {
							system("cls");
							fflush(stdin);
							cout << "Input the Torque  what you want to Search: ";
							cin >> torque;
							for (i = 0; i < COUNT_STRUCT; i++) {
								if (car[i].torque == torque) {
									cout << "Found value in structure number :  " << i + 1
										<< "\nPress any button to return to the menu.";
									_getch();
									mainMenu(car, COUNT_STRUCT);
								}
								else  cout << "Value was not found";
							}
							break;
						}
						case 9: {
						mainMenu(car, COUNT_STRUCT);
						break;
						}
					}
				}
			}
		}
		cout << "Press any button to return to the menu.";
		_getch();
		mainMenu(car, COUNT_STRUCT);
}

void change(Cars * car, int COUNT_STRUCT) {
	system("cls");
	int changeable;
	if (COUNT_STRUCT == 0) cout << "Data is empty : \n";
	else {
		fflush(stdin);
		cout << "Enter the numb of struct what you would like to change: ";
		while (!(cin >> changeable) || changeable < 1 || changeable > COUNT_STRUCT) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Oops! Something went wrong! Try again:";
		}
		system("cls");
		// first of list
		int MARK = 1;
		//last of list
		int last = 9;
		showChangeMenu(MARK);

		char key;
		// 27 = ESC
		while ((key = _getch()) != 27) {
			// 72 = key down
			if (key == 72) {
				if (0 < MARK - 1)
					MARK--;
				else
					MARK = last;
				system("cls");
				showChangeMenu(MARK);
			}
			// 80 = key up
			if (key == 80) {
				if (MARK < last)
					MARK++;
				else
					MARK = 1;
				system("cls");
				showChangeMenu(MARK);
			}
			// 13 = Enter
			if (key == 13) {
				switch (MARK) {
					case 1: {
						system("cls");
						fflush(stdin);
						cout << "Change the date of struct (dd.mm.yy):";
						scanf("%d %d %d", &car[changeable - 1].release.day , &car[changeable - 1].release.month , &car[changeable - 1].release.year);
						cout << "\nChange is Succsesful";
						break;
					}
					case 2: {
						system("cls");
						cout << "Change the color: ";
						cin.ignore();
						cin.getline(car[changeable - 1].color,20);
						cout << "Change is Succsesful";
						break;
					}
					case 3: {
						system("cls");
						cin.ignore();
						cout << "Change the Mark :";
						cin.getline(car[changeable - 1].mark,20);
						printf("\nChange is Succsesful");
						break;
					}
					case 4: {
						system("cls");
						cin.ignore();
						cout << "Change the Model :";
						cin.getline(car[changeable - 1].model,20);
						printf("\nChange is Succsesful");
						break;
					}
					case 5: {
						system("cls");
						cin.ignore();
						cout << "Change the Mark :";
						cin.getline(car[changeable - 1].manufacturer_country,20);
						printf("\nChange is Succsesful");
						break;
					}
					case 6: {
						system("cls");
						fflush(stdin);
						cout << "Change the Torque :";
						cin >> car[changeable - 1].torque;
						cout << "\nChange is Succsesful";
						break;
					}
					case 7: {
						system("cls");
						fflush(stdin);
						cout << "Change the Max Speed :";
						cin >> car[changeable - 1].max_Speed;
						cout << "\nChange is Succsesful";
						break;
					}
					case 8: {
						system("cls");
						fflush(stdin);
						cout << "Change the Engine Power :";
						cin >> car[changeable - 1].enginePower;
						cout << "\nChange is Succsesful";
						break;
					}
					case 9: {							
						mainMenu(car, COUNT_STRUCT);
						break;
					}
				}
			cout << "Press any button to return to the menu.";
			_getch();
			mainMenu(car, COUNT_STRUCT);
			}
		}
	}
	cout << "Press any button to return to the menu.";
	_getch();
	mainMenu(car, COUNT_STRUCT);
}

void sort(Cars * car, int COUNT_STRUCT) {
	system("cls");
	if (COUNT_STRUCT == 0) cout << "Data is empty : \n";
	else {
		system("cls");
		// first of list
		int MARK = 1;
		//last of list
		int last = 9;
		showSortMenu(MARK);
		bool key_in;
		char key;
		// 27 = ESC
		while ((key = _getch()) != 27) {
			// 72 = key down
			if (key == 72) {
				if (0 < MARK - 1)
					MARK--;
				else
					MARK = last;
				showSortMenu(MARK);
			}
			// 80 = key up
			if (key == 80) {
				if (MARK < last)
					MARK++;
				else
					MARK = 1;
				showSortMenu(MARK);
			}
			// 13 = Enter
			if (key == 13) {
				switch (MARK) {
				case 1: {
					system("cls");
					cout << "1 - In\n0 - Dec\nEnter the direction of sort : ";
					while (!(cin >> key_in)) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Oops! Something went wrong! Try again:";
					}
					sort_Date(car, COUNT_STRUCT, key_in); 
					cout << "Succsessfull!";
					cout << "Press any button to return to the menu.";
					_getch();
					mainMenu(car, COUNT_STRUCT);
					break;
				}
				case 2: {
					system("cls");
					cout << "1 - In\n0-Dec\nEnter the direction of sort : ";
						while (!(cin >> key_in)) {
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							cout << "Oops! Something went wrong! Try again:";
						}
						(key_in == 1) ? (qsort(car, COUNT_STRUCT, sizeof(car[0]),sort_Mark_In)) : (qsort(car, COUNT_STRUCT, sizeof(car[0]),sort_Mark_Dec));
						
						cout << "Succsessfull!";
						cout << "Press any button to return to the menu.";
						_getch();
						mainMenu(car, COUNT_STRUCT);
					break;
				}
				case 3: {
					system("cls");
					cout << "1 - In\n0-Dec\nEnter the direction of sort : ";
					while (!(cin >> key_in)) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Oops! Something went wrong! Try again:";
					}
					(key_in == 1) ? (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Model_In)) : (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Model_Dec));

					cout << "Succsessfull!";
					cout << "Press any button to return to the menu.";
					_getch();
					mainMenu(car, COUNT_STRUCT);
					break;
				}
				case 4: {
					system("cls");
					cout << "1 - In\n0-Dec\nEnter the direction of sort : ";
					while (!(cin >> key_in)) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Oops! Something went wrong! Try again:";
					}
					(key_in == 1) ? (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Country_In)) : (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Country_Dec));

					cout << "Succsessfull!";
					cout << "Press any button to return to the menu.";
					_getch();
					mainMenu(car, COUNT_STRUCT);
					break;
				}
				case 5: {
					system("cls");
					cout << "1 - In\n0-Dec\nEnter the direction of sort : ";
					while (!(cin >> key_in)) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Oops! Something went wrong! Try again:";
					}
					(key_in == 1) ? (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Color_In)) : (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Color_Dec));

					cout << "Succsessfull!";
					cout << "Press any button to return to the menu.";
					_getch();
					mainMenu(car, COUNT_STRUCT);
					break;
				}
				case 6: {
					system("cls");
					cout << "1 - In\n0-Dec\nEnter the direction of sort : ";
					while (!(cin >> key_in)) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Oops! Something went wrong! Try again:";
					}
					(key_in == 1) ? (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_EnginePower_In)) : (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_EnginePower_Dec));

					cout << "Succsessfull!";
					cout << "Press any button to return to the menu.";
					_getch();
					mainMenu(car, COUNT_STRUCT);
					break;
				}
				case 7: {
					system("cls");
					cout << "1 - In\n0-Dec\nEnter the direction of sort : ";
					while (!(cin >> key_in)) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Oops! Something went wrong! Try again:";
					}
					(key_in == 1) ? (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Speed_In)) : (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Speed_Dec));

					cout << "Succsessfull!";
					cout << "Press any button to return to the menu.";
					_getch();
					mainMenu(car, COUNT_STRUCT);
					break;
				}
				case 8: {
					system("cls");
					cout << "1 - In\n0-Dec\nEnter the direction of sort : ";
					while (!(cin >> key_in)) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Oops! Something went wrong! Try again:";
					}
					(key_in == 1) ? (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Torque_In)) : (qsort(car, COUNT_STRUCT, sizeof(car[0]), sort_Torque_Dec));

					cout << "Succsessfull!";
					cout << "\nPress any button to return to the menu.";
					_getch();
					mainMenu(car, COUNT_STRUCT);
					
					break;
				}
				case 9: {
					mainMenu(car, COUNT_STRUCT);
					break;
				}
				}
			}
		}
	}
}

void filter(Cars* car, int COUNT_STRUCT) {
	system("cls");
	int enumerator = 0;
	if (COUNT_STRUCT == 0 || !car) cout << "DATA IS OUT";
	else {
		for (int i = 0; i < COUNT_STRUCT; i++) {
			if ( strcmp(car[i].mark, "audi") == 0  && car[i].release.year > 1999) {
				enumerator = 1;
			}
		}
		if (enumerator == 1) {
		cout <<" I'm a big fan of audi released after 2000. Therefore, I decided to make just such a filter\n"
			<< "  ----------------------------------------------------------------------------------------------------------------------------------------- \n"
			<< setw(10) << "№"
			<< setw(15) << "Mark"
			<< setw(15) << "Model"
			<< setw(15) << "Country"
			<< setw(15) << "Color"
			<< setw(15) << "Date"
			<< setw(20) << "Max speed"
			<< setw(15) << "Engine power"
			<< setw(15) << "torque" << endl;
		cout << "  ----------------------------------------------------------------------------------------------------------------------------------------- \n";
			for (int i = 0; i < COUNT_STRUCT; i++) {
				if ( strcmp(car[i].mark ,"audi") == 0 && car[i].release.year > 1999) {
					cout << setw(10) << i + 1
						<< setw(15) << car[i].mark
						<< setw(15) << car[i].model
						<< setw(15) << car[i].manufacturer_country
						<< setw(15) << car[i].color
						<< setw(10) << car[i].release.day << "." << car[i].release.month << "." << car[i].release.year
						<< setw(15) << car[i].max_Speed
						<< setw(10) << car[i].enginePower
						<< setw(20) << car[i].torque << endl;
					cout << "  ----------------------------------------------------------------------------------------------------------------------------------------- \n";
				}
			}
		} else cout << "No data matching filtering";
	}
	cout << "\nPress any key to return in main Menu...";
	_getch();
	mainMenu(car, COUNT_STRUCT);
}
