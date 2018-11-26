#include <stdlib.h>
#include <stdio.h>
#include "stackt.c"
int main(){
	Stack Q;
	infotypeStack X,Y,A,Z;
	StackCreateEmpty(&Q);
	X.str.TabKata[1]='c';
	X.harga=2;
	Push(&Q,X);
	Z.str.TabKata[1]='2';
	Z.harga=5;
	Push(&Q,Z);
	printStack(Q);
	Pop(&Q,&Y);
	printStack(Q);
}
