#include <stdlib.h>
#include <stdio.h>
#include "resep.h"
//L

void setTabMenu(TabMenu *T, BinTree MenuTree)
/*Mengisi TabMenu dengan isi file eksternal menu.txt*/
{
    int i;
    
    i = 1;
    STARTKATA();
    while(!EndKata)
    {
        ElmtMenu(*T, i).nama = CKata;
        ElmtMenu(*T, i).harga = Level(MenuTree, i)*100;
        i++;
        ADVKATA();
    }
}
void makeResep(BinTree *Resep)
{
	START("/Users/abiyyuismunandar/Documents/AIstrukDat/Tubes/Tubes/resep.txt");
	//printf("%c",CC);
    makeResepTree(Resep);
}

void makeResepTree(BinTree *Resep)
{
	/*Kamus lokal*/
	int currNum;
	/*Algoritma*/
	ADV();		//Yang di window antara ) atau alfabet, saat start di window adalah (
    //printf("After ADV()before if %c\n",CC);
	if(CC == ')')
	{
		(*Resep) = Nil;
	}
	else //Jika alfabet yand sedang dibaca
	{
		SalinKataTree();	//Keluar dari SalinKata window CC '(' , ')', atau MARK
		currNum = KataToInt(CKata);

		*Resep = Tree(currNum,Nil,Nil);
        //printf("After ADV(): %c\n",CC);
		makeResepTree(&Left(*Resep));
		makeResepTree(&Right(*Resep));
	}
    ADV();
}

void PrintResep(BinTree T,TabMenu M,int h,int space)
/*I.S: space harus 0
 */
{
    if (T != Nil){
        for(int i = 0; i < space ; i++){
            printf(" ");
        }
        printKata(ElmtMenu(M, Akar(T)).nama);
        printf("\n");
        PrintResep(Left(T),M, h, space+h);
        PrintResep(Right(T),M, h, space+h);
    }
}
