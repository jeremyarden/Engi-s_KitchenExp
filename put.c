//
//  put.c
//  CobaResep
//
//  Created by Abiyyu Ismunandar on 11/25/18.
//  Copyright © 2018 Abiyyu Ismunandar. All rights reserved.
//

#include "put.h"

#include <stdio.h>
#include <stdlib.h>

void Put(Stack *hand,Stack *food,BinTree *makanan,player p,MATRIKS kitchen,TabMenu TM)
{
    infotypeStack temp;
    Stack save;
    boolean cektree=false;
    int cnt=0;
    BinTree P;
    balik(hand,&save);   //stack dibalik dulu karena mengambilnya dari paling atas dalam tree
    if (CekNampanAda(p,kitchen)&&(!StackIsEmpty(save))){   //cek nampan dan save apakah kosong
        Pop(&save,&temp);    //klo tidak kosong ambil nilai
        if (IsKataEq(temp.str, TM.TM[Akar(*makanan)].nama)){    //cek apakah sama
            P = *makanan;       
            while (!StackIsEmpty(save)&&(!cektree)){           //cari hingga salah bahan atau hingga stack save habis
                Pop(&save,&temp);
                if (Right(P)!=Nil){         //cek bagian kanan
                    if (IsKataEq(TM.TM[Akar(Right(P))].nama, temp.str)){   
                        P=Right(P);
                    }
                }else if (Left(P)!=Nil){    //cek bagian kiri
                    if (IsKataEq(TM.TM[Akar(Left(P))].nama, temp.str)){
                        P=Left(P);
                    }
                }else{          //kalau gagal
                    cektree=true;
                }
            }
        }
        if (!cektree&&StackIsEmpty(save)){ //jika stack kosong dan belum menemukan salah bahan
            temp.str = TM.TM[Akar(Left(P))].nama;
            temp.harga = TM.TM[Akar(Left(P))].harga;
            Push(food,temp);
        }else{
            printf("Masakan Gagal\n");
        }
    }else if(StackIsEmpty(save)){
        printf("tidak ada bahan\n");
    }else{
        printf("Nampan Tidak ada\n");
    }
    TulisMATRIKS(kitchen);
}

boolean CekNampanAda(player p,MATRIKS kitchen){
    return (p.room==4) && (Elmt(kitchen, X(p), Y(p)) == 'R');
}

