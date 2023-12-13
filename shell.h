#ifndef SHELL_H
#define SHELL_H

/* include files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* ---function prototypes--- */
char **_strtok(char *);
void _exec(char **argv);
void _free(char **ptr);
char *_getline(void);

#endif /* SHELL_H */
