//#include "map.h"

//Harus bikin mesinkata coyy
#include "order.h"

boolean SearchMeja(TabOrd T, int Meja)
/*Mengembalikan True jika meja sudah diisi*/
{
    /*Kamus*/
    boolean found;
    int idx;
    /*Algoritma*/
    idx = 1; found = false;
    while(!found && idx<=Neff(T))
    {
        found = Meja(T,idx) == Meja;
        idx++;
    }
    return found;
}
IdxType SearchOrd (TabOrd T, Kata X){
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
            Found = IsKataEq(Food(T,i), X);
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
            ElmtOrd(*T, i) = ElmtOrd(*T, i+1);
        }
    }
}

void order(player p,TabOrd *T, MATRIKS M, Kata * arr_makanan){
    //matriks itu buat
    //Variables
    //Stack ord adalah stack yang berisi orderan
    //Matriks M adalah board ruangan
    int rand_ord,ordable; //adalah hasil random buat tau orderan
    time_t t; //biarin aja yg ini, pake buat random soalnye
    
    srand((unsigned) time(&t)); // buat random 
    //Algo
    //Cek apakah lu bisa ngambil order sekarang
    NearestCust(p, M, &ordable);
    if((ordable>=1) && (ordable<=9))
    {
        if(!SearchMeja(*T, ordable))
        {
            rand_ord = rand();//take order
            while((rand_ord < 0) || (rand_ord > 7))
            {
                rand_ord = rand();
            }
            //masukin order ke TabOrd
            if(Neff(*T) == 100){
                printf("Array order sudah penuh, silakan selesaikan order yang udah ada dulu\n");
            }
            else{
                Neff(*T)++;
                CopyKata(arr_makanan[rand_ord], &Food(*T,Neff(*T)));
                //ngisi Meja(T, Neff(T)) pake nomor meja
                Meja(*T, Neff(*T)) = ordable;
            }
        }
        else
        {
            printf("Anda tidak bisa mengambil order disini\n");
        }
    }
    else{
        printf("Anda tidak bisa mengambil order disini\n");
    }
}
