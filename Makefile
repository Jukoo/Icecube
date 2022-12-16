#!/usr/bin/make 


export CC=cc  
export LTCC_FLAGS = -ltcc  
export CFLAGS= -Wall    -Wextra   -pedantic  -I ./include  $(LTCC_FLAGS)    
SOURCE=src
EXEC=$(SOURCE)/icecube  

all : $(EXEC)

$(EXEC):
	(cd  $(SOURCE)  && $(MAKE))  

	
.PHONY  : clean  mproper  $(EXEC) 
clean  :
	@(cd  $(SOURCE) && $(MAKE) $@)  

mproper: clean $(EXEC)  
	@(cd  $(SOURCE)  && $(MAKE) $@)  
