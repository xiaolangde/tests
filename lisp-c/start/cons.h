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
    int type; //0表示cons 1表示atom  >1 其他特殊数据结构(也是atom)
    void *vp;
};

struct cl_in   //函数参数
{
    struct cl_var *vp; //当前参数，为NIL表示无参数，同时next域无效
    struct cl_in *next;  //指向下一个参数，为NIL表示没有下一个参数了
};

struct cl_out   //函数返回值，允许返回多值
{
    struct cl_var *vp; //当前返回值的值，为NIL表示返回为NIL，同时next域无效   //toth 为NIL怎么办
    struct cl_out *next;  //下一个返回值，为NIL表示没有下一个返回值了
};

#define CL_FUNC_DEF(name) struct cl_out *cl_func_##name_in_c(struct cl_in *arg0)
#define CL_FUNC_GET(name) cl_func_##name_in_c

//cons 是一个成对单元，其元素类型任意
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
       NIL    T    非空list   特殊数据结构
atom   T      T     nil          T
consp  nil   nil    T           nil
listp  T     nil    T           nil

任何非cons即atom
*/


/* end of file */
