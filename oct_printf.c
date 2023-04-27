#include "main.h"
#include <stdlib.h>
/**
 * printf_oct - Function
 *
 * Description: Converts into octal.
 *
 * @num: The number to convert.
 * @output: The string to append the result to.
 *
 * Return: The length added to output.
 */
int printf_oct(int num, char *output)
{
	char *oct = malloc(32);
	int i = 0, j = 0, length;
	char temp;

	if (oct == NULL)
	{
		free(oct);
		return (-1);
	}
	if (num == 0)
	{
		_strcpy("0", output);
		return (0);
	}

	while (num > 0)
	{
		oct[i] = (num % 8) + '0';
		num /= 8;
		i++;
	}
	oct[i] = '\0';
	j = i - 1;
	i = 0;
	while (i < j)
	{
		temp = oct[i];
		oct[i] = oct[j];
		oct[j] = temp;
		i++;
		j--;
	}
	_strcpy(oct, output);
	length = _strlen(oct) - 1;
	free(oct);
	return (length);
}
