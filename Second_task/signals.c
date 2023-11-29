#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "signals.h"

void signal_handler(int signum) {
    static int count = 0;
    count++;
    printf("Handler %d: Delaying for 1 second. Signal %d received.\n", count, signum);
    sleep(1);
}

void setup_signal_handlers() {
    for (int i = 1; i <= num_handlers; i++) {
        if (signal(SIGINT, signal_handler) == SIG_ERR) {
            perror("Error registering handler for SIGINT");
            exit(EXIT_FAILURE);
        }
    }
}

void validate_argument_count(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_handlers>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}

void validate_num_handlers() {
    if (num_handlers < 1 || num_handlers > MAX_HANDLERS) {
        fprintf(stderr, "Number of handlers should be between 1 and %d.\n", MAX_HANDLERS);
        exit(EXIT_FAILURE);
    }
}
