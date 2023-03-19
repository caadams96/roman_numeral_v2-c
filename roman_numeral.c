//
// Created by corey on 3/17/23.
//

#include <string.h>
#include <stdio.h>
#include <malloc.h>

#include "roman_numeral.h"

#define ROMAN_NUMERAL_MAP_SIZE 7
#define LONG_TO_SHORT_MAP_SIZE 6

static struct {
  int key;
  char* val;
} ROMAN_NUMERAL_MAP[ROMAN_NUMERAL_MAP_SIZE] = {
    {1000, "M"}, {500, "D"}, {100, "C"}, {50, "L"},
    {10, "X"},   {5, "V"},   {1, "I"}

};

static struct {
  char* key;
  char* val;
} LONG_TO_SHORT_MAP[LONG_TO_SHORT_MAP_SIZE] = {{"DCCCC", "CM"},
                                               {"CCCC", "CD"},
                                               {"LXXXX", "XC"},
                                               {"XXXX", "XL" },
                                               {"VIIII", "IX"},
                                               {"IIII", "IV"}

};


/***************************************************/
int roman_to_int(char *roman_numeral) {
  int amount = 0;
  char *roman_str = malloc(32);
   roman_str = roman_numeral;
  // invert map & search and replace any matching substrings 
  for (int i = 0; i <= LONG_TO_SHORT_MAP_SIZE - 1; ++i) {
     roman_str = substitute(roman_str, LONG_TO_SHORT_MAP[i].val,
                 LONG_TO_SHORT_MAP[i].key);
  }

  for (int i = 0; i <= ROMAN_NUMERAL_MAP_SIZE - 1; ++i) {
    amount += count(roman_str, ROMAN_NUMERAL_MAP[i].val) * ROMAN_NUMERAL_MAP[i].key;
  }
  return amount;
}
/***************************************************/

char *int_to_roman(int number_input) {
  char* roman_str = malloc(32);
  static char roman_buffer[32];
  roman_buffer[0] = '\0';

  int difference = 0;
  int amount = 0;

  // build roman numeral string
  for (int i = 0; i <= ROMAN_NUMERAL_MAP_SIZE - 1; ++i) {
    difference = number_input - (number_input % ROMAN_NUMERAL_MAP[i].key);
    amount = difference / ROMAN_NUMERAL_MAP[i].key;
    concat(roman_buffer, ROMAN_NUMERAL_MAP[i].val, amount);
    number_input -= difference;
  }

  roman_str = roman_buffer;
  // search and replace any matching substrings
  for (int i = 0; i <= LONG_TO_SHORT_MAP_SIZE - 1; ++i) {
      roman_str = substitute(roman_str, LONG_TO_SHORT_MAP[i].key,
                             LONG_TO_SHORT_MAP[i].val);
  }

  return roman_str;
}
/***************************************************/
int count( char *pattern, char *string) {

  int count = 0;
  while ((string = strstr(string, pattern))) {
    ++count;
    ++string;
  }
  return count;
}
/***************************************************/
char *concat(char *destination, char *source, int multiplier) {
  for (int i = 0; i <= multiplier - 1; ++i) {
    strcat(destination, source);
  }
  return destination;
}
/***************************************************/
int brutesearch(char *pattern, char *string){
    int i, j , pattern_length = strlen(pattern), string_length = strlen(string);
    for(i = 0, j = 0; j < pattern_length && i < string_length; ++i, ++j){
        while(string[i] != pattern[j]){
            i -= j-1;
            j=0;
            if(i > string_length)
                break;
        }
    }
    if (j == pattern_length)
        return i - pattern_length;
    else
        return i;
}
/***************************************************/

char* substitute(char *input, char *pattern, char *replacement) {
    char *new_string = malloc(1000); // Pointer for new string for output
    int pattern_match_index = brutesearch(pattern, input); // index point of matched pattern
    int string_length = strlen(input), pattern_length = strlen(pattern), replacement_length = strlen(
            replacement); //find length of input strings
    char pattern_match_buffer[1000], left_buffer[1000], right_buffer[1000]; // setup string buffers

    if (pattern_match_index > string_length) {
        //FAILSAFE IF NO MATCH
        strcpy(new_string, input);
    } else {
        //BEGINNING PART OF STRING
        memcpy(left_buffer, &input[0], pattern_match_index);
        left_buffer[pattern_match_index] = '\0';
        //LEFTOVER STRING
        memcpy(right_buffer, &input[pattern_match_index + pattern_length], string_length);
        //SET UP THE MATCHED PATTERN
        memcpy(pattern_match_buffer, &input[pattern_match_index], replacement_length);
        memcpy(pattern_match_buffer, replacement, replacement_length);
        pattern_match_buffer[replacement_length] = '\0';
        //BUILD STRING
        strcat(left_buffer, pattern_match_buffer); // ADD SUBSTITUTE STRING
        strcat(left_buffer, right_buffer); //ADD LEFTOVER STRING
        strcpy(new_string, left_buffer); //copy the mutated left_buffer to output string
//    }
        return pattern_match_index > string_length ? new_string : substitute(new_string, pattern, replacement);
    }


}
/***************************************************/

