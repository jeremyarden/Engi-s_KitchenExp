#include <stdio.h>
#include <stdlib.h>
//belom bikin adt tree
// bikin cmp bandingin string
void Put(Stack *hand,Stack *food,BinTree *makanan,player p,MATRIKS kitchen){
	infotype temp;
	boolean cektree=false;
	int cnt=0;
	addrNode P;
	if (CekNampanAda(p)&&(!StackIsEmpty(hand))){
		Pop(hand,&temp);
		if (cmp(temp.str,Akar(*makanan))){
			P=*makanan;
			while (!StackIsEmpty(hand)&&(!cektree)){
				Pop(hand,&temp);
				if (Right(P)!=Nil){
					if (cmp(Akar(Right(P)),temp.str)){
						P=Right(P);
					}
				}else if (Left(P)!=Nil){
					if (cmp(Akar(Left(P)),temp.str)){
						P=Left(P);
					}
				}else{
					cektree=true;
				}
			}
		}
		if (!cektree&&StackIsEmpty(hand)){
			temp.harga=Level(P,Akar(Left(P)))*10000;
			temp.str=Akar(Left(P));
			Push(food,Akar(Left(P)));
		}else{
			printf("Masakan Gagal\n");
		}
	}else if(StackIsEmpty(hand)){
		printf("tidak ada bahan\n")
	}else{
		printf("Nampan Tidak ada\n");
	}
	TulisMATRIKS(kitchen);
}
CekNampanAda(p){
	return (p.room==4&&kitchen[p.x][p.y]=="R");
}
