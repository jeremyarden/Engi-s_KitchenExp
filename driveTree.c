#include "resep.h"
int main()
{
  /*Kamus*/
  BinTree T;
  TabMenu TM;
  makeResep(&T);
  setTabMenu(&TM);
  PrintResep(T,TM,2,0);
}
