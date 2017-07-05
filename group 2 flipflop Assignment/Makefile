
GTKWAVE := $(shell which gtkwave)

all: flipflop

decoder:prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.1/include -O0 -g3 -Wall -c flipflop.cc
	$(CXX) -L/usr/local/systemc-2.3.1/lib-linux64 -o "flop" flipflop.o -lsystemc
	./flop
	gtkwave -c 4 timing_diagram.vcd

prerequisites: 
ifneq "$(GTKWAVE)" "/usr/bin/gtkwave"
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif
.PHONY: flipflop
