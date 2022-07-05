#include "menu.h"
#include "DATA.h"
#include "fData.h"

#include <iostream>
#include <windows.h>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <fstream>

#include "struct.h"

using namespace std;

void new_DB(Cars *car,int COUNT_STRUCT) {
  	bool next = 1;
  	while( next == true ){
  		system("cls");
  		char FNAME[30];
	   	cout<<"Enter file name :";
		fflush(stdin);
		gets(FNAME);
		
		ofstream fout;
		fout.open(FNAME);
		if(fout.is_open()) cout<<"File has been opened";
		else cout<<"File hasn't been opened";
		cout<<"\nPress...\n1-Countinue \n0-Exit in main menu\n";
		while(!(cin >> next)){
			cin.clear();
			cin.sync();
			cout<<"\nTry again : ";
		}
	}
	mainMenu(car,COUNT_STRUCT);
}

void remove_DB(Cars *car,int COUNT_STRUCT) { 
	bool next = 1;
	char FNAME[30];
  	while( next == true ){
  		system("cls");
	   	cout<<"Enter name what you want to delete :";
		fflush(stdin);
		gets(FNAME);
		
		if(remove(FNAME) != 0 ) cout<<"File hasn't been deleted";
		else cout<<"File has been deleted";
		cout<<"\nPress...\n1-Countinue \n0-Exit in main menu\n";
		while(!(cin >> next)){
			cin.clear();
			cin.sync();
			cout<<"\nTry again : ";
		}
	}
	mainMenu(car,COUNT_STRUCT);
}

void clear(Cars *car,int COUNT_STRUCT) {
	
	system("cls");
	char FNAME[30];
	if( COUNT_STRUCT == 0) cout<<"DATA IS OUT";
	else {
		free(car);
		car = NULL;
		COUNT_STRUCT = 0;
		cout<<"Cleanning was succsessfull";
	}
	
	cout<<"\nPress any key to return in main Menu...";
	getch();
	mainMenu(car,COUNT_STRUCT);
}

void save_DB(Cars *car,int COUNT_STRUCT) {
	system("cls");
	char FNAME[30];
	if (COUNT_STRUCT == 0) cout << "DATA IS OUT";
	else {
	   	cout<<"\nEnter outfile name :";
		fflush(stdin);
		gets(FNAME);
		ofstream fout;
		fout.open(FNAME);
		if(fout.is_open()){
			cout<<"File Open";
				for (int i = 0; i < COUNT_STRUCT ; i++) {
					fout<< i + 1<<"|"
						<< car[i].mark<<"|"
						<< car[i].model<<"|"
						<< car[i].manufacturer_country<<"|"
						<< car[i].color<<"|"
						<< car[i].release.day << "." << car[i].release.month << "." << car[i].release.year<<"|"
						<< car[i].max_Speed<<"|"
						<< car[i].enginePower<<"|"
						<< car[i].torque <<"|"<< endl;
				}
				cout<<"\nSuccsess!";
	        	fout.close();  
		}
	
	else cout<<"\nFILE HAS NOT  OPENED";
	}
		cout<<"\nPress any key to return in main Menu...";
		getch();
		mainMenu(car,COUNT_STRUCT);

}

void load_DB(Cars *car,int COUNT_STRUCT) {
	system("cls");
	char str[100];
	int index = 0; 
	int lineCount = 0;
	int iter_index;
	char FNAME[30];
   	cout<<"Enter out name :";
	fflush(stdin);
	gets(FNAME);
	ifstream fin;
	fin.open(FNAME);
	int while_is_right = 0;
	if(fin.is_open()){
		
		while (!fin.eof()) {
			
			while(fin.getline(str,100)) {
				
				while_is_right = 1 ;
				lineCount++;
				iter_index = 0; 
				COUNT_STRUCT = lineCount;
				car = (Cars *)realloc(car,(COUNT_STRUCT) * sizeof(Cars));
				
				char *temp = strtok(str,"|.");
				while(temp != NULL) {
					
					//cout<<"iter_index = "<<iter_index<<"index= "<<index<<"COUNT_STRUCT"<<COUNT_STRUCT<<endl;
					switch (iter_index) {
						case 1: {
							strcpy(car[index].mark, temp);
							if(strlen(car[index].mark) > 20){
								cout<<"Error! In the "<<iter_index<<" column and  "<< index+1<<"row are incorrect data"<<endl;
								global_cleaner(car,COUNT_STRUCT);
							}
							break;
						}
						case 2: {
							strcpy(car[index].model, temp);
							if(strlen(car[index].model) > 20){
								cout<<"Error! In the "<<iter_index<<" column and  "<< index+1<<"row are incorrect data"<<endl;
								global_cleaner(car,COUNT_STRUCT);
							}
							break;
						}
						case 3: {
							strcpy(car[index].manufacturer_country, temp);
							if(strlen(car[index].manufacturer_country) > 20){
								cout<<"Error! In the "<<iter_index<<" column and  "<< index+1<<"row are incorrect data"<<endl;
								global_cleaner(car,COUNT_STRUCT);
							}
							break;
						}
						case 4: {
							strcpy(car[index].color,temp);
							if(strlen(car[index].color) > 20){
								cout<<"Error! In the "<<iter_index<<" column and  "<< index+1<<"row are incorrect data"<<endl;
								global_cleaner(car,COUNT_STRUCT);
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
							if(!car[index].max_Speed || car[index].max_Speed <0 || car[index].max_Speed > 500){
								cout<<"Error! In the "<<iter_index<<" column and  "<< index+1<<"row are incorrect data"<<endl;
								global_cleaner(car,COUNT_STRUCT);
							}
							break;
						}
						case 9: {
							car[index].enginePower = atoi(temp);
							if(!car[index].enginePower || car[index].enginePower < 0 || car[index].enginePower > 1500) {
								cout<<"Error! In the "<<iter_index<<" column and  "<< index+1<<"row are incorrect data"<<endl;
								global_cleaner(car,COUNT_STRUCT);
							}
							break;
						}
						case 10: {
							car[index].torque = atoi(temp);
							if(!car[index].torque || car[index].torque < 0 || car[index].torque > 1500) {
								cout<<"Error! In the "<<iter_index<<" column and  "<< index+1<<"row are incorrect data"<<endl;
								global_cleaner(car,COUNT_STRUCT);
							}
							break;
						}
					}
					
					temp = strtok(NULL,"|.");
					iter_index++;
				}				
				index++;
			}
				
		}
		
		fin.close();
		cout<< ((while_is_right == 1)? "Succsess!\nPress any key to return in main Menu..." :"\nFile is empty\nPress any key to return in main Menu...");
		getch();
		mainMenu(car,COUNT_STRUCT);
	}
	else cout<<"\nFILE HAS NOT  OPENED";
}

	
	
	



