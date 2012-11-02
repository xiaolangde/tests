#error "cannot do this£¡"

#include <stdio.h>

#define MAKE_MACO(name,value) #define name (value + 1)

MAKE_MACO(PI,3.14)

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
