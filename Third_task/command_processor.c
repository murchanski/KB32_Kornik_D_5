#include "command_processor.h"

void print_help() {
    printf("Simplified Command Processor\n");
    printf("Options:\n");
    printf("-h or --help: Display this help message\n");
    printf("-b or --buffer <size>: Specify buffer size (default is %d)\n", DEFAULT_BUFFER_SIZE);
}

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int command_processor(int argc, char *argv[]) {
    char username[MAX_USERNAME_LENGTH];
    int buffer_size = DEFAULT_BUFFER_SIZE;
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
        perror("Memory allocation error");
        return 1;
    }

    printf("Enter your username: ");
    if (fgets(username, sizeof(username), stdin) == NULL) {
        perror("Error reading username");
        free(buffer);
        return 1;
    }

    remove_newline(username);

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            free(buffer);
            return 0;
        } else if ((strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--buffer") == 0) && i + 1 < argc) {
            buffer_size = atoi(argv[++i]);
            if (buffer_size <= 0) {
                printf("Invalid buffer size. Using the default size: %d\n", DEFAULT_BUFFER_SIZE);
                buffer_size = DEFAULT_BUFFER_SIZE;
            }
        }
    }

    printf("You are working with the command processor, %s\n", username);

    while (1) {
        printf("[%s]$", username);
        if (fgets(buffer, buffer_size, stdin) == NULL) {
            break;
        }

        remove_newline(buffer);

        if (strcmp(buffer, "stop") == 0) {
            printf("Program termination\n");
            break;
        }

        printf("Your command: %s\n", buffer);
        int result = system(buffer);

        if (result != 0) {
            printf("Error executing the command. Return code: %d\n", result);
        }
    }

    printf("Wait 3 seconds...\n");
    sleep(3);
    system("clear");
    free(buffer);
    return 0;
}
