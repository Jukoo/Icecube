// SPDX-License-Identifier: GPL-2.0-only
/*
 * icecube.h for icecube  - interactive c/cxx environnement 
 * Copyright (C) 2022 , by  Umar <jukoo>  (jUmarB@protonmail.com) 
 */

#include  <stdlib.h>
#include  <string.h> 
#include  <errno.h>
#include  <stdio.h> 
#include  <errno.h> 
#include  <unistd.h>  
#include  <assert.h>
#include  <stdarg.h>


#include "icecube.h"
#include "generic.h" 


static void display_usage(char  *programme_basename ) {
    printf(VERSION) ;  
    fprintf(stdout , "Usage : %s [options...]  [-o outfile] [-i infile] [-l libpath]\n" , programme_basename ) ;
    printf(HELP) ; 

}


void argument_parser ( int argc , char *const *argv ,  IcecubeFlagOptionHdl  * ifoh ) { 
    int option_parser  ; 
 
    /* string operatrion basename  format   display the programme  name without './' */ 
    char  *basename  = argv[0] ;  
    if  ( *basename  ==  0x2e && *(basename+1) ==  0x2f)   
    {
        size_t  basename_size  = strlen(basename) ; 
        char *bn =  calloc(basename_size , sizeof(char)) ;  
        memcpy (bn , basename+2 , basename_size) ;
        memset (basename ,  0 ,   basename_size)  ; 
        memcpy (basename , bn  ,  basename_size)  ; 
        free(bn) ;   
    }
    
    if (argc  == 1 )  
    {
        display_usage(basename) ;  
        exit(EXIT_FAILURE) ; 
    } 
    
     

    while  ( (option_parser = getopt(argc , argv , FLAGS ) ) != -1 ) 
    {
        switch (option_parser) 
        {
            case 'i': 
                MCPYDUMB(ifoh->file_input ,  optarg) ; 
                break ; 
            case 'o':
                MCPYDUMB(ifoh->file_output ,  optarg) ; 
                break  ;
            case 'l':
                MCPYDUMB(ifoh->libname ,  optarg) ; 
                break;   
            case 'v': 
                    printf(VERSION) ;  
                    exit(EXIT_SUCCESS) ; 
                    break; 
            case 'h':
                    display_usage(basename) ;  
                    exit(EXIT_SUCCESS) ; 
                    break ;  
            default  : 
                    display_usage(basename)  ; 
                    exit(EXIT_FAILURE) ;  
        }
    }
}

 static void icemesg (  ICESTREAM  outstream   , char const  * mesg ,  ... ) { 

      
     va_list ap ; 
     va_start ( ap , mesg )  ; 
     
     vdprintf (  outstream  , mesg ,  ap ) ;
     
     if ( errno != 0 ) 
     {
        //! check if use  the right stream file  
        if (  outstream == STDOUT_FILENO )
            dprintf(STDERR_FILENO , "WARNING!!::  Wrong strem broadcast\n") ;  
            
     
        dprintf(STDERR_FILENO, "ICE BROKEN : <%i> :  <%s> \n", errno ,  strerror(errno) )  ;  
     }
    
     dprintf(outstream, "%c" , 0xa) ;  
     fflush((void * ) 0 ) ; //! flush  all stream  
     va_end(ap) ;   

 }  

ICECUBE  Ice_t * begin ( Ice_t *  ice){ 
    ice->context  = ( void * ) 0  ; 
    
    ice->set_new_context = tcc_new ; 
    ice->set_output_mode =  tcc_set_output_type; 
    ice->release  = tcc_delete  ; 
     
    ice->context = ice->set_new_context()  ; 
    
    if ( ice->context  ==  ( void * )0  ) 
    {
        icemesg(ICSTDERR ,  "ICE CUBE: Fail to start new context\n") ; 
        exit(EXIT_FAILURE) ; 
    } 
    
    return ice ;   
}

void *release(Ice_t* ice  )  {  

    ice->release(ice->context) ; 
    if ( ice->context  != ( void * )0 ) 
    {
        //! force to set  invalid  address 
        //NOTE : AVOID USING DOUBLE FREE  CORRUPTION  
        ice->context   =  ( void *) 0  ; 
        
    } 

    return  ice->context ;   
} 



void  source_file ( Ice_t * ice  , const char * file)  { 

    //!TODO : CHECK FILE ENTRY  IF IS VALID ... 

     
    ice->__generic_cb__ = tcc_add_file ;  
   
    ice->__generic_cb__( ice->context ,  file )  ;

    
}
