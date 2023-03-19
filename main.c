#include <stdio.h>
//#include <strings.h>//#include <strings.h>

#include <string.h>


#include "roman_numeral.h"
#define q 33554393
#define d 32

int main() {
   printf("%s\n",int_to_roman(2844));
//    printf("%c",roman_to_int("IV"));
   char* string = "Hello World!";
   string =  substitute(string,"World","Corey");
   printf("%s", string);
  return 0;
}


    
