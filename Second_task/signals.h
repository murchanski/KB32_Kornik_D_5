#ifndef SIGNALS_H
#define SIGNALS_H

extern int num_handlers;
#define MAX_HANDLERS 10

void signal_handler(int signum);
void setup_signal_handlers();
void validate_argument_count(int argc, char *argv[]);
void validate_num_handlers();

#endif // SIGNALS_H
