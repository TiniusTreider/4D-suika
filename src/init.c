#define _POSIX_C_SOURCE 200809L

#include "raylib.h"

#include "init.h"

#include <stddef.h>

static inline void init_window(void)
{
        InitWindow(1280, 720, "4D suika");
}

volatile sig_atomic_t interrupted = 0;

void interrupt(int signal)
{
        (void)signal;

        interrupted = 1;
}

static inline void init_signal(void)
{
        struct sigaction sa;

        sa.sa_handler = interrupt;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;

        sigaction(SIGINT, &sa, NULL);
}

void init(void)
{
        init_window();

        init_signal();
}
