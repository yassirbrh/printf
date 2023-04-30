#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
/**
 * printf_int - Function
 *
 * Description: format the integer output
 *
 * @number: The integer to add to output.
 * @output: The Output to add num to.
 *
 * Return: The length of string appended to output..
 */
int printf_int(int number, char *output)
{
	char *str = malloc(sizeof(char) * 12);
	int i = 0, j, len, num = number;
	char tmp;

	if (num == INT_MIN)
		num++;
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
		while (num != 0)
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
	len = _strlen(str);
	/*printf("%d \n", len);*/
	if (number == INT_MIN)
		str[len - 1]++;
	_strcpy(str, output);
	free(str);
	return (len - 1);
}
