CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = dicionario
SRCS = principal.c tabelaHash.c interface.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c tabelaHash.h interface.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) dicionario.exe

.PHONY: all clean
