#include "map.h"
#include "matriks.h"
#include "boolean.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START(FILE *fp) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	pita = fp;
	ADV();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
       fclose(pita);
 	}
}


void FileToMap(FILE *fp, MATRIKS *room)
{
    indeks i, j;

    MakeMATRIKS(8, 8, room);

    START(fp);
    for (i = 1; i <= NBrsEff(*room); i++)
    {
        for (j = 1; j <= NKolEff(*room); j++)
        {
            Elmt(*room, i, j) = CC;
            ADV();
            //printf("%d", Elmt(room1, i, j));
        }
        ADV();
        //printf("\n");
    }
}

void InitMap(MATRIKS *room1, MATRIKS *room2, MATRIKS *room3, MATRIKS *kitchen)
{
    FILE *fp;
    
    fp = fopen("room1.txt", "r");
    FileToMap(fp, room1);
    fp = fopen("room2.txt", "r");
    FileToMap(fp, room2);
    fp = fopen("room3.txt", "r");
    FileToMap(fp, room3);
    fp = fopen("kitchen.txt", "r");
    FileToMap(fp, kitchen);
}

void moveplayer(player *p, MATRIKS room, char cmd, Graph G, adrNode *currLoc){
    if(cmd == 'w'){
        if( (Elmt(room, (p->py)-1, p->px) == 'X' ) || (Elmt(room, (p->py)-1, p->px) == 'Y' ) || (Elmt(room, (p->py)-1, p->px) == 'Z' ) || ((Elmt(room, (p->py)-1, p->px) - '1' >= 0) && (Elmt(room, (p->py)-1, p->px) - '1' <= 8)) || (p->py-1 < 0)){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{
            p->py--;
        }

    }

    if(cmd == 'a'){
        if(( Elmt(room, p->py, p->px-1) == 'X' ) || ( Elmt(room, p->py, p->px-1) == 'Y' ) || ( Elmt(room, p->py, p->px-1) == 'Z' ) || ((Elmt(room, p->py, p->px-1) - '1' >= 0) && (Elmt(room, p->py, p->px-1) - '1' <= 8)) || (p->px-1 < 0)){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{
            p->px--;
        }
    }
    
    if(cmd == 'd'){
        if(( Elmt(room, p->py, p->px+1) == 'X' ) || (Elmt(room, p->py, p->px+1) == 'Y' ) || (Elmt(room, p->py, p->px+1) == 'Z' ) || ((Elmt(room, p->py, p->px+1) - '1' >= 0) && (Elmt(room, p->py, p->px+1) - '1' <= 8)) || (p->px+1 > NKolEff(room))){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{     }
            p->px++;
        }
    }

    if(cmd == 's'){
        if(( Elmt(room, p->py+1, p->px) == 'X' ) || (Elmt(room, p->py+1, p->px) == 'Y' ) || (Elmt(room, p->py+1, p->px) == 'Z' )|| ((Elmt(room, p->py+1, p->px) - '1' >= 0) && (Elmt(room, p->py+1, p->px) - '1' <= 8)) || (p->py+1 > NBrsEff(room))){ //kondisi dia gabisa gerak
            printf("gabisa gerak kesitu\n");
        }
        else{
            p->py++;
        }


    }

    ChangeRoom(G, currLoc, P);
}

void NearestCust(player p, MATRIKS room, int *ordable){
    char up, down, right, left;
    
    *ordable = Elmt(room, p.py, p.px) - '`';

    if((*ordable > 9) || (*ordable < 0)){
        *ordable = -999;
    }
}

void ChangeRoom(Graph G, adrNode *currLoc, player *P)
{
    adrSuccNode P;
    
    if (X(*P) == 5 && Y(*P) == 9 && Room(*P) == 1)
    {
        X(*P) = 2;
        Y(*P) = 1;
        Room(*P) = 2;
        P = SearchEdge(G, 1, 2);
        *currLoc = Succ(P);  
    }
    else if (X(*P) == 9 && Y(*P) == 5 && Room(*P) == 2)
    {
        X(*P) = 1;
        Y(*P) = 5;
        Room(*P) = 3;
        P = SearchEdge(G, 2, 3);
        *currLoc = Succ(P);
    }
    else if (X(*P) == 2 && Y(*P) == 0 && Room(*P) == 3)
    {
        X(*P) = 5;
        Y(*P) = 8;
        Room(*P) = 4;
        P = SearchEdge(G, 3, 4);
        *currLoc = Succ(P);
    }
    else if (X(*P) == 0 && Y(*P) == 5 && Room(*P) == 4)
    {
        X(*P) = 8;
        Y(*P) = 5;
        Room(*P) = 1;
        P = SearchEdge(G, 4, 1);
        *currLoc = Succ(P);
    }
    else if (X(*P) == 9 && Y(*P) == 5 && Room(*P) == 1)
    {
        X(*P) = 1;
        Y(*P) = 5;
        Room(*P) = 4;
        P = SearchEdge(G, 1, 4);
        *currLoc = Succ(P);
    }
    else if (X(*P) == 5 && Y(*P) == 9 && Room(*P) == 4)
    {
        X(*P) = 2;
        Y(*P) = 1;
        Room(*P) = 3;
        P = SearchEdge(G, 4, 3);
        *currLoc = Succ(P);
    }
    else if (X(*P) == 0 && Y(*P) == 5 && Room(*P) == 3)
    {
        X(*P) = 8;
        Y(*P) = 5;
        Room(*P) = 3;
        P = SearchEdge(G, 3, 2);
        *currLoc = Succ(P);
    }
    else if (X(*P) == 2 && Y(*P) == 0 && Room(*P) == 2)
    {
        X(*P) = 5;
        Y(*P) = 8;
        Room(*P) = 1;
        P = SearchEdge(G, 2, 1);
        *currLoc = Succ(P);
    }

}

void PrintMap(player P)
{

}

boolean AvailOrder(player P, MATRIKS room)
{
    if (Elmt(room, X(P), Y(P)) >= 'a' && Elmt(room, X(P), Y(P)) <= 'j')
    {
        return true;
    }
    else
    {
        return false;
    }
}