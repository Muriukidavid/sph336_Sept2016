
#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>


int sc_main(int argc, char *argv[]){
//signals
sc_signal<bool> input1, input2, output1, output2, output3, output4;
//module instances
decoder2 dec2("decoder");
driver dr("driver");
monitor mn("monitor");

//interconnections
dr.d_a(input1);
dec2.x(input1);
mn.monitor_a(input1);

dr.d_b(input2);
dec2.y(input2);
mn.monitor_b(input2);

dec2.s(output1);
mn.monitor_c(output1);

dec2.t(output2);
mn.monitor_d(output2);

dec2.u(output3);
mn.monitor_e(output3);

dec2.v(output4);
mn.monitor_f(output4);

//trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, input1, "binary_first_input");
sc_trace(tf, input2, "binary_second_input");
sc_trace(tf, output1, "input_is_zero_and_zero");
sc_trace(tf, output2, "input_is_zero_and_one");
sc_trace(tf, output3, "input_is_one_and_zero");
sc_trace(tf, output4, "input_is_one_and_one");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(60,SC_NS);
//close the trace file
cout<<"argv[1]: "<<atoi(argv[1])<<endl;
sc_close_vcd_trace_file(tf);
return 0;
}



