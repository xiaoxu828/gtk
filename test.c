// TODO  添加基础库用于项目；
// TODO 	添加语法使用规则用例；
// TODO 	添加注释；
// TODO	导出sdk手册；
// TODO  完善cmake语法；
//编译libevent静态库；20220730
// CJSON库
//二维码生成库
// OPENCV库
//
/**
 * @file test.c
 * @author xuzhang (you@domain.com)
 * @brief 这是一个测试c11标准的程序。
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright Copyright (c) 2022
 * 1.支持unicode字符（中文变量）
 * 2.支持可变数组
 * 3.一定程度上支持重载
 */

// #include <stdio.h>
// #include <stdlib.h>
// #include "config.h"
// #include <gtk/gtk.h>
// #include <assert.h>

// // #include <event2/event.h>
// // #include<sqlite3.h>
// #include <modbus.h>
// #include "mymodbus.h"
// #include <msptrmac.h>
// //  #pragma comment(lib, "ws2_32.lib")
// // #define  TE PROJECT_NAME ## PROJECT_VER
// //可以实现的是同一功能不同类型的重载；
// /**
//  * @brief 一个自定义打印函数的重载，支持直接输入字符串，整形，浮点型，双精度浮点型
//  *
//  * @version  1.0
//  * @author xuzhang (you@domain.com)
//  * @date 2022-07-30
//  * @copyright Copyright (c) 2022
//  */
// #define foo(x) _Generic((x), int                 \
// 						: my_print1_int, float   \
// 						: my_print_float, char * \
// 						: my_print_str, double   \
// 						: my_print_double)(x)
// /**
//  * @brief 打印整形
//  * @param x 整形输入
//  *
//  */
// extern gboolean my_connect_plc(GtkWidget *w, gpointer d);
// extern gboolean my_ip_set(GtkWidget *w, gpointer d);
// extern gboolean my_bool_set_red(GtkWidget *w, gpointer d);
// extern gboolean my_bool_set_hig(GtkWidget *w, gpointer d);
// extern gboolean my_bool_set_greed(GtkWidget *w, gpointer d);

// extern gboolean my_bool_set_time(GtkWidget *w, gpointer d);
// extern gboolean my_bool_set_yellow(GtkWidget *w, gpointer d);
// extern gboolean close_plc_func(gpointer d);
// void my_print1_int(int x)
// {

// 	assert(sizeof(x) == 4);
// 	printf("%d\n", x);
// }
// /**
//  * @brief 打印浮点数
//  *
//  * @param x 浮点输入
//  */
// void my_print_float(float x)
// {

// 	assert(sizeof(x) == 4);
// 	printf("%f\n", x);
// }
// /**
//  * @brief 打印字符串
//  *
//  * @param x 传入的字符串
//  */
// void my_print_str(char *x)
// {
// 	// g_file_open_readwrite()
// 	//  assert(sizeof(x)/==4);
// 	printf("%s\n", x);
// }
// /**
//  * @brief 打印双精度浮点数
//  *
//  * @param x 传入双精度浮点数
//  */
// void my_print_double(double x)
// {

// 	printf("%lf", x);
// }
// char hel[50] = {"hello\0,sdasuff"};
// char *hel1 = "hello";
// int 你好 = 100;
// GtkBuilder *builder;
// GtkWidget *window = NULL;
// GtkWidget *red_led = NULL;
// GtkWidget *greed_led = NULL;
// GtkWidget *yellow_led = NULL;

// GtkWidget *p1_button = NULL;
// GtkWidget *p2_button = NULL;
// GtkWidget *p3_button = NULL;
// GtkWidget *p4_button = NULL;
// GtkWidget *sp1_button = NULL;
// GtkWidget *sp2_button = NULL;
// GtkWidget *sp3_button = NULL;
// GtkWidget *sp4_button = NULL;
// GtkWidget *time_set_input = NULL;
// GtkWidget *time_read_input = NULL;
// GtkWidget *hig_set_input = NULL;
// GtkWidget *hig_read_input = NULL;
// GtkWidget *time_ok_button = NULL;
// GtkWidget *hig_ok_button = NULL;
// GtkWidget *conncet_plc = NULL;
// GtkWidget *close_plc = NULL;

// GtkWidget *plc_ip = NULL;
// GtkWidget *temp_hig = NULL;
// connect_date pc_plc_date;
// GdkColor ture_color;
// GdkColor false_color;
// Plc_adder *pit = NULL;
// // gdk_color_parse ("颜色(如green,red,blue)", &color);

// // Plc_adder plcadder;

// // gtk
// //  GMutex* mutex;
// void gtk_creat_app(int *argc, char **argv[])
// {

// 	// g_thread_init(NULL);
// 	float j = 10.5;
// 	int *k = (int *)&j;
// 	g_print("k=%d\n", *k);
// 	g_print("float=%f\n", *(float *)k);
// 	pit = (Plc_adder *)malloc(sizeof(Plc_adder));
// 	g_print("%p", pit);
// 	//设置plc地址
// 	//三色灯
// 	pit->greed_adder = 21;
// 	pit->red_adder = 20;
// 	pit->yellow_adder = 22;
// 	pit->p1_adder = 10;
// 	pit->p2_adder = 11;
// 	pit->p3_adder = 12;
// 	pit->p4_adder = 13;
// 	// pit->
// 	pit->sp1_adder = 0;
// 	pit->sp2_adder = 1;
// 	pit->sp3_adder = 2;
// 	pit->sp4_adder = 3;
// 	// pit->；
// 	pit->hig_set_adder = 500;
// 	// pit->界值
// 	pit->hig_read_adder = 500;
// 	pit->hig_temp_adder = 0;
// 	pit->time_set_adder = 502;
// 	pit->time_read_adder = 504;
// 	pit->p1_flag = FALSE;
// 	pit->p2_flag = FALSE;
// 	pit->p3_flag = FALSE;
// 	pit->p4_flag = FALSE;
// 	pit->sp1_flag = FALSE;
// 	pit->sp2_flag = FALSE;
// 	pit->sp3_flag = FALSE;
// 	pit->sp4_flag = FALSE;
// 	pit->red_flag = FALSE;
// 	pit->yellow_flag = FALSE;
// 	pit->greed_flag = FALSE;
// 	GError *err = NULL;

// 	 gtk_init(argc, argv);
// // gtk_init();
// 	builder = gtk_builder_new();
// 	gtk_builder_add_from_file(builder, "window1.glade", &err);
// 	if (builder == NULL)
// 	{
// 		fprintf(stderr, "界面文件打开失败%s\n", err->message);
// 		g_error_free(err);
// 		// g_printerr("界面文件打开失败%s",err);
// 	}

	



// 	pc_plc_date = malloc(sizeof(Connect_date));




	







// 	pc_plc_date->ip = (char *)malloc(80);
// 	pc_plc_date->port = 502;
// 	if (pc_plc_date->ip != NULL)
// 	{
// 		pc_plc_date->port = 502;
// 		window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
// 		p1_button = GTK_WIDGET(gtk_builder_get_object(builder, "p1"));
// 		p3_button = GTK_WIDGET(gtk_builder_get_object(builder, "p2"));
// 		p2_button = GTK_WIDGET(gtk_builder_get_object(builder, "p3"));
// 		p4_button = GTK_WIDGET(gtk_builder_get_object(builder, "p4"));
// 		sp1_button = GTK_WIDGET(gtk_builder_get_object(builder, "sp1"));
// 		sp2_button = GTK_WIDGET(gtk_builder_get_object(builder, "sp2"));
// 		sp3_button = GTK_WIDGET(gtk_builder_get_object(builder, "sp3"));
// 		sp4_button = GTK_WIDGET(gtk_builder_get_object(builder, "sp4"));

// 		red_led = GTK_WIDGET(gtk_builder_get_object(builder, "led1"));
// 		greed_led = GTK_WIDGET(gtk_builder_get_object(builder, "led2"));
// 		yellow_led = GTK_WIDGET(gtk_builder_get_object(builder, "led3"));
// 		time_set_input = GTK_WIDGET(gtk_builder_get_object(builder, "time_set"));
// 		time_read_input = GTK_WIDGET(gtk_builder_get_object(builder, "time_read"));
// 		hig_set_input = GTK_WIDGET(gtk_builder_get_object(builder, "hig_set"));
// 		hig_read_input = GTK_WIDGET(gtk_builder_get_object(builder, "hig_read"));
// 		time_ok_button = GTK_WIDGET(gtk_builder_get_object(builder, "time_ok"));
// 		hig_ok_button = GTK_WIDGET(gtk_builder_get_object(builder, "hig_ok"));
// 		conncet_plc = GTK_WIDGET(gtk_builder_get_object(builder, "open_plc"));
// 		close_plc = GTK_WIDGET(gtk_builder_get_object(builder, "close_plc"));
// 		plc_ip = GTK_WIDGET(gtk_builder_get_object(builder, "plc_ip"));
// 		temp_hig = GTK_WIDGET(gtk_builder_get_object(builder, "temp_hig"));
// 		gdk_color_parse("green", &ture_color);
// 		gdk_color_parse("red", &false_color);

// 		//设置BUTTON初始颜色
// 		// gtk_color_button_set_color(p1_button,)
// 		// gtk_color_button_set_rgba(p1_button,&true_rgba);
// 		// gtk_color_button_set_rgba(p2_button,&flase_rgba);

// 		gtk_widget_modify_fg(p1_button, GTK_STATE_FLAG_NORMAL, &false_color);  //背景色
// 		gtk_widget_modify_fg(p2_button, GTK_STATE_FLAG_NORMAL, &false_color);  //背景色
// 		gtk_widget_modify_fg(p3_button, GTK_STATE_FLAG_NORMAL, &false_color);  //背景色
// 		gtk_widget_modify_fg(p4_button, GTK_STATE_FLAG_NORMAL, &false_color);  //背景色
// 		gtk_widget_modify_fg(sp1_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
// 		gtk_widget_modify_fg(sp2_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
// 		gtk_widget_modify_fg(sp3_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
// 		gtk_widget_modify_fg(sp4_button, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
// 		gtk_widget_modify_fg(red_led, GTK_STATE_FLAG_NORMAL, &false_color);	   //背景色
// 		gtk_widget_modify_fg(yellow_led, GTK_STATE_FLAG_NORMAL, &false_color); //背景色
// 		gtk_widget_modify_fg(greed_led, GTK_STATE_FLAG_NORMAL, &false_color);  //背景色

// 		// gtk_widget_modify_fg (GTK_WIDGET(控件), GTK_STATE_NORMAL, &color);//前景色

// 		//关闭程序
// 		g_signal_connect(window, "destroy", gtk_main_quit,NULL);
// 		//设置ip
// 		g_signal_connect(conncet_plc, "pressed", G_CALLBACK(my_connect_plc), pc_plc_date);
// 		//开始连接
// 		g_signal_connect(plc_ip, "activate", G_CALLBACK(my_ip_set), pc_plc_date);
// 		g_signal_connect(red_led, "pressed", G_CALLBACK(my_bool_set_red), pit);
// 		g_signal_connect(greed_led, "pressed", G_CALLBACK(my_bool_set_greed), pit);
// 		g_signal_connect(yellow_led, "pressed", G_CALLBACK(my_bool_set_yellow), pit);

// 		g_signal_connect(hig_ok_button, "pressed", G_CALLBACK(my_bool_set_hig), pit);

// 		g_signal_connect(time_ok_button, "pressed", G_CALLBACK(my_bool_set_time), pit);
// 		g_signal_connect(close_plc, "pressed", G_CALLBACK(close_plc_func), NULL);

// 		g_object_unref(builder);
// 		gtk_widget_show(window);
// 		//   gdk_threads_enter();
// 		gtk_main();
// 		free(pit);
// 		pit=NULL;
// 		free(pc_plc_date);
// 		pc_plc_date=NULL;
// 		//   gdk_threads_leave();
// 	}
// 	//控件加载
// }

// /**
//  * @brief
//  *
//  * @param argc
//  * @param argv
//  * @return int
//  * @version  1.0
//  * @author xuzhang (you@domain.com)
//  * @date 2022-07-29
//  * @copyright Copyright (c) 2022
//  */

// int main(int argc, char *argv[])
// {
// 	//服务器+数据库的例子
// 	// 	struct event_base* base=event_base_new();
// 	// 	// printf("hello word");
// 	// 	int a = 100;
// 	// 	// int arr[a];
// 	// 	// foo(你好);
// 	// 	// float c = 0.5;
// 	// 	// foo(c);
// 	// 	// foo(PROJECT_VER);
// 	// 	foo((int)strnlen(hel,100));
// 	// 	foo((int)sizeof(hel));
// 	// 	gtk_init(&argc,&argv);
// 	// sqlite3* sql_db=NULL;
// 	// int ret=  sqlite3_open("test.db",&sql_db);
// 	// if(ret==0)
// 	// {
// 	// 	foo("sqlopen");
// 	// }
// 	// sqlite3_initialize();
// 	// 	// gtk_widget_new();
// 	// 	foo(PROJECT_NAME);

// 	// 	  GRegex* regex;
// 	//     GMatchInfo *match_info;
// 	//     GError *error = NULL;
// 	//     const gchar *str = "11aa222bb33333cccc44444dddddddd";
// 	//     const gchar *pat = "[0-9]+";

// 	//     regex = g_regex_new(pat, 0, 0, &error);
// 	//     g_regex_match(regex, str, 0, &match_info);

// 	//     while (g_match_info_matches(match_info)) {
// 	//         gchar* word = g_match_info_fetch(match_info, 0);
// 	//         g_print("%s \n",word);
// 	//         g_free(word);

// 	//         g_match_info_next(match_info, NULL);
// 	//     }

// 	//     g_match_info_free(match_info);
// 	//     g_regex_unref(regex);
// 	// gtk的使用
// 	gtk_creat_app(&argc, &argv);

// 	exit(0);
// }
// #include <gtk/gtk.h>

// static void
// activate (GtkApplication* app,
//           gpointer        user_data)
// {
// 	GtkWidget *window;
	
// 	 window = gtk_application_window_new (app);
// 	 gtk_window_set_title (GTK_WINDOW (window), "Window");
// 	 gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
// 	 gtk_widget_show (window);
// }
#include <gtk/gtk.h>
gboolean fun(gpointer d)
{
	while (/* condition */1)
	{
char* t= g_malloc0(100);
	g_print("hello\n");
	g_free(t);
	t=NULL;
	_sleep(100);
		/* code */
	}
	
	
}
static void
activate (GtkApplication* app,
          gpointer        user_data)
{
	GtkWidget *window;
	
	 window = gtk_application_window_new (app);
	 gtk_window_set_title (GTK_WINDOW (window), "Window");
	 gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
	 g_thread_new("t",fun,NULL);
	 gtk_widget_show (window);
}

int
main (int    argc,
	  char **argv)
{
	 GtkApplication *app;
	 int status;
	

	
	 app = gtk_application_new ("og.gtk.example", G_APPLICATION_FLAGS_NONE);
	 g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	 status = g_application_run (G_APPLICATION (app), argc, argv);
	 g_object_unref (app);
	
	 return status;
}
