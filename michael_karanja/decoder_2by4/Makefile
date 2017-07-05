

GTKWAVE := $(shell which gtkwave)
2BY4 :=decoder

all: decoder

decoder:prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.1/include -O0 -g3 -Wall -c decoder_2by4.cc
	$(CXX) -L/usr/local/systemc-2.3.1/lib-linux64 -o "$(2BY4)" decoder_2by4.o -lsystemc
	./$(2BY4)
	gtkwave -c 4 timing_diagram.vcd

prerequisites: 
ifneq "$(GTKWAVE)" "/usr/bin/gtkwave"
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm *.out *.o *.vcd

.PHONY: decoder
