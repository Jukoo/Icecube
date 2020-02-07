#include <iostream>
#include <cstdlib>
#include <stdio.h> 
#include <fstream> 
#include <string>
#include <map> 
#include <vector>
#include <regex>
#include "ic.hh" 

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
static  
void  Rfx_ERR(std::ifstream & r_file ,  std::string  mesg) {
    if (!r_file) 
    { 
        std::cerr <<  mesg << std::endl; 
        exit(RW_FLUX_ERR) ; 
    }
}

static  
void  Wfx_ERR(std::ofstream & w_file ,  std::string  mesg) {
    if (!w_file) 
    { 
        std::cerr <<  mesg << std::endl; 
        exit(RW_FLUX_ERR) ; 
    }
}


//! read binnary file  
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

// just  print  the  variable  affectation  
// int x  = 0  ; 
// ->  0  
//[]  need to perform  this   function  below ....  
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
            std::cout<< directive_statement << std::endl ;  
            directive.push_back(directive_statement) ; 
            return true ; 
        }  

    }else return false  ; 
 
}
void  _records ( 
        std::vector<std::string>&instruction  , 
        std::vector<std::string>&directive   
        ) 
{

    std::string  virtual_cursor  {} ; 
    std::string   ice {BIN_LOC_ _MAIN_} ;
   
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
    
    
    system(CXX   BIN_LOC_  _MAIN_  O_FLAG   BIN_LOC_  EXEC);
    //system("./bin/a.out") ;
    system(A_OUT EXEC) ;
}
