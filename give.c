#include "give.h"

boolean ceksekitar(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3);
int mejaKe(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3);
void Give(Stack *food,TabOrd *order,GameStatus * G,player p,TabMeja *TM,MATRIKS *room1,MATRIKS *room2,MATRIKS *room3){ //T isinya nama makanan,harga
	infotypeStack temp,sampah;
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
			 (*G).Money +=price;		//uang bertambah
			//hapus orderan
			DelOrd(order,idx);		//menghapus order indeks ke idx
		}else{
			Push(food,temp);
			printf("Pesanan salah kirim\n");
		}
	}else{
		printf("Posisi salah\n");	//posisi salah
	}
	if (Room(p)==1){
		TulisMATRIKS(*room1);
	}else if (Room(p)==2){
		TulisMATRIKS(*room2);
	}else if (Room(p)==3){
		TulisMATRIKS(*room3);
	}	//menulis matriks
}
boolean ceksekitar(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3){
//mengecek kondisi sekitar apakah sudah disamping pelanggan atau tidak
//true jika disebelah pelanggan
	if (Room(p)==1){
		return ((Elmt(room1, X(p), Y(p))>='a')&&Elmt(room1, X(p), Y(p))<='j');
	}else if (Room(p)==2){
		return (Elmt(room2, X(p), Y(p))>='a'&&Elmt(room2, X(p), Y(p))<='j');
	}else if (Room(p)==3){
		return (Elmt(room3, X(p), Y(p))>='a'&&Elmt(room3, X(p), Y(p))<='j');
	}else{
		return false;
	}
}
int mejaKe(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3){
//menggembalikan integer yang berupa angka meja pelanggan disebelah
	if (Room(p)==1){
		return Elmt(room1, X(p), Y(p))-'a'+1;
	}else if (Room(p)==2){
		return Elmt(room2, X(p), Y(p))-'a'+1;
	}else {
		return Elmt(room3, X(p), Y(p))-'a'+1;
	}
}
