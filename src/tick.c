#include "raylib.h"

#include "tick.h"

static inline void draw(void)
{
        ClearBackground(RAYWHITE);
}

void tick(void)
{
        BeginDrawing();

        draw();

        EndDrawing();
}

