#include <stdio.h>
#include "map.h"
#include "graph.h"

int main()
{
    FILE *mantul;
    Graph GMap;
    player sergio;
    char cmd;
    int ordable;
    adrNode currLoc;
    MATRIKS room1, room2, room3, kitchen;

    //Buka file, masukin ke mantul
    InitMap(&room1, &room2, &room3, &kitchen);
    InitGraph(&GMap);
    currLoc = First(GMap);

    /*//coba inisialisasi player di ruangan 1, tulis map di keadaan itu
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
    }*/
    
    /* BUAT COMMAND TAKECHCT
    if (cc=='A') {
        CKata="Piring";
        Take(*Hand, CKata);
    }
    else if (cc=='B') {
        CKata="Sendok";
        Take(*Hand, CKata);
    }
    else if (cc=='C') {
        CKata="Garpu";
        Take(*Hand, CKata);
    }
    else if (cc=='D') {
        CKata="Es Krim";
        Take(*Hand, CKata);
    }
    else if (cc=='E') {
        CKata="Nasi";
        Take(*Hand, CKata);
    }
    else if (cc=='F') {
        CKata="Roti";
        Take(*Hand, CKata);
    }
    else if (cc=='G') {
        CKata="Spaghetti";
        Take(*Hand, CKata);
    }
    else if (cc=='H') {
        CKata="Pisang";
        Take(*Hand, CKata);
    }
    else if (cc=='I') {
        CKata="Stroberi";
        Take(*Hand, CKata);
    }
    else if (cc=='J') {
        CKata="Stroberi";
        Take(*Hand, CKata);
    }
    else if (cc=='K') {
        CKata="Telur";
        Take(*Hand, CKata);
    }
    else if (cc=='L') {
        CKata="Ayam Goreng";
        Take(*Hand, CKata);
    }
    else if (cc=='M') {
        CKata="Patty";
        Take(*Hand, CKata);
    }
    else if (cc=='N') {
        CKata="Sosis";
        Take(*Hand, CKata);
    }
    else if (cc=='O') {
        CKata="Bolognese";
        Take(*Hand, CKata);
    }
    else if (cc=='P') {
        CKata="Carbonara";
        Take(*Hand, CKata);
    }
    else if (cc=='Q') {
        CKata="Keju";
        Take(*Hand, CKata);
    }


    return 0;
}