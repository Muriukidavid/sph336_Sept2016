/*
* Author: kedii raphael
*/


#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//signals
sc_signal<bool> in_1, in_2, out1, out2, out3, out4;
//module instances
decoder2 dec("decoder");
driver dr("driver");
monitor mn("monitor");

//interconnections
dr.da(in_1);
dec.m(in_1);
mn.ma(in_1);

dr.db(in_2);
dec.n(in_2);
mn.mb(in_2);

dec.v(out1);
mn.mc(out1);

dec.w(out2);
mn.md(out2);

dec.x(out3);
mn.me(out3);

dec.y(out4);
mn.mf(out4);

//trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in_1, "binary_first_input");
sc_trace(tf, in_2, "binary_second_input");
sc_trace(tf, out1, "input_is_zero_and_zero");
sc_trace(tf, out2, "input_is_zero_and_one");
sc_trace(tf, out3, "input_is_one_and_zero");
sc_trace(tf, out4, "input_is_one_and_one");


if( !sc_pending_activity() )
sc_start(25,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}



