%module mymodule  
%{  
#include "my_source.h"  
%}  
  
%include "typemaps.i"  
%include "cpointer.i"  
  
extern int my_function(int, double);