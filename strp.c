#include <stdio.h>
#include "str.h"
#include <assert.h>

/*--------------------------------------------------------------------*/
/* the code below is for all of the functions in the string class 
   implemented using an pointer based implementation */
/*--------------------------------------------------------------------*/

/* return the number of characters that are in the string passed in */
size_t Str_getLength(const char *inputString) {

    /* creates the pointer that points to the end of the string */
    const char *endChar;

    /* asserts that the string is not null */
    assert(inputString != NULL);

    /* sets the end to the start for now */
    endChar = inputString;

    /* loops through until the end char is reached */
    while (*endChar != '\0') {
        endChar++;
    }

    /* returns the differences between the start and end, which is
       the length */
    return (size_t)(endChar - inputString);
}

/*--------------------------------------------------------------------*/

/* takes the characters in string2 and copies them into string1 */
char *Str_copy(char *inputString1, const char *inputString2) {

    /* creates the pointer to use that will be returned */
    char *returnPointer = inputString1;

    /* asserts that both the pointers passed in are not null */
    assert(inputString1 != NULL);
    assert(inputString2 != NULL);

    /* goes through string2 and fills in values */
    while (*inputString2 != '\0') {
        *inputString1 = *inputString2;
        inputString1++;
        inputString2++;
    }

    /* adds the end char to string1 */
    *inputString1 = '\0';

    /* returns the original that points to the start of the copy */
    return returnPointer;
}

/*--------------------------------------------------------------------*/

/* takes the characters in string2 and concatenates them to string 1 */
char *Str_concat(char *inputString1, const char *inputString2) {

    /* creates the return pointer and sets it to the end of string 1 */
    char *returnPointer;

    /* asserts that both the pointers passed in are not null */
    assert(inputString1 != NULL);
    assert(inputString2 != NULL);

    /* sets the value */
    returnPointer = inputString1 + Str_getLength(inputString1);

    /* sets the string1 pointer to the end of string1 too */
    inputString1 = returnPointer;

    /* goes through string2 and adds the characters */
    while (*inputString2 != '\0') {
        *inputString1 = *inputString2;
        inputString1++;
        inputString2++;
    }
    *inputString1 = '\0';

    /* returns the return pointer */
    return returnPointer;
}

/*--------------------------------------------------------------------*/

/* looks at the contents of string1 and string2. returns 0 if they are
   equal in character contents, -1 if string1 is lexicographically less,
   1 if string1 is lexicographically more than string2 */
int Str_compare(const char *inputString1, const char *inputString2) {

    /* asserts that both the pointers passed in are not null */
    assert(inputString1 != NULL);
    assert(inputString2 != NULL);

    /* goes through the strings until they differ */
    while (*inputString1 == *inputString2) {
        inputString1++;
        inputString2++;
    }

    /* creates the variables to store the chars now that we know they are different */
    /* checks the cases where at least one of them saw an end char */
    if (*inputString1 == '\0') {
        /* checks if both ended */
        if (*inputString2 == '\0') return 0;
        /* if only string1 ended then return -1 */
        else return -1;
    }
    /* if only string2 ended then return 1*/
    else if (*inputString2 == '\0') return 1;

    /* compare chars now that neither reached end char */
    if (*inputString1 - *inputString2 < 0) {
        return -1;
    }
    else return 1;

    /* if it reaches the end without differing, then return 0 */
    return 0;
}

/*--------------------------------------------------------------------*/

/* looks through string1 and returns the pointer to the first place
   string2 shows up in string 1*/
char *Str_search(const char *inputString1, const char *inputString2) {

    /* creates the pointers to be used during the loops */
    const char *currentPointer = inputString1;
    const char *pointer1 = inputString1;
    const char *pointer2 = inputString2;

    /* asserts that both the pointers passed in are not null */
    assert(inputString1 != NULL);
    assert(inputString2 != NULL);

    /* check if string2 is an empty string */
    if (*inputString2 == '\0') return (char *)inputString1;

    while (*currentPointer != '\0') {

        pointer2 = inputString2;
        pointer1 = currentPointer;

        /* keeps going until not equal anymore or one ended */
        while (*pointer1 != '\0' && *pointer2 != '\0' &&
             *pointer1 == *pointer2) {
            pointer1++;
            pointer2++;
        }

        /* now that not equal or ended, check if the end of string 2 
           reached */
        if (*pointer2 == '\0') {
            return (char *)currentPointer;
        }

        currentPointer++;
    }

    /* if string 2 not found, return null */
    return NULL;
}

/*--------------------------------------------------------------------*/