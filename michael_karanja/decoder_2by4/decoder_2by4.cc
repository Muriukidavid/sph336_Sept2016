
#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>


int sc_main(int argc, char *argv[]){
//signals
sc_signal<bool> in1, in2, out1, out2, out3, out4;
//module instances
decoder2 dec2("decoder");
driver dr("driver");
monitor mn("monitor");

//interconnections
dr.d_a(in1);
dec2.x(in1);
mn.m_a(in1);

dr.d_b(in2);
dec2.y(in2);
mn.m_b(in2);

dec2.s(out1);
mn.m_c(out1);

dec2.t(out2);
mn.m_d(out2);

dec2.u(out3);
mn.m_e(out3);

dec2.v(out4);
mn.m_f(out4);

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

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(60,SC_NS);
//close the trace file
cout<<"argv[1]: "<<atoi(argv[1])<<endl;
sc_close_vcd_trace_file(tf);
return 0;
}



