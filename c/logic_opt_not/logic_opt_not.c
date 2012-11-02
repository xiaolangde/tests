#include "stdio.h"

#define HIGH 0
#define LOW  !HIGH

int main(void)
{
	int a,b,c,d;
	a = !HIGH;
	b = !LOW;
	c = HIGH ^ (!0x3);
	d = !(-3);
	printf("a=%d b=%d c=%d d=%d",a,b,c,d);
}