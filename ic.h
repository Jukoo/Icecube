#ifndef ICXX_H
#define ICXX_H

#include <string>
#include <iostream>

#define  BIN_LOC_           "bin/"
#define  FLASH_FILE         "ffcxx.bin"
#define  TMPF_EXEC          ".ffcxx.cc"
#define  A_OUT              "./a.out"
#define  TEMP               "tmp"

#define  IC_RUNTIME_ERROR   0X03 
#define  IC_VERSION         "v0.0.1"
#define  CXX                "g++ "
#define  OS_CXX_VERSION system("g++  --version")
#define  INTERACTIVE_LOOP   true 
#define  DEFAULT_PROMPT     "In" 
#define  SIG_INTENTION      0x017 
#define  APP_SYS_CALL       "return 0X00 ; }" 

#define  RW_FLUX_ERR        0X03E8 

typedef  struct  {
    std::basic_string<char> QUIT ; 
    std::basic_string<char> EXIT ; 
    std::basic_string<char> BYE  ; 
}ABORT_SIG  ;  

void  print_header_intro(std::basic_string<char>  = IC_VERSION); 
void  bin_snap(std::basic_ofstream <char> & ); 
void  cursor_filter (std::basic_string<char>  ,int & ) ; 
void  cxx_compil() ; 


static
void Rfx_ERR(std::basic_ifstream <char> & ,
                    std::basic_string<char>) ; 
static 
void Wfx_ERR(std::basic_ofstream <char> & ,
                    std::basic_string<char>) ; 


#endif  
