#include <stdio.h>

typedef void * pvoid;
typedef int MSTATUE;
typedef void (*mfunc)(pvoid);
typedef struct _machine
{
	#define MAX_STATES 10
	int states;	//num of state
	mfunc menus[MAX_STATES]; //fun of every state
	//int *menus;    //used malloc
	mfunc mfdefault;
	//int nowstate; // now state
	pvoid pvshare; //share data
}machine,*pmachine;

typedef struct _share
{
	int state;
	int i;
}shareData,*pshareData;

enum sys_state
{
	_state_idel,
	_state_run,
	_state_sleep,
};

void sysIdel(pvoid pvshare)
{
	pshareData temp =(pshareData)pvshare;
	temp->i=_state_idel+10;
	temp->state = _state_run;
}
void sysRun(pvoid pvshare)
{
	pshareData temp =(pshareData)pvshare;
	temp->i=_state_run+10;
	temp->state = _state_sleep;
}
void sysSleep(pvoid pvshare)
{
	pshareData temp =(pshareData)pvshare;
	temp->i=_state_sleep+10;
	temp->state = 100; //default
}
void sysDefault(pvoid pvshare)
{
	pshareData temp =(pshareData)pvshare;
	temp->i=0xa5;
	temp->state = _state_idel;	
}

void machine_entry(pmachine pmObject,int states,int initstate,mfunc defau,pvoid pvshare)
{
	pmObject->states=states;
	pmObject->pvshare=pvshare;
	*(int *)(pmObject->pvshare)=initstate;
	pmObject->mfdefault=defau;

	pmObject->menus[_state_idel]=sysIdel;
	pmObject->menus[_state_run]=sysRun;
	pmObject->menus[_state_sleep]=sysSleep;
}
void startmachine(pmachine pmObject)
{
	if(*(int *)(pmObject->pvshare) < pmObject->states)
	{
		pmObject->menus[*(int *)(pmObject->pvshare)](pmObject->pvshare);
	}
	else
	{
		pmObject->mfdefault(pmObject->pvshare);
	}
}
int main(int argc, char *argv[])
{
	int i;
	machine testmachine;
	shareData testdata;
	machine_entry(&testmachine,3,200,sysDefault,&testdata);
	//printf("Hello, world\n");
	//printf("sizeof enum:%d\n",sizeof(enum sys_state)); //打印的是：枚举类型一个元素的大小，默认int型
	for(i=0;i<20;i++)
	{
		printf("testdata.i=%d,testdata.state=%d\n",testdata.i,testdata.state);
		startmachine(&testmachine);
	}
	return 0;
}

