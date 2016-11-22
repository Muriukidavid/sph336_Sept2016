CXX=g++

all: decoder2by4

decoder2by4:
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.1/include -O0 -g3 -Wall -c decoder.cc
	$(CXX) -L/usr/local/systemc-2.3.1/lib-linux64 -o "decoder" decoder.o -l systemc
	

	./decoder
	gtkwave  timing_diagram.vcd
clean:	
	rm ./decoder
	rm -o
.PHONY:
	decoder
