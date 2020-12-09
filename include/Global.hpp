#pragma once

/* Store all global defines and constants here */

#define Global inline const

namespace surviv
{
    Global long double PI = 3.14159265359;
    Global short VIEW_DIM_X = 800;
    Global short VIEW_DIM_Y = 800;
    Global short PLAYER_ORIGIN_OFFSET = 12;
    Global int DEFAULT_PLAYER_SPEED = 10;
}

#undef Global
