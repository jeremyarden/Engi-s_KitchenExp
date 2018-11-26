#include "boolean.h"
#include "jam.c"
#include <stdlib.h>
#include <stdio.h>
int main(){
	long a;
	JAM X;
	Hour(X)=1;
	Minute(X)=2;
	Second(X)=2;
	TulisJAM (X);
	a=JAMToDetik (X);
	NextDetik(X);
	printf("%ld\n",a);
}
