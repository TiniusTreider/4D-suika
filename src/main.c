#include "raylib.h"

static inline void init_window(void)
{
        InitWindow(1280, 720, "4D suika");
}

static inline void clean_window(void)
{
        CloseWindow();
}

int main(void)
{
        init_window();

        clean_window();

        return 0;
}

