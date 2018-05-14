/**
 * linkedlist.h
 *
 * linked list with head and tail node
 *
 * Created by Houor
 */

#include "stdio.h"
#include "stdlib.h"

#include "fixlengthstring.h"


int assignString(FLString string, char *chars) {
    int i;
    int count;
    char *c;

    for (count = 0, c = chars; *c; ++count, ++c);

    if (count == 0) {
        string[0] = 0;
    } else {
        if (count < MAX_STRING_LENGTH) {
            for (i = 0; i < count; i++) {
                string[i + 1] = *(chars + i);
            }
            string[0] = count;
        } else {
            for (i = 0; i < MAX_STRING_LENGTH; i++) {
                string[i + 1] = *(chars + i);
                string[0] = MAX_STRING_LENGTH;
            }
        }
    }

    return OK;
}


int isEmpty(FLString string) {
    if (string[0]) {
        return FALSE;
    } else {
        return TRUE;
    }
}

int length(FLString string) {
    return string[0];
}

int compare(FLString s, FLString t) {
    int i;
    if (s[0] == 0 && t[0] == 0)
        return 0;

    for (i = 1; i <= s[0] && i <= t[0]; i++) {
        if (s[i] == t[i])
            continue;

        if (s[i] > t[i]) {
            return 1;
        } else {
            return -1;
        }
    }

    // all of the characters in the shorter string is equals with the longer string,
    // but the length of the string is not equal, then the longer string is bigger
    if (s[0] > t[0]) {
        return 1;
    } else if (s[0] == t[0]) {
        return 0;
    } else {
        return -1;
    }
}

int concat(FLString st, FLString s, FLString t) {
    int i;
    int temp;
    if (s[0] + t[0] <= MAX_STRING_LENGTH) {
        for (i = 1; i <= s[0]; i++) {
            st[i] = s[i];
        }
        for (i = 1; i <= t[0]; i++) {
            st[i + s[0]] = t[i];
        }
        st[0] = s[0] + t[0];
    } else if (s[0] < MAX_STRING_LENGTH) {
        for (i = 1; i <= s[0]; i++) {
            st[i] = s[i];
        }
        temp = MAX_STRING_LENGTH - s[0];
        for (i = 1; i <= temp; i++) {
            st[i + s[0]] = t[i];
        }
        st[0] = MAX_STRING_LENGTH;
    } else {
        for (i = 1; i <= MAX_STRING_LENGTH; i++) {
            st[i] = s[i];
        }
        st[0] = MAX_STRING_LENGTH;
    }

    return OK;
}

int subString(FLString sub, FLString str, int position, int length) {
    int i;
    if (position < 1 || position > str[0] || length < 0 || length > str[0] - position + 1) {
        return ERROR;
    }

    for (i = 1; i <= length; i++) {
        sub[i] = str[position + i - 1];
    }
    sub[0] = length;

    return OK;
}

int indexBF(FLString string, FLString pattern, int position, int *index) {

    int i, j;

    if (string[0] == 0) {
        return ERROR;
    }

    if (position < 1 || position > string[0] || position + pattern[0] > string[0]) {
        return INFEASIBLE;
    }

    i = position;
    j = 1;

    while (i <= string[0] && j <= pattern[0]) {
        if (string[i] == pattern[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }

    if (j > length(pattern)) {
        *index = i - pattern[0];
    } else {
        *index = -1;
    }

    return OK;
}

int *calculateNext(FLString pattern) {
    int i = 1;
    int j = 0;

    int *next = (int *) malloc((length(pattern) + 1) * sizeof(int));
    if (!next) {
        return OVERFLOW;
    }

    *next = *(next + 1) = 0;


    while (i < pattern[0]) {
        if (j == 0 || pattern[i] == pattern[j]) {
            i++;
            j++;
            *(next + i) = j;
        } else {
            j = next[j];
        }
    }

    printf("\n\t\tthe next array: ");
    for (i = 1; i <= length(pattern); i++) {
        printf("%d\t", *(next + i));
    }
    printf("\n");

    return next;
}

int *optimizeCalculateNext(FLString pattern) {
    int i = 1;
    int j = 0;

    int *next = (int *) malloc((length(pattern) + 1) * sizeof(int));
    if (!next) {
        return OVERFLOW;
    }

    *next = *(next + 1) = 0;


    while (i < pattern[0]) {
        if (j == 0 || pattern[i] == pattern[j]) {
            i++;
            j++;
            if (pattern[i] != pattern[j]) {
                *(next + i) = j;
            } else {
                *(next + i) = *(next + j);
            }
        } else {
            j = next[j];
        }
    }

    printf("\n\t\tthe next array: ");
    for (i = 1; i <= length(pattern); i++) {
        printf("%d\t", *(next + i));
    }
    printf("\n");

    return next;
}


int indexKMP(FLString string, FLString pattern, int position, int *index) {

    int i, j;
    int *next;

    if (string[0] == 0) {
        return ERROR;
    }

    if (position < 1 || position > string[0] || position + pattern[0] > string[0]) {
        return INFEASIBLE;
    }


    *index = -1;
    next = calculateNext(pattern);

    i = position;
    j = 1;

    while (i <= string[0] && j <= pattern[0]) {
        if (j == 0 || string[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = *(next + j);
        }
    }

    if (j > length(pattern)) {
        *index = i - pattern[0];
    } else {
        *index = -1;
    }

    free(next);


    return OK;
}


int printString(FLString s) {
    int i;
    for (i = 0; i < s[0]; i++) {
        printf("%c", s[i + 1]);
    }
    printf("\n");
    return OK;
}