CC=g++
CLFAGS=-Wall -std=c++11 -static
LIBS=-lcurl

roe: HTTPDownloader.o roe.o main.o table.o currency.o
	$(CC) -o $@ $(CFLAGS) $^ $(LIBS)

main.o: main.cpp 
	$(CC) -c $< $(CFLAGS) $(LIBS)

roe.o: roe.cpp roe.h currency.o table.o
	$(CC) -c $< $(CFLAGS) $(LIBS)

table.o: table.cpp
	$(CC) -c $< $(CFLAGS) $(LIBS)
	
currency.o: currency.cpp
	$(CC) -c $< $(CFLAGS) $(LIBS)

HTTPDownloader.o: HTTPDownloader.cpp  HTTPDownloader.h
	$(CC) -c $< $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o

install: roe
	cp $< /usr/local/bin/
