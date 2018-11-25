#include <stdio.h>
#include "boolean.h"
#include "arraymeja.h"
#include "matriks.h"
#include "map.h"
#include "stackt.c"
#include "order.c"
#include <stdlib.h>
boolean ceksekitar(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3);
int mejaKe(p,room1,room2,room3);
void Give(Stack *food,TabOrd *order,int uang,player p,TabMeja *TM,MATRIKS *room1,MATRIKS *room2,MATRIKS *room3){ //T isinya nama makanan,harga
	infotype temp,sampah;
	IdxType idx;
	int price,table;
	if (ceksekitar(p,*room1,*room2,*room3)){	
		Pop(food,&temp);	//pop makanan
		//search masih belum bener
		table=mejaKe(p,*room1,*room2,*room3);
		if (SearchOrd(*order,temp.str)==table){		//jika pesanan benar		
			if (Room(p)==1){
				kosongmeja(TM,room1,SearchOrd(*order,temp.str));
			}else if (Room(p)==2){
				kosongmeja(TM,room2,SearchOrd(*order,temp.str));
			}else if (Room(p)==3){
				kosongmeja(TM,room3,SearchOrd(*order,temp.str));
			}		//kosongkan meja
		//set info queue order
			idx=SearchOrd(*order,temp.str);	//cari indeks yang akan dihapus di order
			price=temp.harga;	//harga
			uang+=price;		//uang bertambah
			//hapus orderan
			DelOrd(order,idx);		//menghapus order indeks ke idx
		}else{
			Push(food,temp);
			printf("Pesanan salah kirim\n");
		}
	}else{
		printf("Posisi salah\n");
	}
	if (Room(p)==1){
		TulisMATRIKS(*room1);
	}else if (Room(p)==2){
		TulisMATRIKS(*room2);
	}else if (Room(p)==3){
		TulisMATRIKS(*room3);
	}
}
boolean ceksekitar(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3){
	if (Room(p)==1){
		return ((room1[X(p)][Y(p)]>='a')&&(room1[X(p)][Y(p)]<='j'));
	}else if (Room(p)==2){
		return (room2[X(p)][Y(p)]>='a'&&room2[X(p)][Y(p)]<='j');
	}else if (Room(p)==3){
		return (room3[X(p)][Y(p)]>='a'&&room3[X(p)][Y(p)]<='j');
	}else{
		return false;
	}
}
int mejaKe(p,room1,room2,room3){
	if (Room(p)==1){
		return room1[X(p)][Y(p)]-'a'+1;
	}else if (Room(p)==2){
		return room2[X(p)][Y(p)]-'a'+1;
	}else if (Room(p)==3){
		return room3[X(p)][Y(p)]-'a'+1;
	}
}
