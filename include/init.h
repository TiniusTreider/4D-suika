#ifndef INIT_H
#define INIT_H

#include <signal.h>

extern volatile sig_atomic_t interrupted;

void init(void);

#endif

