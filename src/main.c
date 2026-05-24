#include "raylib.h"

#include "init.h"
#include "tick.h"
#include "clean.h"

int main(void)
{
        init();

        while (!interrupted)
        {
                tick();
        }

        clean();

        return 0;
}

