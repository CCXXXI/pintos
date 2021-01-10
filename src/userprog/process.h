#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"
#include <list.h>

typedef int pid_t;

/* States in a user process's life cycle. */
enum process_status
{
    PROCESS_LOADING, /* Default state. */
    PROCESS_FAILED,  /* Failed to load. */
    PROCESS_NORMAL,  /* Running process. */
};

/* Contains the infos that should not be discarded when thread exit. */
struct process
{
    struct thread *thread;      /* Pointer to struct thread. */
    pid_t pid;                  /* Process identifier. */
    enum process_status status; /* Process state. */
    int exit_code;              /* Exit code. */
    struct list_elem allelem;   /* List element for all processes list. */
    struct list_elem elem;      /* List element for children list. */
    struct list children;       /* List of children. */
    struct process *parent;     /* Parent. */
};

tid_t process_execute(const char *file_name);
int process_wait(tid_t);
void process_exit(void);
void process_activate(void);
struct process *create_process(struct thread *t);
struct process *get_process(pid_t pid);

#endif /* userprog/process.h */
