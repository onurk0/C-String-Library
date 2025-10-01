/*
    CSC 325-01
    Lab 6 - my_strings.c
    Name: Onur Kose
*/

#include "my_strings.h"
#include <stdlib.h>

// my_strstr will find the first occurence of needle in haystack
char *my_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {    // needle is empty string - return haystack
    return (char*)haystack;
  }

  while (*haystack != '\0') {   // run until end of haystack
    const char *h = haystack;    // pointer to beginning of haystack
    const char *n = needle;     // pointer to beginning of needle


    // iterate through the strings while current chars
    // are equal and the end of either string has not
    // been reached
    while (*h != '\0' && *n != '\0' && *h == *n ) { 
      h++;
      n++;
    }

    // needle was found in haystack, return haystack
    // this will also return everything after needle in the haystack
    if (*n == '\0') {
      return (char*)haystack;
    }

    haystack++;
  }

  return NULL; 
}

// * my_strcat will concatenate src to the end of dst
// * a buffer overflow may occur, but it is the user's 
// * responsibility to ensure that dst is large to concatenate
char *my_strcat(char *restrict dst, const char *restrict src) {
  
  // str keeps track of the beginning of the dst string
  // since dst no longer points to the beginning of the string
  // but rather to the end 
  char *str = dst;
  
  // move dst pointer to the end (also handles empty strings)
  while (*dst != '\0') {
    dst++;
  }

  // * concatenate src to dst until the end is reached
  // * and iterate through each 
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';    // set end of string

  return str;    // return beginning of the dst
}

// my_strchr will find the first occurance of c in *s
char *my_strchr(const char *s, int c) {
  
  // go through the string; if 2 chars are matching, return
  while (*s++) {
    if (*s == c) {
      return (char *)s;
    }
  }
  return NULL;
}

// compares the equality of 2 strings
int my_strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {  // compare each letter and progress through the array
    s1++;
    s2++;
  }
  return *s1 - *s2;
  // return the final value (0 is equal, < 0 if
  // s1 less than s2, > 0 if s1 greater than s2 )
}

// my_strcpy will copy string src into string dst
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

