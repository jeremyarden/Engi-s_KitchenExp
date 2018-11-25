#include "boolean.h"
#include "stackt.h"
#include <stdio.h>
#include <stdlib.h>
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void StackCreateEmpty (Stack *S) 
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S)=NilStack;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean StackIsEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return(Top(S)==NilStack);
}
boolean StackIsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return(Top(S)==MaxEl);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypeStack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)+=1;
    InfoTop(*S)=X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypeStack* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X=InfoTop(*S);
    Top(*S)-=1;
}
void balik(Stack *s1,Stack *s2){ //balik stack s1 ke s2
	infotypeStack tmp;
	
	StackCreateEmpty(s2);
	while (!StackIsEmpty(*s1)){
		Pop(s1,&tmp);
		Push(s2,tmp);
	}
}
void printStack(Stack *s){
	Stack stmp;
	int i;
	infotypeStack tmp;
	StackCreateEmpty(&stmp);
	while (!StackIsEmpty(*s)){
		Pop(s,&tmp);
		for(i=1;i<=tmp.str.Length;i++){
			printf("%c",InfoTop(*s).str.TabKata[i]);
		}
		printf("\n");
		Push(&stmp,tmp);
	}	
    balik(&stmp,s);
}
