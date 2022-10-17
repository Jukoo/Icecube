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


#if !defined ( STATEMENTS_PREPROCESS_STACK) 
#define        STATEMENTS_PREPROCESS_STACK

#include <string> 
#include <vector> 


void  init_entry_point(std::vector<std::basic_string<char>>& ); 

void  init_stack_preprocess_head (
        std::vector <std::basic_string<char>> & , 
        bool&) ; 

bool  processor_directive_call(std::basic_string <char>&, std::vector<std::basic_string<char>>&) ;


#endif  
