/*����*/#/*һ��*/include/*�Ϸ���*/<stdio.h>/*Ԥ����*//*ָ*//*��*/
//# include <stdio.h    >
int/*...*/i;
char* s1="abcdefgh //hijklmn";

//Is it a\
valid comment?

//in/*��*/t j;     // ע�ͱ��滻���˿ո� ��˴˾��в�ͨ

//����һ���Ϸ���\
����ע��
/\
/����һ���Ϸ��ĵ���ע��

#def\
ine MAC\
 32 //����һ���Ϸ���\
�궨��


cha\
r* s="����һ���Ϸ���\\
n �ַ���";

#define _X86
#ifdef _X86
#pragma message("_X86 macro activated!")
#else
#error _X86 macro is not activated!
#endif
#define SUM(x,y) ((x)+(y))

#line 35 "zhushi.c"  //ָ���ļ��� �кţ����Խ����ʾ����һ�п�ʼΪ35��

int main(void)
{
	int x,y,*p=&x;
	x=MAC;				//��֤MAC�궨��

	y=0x01<<2+3;		// "+"���ȼ��� "<<" ��		
	// x<<=-2; x<<=40;   //��λ�������ݿ�Ȼ�Ϊ�����Ǵ����
	x^=y;				//��x,y����
	y^=x;
	x^=y;
	
	printf("%s\n%s\n%d\n\102\x0a",s,s1,x); //��֤ǰ�涨����ַ��� and ������� and \102 \x0a ת���ַ�
	y = x/ *p;							//   / *д��һ��ͳ���ע��
	
	printf("SUM(5,5)");    // " " ����ı���Ϊ���ַ���

	printf("%s:%s:%d isSTDC?:%d\n",__FILE__,__FUNCTION__,__LINE__,__STDC__);
	return 1;
}