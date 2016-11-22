 * 2by4driver.h
 *
 *  Created on: Nov 16, 2016
 *      Author: Benson
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include<systemc>

SC_MODULE(driver){
sc_out<bool> d_a;
sc_out<bool> d_a1;

SC_CTOR(driver){
	SC_THREAD(drive);
}

void drive(void){
	while(1){
		d_a=0; d_a1=0;
		wait(5,SC_NS);
		d_a1=1;
		wait(5,SC_NS);
		d_a=1; d_a1=0;
		wait(5, SC_NS);
		d_a1=1;
		wait(5, SC_NS);

	}
}
};




#endif /* 2BY4DRIVER_H_ */
