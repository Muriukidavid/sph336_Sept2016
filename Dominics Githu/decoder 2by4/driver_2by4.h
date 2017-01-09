
#ifndef DRIVER4_H_
#define DRIVER4_H_

#include<systemc>

SC_MODULE(driver){
sc_out<bool> drver_ina,drver_inb;

SC_CTOR(driver){
	SC_THREAD(drive);
}

void drive(void){
	while(1){
		drver_ina=0,drver_inb=0;
		wait(5,SC_NS);
		
		drver_ina=0,drver_inb=1;
		wait(5,SC_NS);
		
		drver_ina=1,drver_inb=0;
		wait(5,SC_NS);
		
		drver_ina=1,drver_inb=1;
		wait(5,SC_NS);
	}
}
};
#endif /* DRIVER_H_ */
