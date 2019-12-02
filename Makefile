#!/usr/bin/make  
CXX=g++ 
CXXFLAG = -v -Wextra 
EXEC=icc
SRC= $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)

all : $(EXEC)

$(EXEC): $(OBJ)
	$(CXX)  -o $@ $^ $(CXXFLAG)  

ic_main.o: ic.h

%.o :  %.cc 
	$(CXX) -o  $@  -c  $< $(CXXFLAG) 
	
.PHONY  : clean  mproper 
clean  : 
	rm  *.o 

mproper: clean 
	rm  $(EXEC)
