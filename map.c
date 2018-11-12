#include "map.h"
#include "matriks.h"
#include "boolean.h"
#include <stdio.h>

char CC;

void FileToMap(FILE *fp)
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

    TulisMATRIKS(room1);
}

void movement(player *p, MATRIKS room, char cmd){
    if(cmd == 'w'){
        if(( Elmt(room, player.px, player.py-1) != '#' ) || (player.py-1 < 0)){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu");
        }
    }

    if(cmd == 'w'){

    }
    
    if(cmd == 'w'){

    }

    if(cmd == 'w'){

    }
}