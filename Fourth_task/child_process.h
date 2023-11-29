#ifndef CHILD_PROCESS_H
#define CHILD_PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char *FILE_NAME;

void create_child_process(int number);

#endif
