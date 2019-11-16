
CXX  =g++  

CXXFLAG = -v -Wextra  

exec_name=ic++



$(exec_name): ic_main.cc  ic_lib/ic.cc 
	$(CXX)  -o $@ $^ $(CXXFLAG)  
