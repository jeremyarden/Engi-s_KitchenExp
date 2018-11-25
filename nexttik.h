//
//  nexttik.h
//  CobaResep
//
//  Created by Abiyyu Ismunandar on 11/25/18.
//  Copyright © 2018 Abiyyu Ismunandar. All rights reserved.
//

#ifndef nexttik_h
#define nexttik_h

#include <stdio.h>
#include <stdlib.h>
#include "jam.h"
#include "order.h"
#include "queue.h"
#include "Place.h"
#include "matriks.h"
#include "arraymeja.h"
#include "mapResto.h"

void NextTik(TabOrd *T,JAM *J,int *day,TabMeja *Meja,Queue *antrean,int *kredibilitas,boolean *exit,player p,MATRIKS *room1,MATRIKS * room2,MATRIKS * room3);

#endif /* nexttik_h */
