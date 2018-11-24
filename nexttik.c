#include <stdio.h>
#include <stdlib.h>
#include "jam.c"
#include "stackt.c"
//jadi nexttik nambah waktu sama ngurangi kesabaran sekaligus klo udah gak sabar hapus pelanggan sambil kredibilitas ngurang
//Queue masih biasa belum prio
void NextTik(JAM *J,int *day,TabMeja *Meja,Queue *antrean,int *kredibilitas,boolean *exit,player p,MATRIKS *room1,*room2,*room3){
	long tik,i;
	boolean found=false;
	infotype sampah;
	*J=NextDetik(*J);
	if (Hour(*J)==0&&Minute(*J)==0&&Second(*J)==0){			//nambah hari jika sebelumnya 23.59.59
		*day++;
	}
	//amtrian, keesabaran
	//kurangin kesabaran sama kredibilitas
	for(i=0;i<=9;i++){
		if (ElmtTerisi(*Meja,i)){
			ElmtKesabaran(*Meja,i)--;
			if (ElmtKesabaran(*Meja,i)==0){
				if (Elmtroom(*Meja,i)==1){
					kosongmeja(TM,room1,i);
				}else if (Elmtroom(*Meja,i)==2){
					kosongmeja(TM,room2,i);
				}else if (Elmtroom(*Meja,i)==3){
					kosongmeja(TM,room3,i);
				}
				*kredibilitas--;
			}
		}
	}
	for(i=Head(*antrean);i<=Tail(*antrean);i++){
		*antrean.T[i].kesabaran--;
	}
	while (!QueueIsEmpty(*antrean)&&(!found)){
		if (InfoHead(*antrean).kesabaran==0){
			Del(antrean, &sampah)
			*kredibilitas--;
		}
		else{
			found=true;
		}
	}
	if (*kredibilitas==0){
		exit=true;
	}
}
