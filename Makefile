#!/usr/bin/make  
CXX=g++ 
CXXFLAG = -Wall  -std=c++17 -Wextra 
EXEC=ice
SRC= $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)

all : $(EXEC)

$(EXEC): $(OBJ)
	$(CXX)  -o $@ $^ $(CXXFLAG)  

ic_main.o: ic.hh

%.o :  %.cc 
	$(CXX) -o  $@  -c  $< $(CXXFLAG) 
	
.PHONY  : clean  mproper 
clean  : 
	rm  *.o 

mproper: clean 
	rm  $(EXEC)
