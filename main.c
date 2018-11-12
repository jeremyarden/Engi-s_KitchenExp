#include <stdio.h>
#include "map.h"

int main()
{
  FILE *mantul;

  mantul = fopen("map.txt", "r");
  FileToMap(mantul);
  return 0;
}
