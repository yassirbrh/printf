#include "main.h"
#include <stdlib.h>
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
	char *str = malloc(sizeof(char) * 12);
	int i = 0, j;
	char tmp;

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
			j = i;
			while (num > 0)
				str[i] = str[j];
			str[j] = tmp;
			i++;
			j--;
		}
	}
	_strcpy(str, output);
	return (_strlen(str) - 1);
}
