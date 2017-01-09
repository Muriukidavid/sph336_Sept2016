/*
* Author: ule msee
*/

#include<systemc.h>

SC_MODULE(decoder){
//input and output ports
sc_in<bool> a;
sc_out<bool> b,c;
//constructor:
SC_CTOR(decoder){
	SC_METHOD(decode);
	sensitive<<a;
	//dont_initialize();
}

//deconstructor
~decoder(){

}

void decode(void){
	b=(a==0)?1:0;
	c=(a==1)?1:0;
}
};




