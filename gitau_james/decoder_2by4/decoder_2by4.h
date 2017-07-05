// Author:Gitau James
#include<systemc.h>
#include "decoder_1by2.h"

SC_MODULE(decoder2){
//input and output ports
sc_in<bool> x, y;
sc_out<bool> s, t, u, v;
sc_signal<bool> signal1, signal2, signal3, signal4;


//pointers
decoder *dec1_ptr, *dec2_ptr;


//constructor:
SC_CTOR(decoder2){

	dec1_ptr = new decoder ("dec1");
	dec1_ptr->a (x);
	dec1_ptr->b (signal1);
	dec1_ptr->c (signal2);

	dec2_ptr = new decoder ("dec2");
	dec2_ptr->a (y);
	dec2_ptr->b (signal3);
	dec2_ptr->c (signal4);



	SC_METHOD(prc_add1);
	sensitive<<signal1<<signal3;
	SC_METHOD(prc_add2);
	sensitive<<signal1<<signal4;
	SC_METHOD(prc_add3);
	sensitive<<signal2<<signal3;
	SC_METHOD(prc_add4);
	sensitive<<signal2<<signal4;

}

//destructor
~decoder2(){

}

//and gates
void prc_add1 () {
	s = signal1 && signal3;
}

void prc_add2 () {
	t = signal1 && signal4;

}
void prc_add3 () {
	u = signal2 && signal3;
}

void prc_add4 () {
	v = signal2 && signal4;
}


};



