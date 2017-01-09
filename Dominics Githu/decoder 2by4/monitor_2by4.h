
#ifndef MONITOR4_H_
#define MONITOR4_H_
#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> mon_i1, mon_i2,mon_o1,mon_o2,mon_o3,mon_o4;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<mon_o1<<mon_o2<<mon_o3<<mon_o4;
	dont_initialize();
}

void monita(void){
cout<<"At "<<sc_time_stamp()<<" Input are: "<<mon_i1<<" and "<<mon_i2<<"Outputs are: "<<mon_o1<<" and "<<mon_o2<<"  and "<<mon_o3<<" and  "<<mon_o4<<endl;
}
};
#endif /* MONITOR_H_ */
