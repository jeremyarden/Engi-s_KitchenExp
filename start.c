#include "start.h"
#include <stdio.h>

void SetStart(GameStatus * G)
/*Mengset status player menjadi default awal*/
{
    (*G).Life = 3;
    (*G).Money = 500;
    (*G).Time = MakeJAM(0, 0, 1);              //Agar di fungsi array meja hari tidak bertambah
}
void MakeEmptyTabName (TabName *T)
/*I.S T sembarang
 F.S  Terbentuk tabel nama yang belum diisi dengan kapasitas 20*/
{
    Neff(*T) = 0;
}

void FillTabName(TabName *T)
/*
 Mengisi TabName dengan username yang sudah pernah diisi
 */
{
    int i,count;
    
    i = 1;count = 0;
    STARTKATA("/Users/abiyyuismunandar/Documents/AIstrukDat/Tubes/4.19AM/Engi-s_KitchenExp-master/name.txt");
    while(!EndKata)
    {
        ElmtTN(*T, i) = CKata;
        i++;count++;
        ADVKATA();
    }
    Neff(*T) = count;
}

void SaveTabName(TabName T)
/*Menuliskan username yang ada di dalam TabName*/
{
    FILE *wr;
    
    wr = fopen("/Users/abiyyuismunandar/Documents/AIstrukDat/Tubes/4.19AM/Engi-s_KitchenExp-master/name.txt", "w");
    for(int i = 1;i<=Neff(T);i++)
    {
        for(int j = 1;j<=ElmtTN(T, i).Length;j++)
        {
            fprintf(wr, "%c",ElmtTN(T, i).TabKata[j]);
        }
        if(i < Neff(T))
        {
            fprintf(wr, ",");
        }
    }
    fprintf(wr, ".");
}
int NbElmtArr (TabName T)
/*Memberikan banyaknya nama dalam tabel nama*/
{
    return Neff(T);
}
int MaxNbEl (TabName T)
/*Mengirimkan kapasitas tabel nama*/
{
    return IdxMax;
}
IdxType GetFirstIdx (TabName T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}
IdxType GetLastIdx (TabName T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (IdxMin + NbElmtArr(T)) - 1;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyTName (TabName T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return NbElmtArr(T) == 0;
}

/* *** Test tabel penuh *** */

boolean IsTabNameFull (TabName T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return NbElmtArr(T) == MaxNbEl(T);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

boolean IsMemberName(TabName T, Kata Name)
/*
 Mengirimkan True jika nama sudah pernah terdaftar pada tabel nama
 */
{
    /*Kamus*/
    boolean Found;
    IdxType idx;
    /*Algoritma*/
    Found = false; idx = GetFirstIdx(T);
    while(!Found && (idx<=GetLastIdx(T)))
    {
        if(IsKataEq(ElmtTN(T, idx), Name))
        {
            Found = true;
        }
        idx++;
    }
    return Found;
}

IdxType IsMemberIdx(TabName T, Kata Name)
/*
 Mengirimkan True jika nama sudah pernah terdaftar pada tabel nama
 */
{
    /*Kamus*/
    boolean Found;
    IdxType idx;
    /*Algoritma*/
    Found = false; idx = GetFirstIdx(T);
    while(!Found && (idx<=GetLastIdx(T)))
    {
        if(IsKataEq(ElmtTN(T, idx), Name))
        {
            Found = true;
        }else
        {
            idx++;
        }
    }
    return (Found)? idx : IdxUndef;
}

void RegistName(TabName *T, boolean * isMember)
/*Menambahkan Neff+1, dan memasukkan username yg diinginkan. Jika nama
 sudah ter-register atau tabel sudah penuh, tabel tidak bertambah dan Neff tetap*/
{
    /*Kamus*/
    /*Algoritma*/
    printf("Masukkan Username Anda: ");
    InputUser();
    if(!(IsMemberName(*T, CKata)) && !(IsTabNameFull(*T)))
    {
        Neff(*T)++;
        CopyKata(CKata, &ElmtTN(*T, Neff(*T)));
        *isMember = false;
    } else
    {
        *isMember = true;
    }
}
