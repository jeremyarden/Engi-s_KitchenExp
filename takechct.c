#include "takechct.h"
#include "matriks.h"

void Take (Stack *Hand, MATRIKS M)
{
    /* Kamus */
    infotypeStack benda;

    /* Algoritma */
    if (Elmt(M,i,j)=='A') {
        benda="Piring";
    }
    else if (Elmt(M,i,j)=='B') {
        benda="Sendok";
    }
    else if (Elmt(M,i,j)=='C') {
        benda="Garpu";
    }
    else if (Elmt(M,i,j)=='D') {
        benda="Es Krim";
    }
    else if (Elmt(M,i,j)=='E') {
        benda="Nasi";
    }
    else if (Elmt(M,i,j)=='F') {
        benda="Roti";
    }
    else if (Elmt(M,i,j)=='G') {
        benda="Spaghetti";
    }
    else if (Elmt(M,i,j)=='H') {
        benda="Pisang";
    }
    else if (Elmt(M,i,j)=='I') {
        benda="Stroberi";
    }
    else if (Elmt(M,i,j)=='J') {
        benda="Stroberi";
    }
    else if (Elmt(M,i,j)=='K') {
        benda="Telur";
    }
    else if (Elmt(M,i,j)=='L') {
        benda="Ayam Goreng";
    }
    else if (Elmt(M,i,j)=='M') {
        benda="Patty";
    }
    else if (Elmt(M,i,j)=='N') {
        benda="Sosis";
    }
    else if (Elmt(M,i,j)=='O') {
        benda="Bolognese";
    }
    else if (Elmt(M,i,j)=='P') {
        benda="Carbonara";
    }
    else if (Elmt(M,i,j)=='Q') {
        benda="Keju";
    }
    SalinKata();
    Push(Hand, benda);
}

void Ch (Stack *Hand, infotypeStack *Sampah)
{
    /* Kamus */

    /* Algoritma */
    while (!(IsEmpty(*Hand))) {
        Pop(Hand, Sampah);
    }
}

void Ct (Stack *Tray, infotypeStack *Sampah)
{
    /* Kamus */

    /* Algoritma */
    while (!(IsEmpty(*Tray))) {
        Pop(Tray, Sampah);
    }
}
