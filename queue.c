#include <err.h>
#include <stdlib.h>
#include "queue.h"

queue* queue_push(queue* start, int val)
{
    // TODO
    while(start->next)
    {
        start = start->next;
    }
    start->next = val;

}

queue* queue_pop(queue* start, int *pval)
{
    // TODO
}

void queue_empty(queue** pstart)
{
    // TODO
}