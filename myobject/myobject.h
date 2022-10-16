/**
 * @file myobject.h
 * @author xuzhang (you@domain.com)
 * @brief 这是一个对象封装的测试用例
 * @version  1.0
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<glib.h>
#include <glib-object.h>





//类的实例实例的方法在这里实现
 struct _MYOBJECT
{
      /* data */
    int a;
    int b;
    char* test;
    GObject* object;//父类
  
};
typedef struct _MYOBJECT MYOBJECT ;
typedef struct _MYOBJECT_CLASS MYOBJECTClass ;
//对象
struct _MYOBJECT_CLASS
{
    /* data */
//一些公用的函数实现方法在这里定义
gboolean (*gfunc)(int a,int b);
};
