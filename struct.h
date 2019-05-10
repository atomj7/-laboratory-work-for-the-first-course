#ifndef STRUCT_H
#define STRUCT_H  
 
struct Date {
	int month;
	int day;
	int year;
};

struct Cars {
	struct Date release;
	char mark[20];
	int max_Speed;
	int torque;
	char model[20];
	char color[20];
	int enginePower;
	char  manufacturer_country[20];
};

 #endif 
