#include <stdio.h>
#include <stdlib.h>
#include "varSizeReg.h"
#include "avaliable.h"

void createCell (AvCell* cell, int position, int bytes){
    cell -> next = NULL;
    cell -> position = position;
    cell -> sizeInBytes = bytes;
}

void createList (AvList* list){
    list -> listSize = 0;
    list -> first = (AvCell*) malloc(sizeof(AvCell));
    list -> last = list -> first;
}
void addCell (AvList* list, AvCell cell){
    AvCell* aux = (AvCell*) malloc(sizeof(AvCell));
    aux -> position = cell.position;
    aux -> sizeInBytes = cell.sizeInBytes;
    aux -> next = NULL;

    AvCell* curr = list -> first;
    while (aux -> next -> sizeInBytes < curr -> sizeInBytes && curr -> next!= NULL)
        curr = curr -> next;

    if (curr -> next != NULL){
        AvCell* temp = curr -> next;
        curr -> next = aux;
        aux -> next = temp;
    }else
        curr -> next = aux;
}
cellPointer removeFirstFit(AvList* list, Cell cell){
    AvCell* aux = list -> first;
    while (aux -> next -> sizeInBytes < cell.sizeInBytes && aux -> next != NULL){
        aux = aux -> next;
    }
    if (aux -> next -> sizeInBytes < cell.sizeInBytes){
        return NULL;
    }else{
        AvCell* temp = aux -> next;
        aux -> next = aux -> next -> next;
        return temp;
    }
}
cellPointer removeBestFit(AvList* list, Cell cell){
    return removeFirstFit(list,cell);
}
cellPointer removeWorstFit(AvList* list, Cell cell){
    AvCell* aux = list -> first;
    while (aux -> next != NULL){
        if (aux -> next -> next == NULL){
         if (aux -> next -> sizeInBytes < cell.sizeInBytes){
                return NULL;
            }else{
                AvCell* temp = aux -> next;
                aux -> next = NULL;
                return temp;
            }
        }
        aux = aux -> next;
    }
   return NULL;
}
void printAvList(AvList list){
    AvCell* aux = list.first;
    printf("\n******************PRINTING FREE SPACES IN THE FILE******************");
    while (aux -> next != NULL){
        printf("\nFree space in position %d, of %d bytes.", aux->position, aux->sizeInBytes);
    }
    printf("\n***************************PRINT FINISHED***************************");
}
