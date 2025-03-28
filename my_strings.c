/*
    CSC 325-01
    Lab 6 - my_strings.c
    Name: Onur Kose
    Email: koseo1@tcnj.edu
*/

#include "my_strings.h"
#include <stdlib.h>


// my_strchr will find the first occurance of c in *s
// interally, c is reprensed as a char  ASCII value)
char *my_strchr(const char *s, int c) {

  if ((char)c == '\0') {  // search character is empty
    return NULL;
  }

  int i = 0;
  while (s[i] != '\0') {

    if (s[i] == (char)c) {
      i++;
      return (char *)&s[i];
    }
    i++;
  }
  return NULL;
}

int my_strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {  // compare each letter and progress through the array
    s1++;
    s2++;
  }
  return *s1 - *s2;
  // return the final value (0 is equal, < 0 if
  // s1 less than s2, > 0 if s1 greater than s2 )
}

// my_strcpy will copy the src string into dst string
char *my_strcpy(char *restrict dst, const char *restrict src) {
  int i = 0;

  while(src[i] != '\0') {  // iterate through src string until end is reached
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';  // sets last element of dst to null (end of string)

  return dst;
}

// my_strdup will copy the contents of char *s into a new location
char *my_strdup(const char *s) {
  char *p = malloc((my_strlen(s) + 1) * sizeof(char));

  if (p == NULL) {  // malloc failed; return NULL
    return NULL;
  }

  my_strcpy(p, s);  // use my_strcpy to copy contents

  return p;
}

// function runs until null character is found; returns length 
size_t my_strlen(const char *s) { 
  size_t length = 0;

  while(s[length] != '\0') {
    length++;
  }
  return length;
}

