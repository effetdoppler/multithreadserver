#include <err.h>
#include <stdlib.h>
#include "shared_queue.h"

shared_queue* shared_queue_new()
{
    struct shared_queue *sq = malloc(sizeof(struct shared_queue));
    sem_t size;
    sq->size = sem_init(size, 0, 0);
    sem_t lock;
    sq->size = sem_init(lock, 0, 0);
    queue *q;
    sq->queue = q;


    return sq;
}

void shared_queue_push(shared_queue* sq, int val)
{
    sem_post(sq->lock);
    queue_push(sq->queue, val);
    sem_wait(sq->lock);
    sem_post(sq->size); 
}

int shared_queue_pop(shared_queue* sq)
{
    sem_wait(sq->size);
    sem_post(sq->lock);
    int *pval;
    queue_pop(sq->queue, pval);
    sem_wait(sq->lock);
    return pval;
}

void shared_queue_destroy(shared_queue* sq)
{
    struct queue** que = sq->queue;
    queue_empty(que);
    sem_destroy(sq->lock);
    sem_destroy(sq->size);
    free(sq);
}