#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int sum=30;		//������Ϊsum
	int mod=10;		//ȡ������Ϊmod
	int leaves=10;	//��������Ϊleaves
	
	char filename[]="text1.txt";
	FILE *fp=NULL;

	//���帨������
	int nowLeave=30;
	int *ifdeleted=NULL; //��Ǹ�����Ƿ�ɾ,��̬����Ϊsum��С
	int i,j;
	int turnNo;

	printf("plaese input sum:");	//����sum:
	scanf("%d",&sum);
	printf("sum=%d\n",sum);
	if(sum<0)
	{
		printf("sum < 0 ,err!\n");
		return -1;
	}
	printf("plaese input mod:");	//����mod:
	scanf("%d",&mod);
	printf("mod=%d\n",mod);
	if(mod<0)
	{
		printf("mod < 0 ,err!\n");
		return -1;
	}

	printf("plaese input leaves:");	//����leaves:
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
	if (fp==NULL) /*��ֻд���ı��ļ�*/
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
