CC = gcc
CFLAGS = -Wall -Wextra -pedantic

TARGET = my_program

SRCS = main.c signals.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c signals.h
	$(CC) $(CFLAGS) -c main.c

signals.o: signals.c signals.h
	$(CC) $(CFLAGS) -c signals.c

clean:
	rm -f $(OBJS) $(TARGET)
