
#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>


int sc_main(int argc, char *argv[]){
//signals
sc_signal<bool> in1, in2, out1, out2, out3, out4;
//module instances
decoder24 dec24("decoder");
driver drvr("driver");
monitor mntr("monitor");

//interconnections
drvr.d_a(in1);
dec24.x(in1);
mntr.m_in1(in1);

drvr.d_b(in2);
dec24.y(in2);
mntr.m_in2(in2);

dec24.q(out1);
mntr.m_out1(out1);

dec24.r(out2);
mntr.m_out2(out2);

dec24.s(out3);
mntr.m_out3(out3);

dec24.t(out4);
mntr.m_out4(out4);

//trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "binary_first_input");
sc_trace(tf, in2, "binary_second_input");
sc_trace(tf, out1, "input_is_zero_and_zero");
sc_trace(tf, out2, "input_is_zero_and_one");
sc_trace(tf, out3, "input_is_one_and_zero");
sc_trace(tf, out4, "input_is_one_and_one");


if( !sc_pending_activity() )
sc_start(60,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}



