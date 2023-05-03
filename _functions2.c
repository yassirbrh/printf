#include "main.h"
/**
 * _pow - Function
 *
 * Description: Return the power of a number to an exponent.
 *
 * @base: The base.
 * @exponent: The exponent.
 *
 * Return: The power of a base to exponent.
 */
int _pow(int base, int exponent)
{
	int result = 1;

	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result *= base;
		base *= base;
		exponent /= 2;
	}
	return (result);
}
