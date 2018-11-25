#include <stdio.h>
#include "resep.h" 
#include "start.h" 
#include "Place.h"
#include "put.h"
#include "graph.h"
#include "takechct.h"
#include "mapResto.h"
#include "arraymeja.h"
#include "order.h"
#include "nexttik.h"

/*Variabel Global*/
MATRIKS Ruang1,Ruang2,Ruang3,Dapur;
BinTree Resep;
TabName TNama;
TabMenu TMenu;
TabMeja TMeja;
TabOrd Order;

Stack Hand, Tray;
GameStatus Pemain;
player p;
MATRIKS ruangan, rtemp;
char cmd;
int ordable;
Graph GMap;
adrNode currLoc;
Queue Q;

/*Prototype Fungsi*/
boolean IsKataEqStr(Kata CKata, char *str);
void InitGame();
void GAMESTART();
void ReloadMap(MATRIKS *rtemp);

int main()
{
    /*Kamus*/

    /*Algoritma*/
    InitGame();
    InitGraph(&GMap);
    currLoc = First(GMap);
    X(p) = 5;
    Y(p) = 5;
    Room(p) = Id(currLoc);
    ReloadMap(&rtemp);
    Elmt(ruangan, X(p), Y(p)) = 'U';
    GAMESTART();
    return 0;
}

void InitGame()
{
    int i;
    infoqueue X;
    InitMap(&Ruang1, &Ruang2, &Ruang3, &Dapur);
    SetStart(&Pemain);
    MakeEmptyTabName(&TNama);
    StackCreateEmpty(&Hand);
    StackCreateEmpty(&Tray);
    i=rand()%2;
    X.orang=2+i*2; //acak jumlah orang 2/4 orang
    X.kesabaran=30; //kesabaran 30
    QueueCreateEmpty(&Q, 10);
    Add(&Q,X);
    /*makeResep(&Resep);
    setTabMenu(&TMenu, Resep);
    MakeMeja(&TMeja);*/
}

void ReloadMap(MATRIKS *rtemp)
{
    if (Id(currLoc) == 1)
    {
        CopyMATRIKS(Ruang1, &ruangan);
        *rtemp = Ruang1;
    }
    else if (Id(currLoc) == 2)
    {
        CopyMATRIKS(Ruang2, &ruangan);
        *rtemp = Ruang2;
    }
    else if (Id(currLoc) == 3)
    {
        CopyMATRIKS(Ruang3, &ruangan);
        *rtemp = Ruang3;
    }
    else if (Id(currLoc) == 4)
    {
        CopyMATRIKS(Dapur, &ruangan);
        *rtemp = Dapur;
    }
}

void GAMESTART()
{
    /* Kamus */
    boolean isMember;
    char cmd;
    infotypeStack Trash;
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
    Elmt(ruangan, X(p), Y(p)) = 'U';
    TulisMATRIKS(ruangan);
    InputUser();
    while (!(CKata.TabKata[1]=='E' && CKata.TabKata[2]=='X' && CKata.TabKata[3]=='I' && CKata.TabKata[4]=='T')) {
        if (CKata.Length==2) {
            if (CKata.TabKata[1]=='G') {
                if (CKata.TabKata[2]=='U') {
                    char cmd = 'w';
                    Elmt(ruangan, X(p), Y(p)) = '#';
                    moveplayer(&p, ruangan, cmd, GMap, &currLoc);
                    Room(p) = Id(currLoc);
                    ReloadMap(&rtemp);
                    Elmt(ruangan, X(p), Y(p)) = 'U';
                    NearestCust(p, rtemp, &ordable);
                    TulisMATRIKS(ruangan);
                    
                }
                else if (CKata.TabKata[2]=='D') {
                    char cmd = 's';
                    Elmt(ruangan, X(p), Y(p)) = '#';
                    moveplayer(&p, ruangan, cmd, GMap, &currLoc);
                    Room(p) = Id(currLoc);
                    ReloadMap(&rtemp);
                    Elmt(ruangan, X(p), Y(p)) = 'U';
                    NearestCust(p, rtemp, &ordable);
                    TulisMATRIKS(ruangan);
                }
                else if (CKata.TabKata[2]=='L') {
                    char cmd = 'a';
                    Elmt(ruangan, X(p), Y(p)) = '#';
                    moveplayer(&p, ruangan, cmd, GMap, &currLoc);
                    Room(p) = Id(currLoc);
                    ReloadMap(&rtemp);
                    Elmt(ruangan, X(p), Y(p)) = 'U';
                    NearestCust(p, rtemp, &ordable);
                    TulisMATRIKS(ruangan);
                }
                else if (CKata.TabKata[2]=='R') {
                    char cmd = 'd';
                    Elmt(ruangan, X(p), Y(p)) = '#';
                    moveplayer(&p, ruangan, cmd, GMap, &currLoc);
                    Room(p) = Id(currLoc);
                    ReloadMap(&rtemp);
                    Elmt(ruangan, X(p), Y(p)) = 'U';
                    NearestCust(p, rtemp, &ordable);
                    TulisMATRIKS(ruangan);
                }
                else {
                    printf("Masukan salah\n");
                }
            }
            else if (CKata.TabKata[1]=='C') {
                if (CKata.TabKata[2]=='H') {
                    Ch(&Hand,&Trash);
                }
                else if (CKata.TabKata[2]=='T') {
                    Ct(&Tray,&Trash);
                }
                else {
                    printf("Masukan salah\n");
                    InputUser();
                }
            }   
            else {
                printf("Masukan salah\n");
                InputUser();
            }
        }
        else if (CKata.Length==3) {
            if (CKata.TabKata[1]=='P' && CKata.TabKata[2]=='U' && CKata.TabKata[3]=='T') {
                Put(&Hand,&Tray,&Resep,p,Dapur,TMenu);
            }
            else {
                printf("Masukan salah\n");
                InputUser();
            }
        }
        else if (CKata.Length==4) {
            if (CKata.TabKata[1]=='T' && CKata.TabKata[2]=='A' && CKata.TabKata[3]=='K' && CKata.TabKata[4]=='E') {
                Take(&Hand,Elmt(ruangan,X(p),Y(p)),TMenu);
            }
            else if (CKata.TabKata[1]=='G' && CKata.TabKata[2]=='I' && CKata.TabKata[3]=='V' && CKata.TabKata[4]=='E') {
                Give(&Tray,&Order,&Pemain,p,&TMeja,&Ruang1,&Ruang2,&Ruang3);
            }
            else {
                printf("Masukan salah\n");
                InputUser();
            }
        }
        else if (CKata.Length==5) {
            if (CKata.TabKata[1]=='P' && CKata.TabKata[2]=='L' && CKata.TabKata[3]=='A' && CKata.TabKata[4]=='C' && CKata.TabKata[5]=='E') {
                Place(&Q,&TMeja,&ruangan);
            }
            else if (CKata.TabKata[1]=='O' && CKata.TabKata[2]=='R' && CKata.TabKata[3]=='D' && CKata.TabKata[4]=='E' && CKata.TabKata[5]=='R') {
                order(p,&Order,ruangan,TMenu); 
            }
            else {
                printf("Masukan salah\n");
                InputUser();
            }
        }
        else if (CKata.Length==6) {
            if (CKata.TabKata[1]=='R' && CKata.TabKata[2]=='E' && CKata.TabKata[3]=='C' && CKata.TabKata[4]=='I' && CKata.TabKata[5]=='P' && CKata.TabKata[6]=='E') {
                PrintResep(Resep,TMenu,2,0);
            }
        }
        else {
            printf("Masukan salah\n");
            InputUser();
        }
        InputUser();
    }
}
