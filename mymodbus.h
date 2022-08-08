
#ifndef mymodbus_H
#define mymodbus_H
#include<glib.h>
typedef struct Connect_Date{
    char* ip;
    int port;
}Connect_date,*connect_date;


typedef struct Plc_Adder{
	int red_adder;
	int greed_adder;
	int yellow_adder;
	int p1_adder;
	int p2_adder;
	int p3_adder;
	int p4_adder;
	int sp1_adder;
	int sp2_adder;
	int sp3_adder;
	int sp4_adder;
	int time_set_adder;
	int time_read_adder;
	int hig_set_adder;
	int hig_read_adder;
	int hig_temp_adder;
	gboolean red_flag;
	gboolean greed_flag;
	gboolean yellow_flag;
	gboolean p1_flag;
	gboolean p2_flag;
	gboolean p3_flag;
	gboolean p4_flag;
	gboolean sp1_flag;
	gboolean sp2_flag;
	gboolean sp3_flag;
	gboolean sp4_flag;









}Plc_adder,*plc_adder;
#endif