
#ifndef put_h
#define put_h

#include <stdio.h>
#include "mesinkata.h"
#include "resep.h"
#include "stackt.h"
#include "mapResto.h"

void Put(Stack *hand,Stack *food,BinTree *makanan,player p,MATRIKS kitchen,TabMenu TM);
boolean CekNampanAda(player p,MATRIKS kitchen);

#endif /* put_h */
