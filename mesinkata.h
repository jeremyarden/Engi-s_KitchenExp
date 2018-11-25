/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '

typedef struct {
    char TabKata[51]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void STARTKATA();
/* I.S. : CC sembarang
 F.S. : EndKata = true, dan CC = MARK;
 atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
 CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
 F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
 CC adalah karakter pertama dari kata berikutnya, mungkin MARK
 Jika CC = MARK, EndKata = true.
 Proses : Akuisisi kata menggunakan procedure SalinKata */

void InputUser();
/* Mengakuisisi Inputtan user kedalam CKata */
void SalinKataTree();
/* Mengakuisisi kata, menyimpan dalam CKata
 I.S. : CC adalah karakter pertama dari kata
 F.S. : CKata berisi kata yang sudah diakuisisi;
 CC = BLANK atau CC = MARK;
 CC adalah karakter sesudah karakter terakhir yang diakuisisi.
 Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsKataEq(Kata s1,Kata s2);
/*
 Mengirimkan true jika kedua string sama, yaitu semua character pada string sama
 */
void CopyKata(Kata Kin, Kata * Kout);
/*Meng-copy isi Kin ke Kout*/
int KataToInt(Kata K);
/*Kata sudah dalam bentuk integer yang valid*/
void printKata(Kata K);
/*
 * Mem-print kata ke screen tanpa \n pada akhir kata
 */

#endif

