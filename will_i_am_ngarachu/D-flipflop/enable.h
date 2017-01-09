#ifndef ENABLE_H
#define ENABLE_H
#include<systemc.h>
SC_MODULE(enable){
sc_out<bool>d_b;
SC_CTOR(enable){
SC_THREAD(enabl);
}
void enabl(void){
while(1){
d_b=0;
wait(5,SC_NS);
d_b=1;
wait(5,SC_NS);
}
}
};
#endif
