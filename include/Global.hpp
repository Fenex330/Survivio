#pragma once

#include <cmath>

/* Store all global defines and constants here */

namespace surviv
{
    constexpr long double PI = std::atan (1) * 4;

    const unsigned short view_dim_X = 800;
    const unsigned short view_dim_Y = 800;
    const unsigned int default_player_speed = 10;
}
