#include "map.h"
#include "matriks.h"
#include "boolean.h"
#include <stdio.h>

char CC;

void FileToMap(FILE *fp, MATRIKS *room)
{
    MATRIKS room1, room2, room3, kitchen;
    indeks i, j;

    MakeMATRIKS(8, 8, &room1);
    MakeMATRIKS(8, 8, &room2);
    MakeMATRIKS(8, 8, &room3);
    MakeMATRIKS(8, 8, &kitchen);

    START();
    for (i = 1; i <= NBrsEff(room1); i++)
    {
        for (j = 1; j <= NKolEff(room1); j++)
        {
            Elmt(room1, i, j) = CC;
            ADV();
            //printf("%d", Elmt(room1, i, j));
        }
        ADV();
        //printf("\n");
    }

    *room = room1;
}

void moveplayer(player *p, MATRIKS room, char cmd){
    if(cmd == 'w'){
        if(( Elmt(room, (p->py)-1, p->px) == 'X' ) || ((Elmt(room, (p->py)-1, p->px) - '1' >= 0) && (Elmt(room, (p->py)-1, p->px) - '1' <= 3)) || (p->py-1 < 0)){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{
            p->py--;
        }

    }

    if(cmd == 'a'){
        if(( Elmt(room, p->py, p->px-1) == 'X' ) || ((Elmt(room, p->py, p->px-1) - '1' >= 0) && (Elmt(room, p->py, p->px-1) - '1' <= 3)) || (p->px-1 < 0)){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{
            p->px--;
        }
    }
    
    if(cmd == 'd'){
        if(( Elmt(room, p->py, p->px+1) == 'X' ) || ((Elmt(room, p->py, p->px+1) - '1' >= 0) && (Elmt(room, p->py, p->px+1) - '1' <= 3)) || (p->px+1 > NKolEff(room))){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{
            p->px++;
        }
    }

    if(cmd == 's'){
        if(( Elmt(room, p->py+1, p->px) == 'X' ) || ((Elmt(room, p->py+1, p->px) - '1' >= 0) && (Elmt(room, p->py+1, p->px) - '1' <= 3)) || (p->py+1 > NBrsEff(room))){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{
            p->py++;
        }
    }
}

void NearestCust(player p, MATRIKS room, int *ordable){
    char up, down, right, left;
    
    *ordable = Elmt(room, p.py, p.px) - '`';

    if((*ordable > 4) || (*ordable < 1)){
        *ordable = -999;
    }
}