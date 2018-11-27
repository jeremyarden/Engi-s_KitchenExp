
/*
 start.h
 Header untuk bagian start game
 */


#ifndef start_h
#define start_h

#include "boolean.h"
#include "mesinkata.h"
#include "jam.h"

#define IdxMax 20
#define IdxMin 1
#define IdxUndef -999
#define MaxStringLen 12

typedef int IdxType;


typedef struct{
    long Money;         //Point
    int Life;           //Integritas Player
    JAM Time;           //Waktu yang telah berlalu di game
} GameStatus;

typedef struct {
    Kata TN[IdxMax+1];
    int Neff;
} TabName;  /*Array yg memegang username yang sudah masuk
             Array selalu rapat kiri
             */

#define Neff(T)   (T).Neff
#define TI(T)     (T).TN
#define ElmtTN(T,i) (T).TN[(i)]

void SetStart(GameStatus * G);
/*Mengset status player menjadi default awal*/

void MakeEmptyTabName (TabName *T);
/*I.S T sembarang
 F.S  Terbentuk tabel nama yang belum diisi dengan kapasitas 20*/

void FillTabName(TabName *T);
/*
 Mengisi TabName dengan username yang sudah pernah diisi
 */

void SaveTabName(TabName T);
/*Menuliskan username yang ada di dalam TabName*/

int NbElmtArr (TabName T);
/*Memberikan banyaknya nama dalam tabel nama*/

int MaxNbEl (TabName T);
/*Mengirimkan kapasitas tabel nama*/

IdxType GetFirstIdx (TabName T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabName T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyTName (TabName T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

boolean IsTabNameFull (TabName T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

boolean IsMemberName(TabName T, Kata Name);
/*
 Mengirimkan True jika nama sudah pernah terdaftar pada tabel nama
 */

IdxType IsMemberIdx(TabName T, Kata Name);
/*
 Mengirimkan Idx jika nama sudah pernah terdaftar pada tabel nama
 */

void RegistName(TabName *T,boolean * isMember);
/*Menambahkan Neff+1, dan memasukkan username yg diinginkan, jika nama
 sudah ter-register, tabel tidak bertambah dan Neff tetap*/


#endif /* start_h */
