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
#include <cstdlib> 
#include <string>
#include <fstream>  
#include <vector>
#include "ic_lib/ic.h" 


int main  (int argc  ,char  **argv ) {
    std::vector<std::string>  i_global_container ;   
    print_header_intro() ;
    ABORT_SIG exit_keys ={"quit",  "exit", "bye"} ; 
    
    std::string  ic_cursor_reader {""} ;  //! cursor reader on stdout 
    std::string const cxx_flash{FLASH_FILE} ; 

    std::ofstream cxx_flux(cxx_flash.c_str()); 
    if (!cxx_flux) {
        std::cerr << "ic++ runtime Error" << std::endl;
        exit(IC_RUNTIME_ERROR) ; 
    }else  bin_snap(cxx_flux); 
    
    // count  line stdint  -> [ ]
    int line_count{1} ; 
    //  set the default prompt 
    std::string prompt {DEFAULT_PROMPT} ;
IC:
    while (INTERACTIVE_LOOP) {
        std::cout << prompt  << "  ["  <<  line_count << "]: " ;  
        std::getline(std::cin ,  ic_cursor_reader) ; 
        if(ic_cursor_reader ==  exit_keys.QUIT || 
           ic_cursor_reader ==  exit_keys.EXIT || 
           ic_cursor_reader ==  exit_keys.BYE)  {
            cxx_flux << APP_SYS_CALL  <<std::endl ;  
            //exit(SIG_INTENTION) ; 
            
            break ; 
        } 
          
        if(cxx_flux) {
            cxx_flux <<ic_cursor_reader << std::endl ;  
            cursor_filter(ic_cursor_reader ,  line_count) ;
            line_count++ ;
            i_global_container.push_back(ic_cursor_reader) ;
        } 
    }

    //compile section 
    cxx_compil() ;
    
    goto IC; 
    
    return  EXIT_SUCCESS ;  
}
