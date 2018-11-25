/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */
#include "boolean.h"
#include <stdio.h>
#include "mesinkata.h"

Kata CKata;
boolean EndKata;

void SalinKataTab()
/* Mengakuisisi kata, menyimpan dalam CKata
 I.S. : CC adalah karakter pertama dari kata
 F.S. : CKata berisi kata yang sudah diakuisisi;
 CC = BLANK atau CC = MARK;
 CC adalah karakter sesudah karakter terakhir yang diakuisisi.
 Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i=1;
    CKata.TabKata[i]=CC;
    ADV();
    while((!EOP) && (CC!=',')&& (i<NMax)){
        i++;
        CKata.TabKata[i]=CC;
        ADV();
    }
    CKata.Length=i;
    if(!EOP){
        ADV();
    }
}

void STARTKATA()
/* I.S. : CC sembarang
 F.S. : EndKata = true, dan CC = MARK;
 atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
 CC karakter pertama sesudah karakter terakhir kata */
{
    char * namaFile = "/Users/abiyyuismunandar/Documents/AIstrukDat/Tubes/CobaResep/CobaResep/menu.txt";
    START(namaFile);
    if (EOP){
        EndKata=true;
    }else{
        EndKata=false;
        SalinKataTab();
    }
}

void InputUser()
/* Mengakuisisi Inputtan user kedalam CKata */
{
    /*Kamus*/
    char c;
    int i;
    /*Algoritma*/
    i = 1;
    do{
        scanf("%c",&c);
        CKata.TabKata[i] = c;
        i++;
    }while( c != '\n' && i<NMax);
    CKata.Length = i-2;
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
 F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
 CC adalah karakter pertama dari kata berikutnya, mungkin MARK
 Jika CC = MARK, EndKata = true.
 Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    if (EOP){
        EndKata=true;
    }else{
        SalinKataTab();
    }
}

void SalinKataTree()
/* Mengakuisisi kata, menyimpan dalam CKata
 I.S. : CC adalah karakter pertama dari kata
 F.S. : CKata berisi kata yang sudah diakuisisi;
 CC = '(' atau ')' atau CC = MARK;
 CC adalah karakter sesudah karakter terakhir yang diakuisisi.
 Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i=1;
    CKata.TabKata[i]=CC;
    ADV();
    while((!EOP) && (CC!='(') && (CC!=')') && (i<NMax))
    {
        i++;
        CKata.TabKata[i]=CC;
        ADV();
    }
    //Keluar ketika CC ( atau ) atau . 
    CKata.Length=i;
}

void CopyKata(Kata Kin, Kata * Kout)
{
    (*Kout).Length = Kin.Length;
    for(int i = 1;i<=Kin.Length;i++)
    {
        (*Kout).TabKata[i] = Kin.TabKata[i];
    }
}

boolean IsKataEq(Kata s1,Kata s2)
/*
 Mengirimkan true jika kedua string sama, yaitu semua character pada string sama
 */
{
    /*Kamus*/
    int i1,i2;
    boolean isEq;
    /*Algoritma*/
    isEq = true;
    i1 = 0;i2 = 0;
    if(s1.Length == s2.Length)
    {
        while(isEq && s1.TabKata[i1] != '\0' && s2.TabKata[i2] != '\0')
        {
            isEq = s1.TabKata[i1] == s2.TabKata[i2];
            i1++;i2++;
        }
        return isEq;
    } else
    {
        return false;
    } 
}

int KataToInt(Kata K)
{
	/*Kamus*/
	int num;
	/*Algoritma*/
	num = 0;
	for(int i = 1;i<= K.Length;i++)
	{
		num = num*10 + ((int)K.TabKata[i] - (int) '0');
	}
	return num;
}

void printKata(Kata K)
{
	for(int i = 1;i<= K.Length; i++)
	{
		printf("%c",K.TabKata[i]);
	}
}
