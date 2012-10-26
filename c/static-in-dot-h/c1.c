#include "static.h"
#include "stdio.h"

//static void init(int a)
//{
//  static_data = a+1;
//}

void init1(void)
{
  init(100);
  printf("c1.c init(100)\n");
}
int call1(void)
{
  return static_data;
}
