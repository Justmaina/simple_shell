#ifndef HEADER_H
#define HEADER_H

#include <stdio.h> /* for printf*/
#include <unistd.h> /* for fork, execve*/
#include <stdlib.h>
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h> /* for errno and perror */
#include <sys/types.h> /* for type pid */
#include <sys/wait.h> /* for wait */
#include <sys/stat.h> /* for use of stat function */
#include <signal.h> /* for signal management */
#include <fcntl.h> /* for open files*/



#include "main.h" /* for msg help and prompt */


/**
 * struct info- struct for the program's data
 * @program_name: the name of the executable
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of excecuted comands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases.
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} program_info;

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(program_info *data);
} builtins;




void inicialize_data(program_info *data, int arc, char *argv[], char **env);


void sisifo(char *prompt, program_info *data);

void handle_ctrl_c(int opr NOTUSED);

int _getline(program_info *data);

/* split the each line for the logical operators if it exist */
int check_logic_ops(char *array_commands[], int i, char array_operators[]);


void expand_variables(program_info *data);

void expand_alias(program_info *data);


int buffer_add(char *buffer, char *str_add);



void tokenize(program_info *data);


char *_strtok(char *line, char *delim);


int execute(program_info *data);

int builtins_list(program_info *data);

char **tokenize_path(program_info *data);

int find_program(program_info *data);


void free_array_of_pointers(char **directories);

void free_recurrent_data(program_info *data);


void free_all_data(program_info *data);

int builtin_exit(program_info *data);

int builtin_cd(program_info *data);

int set_work_directory(program_info *data, char *new_dir);

int builtin_help(program_info *data);

int builtin_alias(program_info *data);

int builtin_env(program_info *data);

int builtin_set_env(program_info *data);

int builtin_unset_env(program_info *data);

char *env_get_key(char *name, program_info *data);

int env_set_key(char *key, char *value, program_info *data);

int env_remove_key(char *key, program_info *data);

void print_environ(program_info *data);

int _print(char *string);

int _printe(char *string);

int _print_error(int errorcode, program_info *data);

int str_length(char *string);

char *str_duplicate(char *string);

int str_compare(char *string1, char *string2, int number);

char *str_concat(char *string1, char *string2);

void str_reverse(char *string);

void long_to_string(long number, char *string, int base);

int _atoi(char *s);

int string_counter(char *string, char *character);

int print_aka(program_info *data, char *alias);

char *get_aka(program_info *data, char *name);

int set_aka(char *alias_string, program_info *data);


#endif
