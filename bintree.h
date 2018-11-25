/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_H_
#define _BINTREE_H_

/* Modul lain yang digunakan : */
#include "boolean.h"
#include "mesinkata.h"


/* *** Definisi Type Pohon Biner *** */
#define Nil NULL
typedef struct treeNode *addrNode;
typedef int infotypeTree;
typedef struct treeNode
{
  infotypeTree info;
  addrNode left;
  addrNode right;
} NodeTree;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

/* *** Konstruktor *** */
BinTree Tree(infotypeTree Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotypeTree Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */


/* Manajemen Memory */
addrNode AlokNodeTree(infotypeTree X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

void PrintTree(BinTree P, int h);
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotypeTree X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P);
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, infotypeTree X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Tinggi(BinTree P);
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */


#endif
