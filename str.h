/*--------------------------------------------------------------------*/
/* str.h.                                                             */
/* Author: Zashaan Shaik                                              */
/*--------------------------------------------------------------------*/
#ifndef STR_INCLUDED
#define STR_INCLUDED

#include <stddef.h>

/*--------------------------------------------------------------------*/

/* return the number of characters that are in inputString */
size_t Str_getLength(const char inputString[]);

/*--------------------------------------------------------------------*/

/* takes the characters in inputString2 and copies them into 
   inputString1. returns the edited inputString1 */
char *Str_copy(char inputString1[], const char inputString2[]);

/*--------------------------------------------------------------------*/

/* takes the characters in inputString2 and concatenates them to 
   inputString1. returns the edited inputString1 */
char *Str_concat(char inputString1[], const char inputString2[]);

/*--------------------------------------------------------------------*/

/* looks at the contents of inputString1 and inputString2. returns 0 if they are
   equal in character contents, -1 if inputString1 is lexicographically less,
   1 if inputString1 is lexicographically more than inputString2 */
int Str_compare(const char inputString1[], const char inputString2[]);

/*--------------------------------------------------------------------*/

/* looks through inputString1 and returns the pointer to the first place
   inputString2 shows up in inputString 1*/
char *Str_search(const char inputString1[], const char inputString2[]);

/*--------------------------------------------------------------------*/

#endif