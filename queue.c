#include <err.h>
#include <stdlib.h>
#include "queue.h"

queue* queue_push(queue* start, int val)
{
    while(start->next)
    {
        start = start->next;
    }
    start->next->val = val;
    return start;

}

queue* queue_pop(queue* start, int *pval)
{
    while(start->next)
    {
        if (start->next)
        {
            if (*start->next->val == pval)
            {
                start->next = start->next->next; 
                break;
            }
        }
        start = start->next;
    }
    return start;
}

void queue_empty(queue** pstart)
{
    // TODO
}