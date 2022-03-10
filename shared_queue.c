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
    while(sq->queue->next)
    {
        sq->queue = sq->queue->next;
    }
    sq->queue->next->val = val;
    sq->
}

int shared_queue_pop(shared_queue* sq)
{
    // TODO
}

void shared_queue_destroy(shared_queue* sq)
{
    // TODO
}