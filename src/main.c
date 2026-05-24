#include "raylib.h"

#include "init.h"
#include "tick.h"
#include "clean.h"

int main(void)
{
        init();

        while (!interrupted && !WindowShouldClose())
        {
                tick();
        }

        clean();

        return 0;
}

