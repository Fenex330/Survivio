#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Player.hpp"
#include "Map.hpp"

int main()
{
    bool key_pressed = false;
    sf::RenderWindow window (sf::VideoMode (surviv::view_dim_X, surviv::view_dim_Y), "Main Menu");
    Player player;
    Map map;

    window.setVerticalSyncEnabled (true);
    window.setKeyRepeatEnabled (false);



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

                case sf::Event::KeyPressed:
                    key_pressed = true;
                    break;

                case sf::Event::KeyReleased:
                    key_pressed = false;
                    break;

                default:
                    break;
            }
        }



        //game logic
        player.move(map, key_pressed);



        //drawing happens from here
        window.setView (map.mainView);
        window.draw (map.sprite);
        window.draw (player.sprite);
        window.display();
        window.clear();
    }



    return EXIT_SUCCESS;
}
