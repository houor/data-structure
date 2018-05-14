/**
 * fixlenghtstring.h
 *
 * header file of fix length string
 *
 * Created by Houor
 */

#ifndef FIXLENGTHSTRING_H
#define FIXLENGTHSTRING_H

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            0
#define INFEASIBLE      -1
#define OVERFLOW        -2

#define MAX_STRING_LENGTH 100

/**
 * the element of index 1 is the length of FLString
 */
typedef unsigned char FLString[MAX_STRING_LENGTH + 1];

/**
 * assign string(char array or string constant) value to FLString
 *
 * if the string's length is greater than FLString, then truncate it to fix MAX_STRING_LENGTH
 *
 * @param string
 * @param chars
 * @return
 */
int assignString(FLString string, char *chars);

int isEmpty(FLString string);

int length(FLString string);

/**
 * compare two FLString
 *
 * @param s
 * @param t
 * @return -1, 0 , 1
 */
int compare(FLString s, FLString t);

/**
 * concat two string into a new string
 *
 * @param st
 * @param s
 * @param t
 * @return
 */
int concat(FLString st, FLString s, FLString t);

int subString(FLString sub, FLString str, int position, int length);

/**
 * get the first position of pattern string in main string used by Brute-Force algorithm
 *
 * @param string main string
 * @param pattern pattern string
 * @position 1 ~ length(string) - length(pattern)
 * @index the position of pattern in main string
 * @return
 */
int indexBF(FLString string, FLString pattern, int position, int *index);

/**
 * get the first position of pattern string in main string used by KMP algorithm
 *
 * @param string main string
 * @param pattern pattern string
 * @position 1 ~ length(string) - length(pattern)
 * @index the position of pattern in main string
 * @return
 */
int indexKMP(FLString string, FLString pattern, int position, int *index);

int printString(FLString s);


#endif //FIXLENGTHSTRING_H
