#include "main.h"
/**
 * printf_string - Function
 *
 * Description: Appends string in the end of output.
 *
 * @string: String to append.
 * @output: Output to append string to.
 *
 * Return: The length added to output.
 */
int printf_string(char *string, char *output)
{
	if (string == NULL)
	string = "(null)";
	_strcpy(string, output);
	return (_strlen(string) - 1);
}
