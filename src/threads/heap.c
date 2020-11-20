#include "heap.h"
#include <string.h>
#include <debug.h>

static void swap(elem_t *, elem_t *);

void heap_init(struct heap *h, heap_less_func cmp)
{
    h->size = 0;
    h->cmp = cmp;
}

/* Returns the top element in the heap (also the greatest). */
elem_t heap_top(struct heap *h)
{
    ASSERT(!heap_empty(h));

    return h->c[0];
}

/* Returns true if the heap is empty, false otherwise. */
bool heap_empty(struct heap *h)
{
    return h->size == 0;
}

/* Pushes the given element to the heap. */
void heap_push(struct heap *h, elem_t e)
{
    size_t i = h->size;
    ASSERT(i < MAX_SIZE);

    h->c[i] = e;
    while (i != 0)
    {
        size_t p = (i - 1) / 2;
        if (h->cmp(h->c[i], h->c[p]))
            break;
        swap(&h->c[i], &h->c[p]);
        i = p;
    }

    h->size++;
}

/* Removes and returns the top element from the heap. */
elem_t heap_pop(struct heap *h)
{
    ASSERT(!heap_empty(h));

    h->size--;
    swap(h->c[0], h->c[h->size]);

    size_t i = 0;
    while (true)
    {
        size_t c = i * 2 + 1;
        if (c >= h->size)
            break;
        if (c + 1 < h->size && h->cmp(h->c[c], h->c[c + 1]))
            c++;
        if (h->cmp(h->c[c], h->c[i]))
            break;
        swap(h->c[i], h->c[c]);
        i = c;
    }
}

static void swap(elem_t *a, elem_t *b)
{
    elem_t t = *a;
    *a = *b;
    *b = t;
}
