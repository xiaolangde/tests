#include <stdio.h>

//It can be compile by gcc
#define min(X,Y) ({typeof (X) x_ = (X);typeof (Y) y_ = (Y);(x_ < y_) ? x_ : y_; })

#define MIN(X,Y) ((X) > (Y) ? (Y) : (X))

int main(int argc, char *argv[])
{
	int a=3;
	int b=6;
	typeof (a) c;
	printf("a=%d,b=%d\n",a,b);
	c=min(a++,b++);
	printf("min(a++,b++) is %d\n",c);
	printf("a=%d,b=%d\n",a,b);
	printf("MIN(a++,b++) is %d\n",MIN(a++,b++));
	printf("a=%d,b=%d\n",a,b);
	return 0;
}
