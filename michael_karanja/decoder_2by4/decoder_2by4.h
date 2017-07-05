#include<systemc.h>
#include "decoder_1by2.h"

SC_MODULE(decoder2){
//input and output ports
sc_in<bool> x, y;
sc_out<bool> s, t, u, v;
sc_signal<bool> s1, s2, s3, s4;


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

//and gates
void prc_add1 () {
	s = s1 && s3;
}

void prc_add2 () {
	t = s1 && s4;

}
void prc_add3 () {
	u = s2 && s3;
}

void prc_add4 () {
	v = s2 && s4;
}


};



