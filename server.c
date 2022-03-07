#define _GNU_SOURCE

#include <err.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "shared_queue.h"

// Number of threads.
const size_t THREAD_COUNT = 4;

// Buffer size in bytes.
const size_t BUFFER_SIZE = 256;

void rewrite(int fd, const void *buf, size_t count)
{
    // TODO (from a previous practical)
}

void echo(int fd_in, int fd_out)
{
    // TODO (from a previous practical)
}

// Function executed by the threads.
void* worker(void* arg)
{
    // Gets the shared queue.
    shared_queue* queue = arg;

    // TODO
}

int main()
{
    // Creates the shared queue.
    shared_queue* queue = shared_queue_new();

    // TODO
}