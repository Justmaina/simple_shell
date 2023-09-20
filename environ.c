#include "shellheader.h"

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @var: pointer to name of environment variable
 * @value: pointer to value of environment variable
 * @env: pointer to array of pointers to the environment variables
 *
 * Return: 0 on success
 */
int _setenv(char *var, char *value, char **env)
{
	char *env_var;
	int idx = 0, var_len = 0, status = 0;

	var_len = _strlen(var);
	env_var = buildstr(var, "=", value);
	for (idx = 0; env[idx]; idx++)
	{
		if (_strncmp(env[idx], var, var_len) == 0)
		{
			free(env[idx]);
			env[idx] = strdup(env_var);
			status = 1;
			break;
		}
	}
	if (status != 1)
	{
		free(env[idx]);
		env[idx] = _strdup(env_var);
		env[++idx] = NULL;
	}
	free(env_var);
	return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @var: name of variable to be removed
 * @env: pointer to array of pointers to environment variables
 *
 * Return: 0 on success
 */
int _unsetenv(char *var, char **env)
{
	char **temp;
	int var_len;

	var_len = _strlen(var);
	while (*env)
	{
		if (_strncmp(*env, var, var_len))
		{
			temp = env;
			free(temp[0]);
			do {
				env[0] = env[1];
				temp++;
			} while (*temp);
		}
	}
	return (0);
}
