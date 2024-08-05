# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -g -std=c18

# Source files
SRCS = $(wildcard *.c)
# Header files
HDRS = $(wildcard *.h)

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
ifeq ($(OS),Windows_NT)
	TEST_EXECUTABLE = test.exe
	EXECUTABLE = histograma.exe
else
	TEST_EXECUTABLE = test
	EXECUTABLE = histograma
endif

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(filter-out test.o, $(OBJS))
	$(CC) -o $@ $^ $(CFLAGS)

$(TEST_EXECUTABLE): $(filter-out main.o, $(OBJS))
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE) $(TEST_EXECUTABLE)