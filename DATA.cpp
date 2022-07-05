#include "DATA.h"

#include "menu.h"

#include "struct.h"

#include <iostream>
#include <windows.h>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;

void inputData(Cars *car,int COUNT_STRUCT) {
	system("cls");
	char key;
//	while ( (key = getch()) != 27) {
		if( COUNT_STRUCT != 0){
			car = (Cars *)realloc(car,(COUNT_STRUCT) * sizeof(Cars));
			for (int i = COUNT_STRUCT-1; i < COUNT_STRUCT; i++) {
				cout << "Enter the information about the  " << i + 1 << " Car :" << endl;
				//input month
				cout << "Enter month of car release :";
				while (!(cin >> car[i].release.month) || car[i].release.month <= 0 || car[i].release.month > 12) {
					cout << "\nTry again. Input month of car release  : ";
					cin.clear();
					cin.sync();
				}
				//input day
				cout << "Enter day of car release :";
				while (!(cin >> car[i].release.day) || car[i].release.day <= 0 || car[i].release.day > 31) {
					cin.clear();
					cin.sync();
					cout << "\nTry again. Input day of car release :";
				}
				//input year
				cout << "Enter year of car release day of car release  :";
				while (!(cin >> car[i].release.year) || car[i].release.year <= 1787 || car[i].release.year > 2019) {
					cin.clear();
					cin.sync();
					cout << "\nTry again :";
				}
				//input the MARK
				fflush(stdin);
				cout << "Enter the MARK of the auto : ";
				gets(car[i].mark);
				//input the model 
				fflush(stdin);
				cout << "Enter the model of  the auto:";
				gets(car[i].model);
				//input the color
				fflush(stdin);
				cout << "Enter the color of the auto:";
				gets(car[i].color);
				//input the country
				cout << "Enter the manufacture country of the auto :";
				gets(car[i].manufacturer_country);
				//input the max speed
				cout << "Enter the max speed of car : ";
				while (!(cin >> car[i].max_Speed) || car[i].max_Speed <= 0 || car[i].max_Speed >= 1270) {
					cout << "\nTry Again !! Input corectly the max speed of auto : ";
					cin.clear();
					cin.sync();
				}
				//input the torque
				cout << "Enter the torque of auto :";
				while (!(cin >> car[i].torque) || car[i].torque <= 0 || car[i].torque >= 2000) {
					cin.clear();
					cin.sync();
					cout << "\nTry again to input corectly  the torque of auto : ";
				}
				//input the engine POwer
				cout << "Enter the  Engine Power of the auto :";
				while (!(cin >> car[i].enginePower) || car[i].enginePower <= 0 || car[i].enginePower >= 2000) {
					cin.clear();
					cin.sync();
					cout << "Try again to input the  Engine Power of the auto : ";
				}
	
				system("cls");
				cout << "DO you want  to input more structs ?\n 1 - Yes \n0 - No :";
				bool flag;
				while (!(cin >> flag)) {
					cout << "Try Again : ";
					cin.clear();
					cin.sync();
				}
				
				if (flag == 1) 	{
					COUNT_STRUCT++;
					car = (Cars *)realloc(car, (COUNT_STRUCT) * sizeof(Cars));
				}
				else mainMenu(car,COUNT_STRUCT);
			}
		}
		else { 
				COUNT_STRUCT = 1;
					car = (Cars *)realloc(car, (COUNT_STRUCT) * sizeof(Cars));
					for (int i = 0 ; i < COUNT_STRUCT; i++) {
						cout << "Enter the information about the  " << i + 1 << " Car :" << endl;
						//input month
						cout << "Enter month of car release :";
						while (!(cin >> car[i].release.month) || car[i].release.month <= 0 || car[i].release.month > 12) {
							cout << "\nTry again. Input month of car release  : ";
							cin.clear();
							cin.sync();
						}
						//input day
						cout << "Enter day of car release :";
						while (!(cin >> car[i].release.day) || car[i].release.day <= 0 || car[i].release.day > 31) {
							cin.clear();
							cin.sync();
							cout << "\nTry again. Input day of car release :";
						}
						//input year
						cout << "Enter year of car release day of car release  :";
						while (!(cin >> car[i].release.year) || car[i].release.year <= 1787 || car[i].release.year > 2019) {
							cin.clear();
							cin.sync();
							cout << "\nTry again :";
						}
						//input the MARK
						fflush(stdin);
						cout << "Enter the MARK of the auto : ";
						gets(car[i].mark);
						//input the model 
						fflush(stdin);
						cout << "Enter the model of  the auto:";
						gets(car[i].model);
						//input the color
						fflush(stdin);
						cout << "Enter the color of the auto:";
						gets(car[i].color);
						//input the country
						cout << "Enter the manufacture country of the auto :";
						gets(car[i].manufacturer_country);
						//input the max speed
						cout << "Enter the max speed of car : ";
						while (!(cin >> car[i].max_Speed) || car[i].max_Speed <= 0 || car[i].max_Speed >= 1270) {
							cout << "\nTry Again !! Input corectly the max speed of auto : ";
							cin.clear();
							cin.sync();
						}
						//input the torque
						cout << "Enter the torque of auto :";
						while (!(cin >> car[i].torque) || car[i].torque <= 0 || car[i].torque >= 2000) {
							cin.clear();
							cin.sync();
							cout << "\nTry again to input corectly  the torque of auto : ";
						}
						//input the engine POwer
						cout << "Enter the  Engine Power of the auto :";
						while (!(cin >> car[i].enginePower) || car[i].enginePower <= 0 || car[i].enginePower >= 2000) {
							cin.clear();
							cin.sync();
							cout << "Try again to input the  Engine Power of the auto : ";
						}
			
						system("cls");
						cout << "DO you want  to input more structs ?\n 1 - Yes \n0 - No :";
						bool flag;
						while (!(cin >> flag)) {
							cout << "Try Again : ";
							cin.clear();
							cin.sync();
						}
					
						if (flag == 1) {
							COUNT_STRUCT++;
							car = (Cars *)realloc(car, (COUNT_STRUCT) * sizeof(Cars));
						}
						else 	mainMenu(car,COUNT_STRUCT);
					}
				}
}

void outputData(Cars *car,int COUNT_STRUCT) {
	
	system("cls");
	if (COUNT_STRUCT  == 0|| !car) cout << "DATA IS OUT";
	else {
		cout << "  ----------------------------------------------------------------------------------------------------------------------------------------- \n";
		cout << setw(10) << "¹"
			<< setw(15) << "Mark"
			<< setw(15) << "Model"
			<< setw(15) << "Country"
			<< setw(15) << "Color"
			<< setw(15) << "Date"
			<< setw(20) << "Max speed"
			<< setw(15) << "Engine power"
			<< setw(15) << "torque" << endl;


		for (int i = 0; i < COUNT_STRUCT ; i++) {
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
	cout<<"\nPress any key to return in main Menu...";
	getch();
	mainMenu(car,COUNT_STRUCT);
}

void global_cleaner(Cars *car,int COUNT_STRUCT){
	car = NULL;
	COUNT_STRUCT = 0;
}





