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
    list -> fileSize = 0;
    list -> first = (AvCell*) malloc(sizeof(AvCell));
    list -> last = list -> first;

    list -> first -> sizeInBytes = 0;
    list -> first -> position = 0;
    list -> first -> next = NULL;
}
void addCell (AvList* list, AvCell cell){
    AvCell* aux = (AvCell*) malloc(sizeof(AvCell));
    aux -> position = cell.position;
    aux -> sizeInBytes = cell.sizeInBytes;
    aux -> next = NULL;
    AvCell* curr = list -> first;

    while ( curr -> next != NULL && aux -> sizeInBytes > curr -> next-> sizeInBytes){
        curr = curr -> next;
    }
    if (curr -> next != NULL){
        AvCell* temp = curr -> next;
        curr -> next = aux;
        aux -> next = temp;
    }else
        curr -> next = aux;

    printf("\nAvaliable cell added. Position: %d. Size: %d", aux -> position, aux -> sizeInBytes);
}
cellPointer removeFirstFit(AvList* list, int size){
    AvCell* aux = list -> first;
    while (aux -> next -> sizeInBytes < size && aux -> next != NULL){
        aux = aux -> next;
    }
    if (aux -> next -> sizeInBytes < size){
        return NULL;
    }else{
        AvCell* temp = aux -> next;
        aux -> next = aux -> next -> next;
        return temp;
    }
}
cellPointer removeBestFit(AvList* list, int size){
    return removeFirstFit(list,size);
}
cellPointer removeWorstFit(AvList* list, int size){
    AvCell* aux = list -> first;
    while (aux -> next != NULL){
        if (aux -> next -> next == NULL){
         if (aux -> next -> sizeInBytes < size){
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
    printf("\n\n******************PRINTING FREE SPACES IN THE FILE******************");
    while (aux != NULL){
        printf("\nFree space in position %d, of %d bytes.", aux->position, aux->sizeInBytes);
        aux = aux -> next;
    }
    printf("\n***************************PRINT FINISHED***************************");
}
