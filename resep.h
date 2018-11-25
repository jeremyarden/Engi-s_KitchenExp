#ifndef _RESEP_H
#define _RESEP_H

#include "bintree.h"
#include "mesinkar.h"
#include "mesinkata.h"

#define nMenu 50
typedef struct 
{
	Kata nama;      //Indeks bersesuaian dengan apa yang ada di posisi tree
	int harga;
}Menu;
typedef struct
{
    Menu TM[nMenu+1];
}TabMenu;

#define ElmtMenu(T,i) (T).TM[(i)]

void setTabMenu(TabMenu *T, BinTree MenuTree);
/*Mengisi TabMenu dengan isi file eksternal menu.txt*/
void makeResep(BinTree *Resep);
/*Pasangan untuk Prosedur MakeResepTree*/
void makeResepTree(BinTree *Resep);
/* Sebelum memakai prosedur, diharapkan mesin karakter sudah di start.
 * Membuat tree yang menyimpan nama-nama bahan makanan 
 * dan makanan dalam tipe bentukan Kata
 */

void PrintResep(BinTree T,TabMenu M,int h,int space);

#endif
