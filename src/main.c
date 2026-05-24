#define _POSIX_C_SOURCE 200809L

#include "raylib.h"

#include "tick.h"

#include <signal.h>
#include <stdbool.h>
#include <unistd.h>

static inline void init_window(void)
{
        InitWindow(1280, 720, "4D suika");
}

static inline void clean_window(void)
{
        CloseWindow();
}

static volatile sig_atomic_t interrupted = false;

void interrupt(int signal)
{
        (void)signal;

        interrupted = true;
}

static inline void init_signal(void)
{
        struct sigaction sa;

        sa.sa_handler = interrupt;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;

        sigaction(SIGINT, &sa, NULL);
}

int main(void)
{
        init_window();
        init_signal();

        while (!interrupted)
        {
                tick();
        }

        clean_window();

        return 0;
}

