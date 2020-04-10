#!/usr/bin/make  

CXX=g++ 
CXXFLAGS = -Wall  -std=c++17 -Wextra 
EXEC=ice 
HEADPATH = include
SRC= $(wildcard *.cc)
HEADER=$(wildcard $(HEADPATH)/*.hh) 
OBJ = $(SRC:.cc=.o)

all : $(EXEC)

$(EXEC): $(OBJ)
	$(CXX)  -o $@ $^ $(CXXFLAGS)  

ice_main.o: $(HEADER)

%.o :  %.cc 
	$(CXX) -o  $@  -c  $< $(CXXFLAGS) 
	
.PHONY  : clean  mproper 
clean  : 
	rm  -rf *.o 

mproper: clean 
	rm -rf $(EXEC)
