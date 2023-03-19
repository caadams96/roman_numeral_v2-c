//
// Created by corey on 3/17/23.
//

#ifndef ROMAN_NUMERAL_V2_ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_V2_ROMAN_NUMERAL_H
int roman_to_int(char *roman_numeral);
char *int_to_roman(int number);

char *concat(char *destination, char *source, int multiplier);

int brutesearch(char *pattern, char *string);
char* substitute(char *input, char *pattern, char *replacement);

int count( char *pattern, char *string);

#endif //ROMAN_NUMERAL_V2_ROMAN_NUMERAL_H
