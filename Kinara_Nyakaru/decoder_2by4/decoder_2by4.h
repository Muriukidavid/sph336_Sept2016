/*
* Author: ule msee
*/

#include<systemc.h>
#include "decoder_1by2.h"

SC_MODULE(decoder2){
//input and output ports
sc_in<bool> x, y;
sc_out<bool> q, r, s, t;
sc_signal<bool> s1, s2, s3, s4, out1, out2, out3, out4;



//pointers
decoder *dec1_ptr, *dec2_ptr;


//constructor:
SC_CTOR(decoder2){

	dec1_ptr = new decoder ("dec1");
	dec1_ptr->a (x);
	dec1_ptr->b (s1);
	dec1_ptr->c (s2);

	dec2_ptr = new decoder ("dec2");
	dec2_ptr->a (y);
	dec2_ptr->b (s3);
	dec2_ptr->c (s4);

	SC_METHOD(decode2);
	sensitive<<x<<y;

	SC_METHOD(prc_add1);
	sensitive<<s1<<s3;
	SC_METHOD(prc_add2);
	sensitive<<s1<<s4;
	SC_METHOD(prc_add3);
	sensitive<<s2<<s3;
	SC_METHOD(prc_add4);
	sensitive<<s2<<s4;

}

//deconstructor
~decoder2(){

}

void prc_add1 () {
	out1 = s1 && s3;
}

void prc_add2 () {
	out2 = s1 && s4;

}
void prc_add3 () {
	out3 = s2 && s3;
}

void prc_add4 () {
	out4 = s2 && s4;
}

void decode2(void){
	q=out1;
	r=out2;
	s=out3;
	t=out4;
}


};




