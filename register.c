#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "register.h"

void initialize(TReg* reg){
    reg -> id= -1;
    strcpy(reg -> desc, "");
}

void setDesc(TReg* reg, char desc[]){
    strcpy(reg -> desc, desc);
}

void setId(TReg* reg, int id){
    reg -> id = id;
}

void printReg(TReg reg, int pos){
    printf("\n%d: Id = %d. Desc.: %s", pos, reg.id, reg.desc);
}

int compare (TReg reg1, TReg reg2){
    if (reg1.id != reg2.id)
        return -1;
    if (strcmp(reg1.desc, reg2.desc))
        return -2;
    return 0;
}
