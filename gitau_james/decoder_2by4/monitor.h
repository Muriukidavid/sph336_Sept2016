#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> monitor_a, monitor_b, monitor_c, monitor_d, monitor_e, monitor_f;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<monitor_c<<monitor_d<<monitor_e<<monitor_f;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" inputs signals are: "<<monitor_a<<" and "<<monitor_b<<" outputs signals are: "<<monitor_c<<" and "<<monitor_d<<" and "<<monitor_e<<" and "<<m_f<<endl;
}
};
