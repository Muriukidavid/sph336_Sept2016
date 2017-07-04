*
 * 2by4monitor.h
 *
 *  Created on: Nov 16, 2016
 *      Author: Benson
 */

#ifndef MONITOR_H_
#define MONITOR_H_

#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> m_a,m_a1, m_b, m_b1,m_b2,m_b3;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_b<<m_b1<<m_b2<<m_b3;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" input are: "<<m_a<< "and"<<m_a1<<" outputs are: "<<m_b<<"," <<m_b1<<","<<m_b2<<","<<m_b3<<","<<endl;
}
};



#endif /* 2BY4MONITOR_H_ */
