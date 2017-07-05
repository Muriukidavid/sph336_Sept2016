#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> m_a, m_b, m_c;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_c;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" inputs are: "<<m_a<<" and "<<m_b<<" outputs are: "<<m_c<<endl;
}
};

