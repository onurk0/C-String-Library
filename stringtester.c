/*
    CSC 325-01
    Lab 6 - stringtester.c
    Name: Onur Kose
    Email: koseo1@tcnj.edu
*/

#include "my_strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// test case for my_strcat
void test_mystrcat() {
  char w1[100] = "Hello, world";
  char w2[] = ":) :(";
  char w3[100] = "Hello, world";
  char w4[] = ":) :(";
  
  if (my_strcat(w1, w2) == NULL) {
    printf("String concatenation failed");
  }
  if (strcat(w3, w4) == NULL) {
    printf("String concatenation failed");
  }
}

// test case for my_strchr
void test_mystrchr() {
  char *word = "Hello, world";
  char a = 'a';
  char b = 'e';
  char *res = my_strchr(word, a);  // returns error - 'a' is not in 'Hello, world'
  char *res1 = my_strchr(word, b);  // return success - 'e' is in 'Hello, world'

  if (my_strchr(word, a) == NULL && strchr(word,a) == NULL) {  // returns error
    printf("Error - '%c' not found", a);
  }
  if (my_strchr(word, b) == NULL && strchr(word,b) == NULL) {    // returns success
    printf("Error- '%c' not found", b);
  }
}

// test case for my_strcmp function
void test_mystrcmp() {
  char *s1 = "whatever 123 456 abc";
  char *s2 = "whatever 123 456 abc";
  char *s3 = "";
  char *s4 = "";

  if (my_strcmp(s1, s2) != strcmp(s1,s2)) {
    printf("Error - strings are not equal");
  }

  if (my_strcmp(s3, s4) != strcmp(s3,s4)) {
    printf("Error - strings are not equal");
  }
}

// test case for my_strcpy function -- working
void test_mystrcpy() {
  char src1[] = "This is the source string :) :) -1 yabadabadoo -(0121){[!@#%]}";
  char src2[] = "";
  char dst1[100];
  char dst2[100];

  my_strcpy(dst1, src1);
  my_strcpy(dst2, src2);
  
  // compare my_strcpy to strcpy 
  if (my_strcpy(dst1, src1) != 0 && strcmp(dst1, src1) != 0) {
    printf("Unable to copy string");
  }
  if(my_strcpy(dst2, src2) != 0 && strcmp(dst2, src2) != 0) {
    printf("Unable to copy string");
  }
}

// test case for my_strdup function
void test_mystrdup() {
  char word[] = "Hello, world";
  char *copy = my_strdup(word);
  
  // check if copy malloc failed
  if (copy == NULL) {
    printf("String copy failed");
  }

  // check if word was copied correctly
  if (strcmp(word, copy) != 0) {
    printf("String copy failed");
  }
  free(copy);    // free copy -- prevents memory leaks
}

// test case for my_strlen function
void test_mystrlen() {  
  if (my_strlen("") != strlen("")) {
    printf("String lengths are not equal");
  }

  if(my_strlen("Random words mean something :) :() ;';'1023") != strlen("Random words mean something :) :() ;';'1023")) {
    printf("String lengths are not equal");
  }
}

int main(int argc, char *argv[]) {

  // * all function calls will be done in main for readability :)

  test_mystrcpy();
  test_mystrdup();
  test_mystrlen();
  test_mystrcmp();
  test_mystrchr();
  test_mystrcat();

  return 0;
}