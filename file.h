#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "register.h"
#include "varSizeReg.h"
#include "avaliable.h"

typedef struct {
    int arrSize;
    int* pos;
    int fileSize;
}avArray;

FILE* createWB(char[]);
FILE* createARB(char[]);
// **************************SAME SIZE REGISTERS**************************
avArray fillEmptyRegisters(char[], int);
void putRegister (char[], avArray*, TReg, int);
void putRegisterNext(char[], avArray*, TReg);
void fillRandom (char[], avArray*, int);
int findRegister(char[], avArray, TReg);
void removeRegister(char[], avArray*, TReg);
void printRegisters(char[], avArray);
int isAvaliable(int, avArray);
void addAvaliable(int, avArray*);
void removeAvaliable(int, avArray*);
void printAvaliable (avArray);

// ************************DIFERENT SIZE REGISTERS************************
AvList createEmpty (char[],int);
void putTFR (char[], AvList*,Tfr);
void putTSR (char[], AvList*,Tsr);
void removeVRegister(char[],AvList*, int, int);
void printVRegisters(char[], AvList);
#endif // FILE_H_INCLUDED

