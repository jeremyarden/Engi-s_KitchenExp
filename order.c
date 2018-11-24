#include "map.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "stackt.h"

typedef int IdxType;

typedef struct {
    string food;
    int meja;
}OrdCust;

typedef struct {
	OrdCust TO[100]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabOrd;

#define Neff(T)   (T).Neff
#define TO(T)     (T).TO
#define Elmt(T,i) (T).TO[(i)]
#define Food(T,i) (T).TO[(i)].food
#define Meja(T,i) (T).TO[(i)].meja
//Harus bikin mesinkata coyy

IdxType SearchOrd (TabOrd T, string X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
    //KAMUS LOKAL
    IdxType i;
    boolean Found;

    //ALGORITMA LOKAL
    if(Neff(T) == 0){
        return IdxUndef;
    }
    else{
        i = 1;
        Found = false;

        while((!Found) & (i <= Neff(T))){
            Found = IsStrEq(Food(T,i), X);
            i++;
        }
        i--;
        if(Found){
            return i;
        }
        else{
            return IdxUndef;
        }
    }
}

void DelOrd(TabOrd *T, IdxType idx){
    /*Delete Elmt(T, idx), dan menjaga array TabOrd tetap kontigu*/
    if(idx == Neff(*T)){
        Neff(*T)--;
    }
    else{
        //timpa-timpaan dari index i sampe neff-1
        for(int i = idx; i < Neff(*T); i++){
            Elmt(*T, i) = Elmt(*T, i+1);
        }
    }
}

void order(TabOrd *T, Matriks M){ //matriks itu buat 
    //Variables
    //Stack ord adalah stack yang berisi orderan
    //Matriks M adalah board ruangan
    int rand_ord; //adalah hasil random buat tau orderan
    time_t t; //biarin aja yg ini, pake buat random soalnye
    
    srand((unsigned) time(&t)); // buat random
    //Algo
    //Cek apakah lu bisa ngambil order sekarang
    if((posisi player berada di penanda) & (meja bisa diambil orderannya)){
        
        rand_ord = random();//take order
        while((rand_ord < 0) || (rand_ord > 7)){
            rand_ord = random();
        }

        //tandain kalo meja ini gabisa ngambil order lagi
        
        //masukin order ke TabOrd
        if(Neff(*T) == 100){
            printf("Array order sudah penuh, silakan selesaikan order yang udah ada dulu");
        }
        else{
            Neff(*T)++;
            StrCopy(arr_makanan[rand_ord], &Nama(T,Neff(*T))); //ngambil nama orderan dari array_nama_orderan, terus salin ke Elemen terbelakang T
            //ngisi Meja(T, Neff(T)) pake nomor meja
        }

    }
    else{
        printf("Anda tidak bisa mengambil order disini");
    }
}
