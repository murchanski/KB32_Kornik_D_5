#include <stdio.h>
#include <stdlib.h>
#include "signals.h"

int main(int argc, char *argv[]) {
    validate_argument_count(argc, argv);

    num_handlers = atoi(argv[1]);
    validate_num_handlers();

    setup_signal_handlers();

    printf("Waiting for process termination handlers. PID = %d\n", getpid());

    while (1) {
    }

    return 0;
}
