#include <stdio.h>
#include "mapResto.h"

char C;
boolean eop;

static FILE * pita;
static int retval;

void STARTRESTO(FILE *fp) {
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
     Karakter pertama yang ada pada pita posisinya adalah pada jendela.
     I.S. : sembarang
     F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
     Jika CC = MARK maka EOP akan menyala (true) */
    
    /* Algoritma */
    pita = fp;
    ADVRESTO();
}

void ADVRESTO() {
    /* Pita dimajukan satu karakter.
     I.S. : Karakter pada jendela =
     CC, CC != MARK
     F.S. : CC adalah karakter berikutnya dari CC yang lama,
     CC mungkin = MARK.
     Jika  CC = MARK maka EOP akan menyala (true) */
    
    /* Algoritma */
    retval = fscanf(pita,"%c",&C);
    eop = (C == MARK);
    if (eop) {
        fclose(pita);
    }
}


void FileToMap(FILE *fp, MATRIKS *room)
{
    indeks i, j;
    
    MakeMATRIKS(8, 8, room);
    
    STARTRESTO(fp);
    for (i = 1; i <= NBrsEff(*room); i++)
    {
        for (j = 1; j <= NKolEff(*room); j++)
        {
            Elmt(*room, i, j) = C;
            ADVRESTO();
            //printf("%d", Elmt(room1, i, j));
        }
        ADVRESTO();
        //printf("\n");
    }
}

void InitMap(MATRIKS *room1, MATRIKS *room2, MATRIKS *room3, MATRIKS *kitchen)
{
    FILE *fp;
    
    fp = fopen("/Users/abiyyuismunandar/Documents/AIstrukDat/Tubes/4.19AM/Engi-s_KitchenExp-master/room1.txt", "r");
    FileToMap(fp, room1);
    fp = fopen("/Users/abiyyuismunandar/Documents/AIstrukDat/Tubes/4.19AM/Engi-s_KitchenExp-master/room2.txt", "r");
    FileToMap(fp, room2);
    fp = fopen("/Users/abiyyuismunandar/Documents/AIstrukDat/Tubes/4.19AM/Engi-s_KitchenExp-master/room3.txt", "r");
    FileToMap(fp, room3);
    fp = fopen("/Users/abiyyuismunandar/Documents/AIstrukDat/Tubes/4.19AM/Engi-s_KitchenExp-master/kitchen.txt", "r");
    FileToMap(fp, kitchen);
}

boolean IsDoor(player P)
{
    if ((X(P) == 5 && Y(P) == 9 && Room(P) == 1) || (X(P) == 9 && Y(P) == 5 && Room(P) == 1))
    {
        return true;
    }
    else if ((X(P) == 2 && Y(P) == 0 && Room(P) == 2) || (X(P) == 9 && Y(P) == 5 && Room(P) == 2))
    {
        return true;
    }
    else if ((X(P) == 0 && Y(P) == 5 && Room(P) == 3) || (X(P) == 2 && Y(P) == 0 && Room(P) == 3))
    {
        return true;
    }
    else if ((X(P) == 5 && Y(P) == 9 && Room(P) == 4) || (X(P) == 0 && Y(P) == 5 && Room(P) == 4))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void moveplayer(player *P, MATRIKS room, char cmd, Graph G, adrNode *currLoc)
{
    if (cmd == 'w')
    {
        if (Elmt(room, (X(*P)-1), Y(*P)) == 'X' || Elmt(room, (X(*P)-1), Y(*P)) == 'Y' || Elmt(room, (X(*P)-1), Y(*P)) == 'Z' || (Elmt(room, (X(*P)-1), Y(*P)) >= '0' && Elmt(room, (X(*P)-1), Y(*P)) <= '9'))
        {
            printf("cant nigger\n");
        }
        else
        {
            X(*P) = X(*P) - 1;
            if (X(*P) < 1 && !IsDoor(*P))
            {
                printf("cant nigger\n");
                X(*P) = X(*P) + 1;
            }
        }
    }
    else if (cmd == 's')
    {
        if (Elmt(room, (X(*P)+1), Y(*P)) == 'X' || Elmt(room, (X(*P)+1), Y(*P)) == 'Y' || Elmt(room, (X(*P)+1), Y(*P)) == 'Z' || (Elmt(room, (X(*P)+1), Y(*P)) >= '0' && Elmt(room, (X(*P)+1), Y(*P)) <= '9'))
        {
            printf("cant nigger\n");
        }
        else
        {
            X(*P) = X(*P) + 1;
            if (X(*P) > NKolEff(room) && !IsDoor(*P))
            {
                printf("cant nigger\n");
                X(*P) = X(*P) - 1;
            }
        }
    }
    else if (cmd == 'a')
    {
        if (Elmt(room, X(*P), (Y(*P)-1)) == 'X' || Elmt(room, X(*P), (Y(*P)-1)) == 'Y' || Elmt(room, X(*P), (Y(*P)-1)) == 'Z' || (Elmt(room, X(*P), (Y(*P)-1)) >= '0' && Elmt(room, X(*P), (Y(*P)-1)) <= '9'))
        {
            printf("cant nigger\n");
        }
        else
        {
            Y(*P) = Y(*P) - 1;
            if (Y(*P) < 1 && !IsDoor(*P))
            {
                printf("cant nigger\n");
                Y(*P) = Y(*P) + 1;
            }
        }
    }
    else if (cmd == 'd')
    {
        if (Elmt(room, X(*P), (Y(*P)+1)) == 'X' || Elmt(room, X(*P), (Y(*P)+1)) == 'Y' || Elmt(room, X(*P), (Y(*P)+1)) == 'Z' || (Elmt(room, X(*P), (Y(*P)+1)) >= '0' && Elmt(room, X(*P), (Y(*P)+1)) <= '9'))
        {
            printf("cant nigger\n");
        }
        else
        {
            Y(*P) = Y(*P) + 1;
            if (Y(*P) > NKolEff(room) && !IsDoor(*P))
            {
                printf("cant nigger\n");
                Y(*P) = Y(*P) - 1;
            }
        }
    }

    ChangeRoom(G, currLoc, P);
}

void NearestCust(player p, MATRIKS room, int *ordable){
    
    *ordable = -999;
    if(Elmt(room, X(p), Y(p)) >= 'a' && Elmt(room, X(p), Y(p)) <= 'j'){
        *ordable = Elmt(room, X(p), Y(p)) - '`';
    }
}

void ChangeRoom(Graph G, adrNode *currLoc, player *P)
{
    adrSuccNode Pn;
    
    if (X(*P) == 5 && Y(*P) == 9 && Room(*P) == 1)
    {
        X(*P) = 2;
        Y(*P) = 1;
        Room(*P) = 2;
        Pn = SearchEdge(G, 1, 2);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 9 && Y(*P) == 5 && Room(*P) == 2)
    {
        X(*P) = 1;
        Y(*P) = 5;
        Room(*P) = 3;
        Pn = SearchEdge(G, 2, 3);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 2 && Y(*P) == 0 && Room(*P) == 3)
    {
        X(*P) = 5;
        Y(*P) = 8;
        Room(*P) = 4;
        Pn = SearchEdge(G, 3, 4);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 0 && Y(*P) == 5 && Room(*P) == 4)
    {
        X(*P) = 8;
        Y(*P) = 5;
        Room(*P) = 1;
        Pn = SearchEdge(G, 4, 1);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 9 && Y(*P) == 5 && Room(*P) == 1)
    {
        X(*P) = 1;
        Y(*P) = 5;
        Room(*P) = 4;
        Pn = SearchEdge(G, 1, 4);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 5 && Y(*P) == 9 && Room(*P) == 4)
    {
        X(*P) = 2;
        Y(*P) = 1;
        Room(*P) = 3;
        Pn = SearchEdge(G, 4, 3);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 0 && Y(*P) == 5 && Room(*P) == 3)
    {
        X(*P) = 8;
        Y(*P) = 5;
        Room(*P) = 3;
        Pn = SearchEdge(G, 3, 2);
        *currLoc = Succ(Pn);
    }
    else if (X(*P) == 2 && Y(*P) == 0 && Room(*P) == 2)
    {
        X(*P) = 5;
        Y(*P) = 8;
        Room(*P) = 1;
        Pn = SearchEdge(G, 2, 1);
        *currLoc = Succ(Pn);
    }
    
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
