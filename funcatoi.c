#include "header.h"

/**
 * _atoi - custom atoi func
 *
 * @s: pointer to str
 * Return: 0, or string int
 */
int _atoi(char *s)
{
  int symbol = 1;
	unsigned int number = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			symbol *= -1;
		if (*s == '+')
			symbol *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * symbol);
}

/**
 * string_counter - count the num of character in string.
 *
 * @string: pointer to str
 * @character: string to be counted
 * Return: 0, or string int
 */
int string_counter(char *string, char *character)
{
	int i = 0, tracker = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			tracker++;
	}
	return (tracker);
}
