CC = g++
CFLAGS = -std=c++11 -Wall -Werror

all: loadbalancer

loadbalancer: main.o loadbalancer.o webserver.o request.o
	$(CC) $(CFLAGS) -o loadbalancer main.o loadbalancer.o webserver.o request.o

main.o: main.cpp LoadBalancer.h WebServer.h Request.h
	$(CC) $(CFLAGS) -c main.cpp

loadbalance.o: loadbalancer.cpp LoadBalancer.h WebServer.h Request.h
	$(CC) $(CFLAGS) -c loadbalancer.cpp

webserver.o: webserver.cpp WebServer.h Request.h
	$(CC) $(CFLAGS) -c webserver.cpp

request.o: request.cpp Request.h
	$(CC) $(CFLAGS) -c request.cpp

clean:
	rm -f loadbalancer *.o
