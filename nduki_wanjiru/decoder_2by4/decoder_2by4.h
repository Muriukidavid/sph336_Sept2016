

#include<systemc.h>
#include "decoder_1by2.h"

SC_MODULE(decoder2){
//input and output ports
sc_in<bool> a,b;
sc_out<bool> c,d,e,f;
sc_signal<bool> s1, s2, s3, s4, out1, out2, out3, out4;



//pointers
decoder *decoder1_ptr, *decoder2_ptr;


//constructor:
SC_CTOR(decoder2){

	decoder1_ptr = new decoder ("dec1");
	decoder1_ptr->a (a);
	decoder1_ptr->b (s1);
	decoder1_ptr->c (s2);

	decoder2_ptr = new decoder ("dec2");
	decoder2_ptr->a (b);
	decoder2_ptr->b (s3);
	decoder2_ptr->c (s4);

	SC_METHOD(decode2);
	sensitive<<a<<b;

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
	out1 = s1&s3;
}

void prc_add2 () {
	out2 = s1&s4;

}
void prc_add3 () {
	out3 = s2&s3;
}

void prc_add4 () {
	out4 = s2&s4;
}

void decode2(void){
	c=out1;
	d=out2;
	e=out3;
	f=out4;
}


};




