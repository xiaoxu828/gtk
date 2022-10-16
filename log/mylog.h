
#ifndef mylog_H
#define mylog_H
#include<stdio.h>
#include <gtk/gtk.h>
enum LOG_FLAG{
    STD_IN=0,
    STD_FILE=1,
    STD_TCP=2,
    STD_UDP=3,
    STD_ERR=4,
};
/**
 * @brief 后续通过线程以及链表的方式添加日志
 * 线程定时把链表的数据更新到日志文件里面
 * 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-11
 * @copyright Copyright (c) 2022
 */
//TODO 将日志往类的方向发展；
//TODO 添加缓存机制，先把数据写入缓存，然后等cpu空闲时写入日志文件

typedef struct MY_LOG_HEAD{
GIOChannel* stream;
  enum  LOG_FLAG flag;
  GList* list;//线程buf，程序通过这个线程去写日志，线程去通过这个更新日志；
GThread* th;//线程句柄
GMutex* mutex;//
GIOChannel*(*my_log_creat)(gchar* stream,enum  LOG_FLAG flag);
gboolean (*my_log_write)(GIOChannel* stream,enum  LOG_FLAG flag,gchar* data);

}My_log_head,*my_log_head;

my_log_head my_log_class_creat(gchar* stream,enum  LOG_FLAG flag);

GIOChannel* my_log_creat(gchar* stream,enum  LOG_FLAG flag);
gboolean my_log_write(GIOChannel* stream,enum  LOG_FLAG flag,gchar* data);

gboolean my_log_close(GIOChannel** stream);

gboolean my_log_class_close(my_log_head* class_log);



#endif