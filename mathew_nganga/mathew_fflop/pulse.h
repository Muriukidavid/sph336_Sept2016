#ifndef pulse_H
#define pulse_H
#include<systemc.h>
SC_MODULE(pulse){
sc_out<bool>p_b;
SC_CTOR(pulse){
SC_THREAD(pl);
}
void pl(void){
while(1){
p_b=0;
wait(5,SC_NS);
p_b=1;
wait(5,SC_NS);
}
}
};
#endif
