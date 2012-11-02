//求一个元素在1个列表中出现时，它之前有多少个元素
//没找到到或者给定列表为空时，返回null
#include <stdio.h>
#define null 0 
int a[] ={5,6,7,8,9,10,2,45,10,12,6,8,7,5,10};
int b;
int *c = &b;
int *mystery(int x,int *y)
{
	int *z;
	if(y == null || (y - a >= sizeof(a)))
		return null;
	else
	{
		if(*y == x)
		{
			b = 0;
			return c;
		}
		else
		{
			z = mystery(x, ++y);
			
			if (z == 0)
			{
				return null;
			}
			else
			{
				b = *z + 1;
				return c;
			}
		}
	}
}
int main(int argc, char *argv[])
{
	int *temp;
	int find = 10;

	for(;;)
	{
		printf("please input the find-num:");
		scanf("%d",&find);
		if(find == -1){break;}
		temp = mystery(find,a);
		if(temp)
		{
			printf ("%d nums before \"%d\"\n",*temp,find);
		}
		else
		{
			printf ("nullL\n");
		}
	}
	printf ("will end\n");
	temp = mystery(10,NULL);
	if(temp)
	{
		printf ("%d nums before \"%d\"\n",*temp,find);
	}
	else
	{
		printf ("nullL\n");
	}
	printf ("end\n");
	return 0;
}
