#ifndef AVALIABLE_H_INCLUDED
#define AVALIABLE_H_INCLUDED

#include "varSizeReg.h"

typedef struct AvCell* cellPointer;

struct AvCell{
    int position;
    int sizeInBytes;
    cellPointer next;
};

typedef struct AvCell AvCell;

typedef struct {
    cellPointer first;
    cellPointer last;
    int fileSize;
}AvList;

void createCell (AvCell*, int, int);
void createList (AvList*);
void addCell (AvList*, AvCell);
AvCell* removeFirstFit(AvList*, Cell);
AvCell* removeBestFit(AvList*, Cell);
AvCell* removeWorstFit(AvList*, Cell);
void printAvList(AvList);

#endif // AVALIABLE_H_INCLUDED
