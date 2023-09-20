#include "shellheader.h"

/**
 * long_to_string - convert number to a string.
 * @number: number to convert
 * @string: buffer to save the num as a string.
 * @base: base for conversion
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long quotient = number;
	char letters[] = "0123456789abcdef";

	if (quotient == 0)
	{
		string[index++] = '0';
	}

	if (string[0] == '-')
	{
		inNegative = 1;
	}

	while (quotient)
	{
		if (quotient < 0)
		{
			string[index++] = letters[-(quotient % base)];
		}
		else
		{
			string[index++] = letters[quotient % base];
			quotient /= base;
		}
	}

	if (inNegative)
	{
		string[index++] = '-';
	}

	string[index] = '\0';
	str_reverse(string);
}
