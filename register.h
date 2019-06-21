#ifndef REGISTER_H_INCLUDED
#define REGISTER_H_INCLUDED

typedef struct {
    char desc[30];
    int id;
} TReg;

void initialize(TReg*);
void setDesc(TReg*,char[]);
void setId(TReg*,int);
void printReg(TReg, int);
int compare (TReg, TReg);
#endif // REGISTER_H_INCLUDED
