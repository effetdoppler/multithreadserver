#include <err.h>
#include <stdlib.h>
#include "shared_queue.h"

shared_queue* shared_queue_new()
{
    struct shared_queue *sq = malloc(sizeof(struct shared_queue));
    return sq;
}

void shared_queue_push(shared_queue* sq, int val)
{
    sq->lock = 0;
    sq->size++;
    queue_push(sq->queue, val);
    sq->lock = 1;
}

int shared_queue_pop(shared_queue* sq)
{
    sq->lock = 0;
    queue_pop(sq->queue, sq->size-1);
    sq->size++;
    sq->lock = 1;
}

void shared_queue_destroy(shared_queue* sq)
{
    queue_empty(sq->queue);
    sq->size = 0;
    sq->lock = 1;
    free(sq);
}