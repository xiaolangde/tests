#include "stdio.h"

#include "static.h"

extern void init1();
extern void init2();
extern int call1();
extern int call2();
int main(void)
{
  printf("call1()return %d\n",call1());
  printf("call2()return %d\n",call2());  
  init1();
  init2();
  printf("call1()return %d\n",call1());
  printf("call2()return %d\n",call2());
  printf("call1()return %d\n",call1());
  printf("call2()return %d\n",call2());
}

