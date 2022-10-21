// SPDX-License-Identifier: GPL-2.0-only
/*
 * icecub.h for icecube  - interactive c/cxx environnement 
 * Copyright (C) 2022 , by  Umar <jukoo>  (jUmarB@protonmail.com) 
 */

#include  <stdlib.h>
#include  <string.h> 
#include  <errno.h>
#include  <stdio.h> 
#include  <errno.h> 
#include  <unistd.h>  
#include  <assert.h> 
#include "include/icecude.h"

IceCube *__shared_context  = (void * )0 ;  

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

IceCube    *create_context_from(  ice_t   context_origine )  { 
     __shared_context    =  context_origine()  ;
     if ( __shared_context  ==  ( void * ) 0 ) 
     {
         perror("IceCube context Error ! ") ; 
         exit(EXIT_FAILURE) ; 
     } 

     return  __shared_context ;  

} 

int set_out_mode  (   outmode  __outm  ,  OUT_MODE  __om   ) { 
   printf ("[sm] sc  %p \n" , __shared_context ) ;   
    return  __outm(__shared_context ,  __om   ) ; 

}

int append_file  (  __generic_cb__  cb_callback , char  const *  filetarget) {  
   return  cb_callback(__shared_context ,  filetarget) ;  
} 

void leave_context  ( drop __context   )  {
   __context(__shared_context)  ;
   __shared_context =  ( void * )0 ;  
} 

int  output_exec  ( __generic_cb__  cb_callback  , const char  *__output_file_exec  ){
    char  exec_filename[MAX_SBUFF]  =  DEF_OUTFILE_EXE ;   

    if  ( __output_file_exec !=  (void * )  0 && strlen(__output_file_exec) > 0 )  
    { 
        memset(exec_filename , 0  , MAX_SBUFF ) ; 
        memcpy (exec_filename , __output_file_exec ,  MAX_SBUFF) ; 
    }
   
    return  cb_callback(__shared_context ,  exec_filename  ) ;  
}
