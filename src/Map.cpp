#include <iostream>
#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Map.hpp"

Map::Map()
{
    mainView.setCenter (sf::Vector2f (0, 0));
    mainView.setSize (sf::Vector2f (surviv::VIEW_DIM_X, surviv::VIEW_DIM_Y));

    defaultInit();
}

void Map::defaultInit()
{
    if (!texture.loadFromFile ("graphics/custom/map-ground.png"))
    {
        std::cerr << "Exiting, resources not found" << std::endl;
        abort();
    }
    
    texture.setSmooth (true);
    texture.setRepeated (false);
    sprite.setTexture (texture);
}
