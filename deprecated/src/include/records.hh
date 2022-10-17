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

#if !defined ( RECORDS ) 
#define        RECORDS  

#define  INTERACTIVE_LOOP   true
#define  DEFAULT_PROMPT     "In"
#define  SIG_INTENTION      0x017
#define  RET_SYS_CALL       "return 0X00 ; }"
#define  COMPILE            "ret"             //! key word  to  compile  programme   

#define  RW_FLUX_ERR        0X03E8

void  cursor_filter (std::basic_string<char>&  ,int & ) ;   //   On build  [ not yet  used  ]  

void  _records (
        std::vector<std::basic_string<char>>&  ,
        std::vector<std::basic_string<char>>& 
        ) ; 

void  cxx_compil() ; 


#endif  
