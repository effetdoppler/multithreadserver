#include <err.h>
#include <stdlib.h>
#include "shared_queue.h"

shared_queue* shared_queue_new()
{
    struct shared_queue *sq = malloc(sizeof(struct shared_queue));
    sem_init(&sq->size, 0, 0);
    sem_init(&sq->lock, 0, 1);
    sq->queue = NULL;

    return sq;
}

void shared_queue_push(shared_queue* sq, int val)
{
    sem_wait(&sq->lock);
    sq->queue = queue_push(sq->queue, val);
    sem_post(&sq->size); 
    sem_post(&sq->lock);
}

int shared_queue_pop(shared_queue* sq)
{
    sem_wait(&sq->size);
    sem_wait(&sq->lock);
    int val;
    sq->queue = queue_pop(sq->queue, &val);
    sem_post(&sq->lock);
    return val;
}

void shared_queue_destroy(shared_queue* sq)
{
    queue** que = &sq->queue;
    queue_empty(que);
    sem_destroy(&sq->lock);
    sem_destroy(&sq->size);
    free(sq);
}