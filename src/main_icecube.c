#include <stdlib.h> 
#include <stdio.h>
#include <assert.h>
#include <errno.h> 

#include "icecube.h"  
#include "generic.h" 

int
main (int argc , char **argv )  { 

    IcecubeFlagOptionHdl  ifoh  ; 
    argument_parser(argc , argv ,  &ifoh) ;

    Ice_t icube ; 
    (void * ) begin(&icube) ;  //! initialize the  context  
                               
    icube.set_output_mode(icube.context ,  OUT_EXE) ; 
   
    source_file(&icube, ifoh.file_input)  ;  

    release(&icube) ;
    
    return EXIT_SUCCESS ;  

} 
