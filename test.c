#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>


struct Date {
	int month;
	int day;
	int year;
};
 
struct Topic {
	int adress1;
	int adress2;
	char text[51];
	struct 	Date ddmmyy;
	
};

int speed, move, folder;

void inData(struct Topic * message,int COUNT_STRUCT);
void outData(struct Topic * message,int COUNT_STRUCT);
void mainMenu(struct Topic * message,int COUNT_STRUCT);
void sort(struct Topic * message,int COUNT_STRUCT);
void showMainMenu(int mark);

int main (int argc, char **argv) {   
	setlocale(LC_ALL," ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color 5E");
	int k = 0 , skorost, moves,folders;
	struct Topic *p;
	p = (struct Topic*)malloc(sizeof(struct Topic));
	if(argv != NULL) {
	for (int i = 0; i < argc; i++) {
        if(strcmp(argv[i],"-slow") == 0){
        	speed = 0;
		}else if (strcmp(argv[i],"-fast") == 0) {
			speed = 1;
		} 
		if(strcmp(argv[i],"-inc") == 0){
        	move = 0;
		}else if (strcmp(argv[i],"-dec") == 0) {
			move = 1;
		} 
		if(strcmp(argv[i],"-1") == 0){
        	folder = 1;
		}else if (strcmp(argv[i],"-2") == 0) {
			folder = 2;
		} 
		if(strcmp(argv[i],"-3") == 0){
        	folder = 3;
		}else if (strcmp(argv[i],"-4") == 0) {
			folder = 4;
		} 	
	}
}
	mainMenu(p,k);
   return 0;
}

void showMainMenu(int mark){
	system("cls");
	printf("peremeshenie po menu   ^  and v \nChoise somthing - ENTER \nBack to main Menu ESC\n");
	printf("Choise what info do you need : \n");
	printf("%s1 - 1 InputData\n", (mark == 1) ? "->" : " ");
	printf("%s2 - 2 Sort Data\n", (mark == 2) ? "->" : " ");
	printf("%s3 - 3 Output Data \n", (mark == 3) ? "->" : " ");
	printf("%s4 - 4 Esc\n", (mark == 4) ? "->" : " ");
}

void mainMenu(struct Topic * message,int COUNT_STRUCT) {
	
	//first of list
	int mark = 1;
	//last of list
	int last = 4;
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
					inData(message, COUNT_STRUCT);
					break;
				case 2:
					sort(message, COUNT_STRUCT);
					break;
				case 3:
					outData(message, COUNT_STRUCT);
					break;
				case 4:
					exit(1);
					break;
			}
		}
	}
}

void inData(struct Topic * message,int COUNT_STRUCT) {
	system("cls");
	printf("Input the count of tickets :  ");
		while(!(scanf("%d",&COUNT_STRUCT))|| COUNT_STRUCT < 0){
			fflush(stdin);
			printf("Try again to Input the count of tickets :  ");
		}
		
		message = calloc(COUNT_STRUCT,sizeof(struct Topic));
		
		for( int i = 0; i < COUNT_STRUCT; i++) {
			printf("Input info about the  [%d] Ticket: ",i+1);
			char str[200];
			int index = 0;
			fflush(stdin);
			 char *newstr = fgets(str, 200, stdin);
			if (  newstr == NULL) {
	                /* Произошла ошибка или был прочитан EOF */
	        }
	        else {
		        /* Удаляем символ конца строки */
		        size_t last = strlen(newstr) - 1;
		        if (newstr[last] == '\n')
		            newstr[last] = '\0';
				
		       	char *temp = strtok(newstr, ".-\"\"");
					while (temp != NULL) {
						printf("\n temp = %s  index = %d",temp,index);
						switch (index) {
							case 0: {
								message[i].adress1 = atoi(temp);
								if (message[i].adress1 > 999 || message[i].adress1 < 100) {
									printf(" 1  adress ne corectnii ");
									printf("\nPress any key to return in main Menu...");
									_getch();
									mainMenu(message, COUNT_STRUCT);
								}
								break;
							}
							case 1: {
								message[i].adress2 = atoi(temp);
								if (message[i].adress2 > 999 || message[i].adress1 < 100) {
									printf(" 2  adress ne corectnii ");
									printf("\nPress any key to return in main Menu...");
									_getch();
									mainMenu(message, COUNT_STRUCT);
								}
								break;
							}
							case 2: {
								strcpy(message[i].text, temp);
								if (strlen(message[i].text) > 50) {
									printf(" text ne corectnii ");
									printf("\nPress any key to return in main Menu...");
									_getch();
									mainMenu(message, COUNT_STRUCT);
								}
								break;
							}
							case 3: {
								message[i].ddmmyy.day = atoi(temp);
								if(message[i].ddmmyy.day > 31 || message[i].ddmmyy.day < 0) {
									printf(" day ne corectnii ");
									printf("\nPress any key to return in main Menu...");
									_getch();
									mainMenu(message, COUNT_STRUCT);
								}
								break;
							}
							case 4: {
								message[i].ddmmyy.month = atoi(temp);
								if(message[i].ddmmyy.month > 12||message[i].ddmmyy.month < 0 ) {
									printf(" month ne corectnii ");
									printf("\nPress any key to return in main Menu...");
									_getch();
									mainMenu(message, COUNT_STRUCT);
								}
								break;
							}
							case 5: {
								message[i].ddmmyy.year = atoi(temp);
								if(message[i].ddmmyy.year > 2019 || message[i].ddmmyy.year < 0) {
									printf(" year ne corectnii ");
									printf("\nPress any key to return in main Menu...");
									_getch();
									mainMenu(message, COUNT_STRUCT);
								}
								break;
							}
						}
						temp = strtok(NULL,".-\"\"");
						index ++ ;
					}
				}
				printf("\n");
			}
			printf("\nPress any key to return in main Menu...");
			_getch();
			mainMenu(message, COUNT_STRUCT);
}

void outData(struct Topic *message, int COUNT_STRUCT){
system("cls");
	int i;
//	while( getch() != 27 ) {
		if (COUNT_STRUCT == 0)
	      printf("\nData is empty : \n");
	    else{
			printf("---------------------------------------------------------------------------------------------------------");
			printf("\n|Session Number:|The adrees  1:\t|The adress2 :\t|Date:\t\t|Text:\t     |");
			printf("\n---------------------------------------------------------------------------------------------------------");
			for( i = 0; i < COUNT_STRUCT; i++){
				printf("\n|№%d\t\t|%d\t\t|%d\t\t|%d.%d.%d\t|\"%s\"|",
				i+1, message[i].adress1, message[i].adress2, message[i].ddmmyy.day, message[i].ddmmyy.month,message[i].ddmmyy.year,message[i].text);
				printf("\n---------------------------------------------------------------------------------------------------------");
				}		
		}
//	}	
	printf("\nPress any key to return in main Menu...");
	_getch();
	mainMenu(message, COUNT_STRUCT);
}	

void sort(struct Topic * message,int COUNT_STRUCT){
	printf("\nspeed  = %d , move = %d  folder = %d", speed, move, folder);
	system("cls");
	
	switch(folder){
		case 1:{
			if(speed == 1) { // insert sort
				if (move == 0){
					//insert sort +inc
					int newElement, location;
				    for (int i = 1; i < COUNT_STRUCT; i++) {
				        newElement = message[i].adress1;
				        location = i - 1;
				        while(location >= 0 && message[location].adress1 > newElement) {
				            message[location+1] = message[location];
				            location = location - 1;
				        }
				        message[location+1].adress1 = newElement;
				    }	
				} else if(move == 1) {	
					//insert sort +dec
					int newElement, location;
				    for (int i = 1; i < COUNT_STRUCT; i++) {
				        newElement = message[i].adress1;
				        location = i - 1;
				        while(location >= 0 && message[location].adress1 < newElement) {
				            message[location+1] = message[location];
				            location = location - 1;
				        }
				        message[location+1].adress1 = newElement;
				    }	
				}
					
			} else { //shell
				if (move == 0){
					
					int i, j, step;
				    int tmp;
				    for (step = COUNT_STRUCT / 2; step > 0; step /= 2)
				        for (i = step; i < COUNT_STRUCT; i++) {
				            tmp = message[i].adress1;
				            for (j = i; j >= step; j -= step) {
				                if (tmp < message[j - step].adress1)
				                    message[j] = message[j - step];
				                else
				                    break;
				            }
				            message[j].adress1 = tmp;
				    	}		
				} else {
					
					int i, j, step;
				    int tmp;
				    for (step = COUNT_STRUCT / 2; step > 0; step /= 2)
				        for (i = step; i < COUNT_STRUCT; i++) {
				            tmp = message[i].adress1;
				            for (j = i; j >= step; j -= step) {
				                if (tmp > message[j - step].adress1)
				                    message[j] = message[j - step];
				                else
				                    break;
				            }
				            message[j].adress1 = tmp;
				    	}
					
				}
			}
			break;
		}
		case 2:{
			if(speed == 1) {
				if (move == 0){
				//insert sort +inc
					int newElement, location;
				    for (int i = 1; i < COUNT_STRUCT; i++) {
				        newElement = message[i].adress2;
				        location = i - 1;
				        while(location >= 0 && message[location].adress2 > newElement) {
				            message[location+1] = message[location];
				            location = location - 1;
				        }
				        message[location+1].adress2 = newElement;
				    }	
				} else if(move == 1) {	
					//insert sort +dec
					int newElement, location;
				    for (int i = 1; i < COUNT_STRUCT; i++) {
				        newElement = message[i].adress2;
				        location = i - 1;
				        while(location >= 0 && message[location].adress2 < newElement) {
				            message[location+1] = message[location];
				            location = location - 1;
				        }
				        message[location+1].adress2 = newElement;
				    }	
				}	
			} else {
				if (move == 0){
					
					int i, j, step;
				    int tmp;
				    for (step = COUNT_STRUCT / 2; step > 0; step /= 2)
				        for (i = step; i < COUNT_STRUCT; i++) {
				            tmp = message[i].adress2;
				            for (j = i; j >= step; j -= step) {
				                if (tmp < message[j - step].adress2)
				                    message[j] = message[j - step];
				                else
				                    break;
				            }
				            message[j].adress2 = tmp;
				    	}		
				} else {
					
					int i, j, step;
				    int tmp;
				    for (step = COUNT_STRUCT / 2; step > 0; step /= 2)
				        for (i = step; i < COUNT_STRUCT; i++) {
				            tmp = message[i].adress2;
				            for (j = i; j >= step; j -= step) {
				                if (tmp > message[j - step].adress2)
				                    message[j] = message[j - step];
				                else
				                    break;
				            }
				            message[j].adress2 = tmp;
				    	}
					
				}
			}
			break;
		}
		case 3:{
			if(speed == 1) {
				if (move == 0){
				//insert sort +inc
					int newElement, location;
				    for (int i = 1; i < COUNT_STRUCT; i++) {
				        newElement = message[i].ddmmyy.year;
				        location = i - 1;
				        while(location >= 0 && message[location].ddmmyy.year > newElement) {
				            message[location+1] = message[location];
				            location = location - 1;
				        }
				        message[location+1].ddmmyy.year = newElement;
				    }	
				} else if(move == 1) {	
					//insert sort +dec
					int newElement, location;
				    for (int i = 1; i < COUNT_STRUCT; i++) {
				        newElement = message[i].ddmmyy.year;
				        location = i - 1;
				        while(location >= 0 && message[location].ddmmyy.year < newElement) {
				            message[location+1] = message[location];
				            location = location - 1;
				        }
				        message[location+1].ddmmyy.year = newElement;
				    }	
				}	
				
			} else {
				if (move == 0){
					
					int i, j, step;
				    int tmp;
				    for (step = COUNT_STRUCT / 2; step > 0; step /= 2)
				        for (i = step; i < COUNT_STRUCT; i++) {
				            tmp = message[i].ddmmyy.year;
				            for (j = i; j >= step; j -= step) {
				                if (tmp < message[j - step].ddmmyy.year)
				                    message[j] = message[j - step];
				                else
				                    break;
				            }
				            message[j].ddmmyy.year = tmp;
				    	}		
				} else {
					
					int i, j, step;
				    int tmp;
				    for (step = COUNT_STRUCT / 2; step > 0; step /= 2)
				        for (i = step; i < COUNT_STRUCT; i++) {
				            tmp = message[i].ddmmyy.year;
				            for (j = i; j >= step; j -= step) {
				                if (tmp > message[j - step].ddmmyy.year)
				                    message[j] = message[j - step];
				                else
				                    break;
				            }
				            message[j].ddmmyy.year = tmp;
				    	}
					
				}
			}
			break;
		}
		case 4:{
			if(speed == 1) {
				if (move == 0){
				//insert sort +inc
					int  location;
					char newElement[51];
				    for (int i = 1; i < COUNT_STRUCT; i++) {
				         strcpy(newElement,message[i].text);
				        location = i - 1;
				        while(location >= 0 && strcmp(newElement,message[i].text) > 0 ) {
				            message[location+1] = message[location];
				            location = location - 1;
				        }
				        strcpy(message[i].text,newElement);
				    }	
				} else if(move == 1) {	
					//insert sort +dec
					int newElement, location;
				    for (int i = 1; i < COUNT_STRUCT; i++) {
				        strcpy(newElement,message[i].text);
				        location = i - 1;
				        while(location >= 0 && strcmp(newElement,message[i].text) < 0) {
				            message[location+1] = message[location];
				            location = location - 1;
				        }
				        strcpy(message[i].text,newElement);
				    }	
				} {
				if (move == 0){
					
					int i, j, step;
				    char newElement[51];
				    for (step = COUNT_STRUCT / 2; step > 0; step /= 2)
				        for (i = step; i < COUNT_STRUCT; i++) {
				            strcpy(newElement,message[i].text);
				            for (j = i; j >= step; j -= step) {
				                if (strcmp(newElement,message[i].text) > 0)
				                    message[j] = message[j - step];
				                else
				                    break;
				            }
				            strcpy(message[i].text,newElement);
				    	}		
				} else {
						
					int i, j, step;
				    char newElement[51];
				    for (step = COUNT_STRUCT / 2; step > 0; step /= 2)
				        for (i = step; i < COUNT_STRUCT; i++) {
				            strcpy(newElement,message[i].text);
				            for (j = i; j >= step; j -= step) {
				                if (strcmp(newElement,message[i].text) < 0)
				                    message[j] = message[j - step];
				                else
				                    break;
				            }
				            strcpy(message[i].text,newElement);
				    	}
					
				}
			}
			break;
		}
	}
	}
}







