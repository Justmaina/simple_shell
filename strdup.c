#include "shellheader.h"

/**
 * _strdup - Duplicates a string.
 * @str: Pointer to the string to be duplicated.
 *
 * Description: This function allocates memory for a new string
 * that is a duplicate of the input string 'str'. It returns a pointer to
 * the newly allocated string.
 *
 * Return: Pointer to the duplicated string, or NULL on allocation failure.
 */
char *_strdup(char *str)
{
	int length, index;
	char *duplicate = NULL;

	if (str != NULL)
	{
		length = _strlen(str);
		duplicate = (char *)malloc(sizeof(char) * (length + 1));
		/*+1 for null terminator*/
		if (!duplicate)
		{
			perror("Memory allocation failed");
			free(duplicate);
			return (NULL);
		}
		for (index = 0; index <= length; index++)
		{
			duplicate[index] = str[index];
		}
		duplicate[index] = '\0'; /*Null-terminate the duplicate string*/
		return (duplicate);
	}
	return (NULL);
}
