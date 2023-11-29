#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_BUFFER_SIZE 127
#define MAX_USERNAME_LENGTH 50

void print_help();
void remove_newline(char *str);
int command_processor(int argc, char *argv[]);

#endif // COMMAND_PROCESSOR_H
