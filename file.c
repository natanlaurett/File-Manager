#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

FILE* createWB(char fileName[]){
    FILE* temp = fopen(fileName,"wb");
    if (temp)
        return temp;
    return NULL;
};

FILE* createARB(char fileName[]){
    FILE* temp = fopen(fileName,"rb+");
    if (temp)
        return temp;
    return NULL;
}


avArray fillEmptyRegisters(char fileName[], int num){
    FILE* file = createWB(fileName);
    avArray vec;
    vec.arrSize = num;
    vec.fileSize = num;
    TReg reg;
    initialize(&reg);
    vec.pos = (int*) malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++){
        fseek(file, i * sizeof(TReg), SEEK_SET);
        fwrite(&reg, sizeof(TReg), 1, file);
        vec.pos[i] = i;
    }
    fclose(file);
    return vec;
}
void putRegister (char fileName[], avArray* avaliable, TReg reg, int position){
    if (avaliable -> fileSize <= position)
        return;
    int i = isAvaliable(position, *avaliable);
    if (i){
        FILE* file = createARB(fileName);
        fseek(file, position * sizeof(TReg), SEEK_SET);
        fwrite(&reg, sizeof(TReg), 1, file);
        removeAvaliable(i, avaliable);
        fclose(file);
        return;
    }
    printf("\nThe position is already occupied. Do you want to overwrite it?(y/n)\n");
    char option = 'y';
    scanf("%c", &option);
    fflush(stdin);
    if (option == 'y'){
        FILE* file = createARB(fileName);
        fseek(file, position * sizeof(TReg), SEEK_SET);
        fwrite(&reg, sizeof(TReg), 1, file);
        fclose(file);
    }
}

void putRegisterNext(char fileName[], avArray* vec, TReg reg){
    FILE* file = createARB(fileName);
    int aux = vec -> pos[0];
    fseek(file, vec -> pos[0] * sizeof(TReg), SEEK_SET);
    fwrite(&reg, sizeof(TReg), 1, file);
    removeAvaliable(aux, vec);
    printf("\nRegister of id %d inserted in position %d.\n", reg.id, aux);
    fclose(file);
}

void fillRandom (char fileName[], avArray* vec, int size){
    srand(1728007);
    char desc[] = "Test description";
    for (int i = 0; i < size; i++){
        TReg reg;
        reg.id = rand() % 50;
        strcpy(reg.desc, desc);
        putRegister(fileName, vec, reg, i);
    }
}

int findRegister(char fileName[], avArray avaliable, TReg reg){
    FILE* file = createARB(fileName);
    fseek (file, 0, SEEK_SET);
    int i = 0;
    while (i < avaliable.fileSize){
        TReg temp;
        fseek(file, i * sizeof(TReg), SEEK_SET);
        fread(&temp, sizeof(TReg), 1, file);
        if(!isAvaliable(i,avaliable)){
            if (!compare(reg,temp)){
                fclose(file);
                return i;
            }
        }
        i++;
    }
    fclose(file);
    return -1;
}
void removeRegister(char fileName[], avArray* avaliable, TReg reg){
    int position = findRegister(fileName,*avaliable, reg);
    if (position != -1){
        addAvaliable(position, avaliable);
        printf("\nRegister of id %d removed from the position %d of the file.\n", reg.id, position);
    }
    else
        printf("The register does not exist in the file.\n");
}
void printRegisters(char fileName[], avArray avaliable){
    printf("\n---------------------------------------PRINTING ACTIVE REGISTERS---------------------------------------\n");
    FILE* file = fopen (fileName, "rb");
    if (!file)
        printf("\nFile not open. Error code 2.\n");
    for (int i = 0; i < avaliable.fileSize; i++){
        if (!isAvaliable(i,avaliable)){
            TReg reg;
            fseek (file, sizeof(TReg) * i, SEEK_SET);
            fread(&reg, sizeof(TReg), 1, file);
            printReg(reg, i);
        }
    }
    printf("\n--------------------------------------------PRINT FINISHED---------------------------------------------\n");
}

int isAvaliable(int number, avArray vec){
    printAvaliable(vec);
    for (int i = 0; i < vec.arrSize; i++){
        if (vec.pos[i] == number)
            return i;
    }
    return 0;
}
void addAvaliable(int number, avArray* vec){
    vec -> pos = realloc (vec->pos, sizeof(int) * (vec -> arrSize + 1));
    vec -> arrSize ++;

    for (int i = 0; i < vec->arrSize; i++){
        if ((vec -> pos[i]) > number){
            int temp = vec -> pos[i];
            vec -> pos [i] = number;
            for (int j = i + 1; j < vec -> arrSize; j++){
                int aux = vec -> pos[j];
                vec -> pos[j] = temp;
                temp = aux;
            }
            return;
        }
    }

}
void removeAvaliable(int number, avArray* vec){
    for (int i = isAvaliable(number, *vec); i < vec -> arrSize - 1; i++){
        vec -> pos[i] = vec -> pos[i + 1];
    }
    vec -> pos = realloc (vec->pos, sizeof(int) * (vec -> arrSize - 1));
    vec -> arrSize --;
}

void printAvaliable (avArray vec){
    printf("\nPRINTING AVALIABLE POSITIONS IN THE FILE...\n");
    int aux;
    for (aux = 0; aux < vec.arrSize - 1; aux++){
        printf("%d, ", vec.pos[aux]);
    }
    printf("%d.\nPRINT FINISHED!\n", vec.pos[vec.arrSize - 1]);
}

//*********************************************************************************************************
AvList createEmpty (int bytes){
    AvList list;
    createList(&list);
    list.fileSize = bytes;
    AvCell cell;
    cell.next = NULL;
    cell.position = 0;
    cell.sizeInBytes = bytes;
    addCell(&list, cell);
    return list;
}
void putVRegister (char fileName[], AvList* list,Cell cell, char type){
    AvCell avCell= removeBestFit(list, cell);
    if (avCell){
        cell.posNext = avCell.position + cell.sizeInBytes;
        cell.sizeInBytes = sizeof(cell);

        FILE* file = createARB(fileName);
        fseek(file,avCell.position,SEEK_SET);
        fwrite(&cell, sizeof(cell), 1, file);
        fclose(file);

        AvCell leftOver;
        int remainSize = avCell.sizeInBytes - cell.sizeInBytes;
        int position = avCell.position + cell.sizeInBytes;

        createCell(&leftOver,position,remainSize);
        addCell(list,leftOver);
    }else
        printf("\nThere is no space in the file.");
}
void removeVRegister(char fileName[],AVList* list, Cell cell){

}
