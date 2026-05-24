#include "raylib.h"

#include "tick.h"

static inline void draw(void)
{
        return;
}

void tick(void)
{
        BeginDrawing();

        draw();

        EndDrawing();
}

