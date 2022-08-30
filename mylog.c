//TODO 添加对其他输出的支持，比如网络，将日志输出到服务器，或者打印到控制台
//TODO  跟内存泄漏工具结合，查看内存日志；

/**
 * @file mylog.c
 * @author xuzhang (you@domain.com)
 * @brief 一个练手的日志库
 * @version  1.0
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <gtk/gtk.h>
#include"mylog.h"
/**
 * @brief 创建日志文件
 * 
 * @param stream 日志名称
 * @param flag 日志输出标志
 * @return GIOChannel* 返回通道
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-12
 * @copyright Copyright (c) 2022
 */
GIOChannel* my_log_creat(gchar* stream,enum LOG_FLAG flag)
{
    GIOChannel* ret=NULL;
    if(flag==STD_IN)
    {
        return true;
    }if (flag==STD_FILE&&stream!=NULL/* condition */)
    {
        GError* err=NULL;
       ret= g_io_channel_new_file(stream,"a+",&err);
        if(ret==NULL)
        {
            g_print("%s\n",err->message);
            g_error_free(err);
            err=NULL;
        }
        
        /* code */
    }
    return ret;
    





}
/**
 * @brief 写日志
 * 
 * @param stream IO流
 * @param flag 日志输出标志
 * @param data 日志记录
 * @return gboolean true写入成功，false写入失败
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-12
 * @copyright Copyright (c) 2022
 */
  gboolean    my_log_write(GIOChannel* stream, enum  LOG_FLAG flag,gchar* data)
{
    if(flag==STD_FILE)
    {
    // g_get_real_time();
    GDateTime* tim;
    tim=g_date_time_new_now_local ();
if(tim==NULL)
{
    return false;
}

gchar* temp=g_date_time_format (tim,"%Y-%m-%d %H:%M:%S:%f");
                    if(temp==NULL)
                    {
                g_date_time_unref(tim);
                tim=NULL;
                return false;
                    }
        //  int lenth=strlen(temp)+strlen(data);
            gsize siz;
          
gchar* buf=g_strconcat(temp,":",data,"\n",NULL);
// if(buf==NULL)
// {
//          g_date_time_unref(tim);
//                 tim=NULL;
//                 g_free(temp);
//                 temp=NULL;

// }
  GError* err=NULL;

            // sprintf_s(buf,lenth+4,"%s:%s\n",tim,data);
g_io_channel_write_chars(stream,buf,-1,&siz,&err);
if(err)
{
    g_print("%s\n",err->message);
    g_error_free(err);
    err=NULL;
    g_date_time_unref(tim);
    tim=NULL;
    g_free(temp);
    temp=NULL;
    g_free(buf);
    buf=NULL;
    return  false;
}
// g_io_channel_write_chars(stream,data,-1,&siz,&err);
// if(err)
// {
// g_print("%s\n",err->message);
// g_error_free(err);
// err=NULL;
// g_date_time_unref(tim);
// tim=NULL;
// g_free(temp);
// temp=NULL;
// return ;
// }
// g_io_channel_write_chars(stream,"\n",-1,&siz,&err);
// if(err)
// {
// g_print("%s\n",err->message);
// g_error_free(err);
// err=NULL;
// g_date_time_unref(tim);
// tim=NULL;
// g_free(temp);
// temp=NULL;
// return ;
// }



// g_io_channel_flush(stream,&err);
// if(err)
// {
// g_print("%s\n",err->message);
// g_error_free(err);
// err=NULL;
// // g_date_time_unref(tim);
// // tim=NULL;
// // g_free(temp);
// // temp=NULL;
// // return ;
// }


g_date_time_unref(tim);
tim=NULL;
g_free(temp);
temp=NULL;
g_free(buf);
buf=NULL;
return true;
    }


    return true;
}
gboolean my_log_close(GIOChannel** stream)
{
    if(stream)
    {
      
    GIOChannel* gio=*stream;
    g_io_channel_close(gio);
    }
    return true;
    


}
/**
 * @brief 设置类里面的方法函数；
 * 
 * @param log_class 
 * @param flag 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-30
 * @copyright Copyright (c) 2022
 */
static void func_set(my_log_head log_class,enum  LOG_FLAG flag)
{
    g_assert(log_class!=NULL);
    g_assert(flag==STD_FILE);
    log_class->flag=flag;
    log_class->list=NULL;
    log_class->my_log_creat=my_log_creat;
    log_class->my_log_write=my_log_close;
return true;
}
/**
 * @brief 关闭类
 * 
 * @param stream 文件名称 
 * @param flag 标志
 * @return my_log_head 返回操作类； 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-30
 * @copyright Copyright (c) 2022
 */
my_log_head my_log_class_creat(gchar* stream,enum  LOG_FLAG flag)
{
    g_assert(stream!=NULL);
    g_assert(flag==STD_FILE);
    my_log_head ret=g_malloc(sizeof(My_log_head));
    if(ret==NULL)
    {
        return ret;
    }
    func_set(ret,STD_FILE);
    ret->stream=ret->my_log_creat(stream,STD_FILE);
    if(ret->stream==NULL)
    {
        g_free(ret);
        ret=NULL;
    }
    
return ret;
}
/**
 * @brief 释放日志类
 * 
 * @param class_log 类的2级地址
 * @return gboolean 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-30
 * @copyright Copyright (c) 2022
 */
gboolean my_log_class_close(my_log_head* class_log)
{
    if(class_log==NULL)
    {
        return true;
    }
    my_log_head temp=*class_log;
    //集成链表以后需要将链表的数据全部写入日志，释放链表才能进行下一步；
    g_io_channel_close(temp->stream);
    temp->stream=NULL;
    if(temp)
    {
          //释放temp内部动态内存；
    g_free(temp);
    temp=NULL;
    }
   
return true;




}


