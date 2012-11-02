#include <stdio.h>

#if COMPILER_C99
	#define COUNT_PARMS2(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _, ...) _
	#define COUNT_PARMS(...) \
			COUNT_PARMS2(11 , ## __VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

	/**
	 * usage:
	 * \code
	 * #define foo_init(...) PP_CAT(foo_init_, COUNT_PARMS(__VA_ARGS__)) (__VA_ARGS__)
	 * \endcode
	 */

#else
	#define COUNT_PARMS2(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _, ...) _
	#define COUNT_PARMS(args...) \
			COUNT_PARMS2(11 , ## args, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

	/**
	 * usage:
	 * \code
	 * #define foo_init(args...) PP_CAT(foo_init_, COUNT_PARMS(args)) (args)
	 * \endcode
	 */

#endif

#define PP_CAT(x,y)         PP_CAT__(x,y)
#define PP_CAT__(x,y)       x ## y

#if COMPILER_C99
	//#define add(...) PP_CAT(add ## _,COUNT_PARMS(__VA_ARGS__)) (__VA_ARGS__)
#else
	#define add(args...) PP_CAT(add_,COUNT_PARMS(args)) (args)
#endif

int add_3(int,int,int);
int add_2(int,int);
int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	printf("add(1,2)=%d\n",add(1,2));
	printf("add(1,2,3)=%d\n",add(1,2,3));
	return 0;
}

int add_2(int a,int b)
{
	return a+b;
}
int add_3(int a,int b,int c)
{
	return a+b+c;
}