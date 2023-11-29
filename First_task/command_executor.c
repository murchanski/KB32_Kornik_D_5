#include "command_executor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void executeCommand(const char *command) {
    printf("Executing command: %s\n", command);
    int result = system(command);
    printf("Exit code: %d\n", result);
}

void runCommandLoop() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter commands (type 'exit' to quit):\n");

    while (1) {
        printf("> ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char *token = strtok(input, ";");

        while (token != NULL) {
            executeCommand(token);
            token = strtok(NULL, ";");
        }
    }
}
