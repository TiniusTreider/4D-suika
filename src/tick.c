#include "draw.h"
#include "physics.h"
#include "tick.h"

void tick(void)
{
        physics();

        draw();
}

