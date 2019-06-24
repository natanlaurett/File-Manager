#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varSizeReg.h"

void printTfr(Tfr reg){
    printf("\nRegister Type 1. Id: %d. Name: %s", reg.id, reg.name);
}

void printTsr(Tsr reg){
    printf("\nRegister Type 2. Id: %d. Value: %f", reg.id, reg.value);
}

int comparetfr (Tfr reg1, Tfr reg2){
    if (reg1.id != reg2.id)
        return 0;
    if (!strcmp(reg1.name,reg2.name))
        return 0;
    return 1;
}

int comparetsr (Tsr reg1, Tsr reg2){
    if (reg1.id != reg2.id)
        return 0;
    if (reg1.value != reg2.value)
        return 0;
    return 1;
}
