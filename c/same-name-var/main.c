#include <stdio.h>

extern int get_count(void);
int count=0;
int main(int argc,char *argv[])
{
	count = 10;
	printf("get_count()=%d\n",get_count());
	return 0;
}