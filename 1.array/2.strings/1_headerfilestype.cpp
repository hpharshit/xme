/* cpprefernce.com for updates

Their are two types of header files:
1.System Header files: comes with compiler
  eg. #include<iostream>

2.user defined header files: written by programmer
eg. #include"this.h"   -->will show error if no this.h file is present in current directory          
*/

/*
  FOR C++ 
1. iostream
    ->  i\o basic   cin,cout
           In C    stdio.h    
                   -> i\o basic    scanf, printf
2. cmath
    -> cos(_);  cosine     ->acos(_);   inverse cosine   ->cosh(_);  hyperbolic cosine    ->ascosh(_);
    -> tan2(a,b);      returns tan(a+b);
    ->abs(_);   abolute value
    ->copysign( a,b ); gives signe of b to a if not same
    ->exp(_) ,exp2(_) (2^),  pow(_) , sqrt(_), cbrt(_)   cuberoot  ,log10()  log base 10, log2()
    ->INFINITY     constant
    ->Comparison macro / functions
      isfinite,isinf, isgreater(a,b),isgreaterequal ,isless,islessequal,islessgreater ,isunordered 
    -> fmax(a,b)  max value,    fmin( , )  min value,   fdim( , )  positive diffrence

    In C  math.h 
          ->same as cmath    but given name as math.h     


3. climits       min(a,arr[i]);     gives min btw them  ; max
                 INT_MIN             INT_MAX
                 UINT_MAX             UINT_MIN
                 (similraly use CHAR,LLONG,SHRT,LONG,UCHAR,ULLONG,ULONG)
        In C  limits.h
              -> same as climts

4. cstdlib
   ->srand   ,rand    random no. generation
   ->String conversion
     atof,atoi,atol,atoll ,strtod,strtof ,strtol,strtold ,strtoll ,strtoul,strtoull 
   -> DMA   calloc,malloc,realloc,free

5.algorithm      
                 sort(str.begin(), str.end() , greater<char>())           
                many other see.
6. cstring 
     -> see functions in 3_0_0_.txt
       In C string.h

7. string 
         it is class   see its functions

8. functional

fstream       read write file file
list          stl
vector        stl       */

