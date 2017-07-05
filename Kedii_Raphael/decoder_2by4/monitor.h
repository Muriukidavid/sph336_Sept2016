/*
* Author: Kedii raphael
*/

#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> ma, mb, mc, md, me, mf;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<mc<<md<<me<<mf;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" inputs are: "<<ma<<" and "<<mb<<" outputs are: "<<mc<<" and "<<md<<" and "<<me<<" and "<<mf<<endl;
}
};

