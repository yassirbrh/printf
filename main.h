#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _strlen(const char *str);
int _strcpy(char *str1, char *str2);
int count_output(va_list arg_list, const char *format);
void printf_format(va_list arg_list, const char *format, char *output);
int printf_char(char c);
int printf_string(char *string, char *output);
int printf_int(int num, char *output);
/**
 * struct printf_functions - struct
 *
 * Description: links directives with functions.
 *
 * @dir: Directives.
 * @f: Functions.
 */
typedef struct printf_functions
{
	char *dir;
	int (*f)();
} printf_f;
#endif /* MAIN_H */
