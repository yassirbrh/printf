#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _printf - Function
 *
 * Description: Produces output according to a format.
 *
 * @format: The string to output.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	char *output;
	int len, i;

	if (format == NULL)
	return (-1);
	i = len = 0;
	va_start(arg_list, format);
	len = count_output(arg_list, format);
	va_end(arg_list);
	len += _strlen(format) - 1;
	output = malloc(len * sizeof(char));
	if (output == NULL)
	{
		free(output);
		return (-1);
	}
	va_start(arg_list, format);
	printf_format(arg_list, format, output);
	while (i < len)
	{
		write(1, output + i, 1);
		i++;
	}
	free(output);
	va_end(arg_list);
	return (i);
}
