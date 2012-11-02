//list ���ʽ��ԭ��(���磺1)���б�(��һ��Բ�����������������ʽ)���
//list�����ɱ����ɣ�һ�����ʽ������һ��ԭ�ӻ���һ����  һ��������+��������� ��ʽ���б�

//nil �����б�Ҳ��ԭ��
/* atom t nil 12 'a 'b 'abc [�� t nil �ַ� �ַ�������ԭ��] 
�κη�cons��ԭ��()   //listҲ��cons
 (defun our-listp (x)
           (or (null x) (consp x)))
*/
/*list 
list�����Ĳ���Ҫ����ֵ

append �������Ӷ��list

*/

/*
quote���� ��� '   :ֻ����һ��������ԭ�����ز���ֵ
eg:
(quote (a b c))  <==> '(a b c)   Ҳ����˵ȥ�� (quote    ) ���� ' ����

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
