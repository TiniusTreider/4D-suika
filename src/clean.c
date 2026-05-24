#include "raylib.h"

#include "clean.h"

static inline void clean_window(void)
{
        CloseWindow();
}

void clean(void)
{
        clean_window();
}

