#include "shellheader.h"

/**
 * str_reverse - function to reverse a string.
 *
 * @string: pointer to the string.
 * Return: void.
 */
void str_reverse(char *string)
{
	int i = 0, length = _strlen(string) - 1;
	char hold;

	while (i < length)
	{
		hold = string[i];
		string[i++] = string[length];
		string[length--] = hold;
	}
}
