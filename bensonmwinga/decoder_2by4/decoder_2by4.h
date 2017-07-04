* decoder2by4.h
 *
 *  Created on: Nov 16, 2016
 *      Author: Benson
 */

#ifndef DECODER_H_
#define DECODER_H_

#include <systemc.h>

SC_MODULE(decoder){
//input and output ports
sc_in<bool> a,a1;
sc_out<bool> b,b1,b2,b3;

//constructor: where the processes are bound to simulation kernel
	SC_CTOR(decoder){
	SC_METHOD(decode);
sensitive<<a;
	sensitive<<a1;
	//dont_initialize();
}

~decoder(){
//delete stuff :P
}

void decode(void){
	b=(a==0 && a1==0)?1:0;
	b1=(a==0 && a1==1)?1:0;
	b2=(a==1 && a1==0)?1:0;
	b3=(a==1 && a1==1)?1:0;
}
};



#endif /* DECODER_H_ */
