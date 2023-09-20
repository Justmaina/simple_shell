#include "shellheader.h"

/**
  * parsecommand - splits command line into array of words
  * @command: string read from the STDIN
  *
  * Return: Arrays of strings read from the STDIN.
  */
char **parsecommand(char *command)
{
	char **args, *token, *com;
	int i, len = 0;

	args = malloc((MAX_ARGS + 1) * sizeof(char *));
	if (!args)
	{
		free(args);
		return (NULL);
	}
	com = _strchr(command, '#');
	if (com != NULL)
		*com = '\0';
	for (i = 0; command[i]; i++)
	{
	if (command[i] == ' ' || command[i] == '\n')
		len++;
	}
	len++;
	com = strtok(command, "\n");
	token = strtok(com, " ");
	for (i = 0; token; i++)
	{
	args[i] = _strdup(token);
	token = strtok(NULL, " ");
	}
	args[i] = NULL;
	if (*args != NULL)
	return (args);
	else
	return (NULL);
}
