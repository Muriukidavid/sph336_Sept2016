#ifndef DRIVER_H_
#define DRIVER_H_

#include<systemc.h>

SC_MODULE(driver){
sc_out<bool> d_a;

SC_CTOR(driver){
	SC_THREAD(drive);
}

void drive(void){
	while(1){
		d_a=0;
		wait(5,SC_NS);
		d_a=1;
		wait(10,SC_NS);
                d_a=0;
		wait(15,SC_NS);
		d_a=1;
	  	wait(20,SC_NS);
                d_a=0;
		wait(25,SC_NS);
		d_a=1;
		wait(30,SC_NS);
	}
}
};
SC_MODULE(enable){
sc_out<bool>d_b;
SC_CTOR(enable){
SC_THREAD(enabl);
}
void enabl(void){
while(1){
d_b=0;
wait(5,SC_NS);
d_b=1;
wait(5,SC_NS);
}
}
};
#endif /* DRIVER_H_ */
