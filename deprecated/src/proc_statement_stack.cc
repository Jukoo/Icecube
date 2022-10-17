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
#include <vector>
#include <string>
#include <fstream> 

#include  "include/tty_colors.hh"
#include  "include/os_conf.hh"
#include  "include/proc_statement_stack.hh"
#include  "include/ice_info_helper.hh"



void init_entry_point(std::vector<std::string>& first_statement_stack) {
    std::string  ref_file {STATMENTS_STARTUP};
    std::ifstream cx_read_stream (ref_file) ;
    std::string cursor {} ;

    if  (cx_read_stream)
    {
        while  (std::getline(cx_read_stream, cursor))
        {
            first_statement_stack.push_back(cursor) ;
        }
    }

}


void  init_stack_preprocess_head (
        std::vector <std::string >& preprocess_first_directive,
        bool &is_std_namespace_enable ) {

    std::ifstream def_pp_stream {PREPROC_INCLUDE};
    std::string cursor  {} ;
    while (  std::getline(def_pp_stream ,  cursor))
    {
            preprocess_first_directive.push_back(cursor) ;
    }

    if  (is_std_namespace_enable)
    {
        preprocess_first_directive.push_back(STDNAMESPACE) ;
    }


}
// detect  all  the preprocessor  declared  inside the interpreter
bool   processor_directive_call( std::string &cursor, std::vector<std::string>& directive) {
    std::string  hashtag   { "#" }  ;
    std::string  directive_statement{} ;
    size_t  pos = cursor.find(hashtag) ;
    std::string  sp  {} ;
    if ( (sp   =  cursor[pos] ) == hashtag)
    {
        for (size_t i = 0 ; i < cursor.size() ;  i++ )
            directive_statement+=cursor[i] ;

        if ( directive_statement.size() >  0x000 )
        {
            std::cout<<set_colorscheme(ITALIC,F_GREEN , 0X00) <<directive_statement  << DEFAULT_COLOR << std::endl ;
            directive.push_back(directive_statement) ;
            return true ;
        }

    }else return false  ;

}

