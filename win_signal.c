/**
 * @file win_signal.c
 * @author xuzhang (you@domain.com)
 * @brief
 * @version  1.0
 * @date 2022-08-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <modbus.h>
#include <gtk/gtk.h>
// modbus连接句柄
#include "mymodbus.h"
extern GMutex *mutex;
modbus_t *m;
extern GtkBuilder *builder;
extern GtkWidget *window;
extern GtkWidget *red_led;
extern GtkWidget *greed_led;
extern GtkWidget *yellow_led;

extern GtkWidget *p1_button;
extern GtkWidget *p2_button;
extern GtkWidget *p3_button;
extern GtkWidget *p4_button;
extern GtkWidget *sp1_button;
extern GtkWidget *sp2_button;
extern GtkWidget *sp3_button;
extern GtkWidget *sp4_button;
extern GtkWidget *time_set_input;
extern GtkWidget *time_read_input;
extern GtkWidget *hig_set_input;
extern GtkWidget *hig_read_input;
extern GtkWidget *time_ok_button;
extern GtkWidget *hig_ok_button;
extern GtkWidget *conncet_plc;
extern GtkWidget *close_plc;
extern GtkWidget *plc_ip;
extern GtkWidget *temp_hig;
extern GdkColor ture_color;
extern GdkColor false_color;
extern Plc_adder *pit;
int thread_run_flag = 0;

/**
 * @brief 定时300ms读取plc的数据
 *
 * @param d
 * @return gboolean
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-05
 * @copyright Copyright (c) 2022
 */
gboolean thread_read_plc(gpointer d)
{

    // while (/* condition */ thread_run_flag)
    // {

    uint8_t ret[100] = {0};
    uint16_t ret_short[20] = {0};
    uint16_t ret_hig[4] = {0};
    modbus_read_bits(m, 0, 30, ret);//等价于c#nmodbus4的ReadSingleCoil方法

    modbus_read_registers(m, 500, 10, ret_short);//等价于ReadHoldingRegisters

    modbus_read_registers(m, 0, 2, ret_hig);//ReadHoldingRegisters


    if (ret[pit->greed_adder])
    {
        // g_print("1\n");
        gtk_widget_modify_fg(greed_led, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //  g_print("1\n");
        gtk_widget_modify_fg(greed_led, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    if (ret[pit->red_adder])
    {
        //  g_print("2\n");
        gtk_widget_modify_fg(red_led, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //   g_print("2\n");
        gtk_widget_modify_fg(red_led, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    if (ret[pit->yellow_adder])
    {
        //   g_print("3\n");
        gtk_widget_modify_fg(yellow_led, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //   g_print("3\n");

        gtk_widget_modify_fg(yellow_led, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    if (ret[pit->p1_adder])
    {
        //   g_print("4\n");

        gtk_widget_modify_fg(p1_button, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //   g_print("4\n");

        gtk_widget_modify_fg(p1_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    if (ret[pit->p2_adder])
    {
        //   g_print("5.0\n");

        gtk_widget_modify_fg(p2_button, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
                                                                             //    g_print("5.1\n");
    }
    else
    {
        //   g_print("5.2\n");

        gtk_widget_modify_fg(p2_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
        //    g_print("5.3\n");
    }
    if (ret[pit->p3_adder])
    {
        //   g_print("6\n");

        gtk_widget_modify_fg(p3_button, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //   g_print("6\n");

        gtk_widget_modify_fg(p3_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    if (ret[pit->p4_adder])
    {
        //   g_print("7\n");

        gtk_widget_modify_fg(p4_button, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //   g_print("7\n");

        gtk_widget_modify_fg(p4_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    if (ret[pit->sp1_adder])
    {
        //   g_print("8\n");

        gtk_widget_modify_fg(sp1_button, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //   g_print("8\n");

        gtk_widget_modify_fg(sp1_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    if (ret[pit->sp2_adder])
    {
        //   g_print("9\n");

        gtk_widget_modify_fg(sp2_button, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //   g_print("9\n");

        gtk_widget_modify_fg(sp2_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    if (ret[pit->sp3_adder])
    {
        //   g_print("10\n");

        gtk_widget_modify_fg(sp3_button, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //   g_print("10\n");

        gtk_widget_modify_fg(sp3_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    if (ret[pit->sp4_adder])
    {
        //   g_print("11\n");

        gtk_widget_modify_fg(sp4_button, GTK_STATE_FLAG_NORMAL, &ture_color); //背景色
    }
    else
    {
        //   g_print("11\n");

        gtk_widget_modify_fg(sp4_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
    }
    //
    uint16_t temp1[3] = {0};
    for (size_t i = 0; i < 2; i++)
    {
        temp1[i] = ret_short[i];
        /* code */
    }
    float *k = (float *)temp1;//c#不具有参考价值，c#变换很麻烦
    
    char *tempstr1 = malloc(100);
    char *tempstr2 = malloc(100);
    char *tempstr3 = malloc(100);

    sprintf_s(tempstr1, 15, "%.2f", *k);
    sprintf_s(tempstr2, 15, "%d", ret_short[4]);

    gtk_entry_set_text(time_read_input, tempstr2);
    gtk_entry_set_text(hig_read_input, tempstr1);
    float *k1 = (float *)ret_hig;
    sprintf_s(tempstr3, 15, "%.2f", *k1);
    gtk_entry_set_text(temp_hig, tempstr3);
    free(tempstr1);
    free(tempstr2);
    free(tempstr3);
    tempstr1=NULL;
    tempstr2=NULL;
    tempstr3=NULL;
    //   gdk_threads_leave();

    //  g_mutex_unlock(mutex);

    if (thread_run_flag == 0)
    {
        return FALSE;
    }

    return TRUE;

    /* code */
    // }
}

/**
 * @brief 连接plc
 *
 * @param w 控件名称
 * @param d 传入的值
 * @return gboolean
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-04
 * @copyright Copyright (c) 2022
 */

gboolean my_connect_plc(GtkWidget *w, gpointer d)
{

    g_print("in");
    if (d)
    {
        connect_date mod = (connect_date)d;

        if (mod->ip)
        {
            m = modbus_new_tcp(mod->ip, mod->port);
            if (m == NULL)
            {
                g_print("打开失败，请检查ip跟端口\n");
            }
            int ret = modbus_connect(m);//连接plc，连接的方法参考上次发的程序
            if (ret == 0)
            {
                thread_run_flag = 1;
                // gdk_threads_add_idle_full()
                gdk_threads_add_timeout(300, thread_read_plc, NULL);//启动定时读取函数;
                // gdk_threads_add_idle_(thread_read_plc,NULL);
                //  g_thread_create(thread_read_plc,NULL,TRUE,NULL);
            }
            g_print("ret=%d\n", ret);
        }
    }
    else
    {
        g_print("请传入一个有效值\n");
    }
    return TRUE;
}
/**
 * @brief 设置IP地址，c#请参考上次发的程序
 * 
 * @param w 
 * @param d 
 * @return gboolean 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-06
 * @copyright Copyright (c) 2022
 */
gboolean my_ip_set(GtkWidget *w, gpointer d)
{
    g_print("hello\n");
    connect_date mod = (connect_date)d;
    gchar *str1 = gtk_entry_get_text(w);
    if (str1)
    {
        strcpy(mod->ip, str1);
        g_print("%s\n", mod->ip);
    }
}
/**
 * @brief 绿灯读取，参考ReadSingleCoil
 *
 * @param w
 * @param d
 * @return gboolean
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-05
 * @copyright Copyright (c) 2022
 */
gboolean my_bool_set_greed(GtkWidget *w, gpointer d)
{
    if (m)
    {
        Plc_adder *p = (Plc_adder *)d;
        //  if(p->greed_flag)
        //  {
        p->greed_flag = !p->greed_flag;
        modbus_write_bit(m, p->greed_adder, p->greed_flag);//ReadSingleCoil


        //
    }
}
/**
 * @brief 红灯的设置
 *
 * @param w
 * @param d
 * @return gboolean
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-05
 * @copyright Copyright (c) 2022
 */
gboolean my_bool_set_red(GtkWidget *w, gpointer d)
{
    Plc_adder *p = (Plc_adder *)d;
    g_print("adder=%d\n", p->hig_read_adder);
    if (m)
    {

        //  if(p->greed_flag)
        //  {
        p->red_flag = !p->red_flag;
        g_print("adder=%d", p->red_adder);
        int ret = modbus_write_bit(m, p->red_adder, p->red_flag);//不需要
        g_print("%d", ret);
        //
    }
}
/**
 * @brief 设置黄灯的状态//WriteSingleCoil
 * 
 * @param w 
 * @param d 
 * @return gboolean 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-06
 * @copyright Copyright (c) 2022
 */
gboolean my_bool_set_yellow(GtkWidget *w, gpointer d)
{
    if (m)
    {
        Plc_adder *p = (Plc_adder *)d;
        //  if(p->greed_flag)
        //  {
        p->yellow_flag = !p->yellow_flag;
        modbus_write_bit(m, p->yellow_adder, p->yellow_flag);//WriteSingleCoil


        //
    }
}
/**
 * @brief 设置临界高度，数据转换不具有参考含义//WriteMultipleRegisters
 * 
 * @param w 
 * @param d 
 * @return gboolean 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-06
 * @copyright Copyright (c) 2022
 */
gboolean my_bool_set_hig(GtkWidget *w, gpointer d)
{
    if (m)
    {
        Plc_adder *p = (Plc_adder *)d;
        const char *temp_str1 = gtk_entry_get_text(hig_set_input);
        if (temp_str1 != NULL && temp_str1 != "")
        {
            char *str_end = NULL;
            float temp_float1 = strtof(temp_str1, &str_end);
            // uint
            g_print("%f", temp_float1);
            // c#不能这样转，否则出错；
            uint16_t *temp_16 = (uint16_t *)&temp_float1;
            modbus_write_registers(m, p->hig_set_adder, 2, temp_16);//WriteMultipleRegisters
            uint16_t j[2];
            modbus_read_registers(m, p->hig_set_adder, 2, j);
            // c#不能这样转，否则会出错；
            float *k = (float *)j;
            g_print("k=%f\n", *k);
        }
    }
}
/**
 * @brief 不涉及数据转换参考方法WriteMultipleRegisters
 * 
 * @param w 
 * @param d 
 * @return gboolean 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-06
 * @copyright Copyright (c) 2022
 */
gboolean my_bool_set_time(GtkWidget *w, gpointer d)
{

    if (m)
    {
        Plc_adder *p = (Plc_adder *)d;
        char *temp_str1 = gtk_entry_get_text(time_set_input);
        if (temp_str1 != NULL && p != NULL)
        {
            // char* str_end=NULL;
            short temp_float1 = (short)atoi(temp_str1);
            // uint

            // modbus_write_registers(m,p->hig_set_adder,2,temp_16);
            modbus_write_register(m, p->time_set_adder, temp_float1);
        }
    }
}
/**
 * @brief 设置拍照时间这个功能不用开发。
 * 
 * @param w 
 * @param d 
 * @return gboolean 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-06
 * @copyright Copyright (c) 2022
 */
gboolean my_bool_get_time(GtkWidget *w, gpointer d)
{

    if (m)
    {
        Plc_adder *p = (Plc_adder *)d;
        uint16_t t = 0;
        modbus_read_registers(m, p->time_read_adder, 1, &t);
        // itoa();

        // modbus_write_registers(m,p->hig_set_adder,2,temp_16);
    }
}
/**
 * @brief 关闭plc连接。
 * 
 * @param d 
 * @return gboolean 
 * @version  1.0
 * @author xuzhang (you@domain.com)
 * @date 2022-08-06
 * @copyright Copyright (c) 2022
 */
gboolean close_plc_func(gpointer d)
{

    // g_print("h1\n");
    thread_run_flag = 0;
    Sleep(200);
    // g_print("h2\n");
    if (m)
    {
        // g_print("h3\n");

        modbus_close(m);
        //  g_print("h4\n");
        modbus_free(m);
        m = NULL;
    }
}
