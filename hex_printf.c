#include "main.h"
#include <stdlib.h>
/**
 * printf_hex - Function
 *
 * Description: Converts number to hexadecimal.
 *
 * @num: The integer.
 * @output: The string to add the result to.
 * @dir: check if x or X in order to print hex chars in lowercase or uppercase.
 *
 * Return: The length added to the output.
 */
int printf_hex(int num, char *output, char dir)
{
	char hex_chars[16], temp;
	char *hex = malloc(sizeof(char) * 32);
	int i, len, j;

	if (hex == NULL)
	{
		free(hex);
		return (-1);
	}
	if (num == 0)
	{
		_strcpy("0", output);
		return (0);
	}
	if (dir == 'x')
	{
		for (i = 0; i < 10; i++)
			hex_chars[i] = i + '0';
		for (i = 10; i < 16; i++)
			hex_chars[i] = i - 10 + 'a';
	}
	else if (dir == 'X')
	{
		for (i = 0; i < 10; i++)
			hex_chars[i] = i + '0';
		for (i = 10; i < 16; i++)
			hex_chars[i] = i - 10 + 'A';
	}
	i = 0;
	while (num > 0)
	{
		hex[i++] = hex_chars[num % 16];
		num /= 16;
	}
	hex[i] = '\0';
	len = _strlen(hex) - 1;
	j = i - 1;
	i = 0;
	while (i < j)
	{
		temp = hex[i];
		hex[i] = hex[j];
		hex[j] = temp;
		i++;
		j--;
	}
	_strcpy(hex, output);
	free(hex);

	return (len);
}
