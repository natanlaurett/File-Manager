#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "register.h"
#include "file.h"
#include "varSizeReg.h"
#include "avaliable.h"

int main()
{
    /*
    TReg reg;
    initialize(&reg);
    setDesc(&reg, "Test description");
    setId(&reg, 49);

    char fileName[] = "binReg.bin";
    avArray vec = fillEmptyRegisters(fileName, 100);
    printf("\nThere are %d empty registers.\n", vec.arrSize);
    fillRandom(fileName, &vec, 50);
    printf("\nThere are %d empty registers.\n", vec.arrSize);

    printRegisters(fileName,vec);
    removeRegister(fileName,&vec, reg);

    printRegisters(fileName,vec);

    setDesc(&reg, "Other description");
    putRegisterNext(fileName,&vec, reg);
    printRegisters(fileName,vec);
    */

    /*
    char fileNameVar[] = "binRegVar.bin";

    AvList list = createEmpty(fileNameVar, 200 * sizeof(Tfr));
    Tfr firstReg;
    firstReg.id = 1;
    firstReg.type = 1;
    strcpy(firstReg.name, "Test");

    Tsr secondReg;
    secondReg.id = 2;
    secondReg.type = 2;
    secondReg.value = 28.015;

    putTFR(fileNameVar, &list, firstReg);
    putTSR(fileNameVar, &list, secondReg);

    firstReg.id = 3;
    strcpy(firstReg.name, "Other");

    secondReg.id = 4;
    secondReg.value = 14.03;

    putTFR(fileNameVar, &list, firstReg);
    putTSR(fileNameVar, &list, secondReg);
    printAvList(list);

    removeVRegister (fileNameVar, &list, 3, 1);
    printAvList(list);
    printVRegisters(fileNameVar);

    firstReg.id = 5;
    strcpy(firstReg.name, "Another one");
    putTFR(fileNameVar, &list, firstReg);

    firstReg.id = 6;
    strcpy(firstReg.name, "Bites the dust");
    putTFR(fileNameVar, &list, firstReg);
    printAvList(list);
    printVRegisters(fileNameVar);
    */
    return 0;
}
