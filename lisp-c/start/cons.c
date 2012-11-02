//list 表达式由原子(比如：1)或列表(由一对圆括号括起的零或多个表达式)组成
//list程序由表达组成，一个表达式可以是一个原子或者一个由  一个操作符+零或多个参数 形式的列表

//nil 即是列表也是原子
/* atom t nil 12 'a 'b 'abc [即 t nil 字符 字符串都是原子] 
任何非cons即原子()   //list也是cons
 (defun our-listp (x)
           (or (null x) (consp x)))
*/
/*list 
list操作的参数要被求值

append 可以连接多个list

*/

/*
quote操作 简记 '   :只接受一个参数，原样返回不求值
eg:
(quote (a b c))  <==> '(a b c)   也就是说去掉 (quote    ) 加上 ' 即可

*/

#include "cons.h"
#include "malloc.h"

CL_FUNC_DEF(cons)
{
    va_list ap;
    void *ret = malloc(sizeof(struct cl_cons));
    va_start(ap,arg0);
    if (arg0)
    {
    }

    va_end(ap);
}

int cl-read(char*in)
{
    
}

/*
CL-USER> (atom t)
T
CL-USER> (atom nil)
T
CL-USER> (atom 'a)
T
CL-USER> (atom 'ab)
T
CL-USER> (atom +)
NIL
CL-USER> (atom '+)
T
CL-USER> (listp ())
T
CL-USER> (atom ())
T
CL-USER> (listp nil)
T
CL-USER> (consp nil)
NIL
CL-USER> (listp t)
NIL
*/

/*
CL-USER> (setf q (cons 'a 'b))
(A . B)
CL-USER> (atom q)
NIL
CL-USER> (consp q)
T
CL-USER> (setf q 'a)
A
CL-USER> q
A
CL-USER> (atom q)
T
CL-USER> (consp q)
NIL
CL-USER> (listp q)
NIL
CL-USER> (setf q (cons 'a nil))
(A)
CL-USER> q
(A)
CL-USER> (listp q)
T
CL-USER> (consp q)
T
CL-USER> (setf q (list 'a 'b 'c))
(A B C)
CL-USER> (consp q)
T
CL-USER> (type-of q)
CONS
*/

/*
CL-USER> (setf arr (make-array '(2 3) :initial-element nil))
#2A((NIL NIL NIL) (NIL NIL NIL))
CL-USER> arr
#2A((NIL NIL NIL) (NIL NIL NIL))
CL-USER> (atom arr)
T
CL-USER> (consp arr)
NIL
CL-USER> (listp arr)
NIL
CL-USER> (null arr)
NIL
CL-USER> (type-of arr)
(SIMPLE-ARRAY T (2 3))

*/


/* end of file */
