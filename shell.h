#ifndef SHELL_H
#define SHELL_H

/* Standard Library */
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* Custom Functions */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

int checker(char **cmd, char *buffer);
void prompt(void);
void signal_handler(int n);
char **tokenize(char *input);
char *check_path(char **path, char *cmd);
char *append_path(char *path, char *cmd);
int builtin_handler(char **cmd, char *input);
void exit_shell(char **cmd, char *input);

void print_env(void);

/* String Custom Functions */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

/* Print Custom Functions */
int _putchar(char c);
int print_str(char *s);

void executor(char *c, char **cmd);
char *find_path(void);

void free_buffers(char **buffer);

/**
 * struct builtin - a new data type for builtins
 * @env: environment
 * @exit: exit
 * 
 * Description: 
 */
struct builtin
{
       	char *env;
	char *exit;
} builtin;

/**
 * struct info - a new data type for info
 * @final_exit: exit
 * @ln_count: counter for ln
 *
 * Description:
 */
struct info
{
	int final_exit;
	int ln_count;
} info;

/**
 * struct flags - data type for mode switching
 * @interactive: interactive mode flag
 *
 * Description:
 */
struct flags
{
	bool interactive;
} flags;

#endif /*SHELL_H*/

