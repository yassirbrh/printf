#include "main.h"
#include <stdlib.h>
#include <limits.h>
/**
 * printf_unsd - Function
 *
 * Description: format the integer output
 *
 * @num: The integer to add to output.
 * @output: The Output to add num to.
 *
 * Return: The length of string appended to output..
 */
int printf_unsd(unsigned int num, char *output)
{
	char *str = malloc(sizeof(char) * 32);
	int i = 0, j;
	char tmp;

	if (str == NULL)
	{
		free(str);
		return (-1);
	}
	if (num == 0)
		str[i++] = '0';
	else if ((int)num < 0)
	{
		_strcpy(bin_to_int(int_to_bin(num)), str);
		_strcpy(str, output);
		return (_strlen(str) - 1);
	}
	else
	{
		if ((int)num < 0)
			num = UINT_MAX;
		j = i;
		while (num > 0)
		{
			str[j++] = num % 10 + '0';
			num /= 10;
		}
		str[j--] = '\0';
		i = 0;
		while (i < j)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			i++;
			j--;
		}
	}
	_strcpy(str, output);
	return (_strlen(str) - 1);
}
