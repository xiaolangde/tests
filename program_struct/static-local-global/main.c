//from http://bbs.csdn.net/topics/70518501

int	a=100;
int	b=a; /*���ֱ������,��ʾ�Ƿ��ĳ�ʼ��.*/
int	*c=&a; /*��ȷ*/
int main()
{
  int	d=100;
  static int	e=100; /*��ȷ*/
  static int	f=d; /*���ֱ������,��ʾ�Ƿ��ĳ�ʼ��.*/
  int	g=d;  /*��ȷ*/
  static int	h=a;/*���ֱ������,��ʾ�Ƿ��ĳ�ʼ��.*/

  return 0;
}