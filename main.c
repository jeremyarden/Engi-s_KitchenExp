#include <stdio.h>
#include "resep.h"
#include "start.h"
#include "mapResto.h"
#include "arraymeja.h"
/*Variabel Global*/
MATRIKS Ruang1,Ruang2,Ruang3,Dapur;
BinTree Resep;
TabName TNama;
TabMenu TMenu;
TabMeja TMeja;
GameStatus Pemain;
/*Prototype Fungsi*/
void InitGame();
void GAMESTART();
int main()
{
    /*Kamus*/
    /*Algoritma*/
    InitGame();
    GAMESTART();
    return 0;
}

void InitGame()
{
    InitMap(&Ruang1, &Ruang2, &Ruang3, &Dapur);
    SetStart(&Pemain);
    MakeEmptyTabName(&TNama);
    makeResep(&Resep);
    setTabMenu(&TMenu, Resep);
    MakeMeja(&TMeja);
}

void GAMESTART()
{
    boolean isMember;
    RegistName(&TNama,&isMember);
    if(isMember)
    {
        printf("Selamat Datang Kembali: ");
        printKata(TNama.TN[IsMemberIdx(TNama, CKata)]);printf("\n");
    } else
    {
        printf("Selamat Datang: ");
        printKata(TNama.TN[TNama.Neff]);printf("\n");
    }
    
    
    
}

