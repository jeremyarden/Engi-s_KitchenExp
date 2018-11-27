//
//  give.h
//  420
//
//  Created by Abiyyu Ismunandar on 11/26/18.
//  Copyright © 2018 Abiyyu Ismunandar. All rights reserved.
//

#ifndef give_h
#define give_h

#include "start.h"
#include <stdio.h>
#include "boolean.h"
#include "arraymeja.h"
#include "matriks.h"
#include "stackt.h"
#include "order.h"
#include <stdlib.h>

boolean ceksekitar(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3);
int mejaKe(player p,MATRIKS room1,MATRIKS room2,MATRIKS room3);
void Give(Stack *food,TabOrd *order,GameStatus * G,player p,TabMeja *TM,MATRIKS *room1,MATRIKS *room2,MATRIKS *room3);

#endif /* give_h */
