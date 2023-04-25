#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _strlen(const char *str);
int _strcpy(char *str1, char *str2);
int count_output(va_list arg_list, const char *format);
void printf_format(va_list arg_list, const char *format, char *output);

#endif /* MAIN_H */
