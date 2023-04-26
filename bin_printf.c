#include "main.h"
#include <stdlib.h>
/**
 * printf_bin - Function
 *
 * Description: Convert an unsigned integer into binary.
 *
 * @num: Unsigned integer to convert into binary.
 * @output: String to append the result to.
 *
 * Return: The length to append to output.
 */
int printf_bin(int num, char *output)
{
	char *bin = malloc(32);
	int i = 0, j = 0, length;
	char temp;

	if (bin == NULL)
	{
		free(bin);
		return (NULL);
	}
	if (num == 0)
	{
		_strcpy("0", output);
		return (0);
	}

	while (num > 0)
	{
		bin[i] = (num % 2) + '0';
		num /= 2;
		i++;
	}
	bin[i] = '\0';
	j = i - 1;
	i = 0;
	while (i < j)
	{
		temp = bin[i];
		bin[i] = bin[j];
		bin[j] = temp;
		i++;
		j--;
	}
	_strcpy(bin, output);
	length = _strlen(bin) - 1;
	free(bin);
	return (length);
}
