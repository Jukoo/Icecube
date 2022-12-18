// SPDX-License-Identifier: GPL-2.0-only
/*
 * icecub.h for icecube  - interactive c/cxx environnement 
 * Copyright (C) 2022 , by  Umar <jukoo>  (jUmarB@protonmail.com) 
 */

#ifndef ICE_CUBE 
#define ICE_CUBE 

#include <libtcc.h> 

/* icecube wrap libtcc  api*/
#ifdef LIBTCCAPI 

#define ICECUBE  
typedef  enum  { 
    OUT_MEM  = 1 ,   
    OUT_EXE , 
    OUT_DLL ,
    OUT_OBJ , 
    OUT_PRP  
} OUT_MODE  ;  

typedef  struct  TCCState IceCube  ; 

typedef struct   { 
    IceCube  *context ; 
    IceCube  *(*set_new_context) (void ) ; 
    int  (*set_output_mode)(IceCube  *  , OUT_MODE  ) ; 
    void (*end_context) (IceCube *  )     
}Ice_t ;
    
/* generic  function that  have same  signature :   
 * -> tcc_add_file 
 * -> tcc_get_symbol
 * -> tcc_add_library 
 * -> tcc_add_library_path 
 * -> tcc_add_sysinclude
 * -> tcc_add_include_path
 * -> tcc_set_lib_path
 * -> tcc_output_file  
 */
typedef  int   (*__generic_cb__)(IceCube * , const char *  )  ; 


ICECUBE  Ice_t  * begin ( Ice_t * __ice_t_struct) ;  


typedef  IceCube   *(*ice_t)(void) ;                           // tcc_new  
typedef  int   (*outmode)(IceCube  *  , int __output_mode)  ;  // tcc_set_output_type  
typedef  void  (*drop)(IceCube * ) ;                           // tcc_delete 


#endif 

#define MAX_SBUFF  0xfe 
#define FLAGS  "i:o:vhl:"
typedef struct  { 
    char  file_output[MAX_SBUFF] ; 
    char  file_input[MAX_SBUFF] ; 
    char  libname[MAX_SBUFF]  ; 
    
} IcecubeFlagOptionHdl  ;  

#define  MCPYDUMB(dest,src)\
    if (memcpy(dest , src , MAX_SBUFF) != dest ) {\
    perror("MCPYDUMB crash !");\
    exit(EXIT_FAILURE);\
}


/* Parse  Argument  flags */  
ICECUBE void argument_parser ( int __argc  , char *const *argv  ,IcecubeFlagOptionHdl  *  __ifoh) ;  

/* Display usage of the program */ 
ICECUBE static void  display_usage(char *restrict  programme_basename) ;

/* Wrap up  Tcc compilation context creation */ 
ICECUBE IceCube * create_context_from( ice_t  );  


ICECUBE int set_out_mode  (  outmode  , OUT_MODE ) ; 
ICECUBE int append_file  ( __generic_cb__   , char  const *)  ; 
ICECUBE int output_exec  ( __generic_cb__   , const  char *  ) ;
ICECUBE void leave_context  ( drop )  ;
#endif 
