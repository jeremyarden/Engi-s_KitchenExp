#include "arraymeja.c"
#include <stdio.h>
#include <stdlib.h>
int main(){
	TabMeja T;
	MakeMeja (&T);
	printf("%d\n",Elmtroom(T,4));
	printf("%d\n",NbElmtTabMeja (T));
}
