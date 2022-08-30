#include"mymalloc.h"
//锁保证在多线程的情况下不会出现错误；
GMutex* mutex;
//链表保存申请内存的所有数据
static GList* malloc_list;
/**
 * @brief 添加节点的所有信息
 * 
 * @param file_name 文件名字
 * @param func_name 函数名字
 * @param name  变量名字
 * @param line 行
 * @param siz 大小
 * @return Malloc_Date* 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-29
 * @copyright Copyright (c) 2022
 */
Malloc_Date* my_malloc_add(char* file_name,char* func_name,char* name,int line ,size_t siz)
{
    g_assert(file_name!=NULL);
    g_assert(func_name!=NULL);
    g_assert(name!=NULL);
    g_assert(siz>0);
    Malloc_Date* ret=g_malloc(sizeof(Malloc_Date));
    if(ret==NULL)
    {
        if(malloc_list)
        {
            g_list_free(malloc_list);
        }
        g_print("err:内存不足");


    }
    ret->file_name=g_malloc(strnlen_s(file_name,1023)+1);
    if(ret->file_name==NULL)
    {
        g_print("err:file_name:%s,func_name:%s,func_name:%s,line:%d,size_t=%d",file_name,func_name,name,line,siz);
    g_free(ret);
        exit(-1);
    }
        g_strlcpy(ret->file_name,file_name,1024);
        
        ret->func_name=g_malloc(strnlen_s(func_name,1023)+1);
        if(ret->func_name==NULL)
        {
           
            g_free(ret->func_name);
             g_free(ret);
       
                 if(malloc_list)
        {
            g_list_free(malloc_list);
        }
             g_print("err:file_name:%s,func_name:%s,func_name:%s,line:%d,size_t=%d",file_name,func_name,name,line,siz);
            exit(-1);
        }
        g_strlcpy(ret->func_name,func_name,1024);
ret->name=g_malloc(strnlen_s(name,1023)+1);\
if(ret->name==NULL)
{
    g_free(ret->file_name);
    g_free(ret->func_name);
    g_free(ret);
    if(malloc_list)
    g_list_free(malloc_list);
 g_print("err:file_name:%s,func_name:%s,func_name:%s,line:%d,size_t=%d",file_name,func_name,name,line,siz);
    
    
    exit(-1);
}
ret->line=line;
ret->sze=siz;
return ret;
}
/**
 * @brief 申请内存
 * 
 * @param file_name 文件名字
 * @param func_name 函数名字
 * @param name 变量名字
 * @param line 行
 * @param siz 大小
 * @return gpointer 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-29
 * @copyright Copyright (c) 2022
 */
gpointer MY_malloc(char* file_name,char* func_name,char* name,int line ,size_t siz){  
    if(mutex==NULL)
    {
        mutex=g_mutex_new();
        if(mutex==NULL)
        {
            g_print("malloc:加锁失败，程序退出");
            exit(-1);
        }
        g_mutex_init(mutex);
    }
        g_assert(file_name!=NULL);
    g_assert(func_name!=NULL);
    g_assert(name!=NULL);
    g_assert(siz>0);
Malloc_Date* pnode=my_malloc_add(file_name,func_name,name,line,siz);

gpointer ret=g_malloc(siz);
pnode->adder=ret;
g_mutex_lock(mutex);
malloc_list= g_list_append(malloc_list,pnode);
g_mutex_unlock(mutex);
// g_free(pnode);
return ret;
}
/**
 * @brief 查找结点
 * 
 * @param a 结点a
 * @param b 结点b
 * @return gint 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-29
 * @copyright Copyright (c) 2022
 */
gint find_p(gconstpointer a,gconstpointer b)
{
  Malloc_Date* temp=a;
  
if( temp->adder <b)
{
    return -1; 
}
else if(temp->adder==b)
{
    return 0;
}else{
return 1;

}



}
/**
 * @brief Construct a new my free object
 * 
 * @param d 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-29
 * @copyright Copyright (c) 2022
 */
MY_free(gpointer d){
    g_mutex_lock(mutex);
  GList* lst=  g_list_find_custom(malloc_list,d,find_p);
  g_mutex_unlock(mutex);
    Malloc_Date* temp=lst->data;
    g_free(temp->file_name);
    g_free(temp->func_name);
    g_free(temp->name);
    g_mutex_lock(mutex);
    malloc_list= g_list_delete_link(malloc_list,lst);
    g_mutex_unlock(mutex);

}
 void(*func_temp)(char* string);
gboolean print_func(gpointer data,gpointer usr_data)
{
    Malloc_Date*temp=data;

    gchar* str_temp= g_strdup_printf("文件名:%s,函数名:%s,所在行:%d,大小:%d,地址:%p",
     temp->file_name,\
     temp->func_name,\
     temp->line,\
     temp->sze,\
     temp->adder);
     func_temp(str_temp);
     g_free(str_temp);
   
 //  func_temp(str_temp);




}
MY_malloc_close(void){
    g_list_free(malloc_list);
}
void free_print(void*(func)(char* string))
{
    g_assert(func!=NULL);
    if(malloc_list)
    {
         
          func_temp=func;
        g_list_foreach(malloc_list,print_func,func);
      //  g_strdup_printf("文件名:%s,函数名:%s,所在行:%d,大小:%d",)


    }



}
