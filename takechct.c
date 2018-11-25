#include "takechct.h"


void Take (Stack *Hand, ElType M,TabMenu TM)
{
    /* Kamus */
    infotypeStack benda;
    /* Algoritma */
    if (M=='A') {
        CopyKata(TM.TM[1].nama, &benda.str);
        benda.harga = TM.TM[1].harga;
    }
    else if (M=='B') {
        CopyKata(TM.TM[2].nama, &benda.str);
        benda.harga = TM.TM[2].harga;
    }
    else if (M=='C') {
        CopyKata(TM.TM[3].nama, &benda.str);
        benda.harga = TM.TM[3].harga;
    }
    else if (M=='D') {
        CopyKata(TM.TM[4].nama, &benda.str);
        benda.harga = TM.TM[4].harga;
    }
    else if (M=='E') {
        CopyKata(TM.TM[5].nama, &benda.str);
        benda.harga = TM.TM[5].harga;
    }
    else if (M=='F') {
        CopyKata(TM.TM[6].nama, &benda.str);
        benda.harga = TM.TM[6].harga;
    }
    else if (M=='G') {
        CopyKata(TM.TM[7].nama, &benda.str);
        benda.harga = TM.TM[7].harga;
    }
    else if (M=='H') {
        CopyKata(TM.TM[8].nama, &benda.str);
        benda.harga = TM.TM[8].harga;
    }
    else if (M=='I') {
        CopyKata(TM.TM[9].nama, &benda.str);
        benda.harga = TM.TM[9].harga;
    }
    else if (M=='J') {
        CopyKata(TM.TM[9].nama, &benda.str);
        benda.harga = TM.TM[9].harga;
    }
    else if (M=='K') {
        CopyKata(TM.TM[10].nama, &benda.str);
        benda.harga = TM.TM[10].harga;
    }
    else if (M=='L') {
        CopyKata(TM.TM[11].nama, &benda.str);
        benda.harga = TM.TM[11].harga;
    }
    else if (M=='M') {
        CopyKata(TM.TM[12].nama, &benda.str);
        benda.harga = TM.TM[12].harga;
    }
    else if (M=='N') {
        CopyKata(TM.TM[13].nama, &benda.str);
        benda.harga = TM.TM[13].harga;
    }
    else if (M=='O') {
        CopyKata(TM.TM[14].nama, &benda.str);
        benda.harga = TM.TM[14].harga;
    }
    else if (M=='P') {
        CopyKata(TM.TM[15].nama, &benda.str);
        benda.harga = TM.TM[15].harga;
    }
    else if (M=='Q') {
        CopyKata(TM.TM[22].nama, &benda.str);
        benda.harga = TM.TM[22].harga;
    }
    Push(Hand, benda);
}

void Ch (Stack *Hand, infotypeStack *Sampah)
{
    /* Kamus */
    
    /* Algoritma */
    while (!(StackIsEmpty(*Hand))) {
        Pop(Hand, Sampah);
    }
}

void Ct (Stack *Tray, infotypeStack *Sampah)
{
    /* Kamus */
    
    /* Algoritma */
    while (!(StackIsEmpty(*Tray))) {
        Pop(Tray, Sampah);
    }
}
