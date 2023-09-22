#include "header.h"

/**
 * print_aka - handle alias
 * @data: program data struct
 * @alias: name of the alias
 * Return: 0 on sucess, num declared in the args
 */
int print_aka(program_info *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_aka -handle alias
 * @data: program's data struct
 * @name: name of the requested alias.
 * Return: 0 on success, number declared in the args, NULL if not found
 */
char *get_aka(program_info *data, char *name)
{
	int i, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
		{
			if (str_compare(name, data->alias_list[i], alias_length) &&
				data->alias_list[i][alias_length] == '=')
			{
				return (data->alias_list[i] + alias_length + 1);
			}
		}
	return (NULL);
}

/**
 * set_aka - creates alias, overides if exists
 * @alias_string: alias to be set
 * @data: program data struct
 * Return: 0 on sucess, number declared in args
 */
int set_aka(char *alias_string, program_info *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = get_aka(data, alias_string + i + 1);
			break;
		}

	for (j = 0; data->alias_list[j]; j++)
		if (str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{
			free(data->alias_list[j]);
			break;
		}
	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = str_duplicate(buffer);
	}
	else
	{
		data->alias_list[j] = str_duplicate(alias_string);
	}
	return (0);
}
