#include <cmath>
#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "SuperPlayer.hpp"

SuperPlayer::SuperPlayer()
{
    defaultInit();
}

void SuperPlayer::move (Map &map)
{
    int mul = surviv::DEFAULT_PLAYER_SPEED; //multiply by speed coefficients

    if (sf::Keyboard::isKeyPressed (sf::Keyboard::D))
    {
        sprite.move (1 * mul, 0 * mul);
        map.mainView.move (1 * mul, 0 * mul);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::A))
    {
        sprite.move (-1 * mul, 0 * mul);
        map.mainView.move (-1 * mul, 0 * mul);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::W))
    {
        sprite.move (0 * mul, -1 * mul);
        map.mainView.move (0 * mul, -1 * mul);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::S))
    {
        sprite.move (0 * mul, 1 * mul);
        map.mainView.move (0 * mul, 1 * mul);
    }
}

void SuperPlayer::rotate (const sf::RenderWindow &window)
{
    sf::Vector2i mouse_position = sf::Mouse::getPosition (window);
    double rot = std::atan2 (mouse_position.y - surviv::VIEW_DIM_Y / 2, mouse_position.x - surviv::VIEW_DIM_X / 2) * (180 / surviv::PI) + 90;
    sprite.setRotation (rot);
}
