#ifndef DATA_H
#define DATA_H  
 
#include "struct.h"


using namespace std; 

//some func for put info
void inputData(Cars *car,int COUNT_STRUCT);
//Announcement of geting information
void outputData(Cars *car,int COUNT_STRUCT);
//Global cleaner
void global_cleaner(Cars *car,int COUNT_STRUCT);

#endif 
