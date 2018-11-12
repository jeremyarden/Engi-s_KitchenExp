/* NIM/Nama : 13517101/Jeremy Arden Hartono
   Tanggal : 26 Oktober 2018
   Topik : ADT List Sirkuler
*/

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "listsirkuler.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
  return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
  First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  address P;

  P = (address) malloc (sizeof(ElmtList));

  if (P != Nil)
  {
    Info(P) = X;
    Next(P) = Nil;
  }

  return P;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
  free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
  address P;

  P = First(L);
  while (Info(P) != X && Next(P) != First(L))
  {
    P = Next(P);
  }
  if (Info(P) == X)
  {
    return P;
  }
  else
  {
    return Nil;
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
  address P, Last;

  P = Alokasi(X);
  if (P != Nil)
  {
    if (IsEmpty(*L))
    {
      First(*L) = P;
      Next(First(*L)) = First(*L);
    }
    else
    {
      Last = First(*L);
      while (Next(Last) != First(*L))
      {
        Last = Next(Last);
      }

      Next(Last) = P;
      Next(P) = First(*L);
      First(*L) = P;
    }
  }
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  address P, P1;

  P = Alokasi(X);
  if (P != Nil)
  {
    if (IsEmpty(*L))
    {
      InsVFirst(L, X);
    }
    else
    {
      P1 = First(*L);
      while (Next(P1) != First(*L))
      {
        P1 = Next(P1);
      }
      Next(P1) = P ;
      Next(P) = First(*L);
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
  address P, Last;

  *X = Info(First(*L));
  P = First(*L);
  if (Next(First(*L)) == First(*L))
  {
    First(*L) = Nil;
  }
  else
  {
    Last = First(*L);
    while (Next(Last) != First(*L))
    {
      Last = Next(Last);
    }

    Next(Last) = Next(P);
    First(*L) = Next(P);
    Next(P) = Nil;
  }
  Dealokasi(P);
}
void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  address Last, Prec;

  Last = First(*L);
  Prec = Nil;
  while(Next(Last) != First(*L))
  {
    Prec = Last;
    Last = Next(Last);
  }

  if (Prec == Nil)
  {
    First(*L) = Nil;
  }
  else
  {
    Next(Prec) = First(*L);
  }
  *X = Info(Last);

  Dealokasi(Last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
  address P1;

  if (IsEmpty(*L))
  {
    First(*L) = P;
    Next(First(*L)) = First(*L);
  }
  else
  {
    P1 = First(*L);
    while (Next(P1) != First(*L))
    {
      P1 = Next(P1);
    }

    Next(P1) = P;
    Next(P) = First(*L);
    First(*L) = P;
  }
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  address Last;

  if (IsEmpty(*L))
  {
    InsertFirst(L, P);
  }
  else
  {
    Last = First(*L);
    while (Next(Last) != First(*L))
    {
      Last = Next(Last);
    }

    Next(Last) = P;
    Next(P) = First(*L);
  }
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  address Last;

  *P = First(*L);
  if (Next(First(*L)) == First(*L))
  {
    First(*L) = Nil;
  }
  else
  {
    Last = First(*L);
    while (Next(Last) != First(*L))
    {
      Last = Next(Last);
    }

    Next(Last) = Next(*P);
    First(*L) = Next(*P);
    Next(*P) = Nil;
  }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
  address Last, Prec;

  Last = First(*L);
  Prec = Nil;
  while (Next(Last) != First(*L))
  {
    Prec = Last;
    Last = Next(Last);
  }

  *P = Last;
  if (Prec == Nil)
  {
    First(*L) = Nil;
  }
  else
  {
    Next(Prec) = First(*L);
  }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  *Pdel = Next(Prec);
  Next(Prec) = Next(*Pdel);
  Next(*Pdel) = Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
  address P, P1, Last;

  P = Search(*L, X);

  if (P != Nil)
  {
    if (P == First(*L) && Next(P) == First(*L))
    {
      First(*L) = Nil;
      Next(P) = Nil;
    }
    else if (P == First(*L) && Next(P) != First(*L))
    {
      Last = First(*L);
      while (Next(Last) != First(*L))
      {
        Last = Next(Last);
      }

      Next(Last) = Next(P);
      First(*L) = Next(P);
      Next(P) = Nil;
    }
    else if (P != First(*L))
    {
      P1 = First(*L);
      while (Next(P1) != P)
      {
        P1 = Next(P1);
      }

      Next(P1) = Next(P);
      Next(P) = Nil;
    }

    Dealokasi(P);
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  address P;

  P = First(L);
  if (IsEmpty(L))
  {
    printf("[]");
  }
  else if(Next(P) == First(L))
  {
    printf("[%d]", Info(P));
  }
  else
  {
    printf("[");
    while(Next(P) != First(L))
    {
      printf("%d,", Info(P));
      P = Next(P);
    }
    printf("%d]", Info(P));
  }
}
