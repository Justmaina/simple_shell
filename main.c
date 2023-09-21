#include "shellheader.h"

/**
 * main - Start the shell
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variable
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *env[])
{
	program_info program_info_struct = {NULL}, *data = &program_info_struct;

	initialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		_print("$ ");
	}
	errno = 0;
	return (0);
}

/**
 * handle_ctrl_c - Print the prompt
 * @opr: Option of the prototype (UNUSED)
 */
void handle_ctrl_c(int opr __attribute__((unused)))
{
	_print("\n");
	_print("$");
}

/**
 * initialize_data - Initialize struct with the info of the program
 * @data: Ptr to program_info structure
 * @argv: Argument vector
 * @env: Environment
 * @argc: Argument count
 */
void initialize_data(program_info *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;

	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = _strdup(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}

/**
 * sisifo - loops the prompt
 * @data: infinite loop for prompt
 */
void sisifo(program_info *data)
{
	while (++(data->exec_counter))
	{
		_print("$ ");
	}
	free(data);
}
