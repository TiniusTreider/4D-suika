#ifndef INIT_H
#define INIT_H

#include <signal.h>

static volatile sig_atomic_t interrupted = 0;

void init(void);

#endif

