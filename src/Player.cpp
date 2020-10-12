#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"

Player::Player()
{
    if (!texture.loadFromFile("graphics/custom/character.png"))
    {
        std::cerr << "Exiting, resources not found" << std::endl;
        abort();
    }
    
    texture.setSmooth(true);
    texture.setRepeated(false);
    sprite.setTexture(texture);
}
