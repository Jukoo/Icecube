#ifndef ICXX_H
#define ICXX_H

#include <string>
#include <fstream>
#include <cstdlib>

#define  BIN_LOC_           "bin/"
#define  PREPROC_INCLUDE    "defsrc/def_preproc"
#define  STATMENTS_STARTUP  "defsrc/statement_startup" 


#define  _MAIN_             "__ice__.cc"
#define  O_FLAG             " -o "
#define  EXEC               "freeze" 
#define  A_OUT              "./bin/"



#define  IC_RUNTIME_ERROR   0X03 
#define  IC_VERSION         "v0.0.1"
#define  CXX                "g++ "
#define  OS_CXX_VERSION system("g++  --version")
#define  INTERACTIVE_LOOP   true 
#define  DEFAULT_PROMPT     "In" 
#define  SIG_INTENTION      0x017 
#define  RET_SYS_CALL       "return 0X00 ; }"
#define  COMPILE            "ret"


#define  RW_FLUX_ERR        0X03E8 

typedef  struct  {
    std::basic_string<char> QUIT ; 
    std::basic_string<char> EXIT ; 
    std::basic_string<char> BYE  ; 
}ABORT_SIG  ;  

void  print_header_intro(std::basic_string<char>  = IC_VERSION); 
void  init_entry_point(std::vector<std::basic_string<char>>& ); 
void  cursor_filter (std::basic_string<char>&  ,int & ) ;
void  init_stack_preprocess_head (std::vector <std::basic_string<char>>  & ) ; 
bool  processor_directive_call(std::basic_string <char>&, std::vector<std::basic_string<char>>&) ;

void  _records (
        std::vector<std::basic_string<char>>&  ,
        std::vector<std::basic_string<char>>& 
        ) ; 

void  cxx_compil() ; 



static
void Rfx_ERR(std::basic_ifstream <char> & ,
                    std::basic_string<char> msg = NULL ) ; 
static 
void Wfx_ERR(std::basic_ofstream <char> & ,
                    std::basic_string<char> msg =  NULL ) ; 


#endif  
