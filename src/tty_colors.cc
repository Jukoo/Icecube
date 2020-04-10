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

#include <string>
#include "include/tty_colors.hh"



std::string  set_colorscheme ( int style   , int font_color  , int background_color ) {
        
        std::string font_style =  std::to_string(style); 
        if  ( font_color  != 0x00 ) 
        {  
             return  COLOR_PREFIX_BEGIN + font_style + ";"+ std::to_string(font_color) + "m" ;  
        }else if (background_color != 0x00 ) {
             return  COLOR_PREFIX_BEGIN + font_style +";"+ std::to_string(background_color)+ "m" ;  
        }else if  ( font_color != 0x00  && background_color!= 0x00) {
            return  COLOR_PREFIX_BEGIN + font_style +";" +std::to_string(font_color) +";"+std::to_string(background_color)+ "m" ;  
        } 
}

