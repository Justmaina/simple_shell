#include "header.h"
/**
 * execute - this function executes a command.
 * @data: ptr to program data struct
 * Return: 0 on success, -1 on fail
 */
int execute(program_info *data)
{
	int retrival = 0, status;
	pid_t pidd;

	retrival = builtins_list(data);
	if (retrival != -1)
		return (retrival);

	retrival = find_program(data);
	if (retrival)
	{
		return (retrival);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			retrival = execve(data->tokens[0], data->tokens, data->env);
			if (retrival == -1)
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
