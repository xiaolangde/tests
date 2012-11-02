#include <stdio.h>
#include <stdlib.h>
void digui()
{
	static unsigned int i=1;		//局部变量多少（大小）影响次数,多定义个a变量，结果不同
	int a=i;
	malloc(10240);
	printf("第a=%d,i=%d次调用！\n",a,i++);  //不同编译器递归次数不一样，估计是栈空间用完了就....
	digui();
}
int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	digui();
	return -6;	//使用了递归溢出后 echo %errorlevel% 不是-6 而是其它，证明 进程就崩溃了
}
