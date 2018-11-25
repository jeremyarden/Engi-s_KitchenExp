#ifndef MAP_H
#define MAP_H

#include "matriks.h"
//#include "listdp.h"
// /#include "mesinkar.h"
#include <stdio.h> 

#define MARK '.'
/* State Mesin */
extern char CC;
extern boolean EOP;

typedef struct{
    int px; //ngasihtau player ada di baris berapa di ruangan
    int py;//ngasihtau player ada di kolom berapa di ruangan
    int room;//ngasihtau player ada di ruangan mana
}player;

#define X(P) P.px
#define Y(P) P.py
#define Room(P) P.room

void START(FILE *fp);
void ADV();
void FileToMap(FILE *fp, MATRIKS *room);
void InitMap(MATRIKS *room1, MATRIKS *room2, MATRIKS *room3, MATRIKS *kitchen);
void moveplayer(player *p, MATRIKS *room, char cmd);
void NearestCust(player p, MATRIKS room, int *ordable);
#endif