#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello, world\n");
    
    return 0;
}

#ifndef main
#error main is not defined!
#endif
