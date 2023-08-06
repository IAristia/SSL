CC = gcc
CFLAGS = -std=c18

all: longitudes

longitudes: histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-x.o graficador.o main.o
	$(CC) $(CFLAGS) histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-x.o graficador.o main.o -o longitudes.exe

main.o: main.c graficador.h histograma.h
	$(CC) $(CFLAGS) -c main.c -o main.o

histograma-1-enum-switch.o: histograma-1-enum-switch.c histograma.h
	$(CC) $(CFLAGS) -c histograma-1-enum-switch.c -o histograma-1-enum-switch.o

histograma-2-goto.o: histograma-2-goto.c histograma.h
	$(CC) $(CFLAGS) -c histograma-2-goto.c -o histograma-2-goto.o

histograma-3-rec.o: histograma-3-rec.c histograma.h
	$(CC) $(CFLAGS) -c histograma-3-rec.c -o histograma-3-rec.o

histograma-x.o: histograma-x.c histograma.h
	$(CC) $(CFLAGS) -c histograma-x.c -o histograma-x.o

graficador.o: graficador.c graficador.h
	$(CC) $(CFLAGS) -c graficador.c -o graficador.o

clean:
	rm -f *.o longitudes.exe
