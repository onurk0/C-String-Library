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

// test case for my_strchr -- fully functional
void test_mystrchr() {
  char *word = "Hello, world";
  char a = 'a';
  char b = 'e';
  char *res = my_strchr(word, a);  // returns error - 'a' is not in 'Hello, world'
  char *res1 = my_strchr(word, b);  // return success - 'e' is in 'Hello, world'

  if (res == NULL) {  // returns error
    printf("Error - character not found");
    exit(1);
  }
  if (res1 == NULL) {    // returns success
    printf("Error - character not found");
    exit(1);
  }
}

// test case for my_strcmp function -- working
void test_mystrcmp() {
  char *s1 = "whatever 123 456 abc";
  char *s2 = "whatever 123 456 abc";
  char *s3 = "";
  char *s4 = "";

  if (my_strcmp(s1, s2) != strcmp(s1,s2)) {
    printf("Error - strings are not equal");
    exit(1);
  }

  if (my_strcmp(s3, s4) != strcmp(s3,s4)) {
    printf("Error - strings are not equal");
    exit(1);
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
  
  if (strcmp(dst1, src1) != 0) {
    exit(1); // Exit with error code if test fails
  }
  if(strcmp(dst2, src2) != 0) {
    exit(1); 
  }
}

// test case for my_strdup function -- working
void test_mystrdup() {
  char word[] = "Hello, world";
  char *copy = my_strdup(word);

  if (copy == NULL || strcmp(word, copy) != 0) {
    exit(1);
  }
  free(copy);    // free copy -- prevents memory leaks
}

// test case for my_strlen function -- working
void test_mystrlen() {  
  if (my_strlen("") != strlen("")) {
    printf("Error - my_strlen");
    exit(1);
  }

  if(my_strlen("Random words mean something :) :() ;';'1023") != strlen("Random words mean something :) :() ;';'1023")) {
    printf("Error - my_strlen");
    exit(1);
  }
}

int main(int argc, char *argv[]) {

  // * all function calls will be done in main for readability :)

  test_mystrcpy();
  test_mystrdup();
  test_mystrlen();
  test_mystrcmp();

  test_mystrchr();

  return 0;
}