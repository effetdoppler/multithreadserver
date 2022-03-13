#include <err.h>
#include <stdlib.h>
#include "queue.h"

queue* queue_push(queue* start, int val)
{
    queue *q = malloc(sizeof(queue));
    if (q == NULL)
        errx(1, "Not enough memory!");
    q->val = val;
    while(start->next)
    {
        start = start->next;
    }
    start->next = q;

    return &start->next;
}

queue* queue_pop(queue* start, int *pval)
{
    while(start->next)
    {
        start = start->next;
    }
    pval = start->val;
    start = NULL;
    free(start);
    start--;
    if (!start)
        return NULL;
    return start;
}

void queue_empty(queue** pstart)
{
    struct queue start = **pstart;
    int *pval;
    while(start.next)
    {
        queue_pop(&start, pval);
    }
}