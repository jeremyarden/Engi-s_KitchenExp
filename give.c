#include <stdio.h>
#include <stdlib.h>
// bikin cmp
// Perbaiki search tabOrd, belum hapus orderan, ceksekitar belum sempurrna
void Give(Stack *food,TabOrd *order,int uang,player p,TabMeja *TM,MATRIKS *room1,*room2,*room3){ //T isinya nama makanan,harga
	infotype temp,sampah;
	IdxType idx;
	int price;
	if (ceksekitar(p)){
		Pop(food,&temp);
		//search masih belum bener
		if (Search2(*order,temp.str)!=-999){
			if (p.room==1){
				kosongmeja(TM,room1,Search2(*order,temp.str));
			}else if (p.room==2){
				kosongmeja(TM,room2,Search2(*order,temp.str));
			}else if (p.room==3){
				kosongmeja(TM,room3,Search2(*order,temp.str));
			}		
		//set info queue order
		//	idx=Search2 (T,temp);
			price=temp.harga;
			uang+=price;
			//hapus orderan
			//Del(order,);
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
ceksekitar(p){
	if (p.room==1){
		return (room1[p.x][p.y]>='a'&&room1[p.x][p.y]<='j');
	}else if (p.room==2){
		return (room2[p.x][p.y]>='a'&&room2[p.x][p.y]<='j');
	}else if (p.room==3){
		return (room3[p.x][p.y]>='a'&&room3[p.x][p.y]<='j');
	}else{
		return false;
	}
}
