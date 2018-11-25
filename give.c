#include <stdio.h>
#include "boolean.h"
#include "arraymeja.h"
#include "matriks.h"
#include "map.h"
#include "stackt.c"
#include "order.c"
#include <stdlib.h>
boolean ceksekitar(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3);
void Give(Stack *food,TabOrd *order,int uang,player p,TabMeja *TM,MATRIKS *room1,MATRIKS *room2,MATRIKS *room3){ //T isinya nama makanan,harga
	infotype temp,sampah;
	IdxType idx;
	int price;
	if (ceksekitar(p,*room1,*room2,*room3)){
		Pop(food,&temp);
		//search masih belum bener
		if (SearchOrd(*order,temp.str)!=-999){
			if (p.room==1){
				kosongmeja(TM,room1,Search2(*order,temp.str));
			}else if (p.room==2){
				kosongmeja(TM,room2,Search2(*order,temp.str));
			}else if (p.room==3){
				kosongmeja(TM,room3,Search2(*order,temp.str));
			}		
		//set info queue order
			idx=SearchOrd(*order,temp.str);
			price=temp.harga;
			uang+=price;
			//hapus orderan
			Del(order,idx);
		}else{
			Push(food,temp);
			printf("Pesanan salah kirim\n");
		}
	}else{
		printf("Posisi salah\n");
	}
	if (p.room==1){
		TulisMATRIKS(*room1);
	}else if (p.room==2){
		TulisMATRIKS(*room2);
	}else if (p.room==3){
		TulisMATRIKS(*room3);
	}
}
boolean ceksekitar(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3){
	if (p.room==1){
		return ((room1[X(p)][Y(p)]>='a')&&(room1[X(p)][Y(p)]<='j'));
	}else if (p.room==2){
		return (room2[X(p)][Y(p)]>='a'&&room2[X(p)][Y(p)]<='j');
	}else if (p.room==3){
		return (room3[X(p)][Y(p)]>='a'&&room3[X(p)][Y(p)]<='j');
	}else{
		return false;
	}
}
