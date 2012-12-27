//from http://bbs.csdn.net/topics/70518501

int	a=100;
int	b=a; /*出现编译错误,提示非法的初始化.*/
int	*c=&a; /*正确*/
int main()
{
  int	d=100;
  static int	e=100; /*正确*/
  static int	f=d; /*出现编译错误,提示非法的初始化.*/
  int	g=d;  /*正确*/
  static int	h=a;/*出现编译错误,提示非法的初始化.*/

  return 0;
}