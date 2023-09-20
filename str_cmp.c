#include "shellheader.h"

/**
 * _strcmp - Compares two strings.
 * @str1: First string to be compared.
 * @str2: Second string to be compared.
 *
 * Description: This function compares two strings 'str1' and 'str2'
 * and returns: - 0 if 'str1' and 'str2' are the same.
 * - A negative value if the ASCII code of the first unmatched character
 *   in 'str1' is less than the corresponding character in 'str2'.
 * - A positive value if the ASCII code of the first unmatched character
 *   in 'str1' is greater than the corresponding character in 'str2'.
 *
 * Return: The result of the comparison.
 */
int _strcmp(char *str1, char *str2)
{
	int diff = 0;
	int count = 0;
	int len1 = 0;
	int len2 = 0;
	int end = 0;

	while (str1[len1] != '\0')
	{
		len1++;
	}

	while (str2[len2] != '\0')
	{
		len2++;
	}

	end = len1 < len2 ? len1 : len2;

	while (count < end)
	{
		if (str1[count] != str2[count])
		{
			diff = str1[count] - str2[count];
			break;
		}
		count++;
	}

	return (diff);
}
