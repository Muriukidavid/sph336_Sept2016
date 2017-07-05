/*
* Author: kedii raphael
*/

#include<systemc.h>
#include "decoder_1by2.h"

SC_MODULE(decoder2){
//input and output ports
sc_in<bool> m, n;
sc_out<bool> v, w, y, x;
sc_signal<bool> sg1, sg2, sg3, sg4, out1, out2, out3, out4;



//pointers
decoder *Decone_ptr, *Dectwo_ptr;


//constructor:
SC_CTOR(decoder2){

	Decone_ptr = new decoder ("decone");
	Decone_ptr->q (m);
	Decone_ptr->r (sg1);
	Decone_ptr->l (sg2);

	Dectwo_ptr = new decoder ("dectwo");
	Dectwo_ptr->q (n);
	Dectwo_ptr->r (sg3);
	Dectwo_ptr->l (sg4);

	SC_METHOD(decode2);
	sensitive<<m<<n;

	SC_METHOD(prc_add1);
	sensitive<<sg1<<sg3;
	SC_METHOD(prc_add2);
	sensitive<<sg1<<sg4;
	SC_METHOD(prc_add3);
	sensitive<<sg2<<sg3;
	SC_METHOD(prc_add4);
	sensitive<<sg2<<sg4;

}

//deconstructor
~decoder2(){

}

void prc_add1 () {
	out1 = sg1 && sg3;
}

void prc_add2 () {
	out2 = sg1 && sg4;

}
void prc_add3 () {
	out3 = sg2 && sg3;
}

void prc_add4 () {
	out4 = sg2 && sg4;
}

void decode2(void){
	v=out1;
	w=out2;
	x=out3;
	y=out4;
}


};




