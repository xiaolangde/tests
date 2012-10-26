#include "static.h"
#include "stdio.h"

//static void init(int a)
//{
//  static_data = a +2;
//}

void init2(void)
{
  init(200);
  printf("c2.c init(200)\n");
}
int call2(void)
{
  return static_data;
}
