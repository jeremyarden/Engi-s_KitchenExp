#ifndef order_h
#define order_h

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "resep.h"
#include "mesinkata.h"
#include "mapResto.h"
#include "matriks.h"
#include <math.h>
#include <time.h>
#include "stackt.h"

typedef int IdxType;
#define IdxUndef -999;
typedef struct {
    Kata food;
    int meja;
}OrdCust;

typedef struct {
    OrdCust TO[100]; /* memori tempat penyimpan elemen (container) */
    int Neff; /* >=0, banyaknya elemen efektif */
} TabOrd;

#define Neff(T)   (T).Neff
#define TO(T)     (T).TO
#define ElmtOrd(T,i) (T).TO[(i)]
#define Food(T,i) (T).TO[(i)].food
#define MejaOrd(T,i) (T).TO[(i)].meja

boolean SearchMeja(TabOrd T, int Meja);
/*Mengembalikan True jika meja sudah diisi*/
IdxType SearchOrd (TabOrd T, Kata X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */

void DelOrd(TabOrd *T, IdxType idx);
/*Delete Elmt(T, idx), dan menjaga array TabOrd tetap kontigu*/

void order(player p,TabOrd *T, MATRIKS M, TabMenu TM);
/*matriks itu buat
//Variables
//Stack ord adalah stack yang berisi orderan
//Matriks M adalah board ruangan
*/

void printOrder(TabOrd Ord);
// mengeprint order Ord
 #endif /* order_h */
