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
player p;
MATRIKS ruangan;
char cmd;
KATA CKata;

/*Prototype Fungsi*/
boolean IsKataEqStr(Kata CKata, char *str);

boolean IsKataEqStr(Kata CKata, char *str) {
    /* Kamus */
    int i;

    /* Algoritma */
    i=1;
    while (i<=CKata.Length && CKata.TabKata[i]==*str[i]) {
        i++;
    }
    if (i==CKata.Length) {
        return true;
    }
    else {
        return false;
    }
}

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
    /* Kamus */
    boolean isMember;
    player p;
    MATRIKS ruangan;
    char cmd;
    
    /* Algoritma */
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
    InputUser();
    if (IsKataEqStr(CKata, "GOKS")) {
        printf("mantaps\n");
    }
    else {
        printf("tolol\n");
    }
    /* while (!IsKataEqStr(CKata, "EXIT")) {
        if (IsKataEqStr(CKata, "GU")) {
            cmd='w';
            moveplayer(&p,&ruangan,cmd);
        }
        else if (IsKataEqStr(CKata, "GD")) {
            cmd='s';
            moveplayer(&p,&ruangan,cmd);
        }
        else if (IsKataEqStr(CKata, "GL")) {
            cmd='a';
            moveplayer(&p,&ruangan,cmd);
        }
        else if (IsKataEqStr(CKata, "GR")) {
            cmd='d';
            moveplayer(&p,&ruangan,cmd);
        }
        else if (IsKataEqStr(CKata, "ORDER")) {
            
        }
        else if (IsKataEqStr(CKata, "PUT")) {

        }
        else if (IsKataEqStr(CKata, "TAKE")) {

        }
        else if (IsKataEqStr(CKata, "CH")) {

        }
        else if (IsKataEqStr(CKata, "CT")) {

        }
        else if (IsKataEqStr(CKata, "PLACE")) {

        }
        else if (IsKataEqStr(CKata, "GIVE")) {

        }
        else if (IsKataEqStr(CKata, "RECIPE")) {

        }
        else {
            printf("Masukan salah, silahkan ulangi");
            InputUser();
        }

    }*/
    
    
}

