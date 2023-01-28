cmake_minimum_required(VERSION 3.23.1) 
project(Icecube)
include_directories(src/include)  
FILE(GLOB_RECURSE  ICECUBE_src  src/*.c) 

add_executable(${PROJECT_NAME} ${ICECUBE_src} )
target_link_libraries( ${PROJECT_NAME}  tcc) 
