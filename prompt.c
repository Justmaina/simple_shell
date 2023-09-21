#include "shellheader.h"

/**
 * print_prompt - Print the shell prompt.
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
