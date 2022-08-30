//TODO 
/**
 * @brief 用于调试内存泄漏的文件
 * 包括的功能，申请内存，释放内存，打印没有被释放的函数；
 * 使用示例
 * 1.重定义malloc，free 函数；
 * 2.申请内存
 * 3.释放内存
 * 4.在程序末尾使用free_print打印所有没有被释放的内存；
 * 分配的内存数据都存放到链表，包括在哪个文件，哪个函数分配的第几行，变量名字；
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-29
 * @copyright Copyright (c) 2022
 */
#ifndef mymalloc_H
#define mymalloc_H
#include<stdlib.h>
#include<stdio.h>
#include<glib.h>
/**
 * @brief 链表的结点
 * 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-29
 * @copyright Copyright (c) 2022
 */
typedef struct  MALLOC_DATE{
        char*func_name;//函数名字
        int line;//第几行
        int sze;//大小
        char* file_name;//文件名字
        char* name;//变量名字
        gpointer adder;

}Malloc_Date,*malloc_date;
/**
 * @brief 用于申请内存
 * 
 * @param file_name 文件名称
 * @param func_name 函数名称
 * @param name 变量名称
 * @param line 行
 * @param siz 大小
 * @return gpointer 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-29
 * @copyright Copyright (c) 2022
 */
gpointer MY_malloc(char* file_name,char* func_name,char* name,int line ,size_t siz);
MY_free(gpointer d);
MY_malloc_close(void);

void free_print(void*(func)(char* string));

 #define my_malloc MY_malloc
 #define my_free MY_free
// void my_malloc_ini();





#endif