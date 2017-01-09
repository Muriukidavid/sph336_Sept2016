
#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>

SC_MODULE(decoder){
//input and output ports
sc_in<bool> dec_a,dec_b;
sc_out<bool> decout1,decout2,decout3,decout4;
//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder){
	SC_METHOD(decode);
	sensitive<<dec_a<<dec_b;
	//dont_initialize();
}

~decoder(){
//delete stuff :P
}

void decode(void){
	decout1=(dec_a==0&&dec_b==0 )?1:0;
	decout2=(dec_a==0&&dec_b==1 )?1:0;
	decout3=(dec_a==1&&dec_b==0 )?1:0;
	decout4=(dec_a==1&&dec_b==1 )?1:0;
	
}
};




#endif /* DECODER_2BY4_H_ */
