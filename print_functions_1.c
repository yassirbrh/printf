#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
/**
 * bin_bits - Function
 *
 * Description: Returns the number of bits to store @num in binary.
 *
 * @num: The integer.
 *
 * Return: The number of bits to store @num in binary.
 */
int bin_bits(int num)
{
	int length = 0;

	while (num > 0)
	{
		num = num / 2;
		length++;
	}

	return (length - 1);
}
/**
 * int_digit - Function
 *
 * Description: Returns how many digit in integer.
 *
 * @num: The integer.
 *
 * Return: Number of digits.
 */
int int_digit(int num)
{
	int count = 0;

	while (num != 0)
	{
		num /= 10;
		++count;
	}
	return (count - 1);
}
/**
 * uint_digit - Function
 *
 * Description: Returns how many digit in unsigned integer.
 *
 * @num: The integer.
 *
 * Return: Number of digits.
 */
int uint_digit(int num)
{
	int count = 0;

	if (num < 0)
	num = UINT_MAX;
	while (num != 0)
	{
		num /= 10;
		++count;
	}
	return (count - 1);
}
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
			{
				va_arg(arg_list, int);
				len++;
			}
			else if (*(format + i + 1) == 's')
			{
				string = va_arg(arg_list, char *);
				if (string == NULL)
					len += 6;
				else
					len += _strlen(string);
			}
			else if (*(format + i + 1) == 'b')
				len += bin_bits(va_arg(arg_list, int));
			else if (*(format + i + 1) == 'd' || *(format + i + 1) == 'i')
				len += int_digit(va_arg(arg_list, int));
			else if (*(format + i + 1) == 'u')
				len += uint_digit(va_arg(arg_list, int));
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
			else if (*(format + i + 1) == 'b')
			{
				j += printf_bin(va_arg(arg_list, int), output + j);
				i++;
			}
			else if (*(format + i + 1) == '%')
				i++;
			else if (*(format + i + 1) == 'u')
			{
				j += printf_unsd(va_arg(arg_list, int), output + j);
				i++;
			}
			else if (*(format + i + 1) == 'o')
			{
				j += printf_oct(va_arg(arg_list, int), output + j);
				i++;
			}
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
