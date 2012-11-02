//test in cygwin
#include <stdarg.h>
#include <stdio.h>

struct st
{
    int a;
    char *b;
};



void print_st(struct st data)
{
    printf("st.a = %d, st.b = %s\n",data.a,data.b);
}
void print_st_p(struct st *data)
{
    printf("st.a = %d, st.b = %s\n",data->a,data->b);
}

//arg: void * ,int, double,char *,struct st *,struct st  

//下面两条已修改
//不能使用char   main.c:26:24: warning: ‘char’ is promoted to ‘int’ when passed through ‘...’
//不能用float    main.c:30:25: warning: ‘float’ is promoted to ‘double’ when passed through ‘...’
//               main.c:30:25: note: (so you should pass ‘double’ not ‘float’ to ‘va_arg’)
//               main.c:30:25: note: if this code is reached, the program will abort
int my_printf(void * n,...)
{
    va_list ap;
    va_start(ap,n);
    printf("int:%d\n",*(int *)n);

    printf("char:%d\n",va_arg(ap,int));
    printf("float:%f\n",va_arg(ap,double));
    printf("char *:%s\n",va_arg(ap,char *));
    print_st_p(va_arg(ap,struct st *));
    print_st(va_arg(ap,struct st));
}


int main()
{
    int a = 1000;
    char b = 200;   //这里的赋值已经溢出了
    float c = 3.14;
    char *d ="this is char *d\n";
    struct st st_data={5,"this is st-data.b\n"};
    struct st *e = &st_data;
    struct st f={69,"this is f.b\n"};

    my_printf((void *)&a,(int)b,(double)c,d,e,f,   a,b,c);
}


