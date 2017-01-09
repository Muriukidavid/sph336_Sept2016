/*
     #Created on: Nov 15, 2016
            #Author: GITAU JAMES
    #Driver module
*/


#ifndef DRIVER_H_
#define DRIVER_H_
#include<systemc>

SC_MODULE(driver){
	sc_out<bool>dr_a,dr_b;
	SC_CTOR(driver){
	    SC_THREAD(drive);
	}
	void drive(void){
		while(1){
			dr_a=0;
			dr_b=0;
			wait(5,SC_NS);
			dr_a=0;
			dr_b=1;
			wait(5,SC_NS);
			dr_a=1;
			dr_b=0;
			wait(5,SC_NS);
			dr_a=1;
			dr_b=1;
			wait(5,SC_NS);
		}
	}
};
#endif
