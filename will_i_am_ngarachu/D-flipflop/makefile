
GTKWAVE := $(shell which gtkwave)
PROG :=Dflipflop

all: Dflipflop

Dflipflop:prerequisites
	 @echo 'building file $(@F)'
	 $(CXX) -I/usr/local/systemc-2.3.1/include -O0 -g3 -Wall -c flipflop.cc
	 $(CXX) -L/usr/local/systemc-2.3.1/lib-linux64 -o "$(PROG)" flipflop.o -lsystemc
	 ./$(PROG)
	 gtkwave -c 4 timing1_diagram.vcd

prerequisites: 
ifneq "$(GTKWAVE)" "/usr/bin/gtkwave"
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm Dflipflop *.o *.vcd 
.PHONY: Dflipflop
