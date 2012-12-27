#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 0x12345678;
    
    printf("a = %x, (char)a = %x, (unsigned char)a = %x\n",a, (char)a, (unsigned char)a);
    
    return 0;
}
