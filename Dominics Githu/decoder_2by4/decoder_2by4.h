#include<systemc.h>
#include "decoder_1by2.h"

SC_MODULE(decoder24){
//input and output ports
sc_in<bool> x, y;
sc_out<bool> q , r, s, t;
sc_signal<bool> s1, s2, s3, s4;


//pointers
decoder *d1_pntr, *d2_pntr;


//constructor:
SC_CTOR(decoder24){

	d1_pntr = new decoder ("d1");
	d1_pntr->a (x);
	d1_pntr->b (s1);
	d1_pntr->c (s2);

	d2_pntr = new decoder ("d2");
	d2_pntr->a (y);
	d2_pntr->b (s3);
	d2_pntr->c (s4);



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
~decoder24(){

}

//and gates
void prc_add1 () {
	q = s1 && s3;
}

void prc_add2 () {
	r = s1 && s4;

}
void prc_add3 () {
	s = s2 && s3;
}

void prc_add4 () {
	t = s2 && s4;
}


};



