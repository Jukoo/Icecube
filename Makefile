#!/usr/bin/make  
export CXX=g++ 
export CXXFLAG = -Wall  -std=c++17 -Wextra  
SOURCE=src
EXEC=$(SOURCE)/ice  

all : $(EXEC)

$(EXEC):
	(cd  $(SOURCE)  && $(MAKE))  

	
.PHONY  : clean  mproper  $(EXEC) 
clean  :
	@(cd  $(SOURCE) && $(MAKE) $@)  

mproper: clean 
	@(cd  $(SOURCE)  && $(MAKE) $@)  
