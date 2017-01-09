GTKWAVE := $(shell which gtkwave)
PROG :=decoder

all: decoder

decoder:prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.1/include -O0 -g3 -Wall -c decoder_2by4.cc
	$(CXX) -L/usr/local/systemc-2.3.1/lib-linux64 -o "$(PROG)" decoder_2by4.o -lsystemc
	./$(PROG)
	gtkwave -c 4 2by4timing_diagram.vcd

prerequisites: 
ifneq "$(GTKWAVE)" "/usr/bin/gtkwave"
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm decoder *.o *.vcd

.PHONY: decoder
