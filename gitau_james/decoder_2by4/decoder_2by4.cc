/*
     #Created on: Nov 15, 2016
            #Author: GITAU JAMES
    #decoder_2by4
*/


#include"decoder0_2by4.h"
#include"driver3.h"
#include"monitor3.h"
#include<systemc.h>
int sc_main(int argc, char *argv[]){
	//some signals for interconections
	sc_signal<bool>input0,input1,output0,output1,output2,output3;
	//module instances
	driver dr("driver_instance");
	decoder dec("decoder_instance");
	monitor mn("monitor_instance");
	//interconnections between modules instances.port()
	dr.dr_a(input0);
	dr.dr_b(input1);
	dec.d_a(input0);
	dec.d_b(input1);
	mn.m_a(input0);
	mn.m_f(input1);
	dec.d_c(output0);
	dec.d_d(output1);
	dec.d_e(output2);
	dec.d_f(output3);
	//monitor outputs
	mn.m_b(output0);
	mn.m_c(output1);
	mn.m_d(output2);
	mn.m_e(output3);
	//create a trace file with nanosecond resolution
	sc_trace_file*tf;
	tf=sc_create_vcd_trace_file("timing_diagram");
	tf->set_time_unit(1, SC_NS);
	//trace the signals interconnecting modules
	sc_trace(tf,input0,"binary_input1");//signals to be traced
	sc_trace(tf,input1,"binary_input2");
	sc_trace(tf,output0,"input_is_zero");
	sc_trace(tf,output1,"input_is_one");
	sc_trace(tf,output2,"input_is_two");
	sc_trace(tf,output3,"input_is_three");
	//run a simulation for 50 systemc nano-seconds
	if(!sc_pending_activity())
		sc_start(50,SC_NS);
	  //close the trace file
	sc_close_vcd_trace_file(tf);
	return 0;
}
