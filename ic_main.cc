//! Copyright (C) <2019>  <Juko>
//! This program is free software: you can redistribute it and/or modify
//! it under the terms of the GNU General Public License as published by
//! the Free Software Foundation, either version 3 of the License, or
//! (at your option) any later version.
//! This program is distributed in the hope that it will be useful,
//! but WITHOUT ANY WARRANTY; without even the implied warranty of
//! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//! GNU General Public License for more details.
//! You should have received a copy of the GNU General Public License
//! along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <iostream>
#include <stdlib.h> 
#include <string>
#include <fstream>  
#include <vector>

//---- LINUX  STUFF  
#if defined(__linux__) 
#include  <unistd.h>
#define   __ASM_UNISTD__    
#endif 

//----
#include "ic.hh" 

using namespace  std::literals ;  


int main  (int argc  ,char  **argv )  { 

    print_header_intro() ;

    //!  display   using namespace  std   
    //!+ by default it's not  enabled
    //!+ the user can enabled it by  using  
    //!+ the flag  "--using-std" ;  
    static bool enable_std_prefix { false } ;  
 
    args_helper (argc , argv  , enable_std_prefix) ;  
    //! parse the arguments  on  stdout   
   
    //!  only linux OS  are concerned  to this section 
    //!  that show  ASM syscall  cheetcheat  ...
    #if defined(__ASM_UNISTD__)
    int  arch_base_type  {  ARCH_BYTE } ; 
   
       if  ( argc  == 0x002 )
       {  
            std::string args_str { argv[0x001] } ;  
            if  ( args_str ==  "--asm_syscall" ) {
                std::cout  << set_colorscheme(BLINK,0x00,  B_BLUE)  <<"ASM SYSCALL"<< DEFAULT_COLOR << std::endl; 
                switch ( arch_base_type) {
                    case  32 : system(SHOW  ASM32_H);break;  
                    case  64 : system(SHOW  ASM64_H);break; 
                } 
            }
       }
    #endif  
   
    //!  make visiual alert  that  indicate the user 
    //!  is using stdandar  namespace   
    if ( enable_std_prefix ) 
        std::cout  << set_colorscheme(BLINK,0x00,  B_RED)  <<"USING NAMESPACE STD"  << DEFAULT_COLOR << std::endl; 
    

    
    ABORT_SIG exit_keys ={"quit",  "exit", "bye"} ; 
  
    
    // count  line stdint  -> [ ]
    int line_count{1} ; 
    //  set the default prompt 
    std::string prompt {DEFAULT_PROMPT} ;
    std::string  ic_cursor_reader {""} ;  //! cursor reader on stdout  
IC:
    std::vector<std::string>  instruction_stack  ; 
    std::vector<std::string>  directive_stack    ;  
    init_stack_preprocess_head (directive_stack , enable_std_prefix) ;  
    init_entry_point(instruction_stack)          ; 
    while (INTERACTIVE_LOOP) 
    {
        std::cout << prompt  << "  ["  <<  line_count << "]: " ;
        (void) fflush(stdin) ;
        std::getline(std::cin ,  ic_cursor_reader) ; 
        if(ic_cursor_reader ==  exit_keys.QUIT || 
           ic_cursor_reader ==  exit_keys.EXIT || 
           ic_cursor_reader ==  exit_keys.BYE)  
        {
            std::fprintf(stdout  , "exit with Abort SIG %p  %c", &exit_keys , 0x00a)  ;    
            exit(SIG_INTENTION) ;  
        }
        if ( ic_cursor_reader == "ret" )  
        {  
           // cx_write_stream <<  RET_SYS_CALL << std::endl;
            _records(instruction_stack ,  directive_stack) ;  
            cxx_compil()  ;  
            break ;   
        } 
        
        if (processor_directive_call(ic_cursor_reader , directive_stack ) ==0x000)  
        {
                //cx_write_stream <<ic_cursor_reader << std::endl ; 
                 //cursor_filter(ic_cursor_reader ,  line_count) ;
                 instruction_stack.push_back(ic_cursor_reader);  
        }            
        line_count++ ;      
    
    }

   goto IC;
       
    return  EXIT_SUCCESS ;  
}
