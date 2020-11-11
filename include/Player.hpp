#pragma once

#include "Map.hpp"

class Player // Abstract Base Class for SuperPlayer, NetPlayer, BotPlayer
{
    public:
        sf::Sprite sprite;
        static unsigned int player_count;

        virtual ~Player();
        virtual void move (Map &map) = 0;
        virtual void rotate(const sf::RenderWindow &window) = 0;

    protected:
        void defaultInit();
        sf::Texture texture;
};
