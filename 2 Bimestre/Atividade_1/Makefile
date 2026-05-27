CC = gcc
CFLAGS = -Wall -std=c11

all:
	$(CC) $(CFLAGS) -o questao1/fibonacciIngenuo questao1/fibonacciIngenuo.c
	$(CC) $(CFLAGS) -o questao2/fibonacciMemoizado questao2/fibonacciMemoizado.c
	$(CC) $(CFLAGS) -o questao3/torresHanoi questao3/torresHanoi.c

clean:
	del /Q questao1\*.exe questao2\*.exe questao3\*.exe 2>nul
