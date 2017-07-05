#include"flipflop.h"
#include"driverf.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> in,in1, out;

//module instances
flipflop flip("flipflop_instance");
driver dr("driver");
enable en("enable_instance");
monitor mn("monitor");
//interconnections b2in modules
dr.d_a(in);
flip.a(in);
mn.m_a(in);
mn.m_b(in1);
mn.m_c(out);

en.d_b(in1);
flip.b(in1);
flip.c(out);



//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing1_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in, "binary_input"); // signals to be traced
sc_trace(tf, in1, "enable");
sc_trace(tf, out, "binary_output");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(100,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}


