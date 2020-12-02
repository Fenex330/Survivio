#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"

unsigned int Player::player_count = 0;

void Player::defaultInit()
{
    if (!texture.loadFromFile ("graphics/custom/character.png"))
    {
        std::cerr << "Exiting, resources not found" << std::endl;
        abort();
    }
    
    texture.setSmooth (true);
    texture.setRepeated (false);
    sprite.setTexture (texture);

    sf::FloatRect boundingBox = sprite.getLocalBounds();
    sprite.setOrigin (boundingBox.width / 2, boundingBox.height / 2);

    Player::player_count++;
}

Player::~Player()
{
    Player::player_count--;
}
