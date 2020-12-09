#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Player.hpp"
#include "SuperPlayer.hpp"
#include "Map.hpp"

int main()
{
    sf::RenderWindow window (sf::VideoMode (surviv::VIEW_DIM_X, surviv::VIEW_DIM_Y), "Main Menu");
    SuperPlayer player;
    Map map;

    window.setVerticalSyncEnabled (true);
    window.setKeyRepeatEnabled (false);

    // Set Window Icon
    sf::Image icon;
    icon.loadFromFile ("graphics/logo/logo-surviv.png");
    window.setIcon (icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    while (window.isOpen())  //Main Game Loop
    {
        sf::Event event;
        while (window.pollEvent (event)) //event handler loop
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }



        //game logic
        player.move (map);
        player.rotate (window);



        //drawing happens from here
        window.setView (map.mainView);
        window.draw (map.sprite);
        window.draw (player.sprite);
        window.display();
        window.clear();
    }



    return EXIT_SUCCESS;
}
