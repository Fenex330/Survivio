#pragma once

#include "Player.hpp"

class SuperPlayer final : public Player
{
    public:
        SuperPlayer();
        virtual ~SuperPlayer();
        virtual void move (Map &map) override;
};
