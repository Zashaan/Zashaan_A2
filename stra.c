/*--------------------------------------------------------------------*/
/* stra.c                                                             */
/* Author: Zashaan Shaik                                              */
/*--------------------------------------------------------------------*/
#include <stdio.h>
#include "str.h"
#include <assert.h>

/*--------------------------------------------------------------------*/
/* the code below is for all of the functions in the string class 
   implemented using the array implementation */
/*--------------------------------------------------------------------*/

/* return the number of characters that are in the string passed in */
size_t Str_getLength(const char inputString[]) {

    /* initializes the tracking variable */
    size_t returnLength = 0;

    /* asserts that the string is not null */
    assert(inputString != NULL);

    /* goes through the string in an array format until the end 
       character is reached, incrementing tracking variable as we go */
    while(inputString[returnLength] != '\0') {
        returnLength++;
    }

    /* returns the tracking variable once its been through the string */
    return returnLength;
}

/*--------------------------------------------------------------------*/

/* takes the characters in string2 and copies them into string1 */
char *Str_copy(char inputString1[], const char inputString2[]) {

    /* initializes the tracking variable */
    int current = 0;

    /* asserts that the strings are not null */
    assert(inputString1 != NULL);
    assert(inputString2 != NULL);

    /* goes through string 2 and copies it over into string 1 until
       the end of string 2 is reached */
    while (inputString2[current] != '\0') {
        inputString1[current] = inputString2[current];
        current++;
    }

    /* copies over the end character to the end of string 1 */
    inputString1[current] = '\0';

    /* returns the final string that has the copied value */
    return inputString1;
}

/*--------------------------------------------------------------------*/

/* takes the characters in string2 and concatenates them to string 1 */
char *Str_concat(char inputString1[], const char inputString2[]) {

    /* creates the variables to be used to track indices */
    size_t current;
    size_t trackString2;

    /* asserts that both strings are valid */
    assert(inputString1 != NULL);
    assert(inputString2 != NULL);

    /* assigns values now */
    current = Str_getLength(inputString1);
    trackString2 = 0;

    /* continues by filling in the contents of string2 */
    while (inputString2[trackString2] != '\0') {
        inputString1[current] = inputString2[trackString2];
        trackString2++;
        current++;
    }

    /* once all the contents have been copied, add the end char */
    inputString1[current] = '\0';

    /* returns the final array */
    return inputString1;
}

/*--------------------------------------------------------------------*/

/* looks at the contents of string1 and string2. returns 0 if they are
   equal in character contents, -1 if string1 is lexicographically less,
   1 if string1 is lexicographically more than string2 */
int Str_compare(const char inputString1[], const char inputString2[]) {

    /* creates the variables to be used to track indices and chars */
    size_t current = 0;
    unsigned char currentString1;
    unsigned char currentString2;
    
    /* asserts that both strings are valid */
    assert(inputString1 != NULL);
    assert(inputString2 != NULL);

    /* loops through the strings until the characters differ or one of 
       them reaches the end char*/
    while(inputString1[current] == inputString2[current] && 
        inputString1[current] != '\0' && 
        inputString2[current] != '\0') {
        current++;
    }

    /* since the characters are now different, check to see which one 
       is actually lexiographically less */
    /* store the chars that each string is at */
    currentString1 = (unsigned char)inputString1[current];
    currentString2 = (unsigned char)inputString2[current];

    /* compare the characters now and return accordingly */
    if (currentString1 < currentString2) {
        return -1;
    }
    else if (currentString1 > currentString2) {
        return 1;
    }

    /* if it reaches the end without differing, then return 0 */
    return 0;
}

/*--------------------------------------------------------------------*/

/* looks through string1 and returns the first place string2 shows up 
   in string 1*/
char *Str_search(const char inputString1[], const char inputString2[]) {

    /* creates the variables to be used to track indices */
    size_t current1 = 0;
    size_t current2 = 0;
    
    /* asserts that both strings are valid */
    assert(inputString1 != NULL);
    assert(inputString2 != NULL);

    /* checks if string2 is empty and returns accordingly */
    if (inputString2[0] == '\0') {
        return (char *)inputString1;
    }

    /* searches through string1 to find characters of string 2 until the
       end of one of them is reached */
    for (current1 = 0; inputString1[current1] != '\0'; current1++) {
        current2 = 0;

        while (inputString2[current2] != '\0' && inputString1[current1
             + current2] == inputString2[current2]) {
            current2++;
        }

        if (inputString2[current2] == '\0') {
            return (char *)(inputString1 + current1);
        }
    }

    /* if string2 not in string1, return null */
    return NULL;
}

/*--------------------------------------------------------------------*/
