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


#if !defined( BASIC_OS_CONF )  
#define       BASIC_OS_CONF 


#if defined(__linux__) 

#define  ASM64_H            "/usr/include/x86_64-linux-gnu/asm/unistd_64.h" 
#define  ASM32_H            "/usr/include/x86_64-linux-gnu/asm/unistd_32.h" 

#define  BIN_LOC_           "/usr/bin/"

#define  PREPROC_INCLUDE    "/usr/share/ice/defsrc/def_preproc"
#define  STATMENTS_STARTUP  "/usr/share/ice/defsrc/statement_startup" 


#define  _MAIN_             "/usr/share/ice/defsrc/__ice__.cc"
#define  O_FLAG             " -o "
#define  EXEC               "ice_freeze" 
#define  A_OUT              "./bin/"
#define  SHOW               " cat" 
#endif  //! __linux__  


#endif  //!  BASIC_OS_CONF 
