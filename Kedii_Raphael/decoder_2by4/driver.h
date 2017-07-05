/*
* Author: kedii raphael
*/

#include<systemc>

SC_MODULE(driver){
sc_out<bool> da, db;

SC_CTOR(driver){
	SC_THREAD(drive);
}

void drive(void){
	while(1){
		da=0;
		db=0;
		wait(5,SC_NS);
		da=0;
		db=1;
		wait(5,SC_NS);
		da=1;
		db=0;
		wait(5,SC_NS);
		da=1;
		db=1;
		wait(5,SC_NS);
	}
}
};

