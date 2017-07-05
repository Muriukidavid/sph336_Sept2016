/*
* Author: lorraine kupa
*/

#include<systemc.h>
#include "decoder_1by2.h"

SC_MODULE(decoder2){
//input and output ports
sc_in<bool> e, f;
sc_out<bool> g, h, i, j;
sc_signal<bool> s1, s2, s3, s4, out1, out2, out3, out4;



//pointers
decoder *Dec1_ptr, *Dec2_ptr;


//constructor:
SC_CTOR(decoder2){

	Dec1_ptr = new decoder ("dec1");
	Dec1_ptr->a (e);
	Dec1_ptr->b (s1);
	Dec1_ptr->c (s2);

	Dec2_ptr = new decoder ("dec2");
	Dec2_ptr->a (f);
	Dec2_ptr->b (s3);
	Dec2_ptr->c (s4);

	SC_METHOD(decode2);
	sensitive<<e<<f;

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
	g=out1;
	h=out2;
	i=out3;
	j=out4;
}


};




