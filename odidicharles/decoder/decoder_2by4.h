#include<systemc.h>
#include "decoder_1by2.h"

SC_MODULE (two_by_four){

	sc_in<bool> a,b;
	sc_out<bool>c, d, e, f;
	sc_signal<bool> s1,s2,s3,s4;

	decoder *dec1_ptr, *dec2_ptr;

SC_CTOR (two_by_four){
	
	dec1_ptr = new decoder("dec1");
		dec1_ptr -> a (a);
		dec1_ptr -> b(s1);
		dec1_ptr -> c(s2);
	dec2_ptr = new decoder("dec2");
		dec2_ptr -> a (b);
		dec2_ptr -> b (s3);
		dec2_ptr -> c (s4);

SC_METHOD (prc_one);
	sensitive<<s1<<s3;
SC_METHOD(prc_two);
	sensitive<<s1<<s4;
SC_METHOD(prc_three);
	sensitive<<s2<<s3;
SC_METHOD(prc_four);
	sensitive<<s2<<s4;

}
//deconstructor
~two_by_four(){

}
void prc_one(){
	c = s1 && s3;
}
void prc_two(){
	d = s1 && s4;
}
void prc_three(){
	e = s2 && s3;
}
void prc_four(){
	f = s2 && s4;
}

};
