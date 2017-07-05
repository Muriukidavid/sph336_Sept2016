This is a 2-by-4 decoder example, which is a makefile project and so no need for an IDE. 
Just cd into this folder and run the command 

    make decoder


A line decoder is a device that changes the input code into a set of signals.<br>
It takes an n-digit binary number and decodes it into 2<sup>n</sup> data lines.
It does the reverse of encoding. <br>
In the following truth table, the output out1 is high when the inputs in1 and in2 are both 0, the output out1 is high when the input in1 is 0 and in2 is 1, the output out2 is high when the input in1 is 1 and in2 is 0, the output out3 is high when the input in1 is 1 and in2 is 1. It decodes a single digit binary number.
Only one signal is high(selected) when the right binary number is available on the input. <br>
Its truth table: 
<p align="left">
  <img src="2by4decoder_truth_table.png" width="250"/>
</p>

###Circuit:
<p align="left">
  <img src="2by4 dec_circuit.png" width="200"/>
</p>

Model of computation:
<p align="left">
  <img src="MOC_dec2by4.png" width="400"/>
</p>
Results:
The above MOC was implemented in systemc (code in this folder) and the following output found from traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="timing_diagram.png" width="400"/>
<p>


