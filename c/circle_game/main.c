#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int sum=30;		//总人数为sum
	int mod=10;		//取幸运数为mod
	int leaves=10;	//留下人数为leaves
	
	char filename[]="text1.txt";
	FILE *fp=NULL;

	//定义辅助变量
	int nowLeave=30;
	int *ifdeleted=NULL; //标记该序号是否被删,动态分配为sum大小
	int i,j;
	int turnNo;

	printf("plaese input sum:");	//输入sum:
	scanf("%d",&sum);
	printf("sum=%d\n",sum);
	if(sum<0)
	{
		printf("sum < 0 ,err!\n");
		return -1;
	}
	printf("plaese input mod:");	//输入mod:
	scanf("%d",&mod);
	printf("mod=%d\n",mod);
	if(mod<0)
	{
		printf("mod < 0 ,err!\n");
		return -1;
	}

	printf("plaese input leaves:");	//输入leaves:
	scanf("%d",&leaves);
	printf("leaves=%d\n",leaves);
	if(leaves<0)
	{
		printf("leaves < 0 ,err!\n");
		return -1;
	}

	if(leaves > sum)
	{
		printf("leaves > sum ,err!\n");
		return -1;
	}

	if((ifdeleted=malloc(sizeof(sum)*sum))!=NULL)
	{
		for(i=0;i<sum;i++)
		{
			ifdeleted[i]=0;
		}
	}
	else
	{
		printf("malloc memory failed!\n");
		return -1;
	}
	fp=fopen(filename,"w");
	if (fp==NULL) /*打开只写的文本文件*/
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(i=0;i<sum;)
	{
		fprintf(fp,"~%d\t",++i);
	}
	fprintf(fp,"\n");

	nowLeave = sum;
	turnNo = 1;
	i=0;
	do
	{
		for(;;)
		{
			if(i>=sum)
			{
				i=0;
				fprintf(fp,"\n");
			}
			if(ifdeleted[i])
			{
				fprintf(fp,"**\t");
			}
			else
			{
				if(turnNo == mod)
				{
					ifdeleted[i]=1;
					nowLeave--;
					turnNo=1;
					fprintf(fp,"*%d\t",sum-nowLeave);
					i++;
					break;
				}
				else
				{
					fprintf(fp,"%d\t",turnNo);
					turnNo++;
				}
				
			}
			i++;
		}
	}
	while (nowLeave>leaves);
	fclose(fp);
	fp=NULL;
	free(ifdeleted);
	ifdeleted=NULL;
	printf("Hello, world\n");
	return 0;
}
