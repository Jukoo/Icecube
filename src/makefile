#!/usr/bin/make 

CC=cc 
LTCC_FLAGS =-ltcc   
CFLAGS= -Wall -Wextra  -pedantic -I ./include   $(LTCC_FLAGS)  
SOURCES=$(wildcard *.c) 
OBJECTS= $(SOURCES:.c=.o)  

bin_exe= icecube  


all=$(bin_exe) 

$(bin_exe) : $(OBJECTS) 
	@echo -e  "[ LD ] $^"
	@$(CC) -o $@   $^ $(CFLAGS)  


%.o : %.c  
	@echo -e "[ CC ] $<" 
	@$(CC) -o $@ -c $<  $(CFLAGS) 
	

.PHONY : clean  mproper 
	 
clean : $(OBJECTS) 
	@echo  -e "[ CLS ] $^"
	rm *.o 
	
mproper  : clean $(bin_exe) 
	@echo -e "remove $<"
	rm $^
