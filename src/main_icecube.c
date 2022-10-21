#include <stdlib.h> 
#include <stdio.h>
#include <assert.h>
#include <errno.h> 

#include "include/icecude.h"  

int
main (int argc , char **argv )  { 

    IcecubeFlagOptionHdl  ifoh  ; 
    argument_parser(argc , argv ,  &ifoh) ;

    (IceCube*) create_context_from(tcc_new) ; 
      
    
    if(set_out_mode(tcc_set_output_type , OUT_EXE )  != 0 )  
    {
        perror("output mode error  ! ") ; 
        exit(EXIT_FAILURE) ; 
    } 
        
    if(append_file(tcc_add_file , ifoh.file_input ) ==-1  ) 
    {
        perror("ICECUBE  compile time error" ) ; 
        return EXIT_FAILURE ;  
    }
    
    if ( output_exec (tcc_output_file  ,  NULL ) != 0 )  
    {
        perror("ICECUBE  compile time error") ;
        return EXIT_FAILURE  ;  
    }

    leave_context (tcc_delete)  ; 
    return EXIT_SUCCESS ; 
} 
