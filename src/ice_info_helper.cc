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
#include <map>
#include <algorithm>  

#include "include/ice_info_helper.hh"



//! print  g++  version information header
//! and display utils argument
void print_header_intro (std::string  ic_tag_version) {
    OS_CXX_VERSION ;
    std::cout << "iC++ " <<  ic_tag_version << " -- an enhanced  Interactive  C++" <<  std::endl;
    std::map<std::string , std::string> args_helper{
            {"$?","Introduction and OverView  of iC++'s feature "},
            {"#help","iC++ help own sys "}
        } ;
    std::map<std::string , std::string>::iterator i_args_helper ;
    for(i_args_helper = args_helper.begin () ;
        i_args_helper !=  args_helper.end();
        i_args_helper++
        )
        std::cout <<  i_args_helper->first  <<" \t -- "<< i_args_helper->second << std::endl;
}

void  ice_usage ( char  **argv_attribute  )
{
     std::string ice_name = argv_attribute[0x000] ;
     std::replace(ice_name.begin() ,  ice_name.end() , '.' , ' ' ) ;
     std::replace(ice_name.begin() ,  ice_name.end() , '/' , ' ') ;
     std::cout << "USAGE  of "  << ice_name <<std::endl ;
     std::cout << "arguments  available :"  <<std::endl ;
     std::cout << STDNAMESPACE_ARGS <<  "  ->  enable to  use  std namespace "  << std::endl ;


     exit(EXIT_FAILURE) ;

}

void  args_helper ( int & argc ,  char **argv   , bool & stdnamespace_label)  {
    if  (argc  == 0x0002 )
    {
         std::string args_string { argv[0x001] } ;
         if  (args_string == STDNAMESPACE_ARGS )  stdnamespace_label  = true ;
         if  ( args_string ==  "-h"  ||  args_string  =="--help")
             ice_usage(argv) ;

    }
    if (argc > 0x0002 ) ice_usage(argv) ;
}


