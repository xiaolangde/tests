#include <stdio.h>
#include<time.h>


/*CL-USER> (defun show-squares (start end)
	   (do ((i start (+ i 1)))
	       ((> i end) 'ok)
	     (format t "~A ~A~%" i (* i i))))
SHOW-SQUARES
CL-USER> (time (show-squares 1 100000))*/

void show_squares(long start, long end)
{
	long i;
	for(i = start; i<=end; i++){
		printf("%ld %ld\n", i, i*i);
	}
}
int main(int argc, char *argv[])
{
	clock_t start,end,time;
	start=clock();
	
	//printf("sizeof(int)=%d,sizeof(long)=%d,sizeof(long long)=%d\n",sizeof(int),sizeof(long),sizeof(long long));
	show_squares(1,10000);

	end=clock();
	time=end-start;
	printf("%d", time);	
	return 0;
}
