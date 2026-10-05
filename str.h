#ifndef STR_INCLUDED
#define STR_INCLUDED

/*--------------------------------------------------------------------*/

/* return the number of characters that are in the string passed in */
size_t Str_getLength(const char *string);

/*--------------------------------------------------------------------*/

/* takes the characters in string2 and copies them into string1 */
char *Str_copy(char *string1, const char *string2);

/*--------------------------------------------------------------------*/

/* takes the characters in string2 and concatenates them to string 1 */
char *Str_concat(char *string1, const char *string2);

/*--------------------------------------------------------------------*/

/* looks at the contents of string1 and string2. returns 0 if they are
   equal in character contents, -1 if string1 is lexicographically less,
   1 if string1 is lexicographically more than string2 */
int Str_compare(const char *string1, const char *string2);

/*--------------------------------------------------------------------*/

/* looks through string1 and returns the pointer to the first place
   string2 shows up in string 1*/
char *Str_search(const char *string1, const char *string2);

/*--------------------------------------------------------------------*/

#endif