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
#include "ic.hh" 

int main  (int argc  ,char  **argv ) {
    std::vector<std::string>  instruction_stack  ; 
    std::vector<std::string>  directive_stack ;  
    print_header_intro() ;
    ABORT_SIG exit_keys ={"quit",  "exit", "bye"} ; 
 
    std::string const  cx_file{BIN_LOC_ FLASH_FILE} ;
    
    std::cout << cx_file << std::endl;
    
    // open file  and pipe  it  to read stream  
    // to write  the  first step  
    std::ofstream cx_write_stream(cx_file ,  std::ios::out | std::ios::binary);  
    if (!cx_write_stream) 
    {
        std::cerr << "ic++ runtime Error" << std::endl;
        exit(IC_RUNTIME_ERROR) ; 
    }else  pipe2read_stream(cx_write_stream);   
    
    // count  line stdint  -> [ ]
    int line_count{1} ; 
    //  set the default prompt 
    std::string prompt {DEFAULT_PROMPT} ;
    std::string  ic_cursor_reader {""} ;  //! cursor reader on stdout  
IC:
    while (INTERACTIVE_LOOP) 
    {
        std::cout << prompt  << "  ["  <<  line_count << "]: " ;  
        std::getline(std::cin ,  ic_cursor_reader) ; 
        if(ic_cursor_reader ==  exit_keys.QUIT || 
           ic_cursor_reader ==  exit_keys.EXIT || 
           ic_cursor_reader ==  exit_keys.BYE)  
        {
            (void)fprintf(stdout  , "exit with Abort SIG %p  %c", &exit_keys , 0x00a)  ;    
            //return  SIG_INTENTION ; 
            break;  
        }
        if ( ic_cursor_reader == "ret" )  
        {  
            cx_write_stream <<  RET_SYS_CALL << std::endl;
            break ;   
        } 
        if(cx_write_stream) 
        {
            cx_write_stream <<ic_cursor_reader << std::endl ;  
            cursor_filter(ic_cursor_reader ,  line_count) ;
            processor_directive_call(ic_cursor_reader , directive_stack ) ; 
            line_count++ ;
           instruction_stack.push_back(ic_cursor_reader) ;
        } 
    }

    //compile section 
   cxx_compil() ;
   goto IC;
       
    return  EXIT_SUCCESS ;  
}
