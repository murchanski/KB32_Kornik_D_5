CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c child_process.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = myprogram

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXECUTABLE)
