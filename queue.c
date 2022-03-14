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
    if (start == NULL)
        return NULL;
    queue* first = start;
    queue* q = start->next;
    *pval = q->val;
    if (q->next != q)
        first->next = q->next;
    else
        first = NULL;
    free(q);
    return first;
}

void queue_empty(queue** pstart)
{
    queue* q = *pstart;
    int val;
    while(q)
        q = queue_pop(q, &val);
    *pstart = NULL;
}