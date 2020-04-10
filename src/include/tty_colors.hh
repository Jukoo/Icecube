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


#if !defined(TTY_COLORS_STDOUT) 
#define      TTY_COLORS_STDOUT  

#include <string.h>  

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


std::string set_colorscheme(int  cs = NORMAL ,  int fc =0x00,  int  bc= 0x00 )  ; 

#endif 
