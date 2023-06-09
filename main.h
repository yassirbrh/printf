#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _strlen(const char *str);
int _strcpy(char *str1, char *str2);
int _strcmp(char *str1, char *str2);
int count_output(va_list arg_list, const char *format);
void printf_format(va_list arg_list, const char *format, char *output);
int printf_char(char c);
int printf_string(char *string, char *output);
int printf_int(int num, char *output);
int printf_bin(int num, char *output);
int printf_unsd(unsigned int num, char *output);
int printf_oct(int num, char *output);
int printf_hex(int num, char *output, char dir);
char *bin_to_int(char *bin);
char *int_to_bin(int num);
int _pow(int base, int exponent);

#endif /* MAIN_H */
