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

extern char **environ;

/*....... Path finders.......*/
int main(int argc, char __attribute__((__unused__)) *argv[], char **env);
char *locate_path(char *com_val);
int execute_command(char *get_address, char __attribute__((__unused__)) **env);

/*........Tokenizers......*/
char **tokenize(char *buffer, const char *delim);
/*char *_strtok(char *str, const char *fem);*/
/*unsigned int find_delim(char n, const char *str);*/

/*........ Environ variables.......*/

char *_getenv(const char *str);
ssize_t read_input(char **get_address, size_t *length_input);
void _printenv(void);

/*.......... String Handlers.........*/
void int_to_string(int value, char *result);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t s);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strdup(char *s);

/*....... Miscillenous....*/
int execute_and_wait(char *command_path, char **tokens, int *e_status);
void _free_memo(char *args[]);
/*ssize_t _getline(char **lineptr, size_t *n, FILE *stream);*/

#endif
