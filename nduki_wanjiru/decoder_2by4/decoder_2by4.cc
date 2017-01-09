#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//signals
sc_signal<bool> in1, in2, out1, out2, out3, out4;
//module instances
decoder2 dec("decoder");
driver dr("driver");
monitor mn("monitor");

//interconnections
dr.d_a(in1);
dec.a(in1);
mn.m_a(in1);

dr.d_b(in2);
dec.b(in2);
mn.m_b(in2);

dec.c(out1);
mn.m_c(out1);

dec.d(out2);
mn.m_d(out2);

dec.e(out3);
mn.m_e(out3);

dec.f(out4);
mn.m_f(out4);

//trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("2by4timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "x");
sc_trace(tf, in2, "y");
sc_trace(tf, out1, "x=0;y=0");
sc_trace(tf, out2, "x=0;y=1");
sc_trace(tf, out3, "x=1;y=0");
sc_trace(tf, out4, "x=1;y=1");

//run a simulation for 40 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(40,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}



