/*
     #Created on: Nov 15, 2016
            #Author: GITAU JAMES
    #Decoder module
*/


#include<systemc.h>

SC_MODULE(decoder){
	//input and output ports
	sc_in<bool>d_a,d_b;
	sc_out<bool>d_c,d_d,d_e,d_f;
	//constructor:where the processes are bound to simulation kernel
	SC_CTOR(decoder){
		SC_METHOD(decode);
		sensitive<<d_a<<d_b;//sensitive to i0 and i1 which are the inputs
		//dont initialize

	}
	~decoder(){
		//delete stuff :P
	}
	void decode(void){
		if(d_a==0 && d_b==0){
			d_c=1;
			d_d=0;
			d_e=0;
			d_f=0;
		}
		else if(d_a==0 && d_b==1){
			d_c=0;
			d_d=1;
			d_e=0;
			d_f=0;
			}
			else if(d_a==1 && d_b==0){
			d_c=0;
			d_d=0;
			d_e=1;
			d_f=0;
			}
			else if(d_a==1 && d_b==1){
			d_c=0;
			d_d=0;
			d_e=0;
			d_f=1;
			}
	}
};
