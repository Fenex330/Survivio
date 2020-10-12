#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Main Menu");
    
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(true); // We want the user to be able to hold down keys
    Player player;

    while (window.isOpen())  //game loop
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    break;

                default:
                    break;
            }
        }

        window.clear();

        //draw stuff here
        window.draw(player.sprite);
        
        window.display();
    }

    return EXIT_SUCCESS;
}
