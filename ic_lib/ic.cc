#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <string>
#include <map> 
#include <vector>
#include <regex>
#include "ic.h" 

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
        i_args_helper++) {
        std::cout <<  i_args_helper->first  <<" \t -- "<< i_args_helper->second << std::endl; 
    } 
} 

//! read binnary file  
void  bin_snap(std::ofstream &ic_flux ) {
    std::string bin_file {"sample.cc"};  
    std::ifstream bin_file_flx (bin_file) ; 
    std::string cursor {} ;  
    if(!bin_file_flx){
        std::cerr  << "connot  open bin file " << std::endl;  
        exit(IC_RUNTIME_ERROR)  ; 
    } 
    if (bin_file_flx)  {
        // begin copy  
        while  (bin_file_flx) {
            std::getline(bin_file_flx, cursor) ; 
            // pipe on  ic_flux 
            ic_flux << cursor << std::endl;  
        } 
    }
}
 
void  cursor_filter  (std::string cursor , int &line_count)   {
      std::vector<std::string> paterns_delimiter {"=" ,"{", "<<" ,">>"} ;
      std::vector<std::string> parse_cursor {""} ;
      std::string p_cursor {""} ; 
      int incre  {1};  
      for  (auto patern : paterns_delimiter) {
           size_t partern_pos =  cursor.find(patern) ; 
           while ( (p_cursor  =  cursor[partern_pos+incre])  == " " ) { 
               incre++ ; 
           }
           if(p_cursor != " ") {
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
      for (auto  each_char :  parse_cursor)  {
          result_display+=each_char ;
      }
      
      std::cout<<"Out [" << line_count << "]: "<<result_display << std::endl ; 
} 

void  cxx_compil()  {
    system(CXX FLASH_FILE) ;
    system("./a.out") ;
}
