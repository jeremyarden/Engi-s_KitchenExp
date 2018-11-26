#include "point.h"
#include <stdio.h>

int main()
{
    POINT P1, P2;

    P1 = MakePOINT(2,3);
    P2 = MakePOINT(3,5);
    write("Point 1 : %d %d", Absis(P1), Ordinat(P1));
    write("Point 2 : %d %d", Absis(P2), Ordinat(P2));
    printf("EQ P1 dan P2 : ");
    printf(EQ(P1, P2));
    Geser(&P1, 2, 2);
    write("Point 1 digeser : %d %d", Absis(P1), Ordinat(P1));
}
