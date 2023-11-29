CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = my_program
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

-include $(DEPS)

%.d: %.c
	@$(CC) -MM $(CFLAGS) $< | sed 's|\($*\)\.o[ :]*|\1.o $@ : |g' > $@

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
