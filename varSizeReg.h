#ifndef VARSIZEREG_H_INCLUDED
#define VARSIZEREG_H_INCLUDED

typedef struct {
    int type;
    int id;
    char name[15];
    int active;
}Tfr;

typedef struct {
    int type;
    int id;
    float value;
    int active;
}Tsr;

void printTfr(Tfr);
void printTsr(Tsr);

int comparetfr (Tfr, Tfr);
int comparetsr (Tsr, Tsr);


#endif // VARSIZEREG_H_INCLUDED
