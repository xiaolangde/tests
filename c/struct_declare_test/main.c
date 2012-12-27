#include <stdio.h>
#include "ext_struct.h"

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 2;
    struct ext_struct *c = ext_struct_malloc();
    
    //printf("sizeof(struct ext_struct) = %d\n",sizeof(struct ext_struct));
    set_a(c, a);
    printf("last c.a = %d\n", set_a(c, b));
    printf("last c.a = %d\n", set_a(c, a));
    //pause();
    return 0;
}
