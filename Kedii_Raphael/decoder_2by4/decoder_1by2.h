/*
* Author: kedii raphael
*/
#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include<systemc.h>

SC_MODULE(decoder){
//input and output ports
sc_in<bool> q;
sc_out<bool> r,l;
//constructor:
SC_CTOR(decoder){
	SC_METHOD(decode);
	sensitive<<q;
	//dont_initialize();
}

//deconstructor
~decoder(){

}

void decode(void){
	r=(q==0)?1:0;
	l=(q==1)?1:0;
}
};




#endif /* DECODER_1BY2_H_ */
