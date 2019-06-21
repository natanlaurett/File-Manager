#ifndef VARSIZEREG_H_INCLUDED
#define VARSIZEREG_H_INCLUDED

typedef struct {
    void* ptr;
    int sizeInBytes;
    int posNext;
}Cell;

typedef struct {
    int id;
    char name[15];
}Tfr;

typedef struct {
    int id;
    float value;
}Tsr;

Cell initializeTfr(Tfr*);
Cell initializeTsr(Tsr*);

void printTfr(Tfr);
void printTsr(Tsr);

int comparetfr (Tfr, Tfr);
int comparetsr (Tsr, Tsr);


#endif // VARSIZEREG_H_INCLUDED
