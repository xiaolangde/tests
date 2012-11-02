/*这是*/#/*一条*/include/*合法的*/<stdio.h>/*预处理*//*指*//*令*/
//# include <stdio.h    >
int/*...*/i;
char* s1="abcdefgh //hijklmn";

//Is it a\
valid comment?

//in/*…*/t j;     // 注释被替换成了空格 因此此句行不通

//这是一条合法的\
单行注释
/\
/这是一条合法的单行注释

#def\
ine MAC\
 32 //这是一条合法的\
宏定义


cha\
r* s="这是一个合法的\\
n 字符串";

#define _X86
#ifdef _X86
#pragma message("_X86 macro activated!")
#else
#error _X86 macro is not activated!
#endif
#define SUM(x,y) ((x)+(y))

#line 35 "zhushi.c"  //指定文件名 行号（测试结果表示：下一行开始为35）

int main(void)
{
	int x,y,*p=&x;
	x=MAC;				//验证MAC宏定义

	y=0x01<<2+3;		// "+"优先级比 "<<" 高		
	// x<<=-2; x<<=40;   //移位超出数据宽度或为负都是错误的
	x^=y;				//将x,y交换
	y^=x;
	x^=y;
	
	printf("%s\n%s\n%d\n\102\x0a",s,s1,x); //验证前面定义的字符串 and 交换结果 and \102 \x0a 转义字符
	y = x/ *p;							//   / *写在一起就成了注释
	
	printf("SUM(5,5)");    // " " 里面的被认为是字符串

	printf("%s:%s:%d isSTDC?:%d\n",__FILE__,__FUNCTION__,__LINE__,__STDC__);
	return 1;
}