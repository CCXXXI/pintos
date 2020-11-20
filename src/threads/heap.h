#ifndef THREADS_HEAP_H
#define THREADS_HEAP_H

/* A heap is a container that provides constant time lookup of the largest
    element, at the expense of logarithmic insertion and extraction. */

#include <stdbool.h>
#include <stddef.h>

/* Max heap size. */
#define MAX_SIZE 1024

/* Compares the value of two heap elements A and B.
    Returns true if A is less than B, or
    false if A is greater than or equal to B. */
typedef bool heap_less_func(void *a, void *b);

/* Pointer to element. */
typedef void *elem_t;

/* Heap. */
struct heap
{
    elem_t c[MAX_SIZE];  /* Container. */
    size_t size;         /* Size. */
    heap_less_func *cmp; /* Compare function. */
};

void heap_init(struct heap *, heap_less_func);
elem_t heap_top(struct heap *);
bool heap_empty(struct heap *);
void heap_push(struct heap *, elem_t);
elem_t heap_pop(struct heap *);

#endif /* threads/heap.h */
