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
    boolean cektree=false;
    int cnt=0;
    BinTree P;
    if (CekNampanAda(p,kitchen)&&(!StackIsEmpty(*hand))){
        Pop(hand,&temp);
        if (IsKataEq(temp.str, TM.TM[Akar(*makanan)].nama)){
            P = *makanan;
            while (!StackIsEmpty(*hand)&&(!cektree)){
                Pop(hand,&temp);
                if (Right(P)!=Nil){
                    if (IsKataEq(TM.TM[Akar(Right(P))].nama, temp.str)){
                        P=Right(P);
                    }
                }else if (Left(P)!=Nil){
                    if (IsKataEq(TM.TM[Akar(Left(P))].nama, temp.str)){
                        P=Left(P);
                    }
                }else{
                    cektree=true;
                }
            }
        }
        if (!cektree&&StackIsEmpty(*hand)){
            P = *makanan;
            temp.str = TM.TM[Akar(Left(P))].nama;
            temp.harga = TM.TM[Akar(Left(P))].harga;
            Push(food,temp);
        }else{
            printf("Masakan Gagal\n");
        }
    }else if(StackIsEmpty(*hand)){
        printf("tidak ada bahan\n");
    }else{
        printf("Nampan Tidak ada\n");
    }
    TulisMATRIKS(kitchen);
}

boolean CekNampanAda(player p,MATRIKS kitchen){
    return (p.room==4) && (Elmt(kitchen, X(p), Y(p)) == 'R');
}

