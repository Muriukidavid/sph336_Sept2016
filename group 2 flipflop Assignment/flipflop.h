#ifndef FLIPFLOP_H
#define FLIPFLOP_H
#include<systemc.h>
SC_MODULE(flipflop){ 
	sc_in<bool>a,b;
	sc_out<bool>c;
	
	SC_CTOR(flipflop){
		SC_METHOD(ff);
			sensitive<<b.pos();
		}
~flipflop(){
}

void ff(void){
	c=a;	
}
};
#endif 


