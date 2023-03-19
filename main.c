#include <stdio.h>
//#include <strings.h>//#include <strings.h>

#include <string.h>


#include "roman_numeral.h"
#define q 33554393
#define d 32

int main() {
   printf("%s\n",int_to_roman(2844));
//    printf("%c",roman_to_int("IV"));
   char* string = "The brown dog chased the bird! and then the dog and dog";
   string =  substitute(string,"dog","cat");
   printf("%s", string);
  return 0;
}


    
