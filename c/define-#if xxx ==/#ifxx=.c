#include <stdio.h>

//#define AI "ai"
#define AI ai

#if AI == "ai"   //错误：标识符“"ai"”在预处理表达式中无效
#error "will never come to there"
#endif

#if AI == ai    //this is right
#error "AI == ai or AI is not defined"
#endif

#if AI != 1
#error "AI != 1 or AI is not defined"
#endif

#if DI != 1
#error "DI != 1 or DI is not defined"
#endif

int main(int argc, char *argv[])
{
    printf("Hello, world\n");
    
    return 0;
}
