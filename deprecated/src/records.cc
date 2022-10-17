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

#include   <iostream>
#include   <cstdlib> 
#include   <string>  
#include   <vector>  
#include   <fstream> 

#include  "include/os_conf.hh"
#include  "include/records.hh"
#include  "include/ice_info_helper.hh"

void  cursor_filter  (std::string &cursor , int &line_count)   {
      std::vector<std::string> paterns_delimiter {"=" ,">","{", "<<" ,">>"} ;
      std::vector<std::string> parse_cursor {""} ;
      std::string p_cursor {""} ; 
      int incre  {1};  
      
      for  (auto patern : paterns_delimiter) 
      {
           size_t partern_pos =  cursor.find(patern) ; 
           
           // continue reading  even  the space  between  
           while ((p_cursor  =  cursor[partern_pos+incre])  == " " )
           {  
               incre++ ; 
           }
           
           if(p_cursor != " ") 
           {
                parse_cursor.push_back(p_cursor) ;  
                int  read_next_char {1} ; 
                int p_cursor_pos = cursor.find(p_cursor) ; 
                while((p_cursor = cursor[p_cursor_pos+read_next_char]) != ";") { 
                    parse_cursor.push_back(p_cursor) ;
                    read_next_char++ ;  
                }
           }
           break ;  
      }  
      
      std::string result_display {""} ; 
      
      for (auto  each_char :  parse_cursor)
      { 
          result_display+=each_char ;
      } 
      std::fprintf(stdout  , " Out [%d] %n" , result_display );  
      //std::cout<<"Out [" << line_count << "]: "<<result_display << std::endl ; 
}

void  _records ( 
        std::vector<std::string>&instruction  , 
        std::vector<std::string>&directive   
        ) 
{

    std::string  virtual_cursor  {} ; 
    std::string   ice {_MAIN_} ;
   
    // clear the previews record  
    std::ofstream  previews_record_stream  ( ice.c_str()  , std::ios::out| std::ios::trunc) ;  
    if  (!previews_record_stream) 
    {
        std::fprintf(stderr , "cannot truncate the previews  records ... %c" , 0x00a ) ;  
        // force to remove   the preview record  
        if ( remove(ice.c_str()) !=  ~-0x001)  
            exit(EXIT_FAILURE) ; 
    }
          
    //  std::ofstream  main_stream_record_add (ice.c_str()  , std::ios::app) ; 
    // don't forget to flus previews record   
     
    std::ofstream main_stream_record(ice.c_str() , std::ios::app) ; 

    if (  !main_stream_record  ) 
    {
        std::fprintf(stderr ,  " ICE  broken  %s %c" ,  ice , 0x00a) ; 
        exit(EXIT_FAILURE) ; 
    } 
           
    if  ( directive.size()  >  0x00 ) 
    {
        for  ( auto  &i  : directive )
            main_stream_record  << i << std::endl ; 
    }
             
    if( instruction.size() > 0x00 )  
    {
        for(auto &i : instruction ) 
            main_stream_record << i  << std::endl ; 
    }
     
    //after catching all the  record  
    //  call the  last  statement   
    main_stream_record <<   RET_SYS_CALL <<  std::endl  ; 
 }

/*
 *
 * reading binary  file to generate
 * the target to make the compilation 
 */
void  cxx_compil()  {
   /* std::string ffcxx {BIN_LOC_ FLASH_FILE}; 
    int dot_pos  = ffcxx.find(".") ; 
    std::string ffcxx_CC_ext  =  ffcxx.substr(0x00 , dot_pos) + ".cc"; 
    std::string no_bin_prefix =  ffcxx_CC_ext.substr(ffcxx_CC_ext.find("/") ,9);
    std::replace(no_bin_prefix.begin()  , no_bin_prefix.end() , '/' , '.') ; 
   */  
    
    
    std::string  binexe  {  BIN_LOC_  EXEC }  ; 
    std::ifstream  exec  (binexe.c_str())    ; 
    if ( exec )  
    {
        if  ( remove(binexe.c_str()) != ~ -0x0001  ) 
        {
             std::fprintf(stderr ,  "Compilation  Error  \n") ; 
             exit(EXIT_FAILURE) ; 
        }
    }
    
    
    //system(CXX   BIN_LOC_  _MAIN_  O_FLAG   BIN_LOC_  EXEC);
    system(CXX   _MAIN_  O_FLAG   BIN_LOC_  EXEC);
    //system("./bin/a.out") ;
    //system(A_OUT EXEC) ;
    system(EXEC) ;
}

