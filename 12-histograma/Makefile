CC = gcc
CFLAGS = -std=c18

all: longitudes.exe

longitudes.exe: main.o histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-x.o graficador.o
	$(CC) $(LDFLAGS) -o longitudes.exe main.o 

main.o:
	$(CC) $(CFLAGS) -c main.c -o main.o

histograma-1-enum-switch.o:
	$(CC) $(CFLAGS) -c histograma-1-enum-switch.c -o histograma-1-enum-switch.o

histograma-2-goto.o:
	$(CC) $(CFLAGS) -c histograma-2-goto.c -o histograma-2-goto.o

histograma-3-rec.o:
	$(CC) $(CFLAGS) -c histograma-3-rec.c -o histograma-3-rec.o

histograma-x.o:
	$(CC) $(CFLAGS) -c histograma-x.c -o histograma-x.o

graficador.o:
	$(CC) $(CFLAGS) -c graficador.c -o graficador.o

clean:
	rm -f *.o longitudes.exe