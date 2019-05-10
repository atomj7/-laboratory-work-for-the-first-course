#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>
#include <math.h>

void showMainMenu(int mark);
void mainMenu();
void task1();
void task2();
void task3();
void task4();
void trapeze(int a, int b, float angle);

int main () {   
	setlocale(LC_ALL," ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color 5E");
	mainMenu();
   return 0;
}

void showMainMenu(int mark){
	system("cls");
	printf("peremeshenie po menu   ^  and v \nChoise somthing - ENTER \nBack to main Menu ESC\n");
	printf("Choise what info do you need : \n");
	printf("%s1 - 1 Task1\n", (mark == 1) ? "->" : " ");
	printf("%s2 - 2 Task2\n", (mark == 2) ? "->" : " ");
	printf("%s3 - 3 Task3\n", (mark == 3) ? "->" : " ");
	printf("%s4 - 4 Task4\n", (mark == 4) ? "->" : " ");
	printf("%s5 - 5 ESC\n", (mark == 5) ? "->" : " ");
}

void mainMenu() {
	
	//first of list
	int mark = 1;
	//last of list
	int last = 5;
	showMainMenu(mark);
	
	char key;
	// 27 = ESC
	while ((key = _getch()) != 27) {
		// 72 = key down
		if (key == 72) {
			if (0 < mark - 1)
				mark--;
			else
				mark = last;
			showMainMenu(mark);
		}
		// 80 = key up
		if (key == 80) {
			if (mark < last)
				mark++;
			else
				mark = 1;
			showMainMenu(mark);
		}
		// 13 = Enter
		if (key == 13) {
			showMainMenu(mark);
			switch (mark) {
				case 1:
					task1();
					break;
				case 2:
					task2();
					break;
				case 3:
					task3();
					break;
				case 4:
					task4();
					break;
				case 5:
					exit(1);
					break;
			}
		}
	}
}

void task1() {
	system("cls");
	int key;
	double x;
	printf("Enter the x :");
	while(!(scanf("%f",&x)) ){
		fflush(stdin);
		printf("Oops! Something went wrong !Try again :");
	}
	printf("Enter the  numb :");
	while(!(scanf("%d",&key)) || key >4 || key < 0){
		fflush(stdin);
		printf("Oops! Something went wrong !Try again :");
	}
	switch(key){
		case 1:{
			printf("%f",pow((abs(pow(sin(x),2)+pow(cos(x),3))),1.5));
			break;
		}
		case 2:{
			printf("%f",(pow((x)/(x*x-5),2))/((log(abs(x)))/(log(2))));
			break;
		}
		case 3:{
			printf("%f",pow(10,(5/x))*pow(2,(-x/2)));
			break;
		}
		case 4:{
			printf("%f",pow(abs((1+3*x)/(pow(x,3))),0.5));
			break;
		}
		
	}
	printf("\nPress any key to return in main Menu...");
	_getch();
	mainMenu();
}

void task2() {
	system("cls");
	int i,j = 0, lost = 0; 
	int S;
	printf("Enter the S :");
	while(!(scanf("%d",&S)) || S < 0 ){
		fflush(stdin);
		printf("Oops! Something went wrong !Try again :");
	}
	float mass[S],newMass[S]; 
	
	printf(" Vvedite massiv iz S elementov: \n");
	for (i = 0; i < S ; i++)  { 
	//	printf(" Vvedite element[%d]: ", i);
		scanf("%f", &mass[i]); 
	}
	for(int i = 0; i < S; i++)
		if(mass[i] <0 ) lost++; //счетчик отрицательных
		
 	if(lost != S){
 		for(int i = 0; i < S; i++) {
 			if(mass[i] >= 0 )  newMass[j++] = mass[i];
 		//	printf("\nnewMass[%d] = %f ",i,newMass[j]);
		 }
		 S = S -lost;
		 for(int i = 0; i < S; i++) {
		 	mass[i] = newMass[i];
		 }
	printf("Vash massiv: ");
	for(i = 0;i< S;i++) { 
		printf(" %f",mass[i]); 
	}
	} else {
		printf("\n MASSIV PUSTOI");
	}
	printf("\nPress any key to return in main Menu...");
	_getch();
	mainMenu(); 
}

void task3() {
	system("cls");

    char string[100];
    setlocale(LC_ALL, "rus");
   printf( "enter string :");
    gets(string);
 
    int index = 0; 
    int sum = 0;
 
    while (string[index] != '\0') 
    {
        if (string[index] != ' ') {
            sum += atoi((string + index)); 
            while (string[index] != ' ')
            index++; 
        }
        else 
            index++;     
    }
            
    printf("%d",sum); 
    
	printf("\nPress any key to return in main Menu...");
	_getch();
	mainMenu(); 
}

void task4() {
	system("cls");
	int N;
	int base1, base2;
	float nook;
	printf("ENTER THE COUNT :");
	while(!(scanf("%d",&N)) || N < 0 ){
		fflush(stdin);
		printf("Oops! Something went wrong !Try again :");
	}
	
	for(int i = 0; i < N; i++){
		printf("BOL'shoe osnovanie :");
		while(!(scanf("%d",&base1)) || base1 < 0 ){
			fflush(stdin);
			printf("Oops! Something went wrong !Try again :");
		}
		printf("Malen'koe osnovanie :");
		while(!(scanf("%d",&base2)) || base2 < 0 ){
			fflush(stdin);
			printf("Oops! Something went wrong !Try again :");
		}
		printf("Ugol(В РАДИАНАХ 30 = 0.524 60 = 1.0472) :");
		while(!(scanf("%f",&nook)) || nook < 0 ){
			fflush(stdin);
			printf("Oops! Something went wrong !Try again :");
		}
		trapeze(base1,base2,nook);
	}
	
    
	printf("\nPress any key to return in main Menu...");
	_getch();
	mainMenu(); 
}

void trapeze(int a, int b ,float angle){
	printf("\nS of Trapeze = %f",((a+b)/2) *(tan(angle)*(a - b)/2));
	printf("\nP of Trapeze = %f\n",a + b +(a - b/(2*cos(angle))) );
}



