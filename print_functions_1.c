#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * count_output - Function
 *
 * Description: Returns the length of the output depending on the variables.
 *
 * @arg_list: List of arguments passed into _printf.
 * @format: The string format passed into _printf.
 *
 * Return: The new length.
 */
int count_output(va_list arg_list, const char *format)
{
	int i = 0, len = 0, dir = 0;
	char *string;

	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			if (*(format + i + 1) == 'c')
			va_arg(arg_list, int);
			else if (*(format + i + 1) == 's')
			{
				string = va_arg(arg_list, char *);
				if (string == NULL)
				len += 6;
				else
				len += _strlen(string);
			}
			dir++;
		}
		i++;
	}
	return (len - dir);
}
/**
 * printf_format - Function
 *
 * Description: Format the final output.
 *
 * @arg_list: List of the arguments passed in _printf.
 * @format: The string passed into _printf.
 * @output: The final output to print.
 *
 * Return: No return because it's a void function.
 */
void printf_format(va_list arg_list, const char *format, char *output)
{
	int i = 0, j = 0;

	while (*(format + i) != '\0')
	{
		*(output + j) = *(format + i);
		if (*(format + i) == '%')
		{
			if (*(format + i + 1) == 'c')
			*(output + j) = printf_char(va_arg(arg_list, int));
			else if (*(format + i + 1) == 's')
			j += printf_string(va_arg(arg_list, char *), output + j);
			else if (*(format + i + 1) == 'd' || *(format + i + 1) == 'i')
			{
				j += printf_int(va_arg(arg_list, int), output + j);
				i++;
			}
			else if (*(format + i + 1) == '%')
			i++;
			else
			{
				i++;
				*(output + j) = *(format + i);
			}
			if (*(format + i + 1) == 's' || *(format + i + 1) == 'c')
			i++;
		}
		i++;
		j++;
	}
	*(output + j) = '\0';
}
