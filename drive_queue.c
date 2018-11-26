#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
int main(){
	Queue Q;
	infoqueue X,Y,A,Z;
	QueueCreateEmpty(&Q,10);
	X.kesabaran=30;
	X.orang=2;
	Add(&Q,X);
	Z.kesabaran=20;
	Z.orang=2;
	Add(&Q,Z);
	A.kesabaran=20;
	A.orang=4;
	Add(&Q,A);
	printQueue(Q);
	Del(&Q,&Y);
	printQueue(Q);
}
