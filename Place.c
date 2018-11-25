//
//  Place.c
//  CobaResep
//
//  Created by Abiyyu Ismunandar on 11/25/18.
//  Copyright Â© 2018 Abiyyu Ismunandar. All rights reserved.
//

#include "Place.h"


//random belum coba
void mengantri(Queue *Q){
    infoqueue X;
    int i;
    if (rand()%20==7){    //merandom waktu bertambahnya antrian dengan peluang 1/20
        i=rand()%2;
        X.orang=2+i*2; //acak jumlah orang 2/4 orang
        X.kesabaran=30; //kesabaran 30
        Add(Q,X);
    }
}
void Place(player p,Queue *Q,TabMeja *T,MATRIKS *M){
    infoqueue Sampah;
    time_t t;
    int mja;
    boolean sudah;
    int i;
    srand((unsigned) time(&t));
    if ((Elmt(*M, X(p), Y(p))>='a')&&Elmt(*M, X(p), Y(p))<='j'){
		mja=Elmt(*M, X(p), Y(p))-'a'+1;
	    i=Head(*Q);
	    if (!Elmtterisi(*T,mja)){
	    	if(Elmtisi(*T,mja)==4){
	    		isimeja(*T,*M,mja,infoOrang(*Q,i),(rand()%25+25));
				Deli(*Q,i,&Sampah)
			}else if(Elmtisi(*T,mja)==2&&infoOrang(*Q,i)==2){
	    		isimeja(*T,*M,mja,infoOrang(*Q,i),(rand()%25+25));
				Deli(*Q,i,&Sampah)
			}else{
				if (i>Tail(*Q)){
					until=Tail(*Q)+MaxEl(*Q);
				}else{
					until=Tail(*Q);
				}
				sudah=false;
				while (until>=i&&!sudah){
					if (infoOrang(*Q,(i-1)%MaxEl(*Q)+1)==2){
						isimeja(*T,*M,mja,2,(rand()%25+25));
						sudah=true;
						Deli(*Q,(i-1)%MaxEl(*Q)+1,&Sampah)
					}else{
						i++;
					}
				}	
				if (!sudah){
					printf("Tidak ada tempat kosong, mohon bersabar\n");
				}
			}
		}else{
			printf("Meja Penuh\n");
		}
	}else{
		printf("Tidak ada meja\n");
	}
}
