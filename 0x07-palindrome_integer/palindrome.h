#ifndef PALINDROME_H
#define PALINDROME_H

/* INCLUDES */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* FUNCTIONS */
int is_palindrome(unsigned long n);
char* itoa(int num, char* str, int base);
void rev_string(char *s);

#endif