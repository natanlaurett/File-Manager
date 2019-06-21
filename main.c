#include <stdio.h>
#include <stdlib.h>
#include "register.h"
#include "file.h"

int main()
{
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
    //printAvaliable(vec);
    removeRegister(fileName,&vec, reg);

    printRegisters(fileName,vec);
    //printAvaliable(vec);

    putRegisterNext(fileName,&vec, reg);
    printRegisters(fileName,vec);
    //printAvaliable(vec);

    return 0;
}
