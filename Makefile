CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SOURCES = my_printf.c
#DEPS = my_headers.h
OBJFILES = $(SOURCES:.c=.o)
TARGET = my_printf
all: $(TARGET)


$(TARGET): $(OBJFILES) #$(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)


.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES)
