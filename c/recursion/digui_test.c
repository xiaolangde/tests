#include <stdio.h>
#include <stdlib.h>
void digui()
{
	static unsigned int i=1;		//�ֲ��������٣���С��Ӱ�����,�ඨ���a�����������ͬ
	int a=i;
	malloc(10240);
	printf("��a=%d,i=%d�ε��ã�\n",a,i++);  //��ͬ�������ݹ������һ����������ջ�ռ������˾�....
	digui();
}
int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	digui();
	return -6;	//ʹ���˵ݹ������ echo %errorlevel% ����-6 ����������֤�� ���̾ͱ�����
}
