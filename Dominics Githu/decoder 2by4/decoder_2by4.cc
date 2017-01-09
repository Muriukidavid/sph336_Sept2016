
#include"decoder_2by4.h"
#include"driver_2by4.h"
#include"monitor_2by4.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> in1,in2, out1,out2,out3,out4;
//module instances
decoder dec("decoder_instance");
driver dr("driver");
monitor mn("monitor");
//interconnections b2in modules
dr.drver_ina(in1);
dr.drver_inb(in2);

dec.dec_a(in1);
dec.dec_b(in2);


mn.mon_i1(in1);
mn.mon_i2(in2);


dec.decout1(out1);
mn.mon_o1(out1);

dec.decout2(out2);
mn.mon_o2(out2);

dec.decout3(out3);
mn.mon_o3(out3);

dec.decout4(out4);
mn.mon_o4(out4);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "binary_input"); // signals to be traced
sc_trace(tf, in2, "binary_input"); // signals to be traced
sc_trace(tf, out1, "input_is_one");
sc_trace(tf, out2, "input_is_zero");
sc_trace(tf, out3, "input_is_zero");
sc_trace(tf, out4, "input_is_zero");


//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(25,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}
