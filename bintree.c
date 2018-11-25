#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

/* *** Konstruktor *** */
BinTree Tree(infotypeTree Akar, BinTree L, BinTree R){
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
    BinTree T = AlokNodeTree(Akar);
    if(T != Nil){
      Left(T) = L;
      Right(T) = R;
    }
    return T;
}
void MakeTree(infotypeTree Akar, BinTree L, BinTree R, BinTree *P){
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
    BinTree T = AlokNodeTree(Akar);
    if(T != Nil){
      Left(T) = L;
      Right(T) = R;
    }
    *P = T;  
}

/* Manajemen Memory */
addrNode AlokNodeTree(infotypeTree X){
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    addrNode P = (addrNode) malloc (sizeof(infotypeTree));
    if (P != Nil){
        Akar(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}
void DealokNode(addrNode P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
    free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
/* Mengirimkan true jika P adalah pohon biner kosong */
    return P == Nil;
}
boolean IsTreeOneElmt(BinTree P){
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
    return ((P != Nil) && (Left(P) == Nil) && (Right(P) == Nil));
}
boolean IsUnerLeft(BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
  return ((!IsTreeEmpty(P)) && (Left(P) != Nil) && (Right(P) == Nil));   
}
boolean IsUnerRight(BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
  return ((!IsTreeEmpty(P)) && (IsTreeEmpty(Left(P))) && (!IsTreeEmpty(Right(P))));
}
boolean IsBiner(BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
    return ((!IsTreeEmpty(P)) && (!IsTreeEmpty(Left(P))) && (!IsTreeEmpty(Right(P))));
}

void PrintTreeMod(BinTree P, int h, int space)
{
  if (P != Nil){
    for(int i = 0; i < space ; i++){
      printf(" ");
    }
    printf("%d\n",Akar(P));
    PrintTreeMod(Left(P), h, space+h);
    PrintTreeMod(Right(P), h, space+h);
  }
}
void PrintTree(BinTree P, int h)
{
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
  PrintTreeMod(P, h, 0);
}
/* *** Searching *** */
boolean SearchTree(BinTree P, infotypeTree X)
{
/* Mengirimkan true jika ada node dari P yang bernilai X */
  if(IsTreeEmpty(P)){
    return false;
  }
  else if(Akar(P)==X)
  {
    return true;
  }
  else{
    return (SearchTree(Left(P), X) || SearchTree(Right(P), X));
  }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
/* Mengirimkan banyaknya elemen (node) pohon biner P */
  if(IsTreeEmpty(P)){
    return 0;
  }
  else{
    return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
  }
}
int NbDaun(BinTree P){
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
  if(IsTreeOneElmt(P)){
    return 1;
  }
  else{
    if(IsUnerLeft(P)) return NbDaun(Left(P));
    else if(IsUnerRight(P)) return NbDaun(Right(P));
    else return NbDaun(Left(P)) + NbDaun(Right(P));
  }
}
boolean IsSkewLeft(BinTree P){
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
  if(P == Nil){
      return true;
    }
    else{
      return IsSkewLeft(Left(P)) && (Right(P) == Nil);
    }
}
boolean IsSkewRight(BinTree P){
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
  if(P == Nil){
      return true;
    }
    else{
      return IsSkewRight(Right(P)) && (Left(P) == Nil);
    }
}
int Level(BinTree P, infotypeTree X){
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
  if(Akar(P)==X){
    return 1;
  }
  else{
    if(SearchTree(Left(P), X)){
      return 1 + Level(Left(P), X);
    }
    else {
      return 1 + Level(Right(P), X);
    }
  }
}
int Tinggi(BinTree P){
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
  //gajelas woyyyyyy
  if(IsTreeEmpty(P)){
    return 0;
  }
  else{
    if(Tinggi(Left(P)) > Tinggi(Right(P))){
      return 1 + Tinggi(Left(P));
    }
    else{
      return 1 + Tinggi(Right(P));
    }
  }
}
