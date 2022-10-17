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

#if !defined( ICE_I_HELPER ) 
#define       ICE_I_HELPER 

#define  STDNAMESPACE_ARGS  "--using-std"               //!  argument  flag  to enable  standard  namespace    : ice  --using-std  
#define  STDNAMESPACE       "using namespace std;"  

#define  IC_RUNTIME_ERROR   0X03 

#define  IC_VERSION         "v0.0.1"
#define  CXX                "g++ "
#define  OS_CXX_VERSION system("g++  --version")


void args_helper  ( int & , char ** ,  bool &);

void ice_usage ( char **  ) ;

void  print_header_intro(std::basic_string<char>  = IC_VERSION);


#endif  
