#include "shellheader.h"

/**
 * _getenv - get value of given environment variable
 * @var: pointer to Environment variable whose value is needed
 * @env: pointer to array of pointers to environment variables
 *
 * Return: pointer to retrieved value, or NULL on failure
 *donr
 */
char *_getenv(char *var, char **env)
{
	int xa, idx, var_len;
	char *env_var;

	var_len = _strlen(var);
	for (xa = 0; env[idx]; idx++)
	{
		if (_strncmp(env[idx], var, var_len) == 0)
		{
			env_var = env[xa];
			break;
		}
	}
	env_var = strtok(env_var, "=");
	free(env_var);
	env_var = strtok(NULL, "=");
	return (env_var);
}
/**
 * printenv - prints the current environment
 * @env: pointer to array of pointers to environment variables
 *
 * Return: no return value
 */
int printenv(char **env)
{
	char **my_env = env;
	int len = 0;

	while (*my_env)
	{
		while (*(*my_env + len))
			len++;
		write(STDOUT_FILENO, *my_env, len);
		write(STDOUT_FILENO, "\n", 2);
		len = 0;
		my_env++;
	}
	return (0);
}
