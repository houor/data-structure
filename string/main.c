#include <stdio.h>

#include "fixlengthstring.h"

int main() {
    FLString h;
    FLString s;
    FLString w;
    FLString empty;
    FLString hs;
    FLString hsw;
    FLString temp;
    FLString string;
    FLString pattern;
    int index;

    char hello[] = "Hello";
    char space[] = " ";
    char world[] = "world!";
    char emptyString[] = "";

    assignString(h, hello);
    printString(h);
    printf("the length of hello is %d.\n", length(h));
    printf("the 'hello' string is %s empty.\n", isEmpty(h) == FALSE ? "not" : "");

    assignString(s, space);
    printString(s);
    printf("the length of space is %d.\n", length(s));
    printf("the ' ' string is %s empty.\n", isEmpty(s) == FALSE ? "not" : "");

    assignString(w, world);
    printString(w);
    printf("the length of world is %d.\n", length(w));
    printf("the 'world' string is %s empty.\n", isEmpty(w) == FALSE ? "not" : "");

    assignString(empty, emptyString);
    printString(empty);
    printf("the length of world is %d.\n", length(empty));
    printf("the '' string is %s empty.\n", isEmpty(empty) == FALSE ? "not" : "");

    printf("\nCompare String......\n");
    printf("the result of comparing Hello and world is %d\n\n", compare(h, w));
    printf("the result of comparing Hello and space is %d\n\n", compare(h, s));
    printf("the result of comparing Hello and Hello is %d\n\n", compare(h, s));


    printf("\nConcat String......\n");
    concat(hs, h, s);
    concat(hsw, hs, w);

    printf("the result of concatenating this three string is: ");
    printString(hsw);

    printf("\nSubstring......\n");

    if (subString(temp, hsw, 2, 3) == OK) {
        printf("substring 3 characters from position 2 is: ");
        printString(temp);
    }

    if (subString(temp, hsw, 2, 100) == OK) {
        printf("substring 100 characters from position 2 is: ");
        printString(temp);
    } else {
        printf("substring 100 characters from position 2 is out of the bound of string");
    }

    printf("\n\nFind pattern in string......\n");

    assignString(string, "acabaabaabcacaabc");
    assignString(pattern, "abaabcac");
    printf("Main String:");
    printString(string);
    printf("Pattern String:");
    printString(pattern);

    printf("used by Brute-Force algorithm:\n");
    if (indexBF(string, pattern, 1, &index) == OK) {
        printf("\tthe index of pattern in main string is %d.\n", index);
    } else {
        printf("\tthe pattern string is not in main string.\n");
    }

    printf("used by KMP algorithm:\n");
    if (indexKMP(string, pattern, 1, &index) == OK) {
        printf("\tthe index of pattern in main string is %d.\n", index);
    } else {
        printf("\tthe pattern string is not in main string.\n");
    }

    printf("========================================================\n");

    assignString(string, "bbc abcdab abcdabcdabde");
    assignString(pattern, "abcdabd");
    printf("Main String:");
    printString(string);
    printf("Pattern String:");
    printString(pattern);

    printf("used by Brute-Force algorithm:\n");
    if (indexBF(string, pattern, 1, &index) == OK) {
        printf("\tthe index of pattern in main string is %d.\n", index);
    } else {
        printf("\tthe pattern string is not in main string.\n");
    }

    printf("used by KMP algorithm:\n");
    if (indexKMP(string, pattern, 1, &index) == OK) {
        printf("\tthe index of pattern in main string is %d.\n", index);
    } else {
        printf("\tthe pattern string is not in main string.\n");
    }

    return 0;
}
