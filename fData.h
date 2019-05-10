#ifndef FDATA_H
#define FDATA_H  

#include "struct.h"


using namespace std;
 
//new_DB
void new_DB(Cars *car,int COUNT_STRUCT);
//Delete File
void remove_DB(Cars *car,int COUNT_STRUCT);
//Clean memory
void clear(Cars *car,int COUNT_STRUCT);
//From array to txt
void save_DB(Cars *car,int COUNT_STRUCT);
//from txt to array
void load_DB(Cars *car,int COUNT_STRUCT);

 #endif 
