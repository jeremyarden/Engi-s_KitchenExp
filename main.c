#include <stdio.h>
#include "map.h"

int main()
{
    FILE *mantul;
    player sergio;
    char cmd;
    int ordable;
    MATRIKS room, rcopy;

    //Buka file, masukin ke mantul
    mantul = fopen("map.txt", "r");
    FileToMap(mantul, &room);
    CopyMATRIKS(room, &rcopy);
    //rcopy itu matriks buat ditampilin ke layar. Soalnya kalo nampilin ke layar pake matriks aslinya,
    //nanti ketimpa timpa gajelas gitu

    //coba inisialisasi player di ruangan 1, tulis map di keadaan itu
    sergio.px=5;
    sergio.py=5;
    Elmt(rcopy, sergio.px, sergio.py) = 'P';
    TulisMATRIKS(rcopy);
    printf("\n");

    //selama input bukan x, terus jalanin program: gerakin player dan nampilin map
    scanf("%c", &cmd);

    while(cmd != 'x'){
        Elmt(rcopy, sergio.py, sergio.px) = '#'; //tempat sebelum player pindah jadi x lagi
        moveplayer(&sergio, room, cmd);//gerakin player, control:w,a,s,d
        Elmt(rcopy, sergio.py, sergio.px) = 'P';//tempat player sekarang jadi P
        NearestCust(sergio, room, &ordable);
        TulisMATRIKS(rcopy);
        if(ordable == -999){
            printf("You can't take order here\n");
        }
        else{
            printf("Table %d\n", ordable);
        }
        scanf("%c", &cmd);
    }



    return 0;
}