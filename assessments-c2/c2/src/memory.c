#include "memory.h"
#include "platform.h"

/* Simple stub memory module with an init function. */

static int memory_initialized = 0;

void memory_init(void)
{
    /* In real target: initialize memory subsystem. Here: set flag. */
    memory_initialized = 1;
}

int memory_is_initialized(void)
{
    return memory_initialized;
}
