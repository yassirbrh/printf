#include "main.h"
#include <stdlib.h>
/**
 * _strlen - Function
 *
 * Description: Returns the length of a string.
 *
 * @str: Pointer to the string to output.
 *
 * Return: The length of a string.
 */
int _strlen(const char *str)
{
	int length;

	length = 0;
	while (*(str + length) != '\0')
	length++;

	return (length);
}
/**
 * _strcpy - Function
 *
 * Description: Copy the content of a string into other string.
 *
 * @str1: String to copy.
 * @str2: Pointer to copy the string into it.
 *
 * Return: 0 Always (Success)
 *         1 Failure
 */
int _strcpy(char *str1, char *str2)
{
	int i;

	if (str1 == NULL)
	return (1);
	i = 0;
	while (*(str1 + i) != '\0')
	{
	*(str2 + i) = *(str1 + i);
	i++;
	}
	*(str2 + i) = '\0';
	return (0);
}
