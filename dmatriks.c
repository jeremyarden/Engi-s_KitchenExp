#include "matriks.h"
#include <stdio.h>

int main()
{
    MATRIKS M, M1;

    BacaMATRIKS(&M, 8, 8);
    TulisMATRIKS(M);

    CopyMATRIKS(M, &M1);
    printf("Matriks M1 hasil copy M : \n");
    TulisMATRIKS(M1);
}