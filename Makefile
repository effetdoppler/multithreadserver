CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = -pthread -fsanitize=address

all: test_shared_queue server

test_shared_queue: test_shared_queue.o shared_queue.o queue.o
server: server.o shared_queue.o queue.o
shared_queue.o: shared_queue.c shared_queue.h queue.o
queue.o: queue.c queue.h

.PHONY: clean

clean:
	${RM} test_shared_queue test_shared_queue.o
	${RM} server server.o
	${RM} shared_queue.o queue.o