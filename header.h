#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

extern char** environ;

int main(int argc, char *argv[], char **env);
char **tokenize(char *buffer, const char *delim);
char *locate_path(char *com_val);
char *_getline();


int _execute(char *args, char **envp);


/*....... String Handlers.....*/
void int_to_string(int value, char *result);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
void _puts(char *str);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strndup(char *s);

/*..... Environments handlers....*/
int prog_setenv(char args, char __attribute__((__unused__)) **ard);
int prog_unsetenv(char **args, char __attribute__((__unused__)) **ard);
void _printenv(void);
void print_env_variable(const char *str);

/*........MISCELLINEOUS...*/
unsigned int find_delim(char n, const char *str);
void _error(const char *args, int error_msg);

#endif
