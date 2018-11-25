#include <stdio.h>
#include <math.h>
#include "point.h"        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
	POINT P;
	Absis(P)=X;
	Ordinat(P)=Y;
	return P;
}/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	return ((Absis(P1)==(Absis(P2)))&&(Ordinat(P1)==(Ordinat(P2))));
}
void Geser (POINT *P, int deltaX, int deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
	*P=MakePOINT(Absis(*P)+deltaX,Ordinat(*P)+deltaY); 
}
