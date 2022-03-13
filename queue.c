#include <err.h>
#include <stdlib.h>
#include "queue.h"

queue* queue_push(queue* start, int val)
{
    queue *q = malloc(sizeof(queue));
    if (q == NULL)
        errx(1, "Not enough memory!");
    q->val = val;
    if (start == NULL)
    {
        q->next = q;
    }
    else
    {
        q->next = start->next;
        start->next = q;
    }
    
    return q;
}

queue* queue_pop(queue* start, int *pval)
{
    queue* first = start;
    queue * q = start->next;
    *pval = q->val;
    if (q->next != first)
        start->next = q->next;
    free(q);
    if (!start)
        return NULL;
    return start;
}

void queue_empty(queue** pstart)
{
    queue start = **pstart;
    int *pval = NULL;
    queue *res = queue_pop(&start, pval);
    while(res)
    {
        res = queue_pop(&start, pval);
    }
}