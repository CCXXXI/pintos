#ifndef THREADS_INIT_H
#define THREADS_INIT_H

#include <debug.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Page directory with kernel mappings only. */
extern uint32_t *init_page_dir;

/* Flag used to control if sema_up should call thread_yield. */
bool ready_to_run;

#endif /* threads/init.h */
