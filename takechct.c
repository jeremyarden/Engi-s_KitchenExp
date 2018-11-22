#include "takechct.h"

void Take (Stack *Hand, infotype CKata)
{
    /* Kamus */

    /* Algoritma */
    /* bikin ketemu sama apa di matriks nya */
    SalinKata();
    Push(Hand, CKata);
}

void Ch (Stack *Hand, infotype *Sampah)
{
    /* Kamus */

    /* Algoritma */
    while (!(IsEmpty(*Hand))) {
        Pop(Hand, Sampah);
    }
}

void Ct (Stack *Tray, infotype *Sampah)
{
    /* Kamus */

    /* Algoritma */
    while (!(IsEmpty(*Tray))) {
        Pop(Tray, Sampah);
    }
}
