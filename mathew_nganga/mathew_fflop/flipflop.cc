#include"flipflop.h"
#include"driverf.h"
#include"pulse.h"
#include"monitorf.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> in1,in2, out;

//module instances
flipflop f("flipflop_instances");
driver dr("driverf");
pulse pl("pulse");
monitor mn("monitorf");
//interconnections b2in modules
dr.d_a(in1);
f.a(in1);
mn.m_a(in1);

pl.p_b(in2);
f.b(in2);
mn.m_b(in2);

f.c(out);
mn.m_c(out);



//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timingF_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "binary_input"); // signals to be traced
sc_trace(tf, in2, "clock");
sc_trace(tf, out, "binary_output");

//run a simulation for 15 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(85,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}


