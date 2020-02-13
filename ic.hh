#ifndef ICXX_H
#define ICXX_H

#include <string>
#include <fstream>
#include <stdlib.h>

#define  BIN_LOC_           "bin/"
#define  PREPROC_INCLUDE    "defsrc/def_preproc"
#define  STATMENTS_STARTUP  "defsrc/statement_startup" 


#define  _MAIN_             "__ice__.cc"
#define  O_FLAG             " -o "
#define  EXEC               "freeze" 
#define  A_OUT              "./bin/"

#define  STDNAMESPACE_ARGS  "--using-std"
#define  STDNAMESPACE       "using namespace std;"

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


//! colors 
#define   COLOR_PREFIX_BEGIN "\033["  
#define   DEFAULT_COLOR      "\033[0m" 

//! font style  

#define  NORMAL    0 
#define  BOLD      1  
#define  DARKEN    2 
#define  ITALIC    3 
#define  UNDERLINE 4 
#define  BLINK     5 
#define  REVERSE   7 
#define  INVISIBLE 8
#define  BARRED    9  

//! font colors  
#define  F_BLACK   30
#define  F_RED     31
#define  F_GREEN   32
#define  F_YELLOW  33
#define  F_BLUE    34
#define  F_MAGENTA 35
#define  F_CYAN    36
#define  F_WHITE   37


//! background  colors  
#define  B_BLACK   40
#define  B_RED     41
#define  B_GREEN   42
#define  B_YELLOW  43
#define  B_BLUE    44 
#define  B_MAGENTA 45
#define  B_CYAN    46
#define  B_WHITE   47  






typedef  struct  {
    std::basic_string<char> QUIT ; 
    std::basic_string<char> EXIT ; 
    std::basic_string<char> BYE  ; 
}ABORT_SIG  ;  

std::string  set_colorscheme(int  cs = NORMAL ,  int fc =0x00,  int  bc= 0x00 )  ; 
void  ice_usage ( char **  ) ; 
void  print_header_intro(std::basic_string<char>  = IC_VERSION); 
void  init_entry_point(std::vector<std::basic_string<char>>& ); 
void  cursor_filter (std::basic_string<char>&  ,int & ) ;
void  init_stack_preprocess_head (
        std::vector <std::basic_string<char>> & , 
        bool&) ; 
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
