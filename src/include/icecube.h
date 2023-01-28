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
    int  (*set_output_mode)(IceCube  *  ,  OUT_MODE  ) ; 
    void (*release) (IceCube *  )   ; 

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
    int   (*__generic_cb__)(IceCube * , const char *  )  ; 

}Ice_t ;

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

typedef enum   {  
    ICSTDOUT = 1  , 
    ICSTDERR 
} ICESTREAM ;

static void icemesg(ICESTREAM  iceout  , char  const *mesg ,  ... ) ; 

/* Parse  Argument  flags */  
ICECUBE void argument_parser ( int __argc  , char *const *argv  ,IcecubeFlagOptionHdl  *  __ifoh) ;  

/* Display usage of the program */ 
ICECUBE static void  display_usage(char *restrict  programme_basename) ;

void * release ( Ice_t * ) ; 


//Add file   
static void   is_file (const char  * __file ) ; 
static int  file_size ( const char  *__file) ;  
void  source_file ( Ice_t * , const char *file ) ;  

#endif 
