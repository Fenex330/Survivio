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
    int mul = surviv::default_player_speed; //multiply by speed coefficients

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

void SuperPlayer::rotate(const sf::RenderWindow &window)
{
    sf::Vector2i local_mouse_position = sf::Mouse::getPosition (window);
    sf::Vector2f sprite_position = sprite.getPosition();

    double distance = std::sqrt (std::pow ((sprite_position.x - local_mouse_position.x), 2) + std::pow ((sprite_position.x - local_mouse_position.x), 2));
    double rot = std::acos ((local_mouse_position.y - surviv::view_dim_Y) / distance) * (180 / surviv::PI);

    sprite.setRotation (rot);
}
