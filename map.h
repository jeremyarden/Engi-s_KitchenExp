#ifndef MAP_H
#define MAP_H

#include "matriks.h"
//#include "listdp.h"
#include "mesinkar.h"
#include <stdio.h> 

typedef struct{
    int px; //ngasihtau player ada di baris berapa di ruangan
    int py;//ngasihtau player ada di kolom berapa di ruangan
    int room;//ngasihtau player ada di ruangan mana
}player;

void FileToMap(FILE *fp, MATRIKS *room);

void moveplayer(player *p, MATRIKS room, char cmd);

void NearestCust(player p, MATRIKS room, int *ordable);

#endif