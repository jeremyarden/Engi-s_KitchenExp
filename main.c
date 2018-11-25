#include <stdio.h>
#include "mapResto.h"
#include "graph.h"

int main()
{
    FILE *mantul;
    Graph GMap;
    player Pl;
    char cmd, abc;
    int ordable;
    adrNode currLoc;
    adrSuccNode P;
    MATRIKS room1, room2, room3, kitchen, rcopy;

    InitMap(&room1, &room2, &room3, &kitchen);
    InitGraph(&GMap);
    currLoc = First(GMap);

    //coba inisialisasi player di ruangan 1, tulis map di keadaan itu
    
    X(Pl) = 5;
    Y(Pl) = 5;
    Room(Pl) = Id(currLoc);
    if (Id(currLoc) == 1)
    {
        CopyMATRIKS(room1, &rcopy);
    }
    else if (Id(currLoc) == 2)
    {
        CopyMATRIKS(room2, &rcopy);
    }
    else if (Id(currLoc) == 3)
    {
        CopyMATRIKS(room3, &rcopy);
    }
    else if (Id(currLoc) == 4)
    {
        CopyMATRIKS(kitchen, &rcopy);
    }
    Elmt(rcopy, X(Pl), Y(Pl)) = 'U';
    TulisMATRIKS(rcopy);

    scanf("%c", &cmd);
    while (cmd != 'x')
    {
        Elmt(rcopy, X(Pl), Y(Pl)) = '#';
        moveplayer(&Pl, rcopy, cmd, GMap, &currLoc);
        Room(Pl) = Id(currLoc);
        if (Id(currLoc) == 1)
        {
            CopyMATRIKS(room1, &rcopy);
        }
        else if (Id(currLoc) == 2)
        {
            CopyMATRIKS(room2, &rcopy);
        }
        else if (Id(currLoc) == 3)
        {
            CopyMATRIKS(room3, &rcopy);
        }
        else if (Id(currLoc) == 4)
        {
            CopyMATRIKS(kitchen, &rcopy);
        }
        Elmt(rcopy, X(Pl), Y(Pl)) = 'U';
        TulisMATRIKS(rcopy);
        scanf(" %c", &cmd);
    }
    return 0;
}
