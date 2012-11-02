#ifndef __cl_implement_in_c_h__
#define __cl_implement_in_c_h__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

const void* NIL = "NIL";
const void* T = "T";

#define nil NIL
#define t T
//
struct cl_var
{
    int type; //0��ʾcons 1��ʾatom  >1 �����������ݽṹ(Ҳ��atom)
    void *vp;
};

struct cl_in   //��������
{
    struct cl_var *vp; //��ǰ������ΪNIL��ʾ�޲�����ͬʱnext����Ч
    struct cl_in *next;  //ָ����һ��������ΪNIL��ʾû����һ��������
};

struct cl_out   //��������ֵ�������ض�ֵ
{
    struct cl_var *vp; //��ǰ����ֵ��ֵ��ΪNIL��ʾ����ΪNIL��ͬʱnext����Ч   //toth ΪNIL��ô��
    struct cl_out *next;  //��һ������ֵ��ΪNIL��ʾû����һ������ֵ��
};

#define CL_FUNC_DEF(name) struct cl_out *cl_func_##name_in_c(struct cl_in *arg0)
#define CL_FUNC_GET(name) cl_func_##name_in_c

//cons ��һ���ɶԵ�Ԫ����Ԫ����������
struct cl_cons
{
    struct cl_var *car;
    struct cl_var *cdr;
};



#ifdef __cplusplus
}
#endif
#endif  // __cl_implement_in_c_h__

/*
       NIL    T    �ǿ�list   �������ݽṹ
atom   T      T     nil          T
consp  nil   nil    T           nil
listp  T     nil    T           nil

�κη�cons��atom
*/


/* end of file */
