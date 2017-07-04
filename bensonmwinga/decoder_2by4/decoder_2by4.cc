/*
 * 2by4decoder.cc
 *
 *  Created on: Nov 16, 2016
 *      Author: Benson
 */
#include<systemc.h>

#include "decoder.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> ina,ina1,outb,outb1,outb2,outb3;
//module instances
decoder dec("decoder_instance");
driver dr("driver");
monitor mn("monitor");
//interconnections b2in modules
dr.d_a(ina);
dec.a(ina);
mn.m_a(ina);

dr.d_a1(ina1);
dec.a1(ina1);
mn.m_a1(ina1);
dec.b(outb);
mn.m_b(outb);

dec.b1(outb1);
mn.m_b1(outb1);

dec.b2(outb2);
mn.m_b2(outb2);

dec.b3(outb3);
mn.m_b3(outb3);


//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, ina, "1st_binary_input");// signals to be traced
sc_trace(tf,ina1,  "2nd_binary_input");
sc_trace(tf, outb, "input_is_zero");
sc_trace(tf, outb1, "input_is_one");
sc_trace(tf, outb2, "input_is_two");
sc_trace(tf, outb3, "input_is_three");
//run a simulation for 20 system c nanoseconds
if( !sc_pending_activity() )
sc_start(20,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}
