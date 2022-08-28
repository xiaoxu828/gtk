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