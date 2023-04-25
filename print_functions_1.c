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
 * printf_int - Function
 *
 * Description: format the integer output
 *
 * @integer: The integer to print.
 *
 * return: String containing the integer.
 */
char *printf_int(int num)
{
	char *str = malloc(sizeof(char) * 12);
	int i = 0, j;
	char tmp;
	if (num < 0)
	{
		num = -num;
		str[i++] = '-';
	}
	if (num == 0)
	str[i++] = '0';
	else
	{
		j = i;
		while (num > 0)
		{
			str[j++] = num % 10 + '0';
			num /= 10;
		}
		str[j--] = '\0';
		while (i < j)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			i++;
			j--;
		}
	}
	return (str);
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
	char *string;

	while (*(format + i) != '\0')
	{
		*(output + j) = *(format + i);
		if (*(format + i) == '%')
		{
			if (*(format + i + 1) == 'c')
			*(output + j) = va_arg(arg_list, int);
			else if (*(format + i + 1) == 's')
			{
				string = va_arg(arg_list, char *);
				if (string == NULL)
				string = "(null)";
				_strcpy(string, output + j);
				j += _strlen(string) - 1;
			}
			else if (*(format + i + 1) == 'd' || *(format + i + 1) == 'i')
			{
				string = printf_int(va_arg(arg_list, int));
				_strcpy(string, output + j);
				j += _strlen(string) - 1;
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
